#ifndef network_h
#define network_h
String fetchCurrentIpAddress();
void updateInfomaniakHostname(String ipAddress);
void connectToWifi();
bool isWifiConnected();
#endif