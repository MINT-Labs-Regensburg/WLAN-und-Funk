#include <WiFi.h>

const char* ssid = "FRITZ!Box 75902";
const char* password = "04562358016988474025";

void setup() {
  Serial.begin(115200);
  Serial.println("+++ START +++");

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Mit WiFi verbunden");
  Serial.print("IP= ");
  Serial.println(WiFi.localIP());


}

void loop() {


}
