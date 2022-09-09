# ELEC1601 Group 8 Exercise 3

Worked with light sensors and continuous servos to simulate how a robot might work.

## Part 3

### How the code is structured

Wheels is a class that controls the movement of the robot, with methods for the 4 movement types specified.
LightSensor is a class that wraps pins which are connected to the light sensor on either side.
The loop calls the light sensor’s checking function to read from its analog pin and see if it should turn or not. Otherwise it just keeps moving forward.

### Complications

Initially I tried initialising the servos in the Wheels constructor but that didn't work because of the order the code is compiled in resulting in weird behaviour from the servo library. So I had to initialise them separately and attach them separately which is not ideal but it works.

> Formatting/spacing is also weird from tinkercad
