#include <Arduino.h>
void setup() {
    Serial.begin(115200);

}
uint8_t Sum(uint32_t sec) {
    uint8_t i=0;
    while(sec>0) {
        i++;
        sec=sec/10;
    }
    return i;
}
void Out(uint32_t sec, char Number[]) {
    uint8_t i=Sum(sec);
    Number[0]='E';
    Number[1]=i+'0';
    Number[2]='M';
    for (uint8_t j=0;j<i; j++ ) {
        Number[j+3]=sec%10+'0';
        sec=sec/10;
        Number[j+4]='E';
    } 
}
char Number[255]={0};
void loop(){
    uint32_t sec=millis();
    Out(sec, Number);
    Serial.println(Number);
    Serial.println(sec);
}
