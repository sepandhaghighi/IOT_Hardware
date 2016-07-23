
String PostData = "{\"reqtype\":\"upload\",\"uid\":\"5\",\"password\":\"123\",\"temperature\":\"1000\",\"humidity\":\"1000\",\"pulse\":\"750\",\"reqtime\":\"\"}";

void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  // initialize the ledPin as an output:
}

void loop() {

  delay(5000);
  Serial.println(PostData);

}

