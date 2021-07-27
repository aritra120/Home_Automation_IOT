#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "9KA2Tk2A5XGgFUn5b8qcjppOqn8WPl9w";
char ssid[] = "ayan";
char pass[] = "123456789";
const int button = D2;
const int led = D5;
int m = 0;
int p = 0;
#define vbutton V1

BLYNK_WRITE(V0)
{
  m = param.asInt();
  Serial.println(m);
}
BLYNK_WRITE(V1)
{
  p = param.asInt();
  Serial.println(p);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  int b = digitalRead(button);
  Blynk.run();
  Serial.println(b);
  if(m==1)
  {
    digitalWrite(led, digitalRead(D2));
    Blynk.virtualWrite(vbutton, digitalRead(D5));
  }
  else
  {
    digitalWrite(led, p);
  }
}
