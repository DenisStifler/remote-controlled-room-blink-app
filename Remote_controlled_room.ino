#include <UIPEthernet.h>
#include <BlynkSimpleUIPEthernet.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>
#define DHTPIN 3
#define RGBPIN 4
//#define DHTTYPE DHT11
#define NUMPIXELS 16
#define RELAY 5

char auth[] = "4115e6a928134d3ba13c305a186a242b";
//DHT dht(DHTPIN, DHTTYPE);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, RGBPIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Blynk.begin(auth);
  //dht.begin();
  strip.begin();
  strip.show();
  strip.show();
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
}

void loop()
{
  Blynk.run();
}

//BLYNK_READ(V0) // SET TEMPERATURE
//{
 // byte t = dht.readTemperature();
  //Blynk.virtualWrite(V0, t);
//}

BLYNK_WRITE(V1) // SET RGB
{
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();
  for(int i=0;i<NUMPIXELS;i++)
  {   
    strip.setPixelColor(i, strip.Color(R,G,B)); 
    strip.show();
  }
}

//BLYNK_READ(V2) // SET HUMIDITY
//{
 // byte h = dht.readHumidity();
 // Blynk.virtualWrite(V2, h);
//}

BLYNK_WRITE(V3) // SET RELAY
{
  int stateRelay = param.asInt();
  if (stateRelay == 66) {
    digitalWrite(RELAY, LOW);
  }
  if (stateRelay == 45) {
    digitalWrite(RELAY, HIGH);  
  }
}
 


