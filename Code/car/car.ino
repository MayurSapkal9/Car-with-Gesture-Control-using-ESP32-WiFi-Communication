#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

int motor1pin1 = 25;
int motor1pin2 = 26;

int motor2pin3 = 27;
int motor2pin4 = 33;

int led = 2;

//Your IP address or domain name with URL path
const char* serverNameread_X = "http://192.168.4.1/temperature";
const char* serverNameread_Y = "http://192.168.4.1/humidity";
const char* serverNameread_Z = "http://192.168.4.1/pressure";

#include <Wire.h>
String X;
String Y;
String Z;

float x;
float y;
float z;

unsigned long previousMillis = 0;
const long interval = 1000; 

void setup() {
  Serial.begin(115200); 

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  pinMode(motor2pin4, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
    digitalWrite(led, LOW);
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(led, HIGH);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      X = httpGETRequest(serverNameread_X);
      Y = httpGETRequest(serverNameread_Y);
      Z = httpGETRequest(serverNameread_Z);
      Serial.println("X: " +X  + "Y: " + Y+ " Z: " + Z );

      x = atof(X.c_str());
      y = atof(Y.c_str());
      z = atof(Z.c_str());
      //Serial.println(x);
           
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
      connect_WiFi();
      digitalWrite(led, LOW);
    }
    car();
  }
  
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void connect_WiFi(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(led, HIGH);
}

void car(){
  if (x > 5 && z < 10){
    //forward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, HIGH);
  } else if (x < -4 && z < 10){
    //backward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  } else if (y < -8 && z < 8){
    //right
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  } else if (y > 7 && z < 8){
    //left
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, HIGH);    
  } else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, LOW);
  }
}
