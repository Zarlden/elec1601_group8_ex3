// C++ code
//
#include <Servo.h>
#define LEFT_READ 12
#define RIGHT_READ 13
#define LEFT_ANALOG_READ A4
#define RIGHT_ANALOG_READ A5
#define HIGH_SPEED_MAGNITUDE 200
#define MED_SPEED_MAGNITUDE 100
#define LOW_SPEED_MAGNITUDE 50
#define STATIONARY_MS 1500

// From the perspective of the arduino board looking
// at the servos

Servo leftServo;
Servo rightServo;


class Wheels
{

  public:
  
  	void right(int speed)
    {
      // Both rotate clockwise

      leftServo.writeMicroseconds(STATIONARY_MS - speed);
      rightServo.writeMicroseconds(STATIONARY_MS - speed);

    }

    void left(int speed)
    {
      // Both rotate clockwise

      leftServo.writeMicroseconds(STATIONARY_MS + speed);
      rightServo.writeMicroseconds(STATIONARY_MS + speed);
    
    }
  
    void reverse(int speed)
    {
      // Servos on opposite sides ss:
      // Right one needs to spin anticlockwise
      // Left one needs to spin clockwise

      // Opposite of forwards
      // Directions to go forward
      leftServo.writeMicroseconds(STATIONARY_MS + speed);
      rightServo.writeMicroseconds(STATIONARY_MS - speed);

    }

    void forward(int speed)
    {

      // Servos on opposite sides ss:
      // Right one needs to spin clockwise
      // Left one needs to spin anticlockwise

      // Directions to go reverse
      leftServo.writeMicroseconds(STATIONARY_MS - speed);
      rightServo.writeMicroseconds(STATIONARY_MS + speed);

    }

};

class LightDetector
{
  private:
  	int pin;
  	int value;
  public:
  	LightDetector(int _pin)
    {
      pin = _pin;
    }
    // Reads one value of the current light sensor this tick
    // Should be used in the main loop
  	int readSensorTick()
    {
      value = analogRead(pin);
      return value;
    }
  	
  	void printSensorTick()
    {
      Serial.println(value);
    }
};

LightDetector leftLight(LEFT_ANALOG_READ);
LightDetector rightLight(RIGHT_ANALOG_READ);
Wheels shieldBotDriver;

void setup()
{
  leftServo.attach(LEFT_READ);
  rightServo.attach(RIGHT_READ); 
    
  // Scenario 1
  shieldBotDriver.forward(MED_SPEED_MAGNITUDE);
}


void loop()
{
   // Scenario 2
   if (leftLight.readSensorTick() < 200)
   {
     shieldBotDriver.left(LOW_SPEED_MAGNITUDE);
     leftLight.printSensorTick();
   }
   // Scenario 3
   else if (rightLight.readSensorTick() < 200)
   {
     shieldBotDriver.right(LOW_SPEED_MAGNITUDE);
     rightLight.printSensorTick();
   }
   shieldBotDriver.forward(MED_SPEED_MAGNITUDE);
}

