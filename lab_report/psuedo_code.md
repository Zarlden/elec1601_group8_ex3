# Pseudo code the lab

## Simulation

```c
import the Servo library
constant LEFT_ANALOG = A4
constant RIGHT_ANALOG = A5
constant LEFT_SERVO = 12
constant RIGHT_SERVO = 13
constant MEDIUM_SPEED_MAGNITUDE = 100
constant LOW_SPEED_MAGNITUDE = 50

COMMENT: Class controlling the movement of the servos
class Driver
  public:
    leftServo: Servo
    rightServo: Servo

    method forward(speed: integer):
      Make leftServo rotate counterclockwise at speed
      Make rightServo rotate clockwise at speed
    endmethod

    method reverse(speed: integer):
      Make leftServo rotate clockwise at speed
      Make rightServo rotate counterclockwise at speed
    endmethod

    method right(speed: integer):
      Make leftServo rotate counterclockwise at speed
      Make rightServo rotate counterclockwise at speed
    endmethod

    method left(speed: integer):
      Make leftServo rotate clockwise at speed
      Make rightServo rotate clockwise at speed
    endmethod
endclass

COMMENT: Wrapper class for the light detector pins
class LightDetector:
  private:
    pin: integer

  public:
    constructor LightDetector(_pin: integer):
      pin = _pin
    endconstructor

    method readSensorTick():
      return the analog value read by the pin field
    endmethod
endclass

COMMENT: Initalise objects, passing in the corresponding pins to the LightDetector constructor
leftLight(LEFT_ANALOG): LightDetector
rightLight(RIGHT_ANALOG): LightDetector
shieldBotDriver(): Driver

function setup():
  Attach the leftServo of shieldBotDriver to the LEFT_SERVO pin
  Attach the rightServo of shieldBotDriver to the RIGHT_SERVO pin
endfunction

function loop():
  Call the forward(MEDIUM_SPEED_MAGNITUDE) method of shieldBotDriver
  delay 3000 ms

  if readSensorTick() method of leftLight < 2V:
    Call the left(LOW_SPEED_MAGNITUDE) method of shieldBotDriver
    delay 3000 ms
  endif

  if readSensorTick() method of rightLight < 2V:
    Call the right(LOW_SPEED_MAGNITUDE) method of shieldBotDriver
    delay 3000 ms
  endif
endfunction
```
