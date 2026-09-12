#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int AIN1 = 2, PWMA = 3, AIN2 = 4;   
const int BIN1 = 5, PWMB = 6, BIN2 = 7;   
const int STBY = 8;
const int BTN_A = 12;

const int SERVO_PIN = 9;
const int HEATER_PIN = 10;   
const int BTN_B = 13;

Servo swingArm;

const int MOTOR1_SPEED = 50;   
const int MOTOR2_SPEED = 50;   
const unsigned long TWIST_TIME_MS = 300;

const unsigned long HEAT_TIME_MS = 1000;   
const int SERVO_START_ANGLE = 10;
const int SERVO_END_ANGLE = 150;
const unsigned long CUT_MOVE_TIME_MS = 250; 

bool stationABusy = false;
bool stationBBusy = false;

void setup() {
  Serial.begin(9600);

  pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT); pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT); pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH); 

  pinMode(HEATER_PIN, OUTPUT);
  digitalWrite(HEATER_PIN, LOW);

  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);

  swingArm.attach(SERVO_PIN);
  swingArm.write(SERVO_START_ANGLE);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed"));
  }
  showMessage("Ready.", "Awaiting candy...");
}

void loop() {
  if (!stationABusy && digitalRead(BTN_A) == LOW) {
    runStationA();
  }
  if (!stationBBusy && digitalRead(BTN_B) == LOW) {
    runStationB();
  }
}

void runStationA() {
  stationABusy = true;
  showMessage("Station A", "Unwrapping...");

  digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, MOTOR1_SPEED);
  analogWrite(PWMB, MOTOR2_SPEED);

  unsigned long start = millis();
  while (millis() - start < TWIST_TIME_MS) {
    int pct = map(millis() - start, 0, TWIST_TIME_MS, 0, 100);
    showMessage("Station A", ("Progress: " + String(pct) + "%").c_str());
    delay(150);
  }

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);

  showMessage("Station A", "Unwrapped. Somehow.");
  delay(1500);
  showMessage("Ready.", "Awaiting candy...");
  stationABusy = false;
}

void runStationB() {
  stationBBusy = true;
  swingArm.write(SERVO_START_ANGLE);

  showMessage("Station B", "Heating...");
  digitalWrite(HEATER_PIN, HIGH);
  delay(HEAT_TIME_MS);

  showMessage("Station B", "Cutting...");
  for(int i = SERVO_START_ANGLE; i<SERVO_END_ANGLE; i+=5){
  swingArm.write(i);
  delay(CUT_MOVE_TIME_MS);
  }
  delay(300);
  swingArm.write(SERVO_START_ANGLE);
  delay(CUT_MOVE_TIME_MS);
  digitalWrite(HEATER_PIN, LOW);

  showMessage("Station B", "Cut complete.");
  delay(1500);
  showMessage("Ready.", "Awaiting candy...");
  stationBBusy = false;
}

void showMessage(const char* line1, const char* line2) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(line1);
  display.setCursor(0, 16);
  display.println(line2);
  display.display();
}
