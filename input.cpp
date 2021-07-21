#include <Arduino.h>
void setup()
{
    Serial1.begin(115200, SERIAL_8N1, GPIO_NUM_3, GPIO_NUM_1);
    Serial2.begin(115200, SERIAL_8N1, GPIO_NUM_16, GPIO_NUM_17);
}
uint8_t length(){
char word;
uint8_t len=0;
while(len == 0 && word!='M') {
if (word =='E')
{
word=Serial2.read();
if (static_cast<uint8_t>(word-'0')>=0 && static_cast<uint8_t>(word-'0')<=9){
len=len*10+static_cast<uint8_t>(word-'0');
}
} else {
    word=Serial2.read();
}
};
return len;
}
char Number[20]={0};
uint8_t message(char Number[]){
    uint8_t len=length();
    if (len!=0) {
    //Serial1.println(len);
    char M=Serial2.read();
    char word;
        for (uint8_t i=0; i<len; i++) {
            while (Serial2.available()<0) {

            }
            word=Serial2.read();
            //Serial1.print(word);
          /* if (static_cast<uint8_t>(word-'0')>=0 && static_cast<uint8_t>(word-'0')<=9) {
                break; */
           Number[i]=word;
           if (word == 'M')
           {
               i=i-1;
           };
           // }
        }   //Serial1.println();
        } return len;
    }
void loop()
{
while(!Serial2) {};
uint8_t len=message(Number);
Serial1.println();
char number_2[len+1];
for (uint8_t i=0, j=len-1; i<=len-1; i=i+1, j=j-1 ) {
    //Serial1.print(Number[i]);
    number_2[j]=Number[i];
    if (static_cast<uint8_t>(number_2[j]-'0')>9) {
        for (uint8_t i=0; i<=len-1; i=i+1) {
             number_2[i]='0';
        };
        break;
    };
};
for (uint8_t i=0; i<=len-1; i=i+1)
{
    Serial1.print(number_2[i]);
};
delay(1);
}
