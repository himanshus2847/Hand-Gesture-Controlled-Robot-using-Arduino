#include <VirtualWire.h>

#define m1 2
#define m2 3
#define m3 4
#define m4 5

void setup()
{
    vw_set_rx_pin(11);
    vw_setup(2000);
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);
    vw_rx_start();
    Serial.begin(9600);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='f')
      {  
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       Serial.println("Forward");
      }  
      else if(buf[0]=='b')
      {
       digitalWrite(m1,LOW);
       digitalWrite(m2,HIGH);
       digitalWrite(m3,LOW);
       digitalWrite(m4,HIGH);
       Serial.println("Backward");
      }
      else if(buf[0]=='r')
      {
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       Serial.println("Left");
      }
      else if(buf[0]=='l')
      {
       digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       Serial.println("Right");
      }
      else if(buf[0]=='s')            
      {
       digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
       digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       Serial.println("Stop");
      }
    }
}
