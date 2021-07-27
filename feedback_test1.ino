#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int p = 0;
char auth[] = "9KA2Tk2A5XGgFUn5b8qcjppOqn8WPl9w";
char ssid[] = "ayan";
char pass[] = "123456789";

void checkPhysicalButton();

int relay1State = LOW;
int pushButton1State = HIGH;

int relay2State = LOW;
int pushButton2State = HIGH;

int relay3State = LOW;
int pushButton3State = HIGH;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V6)
{
  p = param.asInt();
  Serial.println(p);
}
BLYNK_CONNECTED() {

  // Request the latest state from the server

  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);

  // Alternatively, you could override server state using:
 // Blynk.virtualWrite(V1, relay1State);
 // Blynk.virtualWrite(V2, relay2State);
 // Blynk.virtualWrite(V3, relay3State);
}

BLYNK_WRITE(V1) {
  int relay1State = param.asInt();
  digitalWrite(D5, relay1State);
}

BLYNK_WRITE(V2) {
  int relay2State = param.asInt();
  digitalWrite(D6, relay2State);
}
BLYNK_WRITE(V3) {
  int relay3State = param.asInt();
  digitalWrite(D7, relay3State);
}

void checkPhysicalButton()
{
  if (digitalRead(D5) == LOW) {
    // pushButton1State is used to avoid sequential toggles
    if (pushButton1State != LOW) {

      // Toggle Relay state
      relay1State = !relay1State;
      digitalWrite(D5, relay1State);

      // Update Button Widget
      Blynk.virtualWrite(V1, relay1State);
    }
    pushButton1State = LOW;
  } else {
    pushButton1State = HIGH;
  }

  if (digitalRead(D6) == LOW) {
    // pushButton2State is used to avoid sequential toggles
    if (pushButton2State != LOW) {

      // Toggle Relay state
      relay2State = !relay2State;
      digitalWrite(D6, relay2State);

      // Update Button Widget
      Blynk.virtualWrite(V2, relay2State);
    }
    pushButton2State = LOW;
  } else {
    pushButton2State = HIGH;
  }

  if (digitalRead(D7) == LOW) {
    // pushButton3State is used to avoid sequential toggles
    if (pushButton3State != LOW) {

      // Toggle Relay state
      relay3State = !relay3State;
      digitalWrite(D7, relay3State);

      // Update Button Widget
      Blynk.virtualWrite(V3, relay3State);
    }
    pushButton3State = LOW;
  } else {
    pushButton3State = HIGH;
  }
}

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
