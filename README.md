# Project Name: Sumo Robot

# Aims and Objectives
The primary aim of our project is to design and develop an Arduino-based sumo robot capable of participating in competitive robot battles. Our objectives include:
1.	Integrating sensors for navigation and opponent detection.
2.	Implementing intelligent algorithms for autonomous decision-making.
3.	Incorporating motors for agile movement and strategic maneuvers.
4.	Creating a robust chassis design for durability and stability during battles.

# Project Summary

# What is our project? 
Our project focuses on developing an Arduino sumo robot, a compact and agile machine made for engaging in intense robot battles. These battles feature two robots locked within a defined arena with the primary objective of pushing the opponent out of the ring. Our sumo robot design will integrate a sophisticated array of sensors, motors, and intelligent algorithms enabling it to autonomously navigate the arena, identify opponents, and execute strategic maneuvers with precision.

# Why are we selecting this project? 
We selected this project for several reasons:
·	Educational Value: It offers a practical application of embedded systems and robotics concepts learned in class.
·	Technical Challenge: Building a competitive sumo robot requires integrating hardware and software components effectively.
·	Creative Problem-Solving: Designing algorithms for navigation and opponent detection challenges us to think innovatively.
·	Engagement: Robot battles are exciting and visually appealing, making the project engaging for both creators and spectators.
·	Skill Development: Participants gain skills in programming, electronics, mechanical design, and project management.

# Advantages:
·	Enhances understanding of embedded systems and robotics.
·	Provides hands-on experience in hardware integration and software development.
·	Fosters creativity and problem-solving skills through algorithm design.
·	Engages participants in competitive and visually appealing robot battles.
·	Offers educational value for students, educators, and robotics enthusiasts alike.
 
# Components List
1.	Arduino Nano & Uno
  o	Microcontroller boards used for programming and controlling the robot's functions.
2.	Breadboard
  o	A platform for building and testing electronic circuits.
3.	Ultrasonic Sensor HC-SR04
  o	Sensor for measuring the distance to obstacles using ultrasonic waves.
4.	Infrared Sensor TCRT5000 (x2)
  o	Sensors for detecting surface colors (black or white) to help with navigation and positioning.
5.	DC Motor (x2)
  o	Motors for driving the robot's wheels.
6.	Motor Driver Board
  o	Interface between the Arduino and the motors, allowing for control of motor speed and direction.
7.	OLED 1.8" Display
  o	Small screen for displaying animations.
8.	Switch
  o	Used to power the robot on and off.
9.	Robot Body
  o	The chassis that houses all the components and provides structural integrity.
10.	Battery (x4)
  o	Power source for the robot.
11.	Battery House
  o	Holder for the batteries.
12.	Jumper Wires
  o	Wires for making electrical connections between components.
13.	Miscellaneous Materials
  o	Additional materials for designing and assembling the robot.

# Detailed Description and Functions

# Hardware Setup

·	Motors and Motor Driver:
  o	The motors are connected to the motor driver board, which is controlled by the Arduino Nano. The motor driver allows us to control the speed and direction of each motor independently.
  
·	Sensors:
  o	The Ultrasonic Sensor HC-SR04 is mounted at the front of the robot to detect obstacles. It sends out ultrasonic waves and measures the time taken for the waves to return after hitting an object, thus calculating the distance.
  o	Two TCRT5000 infrared sensors are placed underneath the robot to detect the color of the surface. These sensors help the robot determine if it is near the edge of the ring (typically marked by a white line) or if it is on the playing surface (typically black).
  
·	OLED Display:
  o	The OLED display is used to show animations or the status of the robot, providing visual feedback during operation.
  
·	Power Supply:
  o	The robot is powered by four batteries housed in a battery holder, providing sufficient voltage and current to the motors and sensors.
  
# Software Design

·	Navigation and Obstacle Avoidance:
  o	The robot uses the ultrasonic sensor to avoid obstacles. If an object is detected within a certain distance, the robot will change direction to avoid it.
·	Edge Detection:
  o	The infrared sensors constantly monitor the surface color. If a sensor detects a white surface, the robot will move away from the edge to avoid falling out of the ring.
·	Movement and Strategy:
  o	The motors are controlled to execute various movements such as moving forward, backward, and rotating. These movements are combined to create strategies for pushing the opponent out of the ring.
  
# Code Implementation

·	Initialization:
  o	Setup pin modes for motors, sensors, and the OLED display.
·	Main Loop:
  o	Continuously read sensor values and make decisions based on the sensor inputs.
  o	Control motor speed and direction to navigate the arena and engage with the opponent.
  o	Update the OLED display with relevant information or animations.

# Conclusion
Through systematic testing and optimization, the sumo robot’s sensors and motor functions were fine-tuned to enhance performance and reliability. The adjustments to sensor thresholds and motor control logic significantly improved the robot’s ability to navigate and respond to its environment, resulting in better competitive performance.
