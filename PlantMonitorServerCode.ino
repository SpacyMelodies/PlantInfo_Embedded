#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

// Currently set for mobile hotspot
// set to your home network when wanting to connect there
const char* ssid = "";
const char* pass = "";
String valueString = "1";


void setup() {
  
  WiFi.begin(ssid, pass);
  Serial.begin(115200);  
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Conncecting to WiFi");
    Serial.println(".");
    delay(500);
  } 
  Serial.println("Conncected!");
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  server.on("/",[](){server.send(200,"text/plain",valueString);});
  server.begin();
}


void loop() {
  delay(100);
  if(Serial.available() > 0)
  {
  valueString = Serial.readStringUntil('\n');
  server.handleClient();
  }
}
