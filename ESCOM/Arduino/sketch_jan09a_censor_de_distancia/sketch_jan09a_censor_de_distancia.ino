#include <SFE_BMP180.h>
#include <Wire.h>
#include <NewPing.h>
long distancia;
long tiempo;
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
SFE_BMP180 pressure;
#define ALTITUDE 1655.0
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  /*
  //Serial.println("REBOOT");
  //if (pressure.begin())
    //Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }*/
  pressure.begin( );
}

void loop() {
  char status;
  double T,P,p0,a;
  int uS = sonar.ping_median();
  //Serial.print(uS);
  //Serial.print("\n\n");
  if(uS<40)
  {
    digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  }
  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0)
    {
      //Serial.print("temperature: ");
      Serial.print(T,2);
      Serial.print("\n");
      //Serial.print(" deg C, ");
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          //Serial.print("absolute pressure: ");
          Serial.print(P,2);
          Serial.print("\n");
          //Serial.print(" mb, ");
          //Serial.print(P*0.0295333727,2);
          //Serial.println(" inHg");
          p0 = pressure.sealevel(P,ALTITUDE); // we're at 1655 meters (Boulder, CO)
          //Serial.print("relative (sea-level) pressure: ");
          //Serial.print(p0,2);
          //Serial.print("\n");
          //Serial.print(" mb, ");
          //Serial.print(p0*0.0295333727,2);
          //Serial.println(" inHg");

          a = pressure.altitude(P,p0);
          //Serial.print("computed altitude: ");
          Serial.print(a,0);
          Serial.print("\n");
          //Serial.print(" meters, ");
          //Serial.print(a*3.28084,0);
          //Serial.println(" feet");
         }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");

  delay(1000);

}
