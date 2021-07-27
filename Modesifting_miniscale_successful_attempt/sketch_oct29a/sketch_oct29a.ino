#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int p = 0;
char auth[] = "************************";
char ssid[] = "*****";
char pass[] = "*********";
void setup()
{ Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);}
BLYNK_WRITE(V6)
{ p = param.asInt();
  Serial.println(p);}
void loop()
{
  Blynk.run();
  if(p==1)
  {
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
    delay(1000);
    digitalWrite(D5,HIGH);
    delay(500);
    digitalWrite(D6,HIGH);
    delay(500);
    digitalWrite(D7,HIGH);
    delay(500);
  }
}
