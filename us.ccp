#include <Arduino.h>
#define trigpin GPIO_NUM_19
#define echopin GPIO_NUM_22
class US {
  public:
  uint8_t trig;
  uint8_t echo;
  US(uint8_t set_trig, uint8_t set_echo){
    uint8_t trig=set_trig;
    uint8_t echo=set_echo;
    pinMode(set_trig, OUTPUT);
    pinMode(set_echo, INPUT); 
    };
  double getDistance() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(echo, LOW);
    double distance= pulseIn(echo, HIGH);
    distance=distance/58.0;
    return distance;

  };
};
US ultra(trigpin, echopin);
void setup() {
  Serial.begin(115200);
  while(!Serial){};
}

void loop() {
  double a =ultra.getDistance();
  Serial.println(a);
  delay(100);
}
