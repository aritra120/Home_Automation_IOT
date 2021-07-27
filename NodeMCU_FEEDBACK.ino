//BY_AYAN_HALDER: simple feedback to blynk app.
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

BlynkTimer timer;
void checkPhysicalButton();
int ledState = LOW;
int buttonState = HIGH;

char auth[] = "9KA2Tk2A5XGgFUn5b8qcjppOqn8WPl9w";
char ssid[] = "ayan";
char pass[] = "123456789";

//#define SERVER "blynk-cloud.com"
//#define PORT 8442

#define led D5
#define button D2
#define Vbutton V0

#define OTA_HOSTNAME "Feedback Test"

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(Vbutton);
}
BLYNK_WRITE(Vbutton)
{
  ledState = param.asInt();
  digitalWrite(led, ledState);
}
void checkPhysicalButton()
{
  if (digitalRead(button) == LOW)
  {
    if (buttonState != LOW)
    {
      ledState = !ledState;
      digitalWrite(led, ledState);
      Blynk.virtualWrite(Vbutton, ledState);
    }
    buttonState = LOW;
  }
  else
  {
    buttonState = HIGH;
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  ArduinoOTA.setHostname(OTA_HOSTNAME);
  ArduinoOTA.begin();

  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(led, ledState);
}
void loop()
{
  Blynk.run();
  ArduinoOTA.handle();
  timer.run();
  Serial.println(buttonState);
}
