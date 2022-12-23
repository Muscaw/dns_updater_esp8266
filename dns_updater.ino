#include "network.h"
#include "display.h"
#include "secrets.h"

void setup() {
  Serial.begin(115200);
  setupScreen();
  displayWifiStatus(false);
  connectToWifi();
}

void loop() {

  displayWifiStatus(isWifiConnected());

  while(!isWifiConnected()) {
    connectToWifi();
  }

  String currentIpAddress = getCurrentAssignedIpAddress(INFOMANIAK_HOSTNAME);
  Serial.print("Current dynamic address: ");
  Serial.println(currentIpAddress);

  displayCurrentInfomaniakAddress(currentIpAddress);

  String publicIpAddress = fetchCurrentIpAddress();
  displayPublicIpAddress(publicIpAddress);
  updateInfomaniakHostname(publicIpAddress);

  delay(300000);
}
