// C++ code
//
#include <Servo.h>
#define LEFT_READ 12
#define RIGHT_READ 13
#define FULL_SPEED_CLOCKWISE_MS 1700
#define FULL_SPEED_ANTICLOCKWISE_MS 1300
#define STATIONARY_MS 1500

// From the perspective of the arduino board looking
// at the servos
Servo leftServo;
Servo rightServo;

void forward(int duration);
void reverse(int duration);
void right(int duration);
void left(int duration);

void setup()
{
  leftServo.attach(LEFT_READ);
  rightServo.attach(RIGHT_READ);
  int test_duration = 3000;
  
  
  
  forward(test_duration);
  reverse(test_duration);
  left(test_duration);
  right(test_duration);
  
}

void loop()
{

}


void right(int duration)
{
  // Both rotate clockwise
  
  leftServo.writeMicroseconds(FULL_SPEED_ANTICLOCKWISE_MS);
  rightServo.writeMicroseconds(FULL_SPEED_ANTICLOCKWISE_MS);
  // 3 second delay
  delay(duration);
  
  // Pause - 1500 is stationary
  leftServo.writeMicroseconds(STATIONARY_MS);
  rightServo.writeMicroseconds(STATIONARY_MS);
}

void left(int duration)
{
  // Both rotate clockwise
  
  leftServo.writeMicroseconds(FULL_SPEED_CLOCKWISE_MS);
  rightServo.writeMicroseconds(FULL_SPEED_CLOCKWISE_MS);
  // 3 second delay
  delay(duration);
  
  // Pause - 1500 is stationary
  leftServo.writeMicroseconds(STATIONARY_MS);
  rightServo.writeMicroseconds(STATIONARY_MS);
}
void reverse(int duration)
{
  // Servos on opposite sides ss:
  // Right one needs to spin anticlockwise
  // Left one needs to spin clockwise
  
  // Opposite of forwards
  // Directions to go forward
  leftServo.writeMicroseconds(FULL_SPEED_CLOCKWISE_MS);
  rightServo.writeMicroseconds(FULL_SPEED_ANTICLOCKWISE_MS);
  // 3 second delay
  delay(duration);
  
  // Pause - 1500 is stationary
  leftServo.writeMicroseconds(STATIONARY_MS);
  rightServo.writeMicroseconds(STATIONARY_MS);
}

void forward(int duration)
{
  
  // Servos on opposite sides ss:
  // Right one needs to spin clockwise
  // Left one needs to spin anticlockwise
  
  // Directions to go reverse
  leftServo.writeMicroseconds(FULL_SPEED_ANTICLOCKWISE_MS);
  rightServo.writeMicroseconds(FULL_SPEED_CLOCKWISE_MS);
  
  // 3 second delay
  delay(duration);
  
  // Pause - 1500 is stationary
  leftServo.writeMicroseconds(STATIONARY_MS);
  rightServo.writeMicroseconds(STATIONARY_MS);
}


void testSpins()
{
    // Velocity
  /*
  leftServo.write(80);
  rightServo.write(100);
  delay(1000);
  leftServo.write(90);
  rightServo.write(90);
  delay(1000);
  */
  
  // Actual location
  /*
  leftServo.writeMicroseconds(1400);
  rightServo.writeMicroseconds(1600);
  delay(1000);
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);
  delay(1000);
  */
  
  //1300 spins fullspeed clockwise
//  leftServo.writeMicroseconds(1300);
  
  //1400 spins slow clockwise
//    leftServo.writeMicroseconds(1400);
  
    //1500 almost stationary
//    leftServo.writeMicroseconds(1500);
  
    //1600 spins slow anticlockwise
//    leftServo.writeMicroseconds(1600);
  
    //1700 spins fullspeed anticlockwise
//    leftServo.writeMicroseconds(1700);
  
}
