

#include <ESP8266WiFi.h>


const char* ssid     = "IOT-CUP";
const char* password = "";

const char* host = "autiot.coolpage.biz";
String PostData = "";

void setup() {
  Serial.begin(115200);
  delay(10);
//  pinMode(0,INPUT);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  /////////////
//  delay(7000);
  ////////////
  while (Serial.available() <= 0) {Serial.println("waiting..");delay(300);}
  if (Serial.available()) {
    delay(100); //allows all serial sent to be received together
    PostData=Serial.readString();
  }
 
   Serial.println(PostData);  
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
    return;
  }

/////////////
//PostData = "{\"reqtype\":\"upload\",\"uid\":\"2\",\"password\":\"123\",\"temperature\":\"24\",\"humidity\":\"30\",\"pulse\":\"75\",\"reqtime\":\"\"}";
////////////

client.println("POST /users.php HTTP/1.1");
client.println("Host: autiot.coolpage.biz ");
client.println("Cache-Control: no-cache");
client.println("Content-Type: application/json");
client.print("Content-Length: ");
client.println(PostData.length());
client.println();
client.println(PostData);

long interval = 2000;
unsigned long currentMillis = millis(), previousMillis = millis();

while(!client.available()){

  if( (currentMillis - previousMillis) > interval ){

    Serial.println("Timeout");
//    blinkLed.detach();
    digitalWrite(2, LOW);
    client.stop();     
    return;
  }
  currentMillis = millis();
}

while (client.connected())
{
  if ( client.available() )
  {
    char str=client.read();
   Serial.print(str);
  }      
}
Serial.println("");
Serial.flush();
}

