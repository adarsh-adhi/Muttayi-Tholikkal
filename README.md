<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />



# Muttayi Tholikkal 🎯


## Basic Details
### Team Name: Barely functional


### Team Members
- Team Lead: Adarsh S - CUCEK
- Member 2: Nazarullakhan A - CUCEK

### Project Description
Our project is the most over-engineered Candy Unwrapper. It can Unwrapp two kinds of candies- the twist wrap and flow wrap candy. It uses two rotating clips to unwrap the twisted candies and a heated swing arm to cut through the plastic pouch of the flow wrap candy.

### The Problem (that doesn't exist)
Sometimes people crave candies and get lazy to twist/tear the candy wrap. 

### The Solution (that nobody asked for)
Our project solves this problem by using a twin-twist clip mechanism to twist-unwrap twist wrap candies and a heated cutting swing arm mechanism to slice through the plastic pouch of flow wrap candies.

## Technical Details
### Technologies/Components Used
For Software:
- C++/Arduino
- State machines running in loop, triggered by two buttons
- Wire, Adafruit_GFX, Adafruit_SSD1306, Servo
- Arduino IDE

For Hardware:
- Arduino UNO, SSD1306 OLED, TB6612FNG, MG996R, TIP122, Gear motors, Tacktile buttons, LM2596 Buck converter, Nichrome wire
- Twin rotating clips, heated swing arm, Oled display for status
- Soldering iron, Lead, Double side tape, Glue, Scissors, Cutter

### Implementation
For Software:
# Installation
Arduino IDE

### Project Documentation

# Diagrams
![Workflow](Add your workflow/architecture diagram here)
*Add caption explaining your workflow*

For Hardware:

# Schematic & Circuit
![Circuit](Add your circuit diagram here)
*Add caption explaining connections*

![Schematic](Add your schematic diagram here)
*Add caption explaining the schematic*

# Build Photos
- https://github.com/adarsh-adhi/Muttayi-Tholikkal/blob/main/WhatsApp%20Image%202026-09-13%20at%2010.52.11%20PM.jpeg
This is the servo with the frame and heating element. The element is very thin, comparable to a strand of hair, which heats up and glows red when powered ON. The servo then sweeps the frame for a smooth slice.

- https://github.com/adarsh-adhi/Muttayi-Tholikkal/blob/main/WhatsApp%20Image%202026-09-12%20at%207.07.56%20PM.jpeg
This is the twist unwrap mechanism. The toffee candy is placed securely in the middle clip. Then the two clips on both side is clipped onto the two ends of the twist wrap. When powered ON, the two end clips rotate, which rotates the wrap thus unwrapping it. The middle clip holds the candy in place.

- https://github.com/adarsh-adhi/Muttayi-Tholikkal/blob/main/WhatsApp%20Image%202026-09-13%20at%2010.52.10%20PM%20(1).jpeg
This is the TIP122 NPN power Darlington transistor. We used this to control the power ON/OFF of the heating element. It is bolted onto a small heat sink for heat dissipation. The base is connected to D10 of UNO via a 680ohm resistor to limit base current.

- https://github.com/adarsh-adhi/Muttayi-Tholikkal/blob/main/WhatsApp%20Image%202026-09-13%20at%2010.51.59%20PM.jpeg
This picture shows the internal wiring and circuit of the Muttayi Tholikkal machine. All the components are wired to each other. We have connected all components using jumper wires, breadboard and soldering. We secured each components, so that they stay in place and not cause any connection failure or system glitch.

- https://github.com/adarsh-adhi/Muttayi-Tholikkal/commit/d55290407ea38f1e725a39cb05bef09f146ce0b2
This is the final product. it has two stations- 
1. Twin twist station
2. Heated sweep station
Each station does a different procedure to unwrap different candy wraps. Twist station has a fixed clip, to which user can clip their candy, and two rotating clips, to which they can clip the wrap ends. The rotating clips rotate for a fixed time, which in turn rotatess the twist wraps and thus unwraps it.
The heated sweep arm works by firstly heatig up the heatng element and making a slow, smooth slice through the flow wrap packaging, thus unwrap it. It has a heating element(taken from an old soldering iron), connected to a frame(made with ice-cream sticks), which is glued to the shaft of a servo motor. The servo slowly sweeps from 0° to 180° and then returns back to it's original position. When a flow wrap candy is placed in front of the sweep movement, the heat & slow sweep movement slices the plastic wrap clean.

### Project Demo
# Video
[Add your demo video link here]
*Explain what the video demonstrates*

# Additional Demos
[Add any extra demo materials/links]

## Team Contributions
- [Name 1]: [Specific contributions]
- [Name 2]: [Specific contributions]
- [Name 3]: [Specific contributions]

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)



