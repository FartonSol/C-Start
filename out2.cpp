#include <Arduino.h>

void setup() {
    Serial1.begin(115200, SERIAL_8N1, GPIO_NUM_3, GPIO_NUM_1); 
    Serial2.begin(115200, SERIAL_8N1, GPIO_NUM_16, GPIO_NUM_17);
}

uint8_t length() {
    char word='U';
    while (word!='E') {
        if (Serial2.available()>0) {
            word=Serial2.read();
        }
    }
    uint8_t len = 0;
    while(word!='M') {
        if (Serial2.available()>0) {
            word = Serial2.read();
            if (static_cast<uint8_t>(word - '0') >= 0 && static_cast<uint8_t>(word - '0') <= 9) {
                len = len * 10 + static_cast<uint8_t>(word - '0');
            }
        }
    }
    if (len>20) {
        len=0;
    }
    return len;
}
char Number[20]={0};

uint8_t message(char Number[]) {
    uint8_t len = length();
    if (len != 0) {
        char word=Serial2.read();
        for (uint8_t i = 0; i < len; i++) {
            if (static_cast<uint8_t>(word-'0')>=10) {
                len=0;
                Serial1.println('k');
                Serial1.println(word);
                break;
            }
            Number[i] = word;
            word = Serial2.read();
        }
        /*if (word!='E') {
            len=0;
            Serial1.println('h');
        }*/
    }
    return len;
}

void loop() {
    while(!Serial2) {};
    uint8_t len=message(Number);
    Serial1.println(len);
   /* char number_2[len+1];
    for (uint8_t i=0; i<=len-1; i=i+1) {
        number_2[len-1-i] = Number[i];
    };
    uint32_t number_final;
    for (uint8_t i=0; i<=len-1; i=i+1)
    {
        number_final=number_final*10+static_cast<uint8_t>(number_2[i]);
    };
    Serial2.println(number_final);
    delay(1); */
}
