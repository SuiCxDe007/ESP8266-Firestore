#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

const char* ssid = "SuiCxDe4G";
const char* password = "kk=@QW12XX";
const char* serverName = "http://firebaseapi.herokuapp.com";
void setup(void)
{ 

  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){
  
      HTTPClient http;
      http.begin(serverName);
      String id="23";
      String location="dead";
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"id\":\"" + id + "\",\"location\":\"" + location + "\"}");
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

 
 }else{
    Serial.println("Error in WiFi connection");
 }
 
  delay(10000);
}
