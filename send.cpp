#include <Arduino.h>
#include <math.h>
void setup()
{
    Serial.begin(115200);
}
int delenie(int a) {
    int i=0;
    while (1) {
        a=a/10;
        i=i+1;
        if (a==0) {
            return i;
            break;
        };

    };
}
void otpr(int a, int i) {
    int c=pow(10, (i-1));
    while (1) {
        if (c==0)
        {
            break;
        } else {
            char b=a/c+'0';
            Serial.println(b);
            Serial.println(c);
            a=a%c;
            c=c/10;
        }
    };
}
void loop()
{
    int a=millis();
    int i=delenie(a);
    Serial.print('E');
    Serial.print(delenie(a));
    Serial.print('M');
    otpr(a,i);
    Serial.println('E');
    Serial.println(a);
    }
