#include "network.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  setupScreen();
  connectToWifi();
}

void loop() {

  while(!isWifiConnected()) {
    connectToWifi();
  }

  String publicIpAddress = fetchCurrentIpAddress();
  displayPublicIpAddress(publicIpAddress);
  updateInfomaniakHostname(publicIpAddress);

  delay(300000);
}
