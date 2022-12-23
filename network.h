#ifndef network_h
#define network_h
String fetchCurrentIpAddress();
void updateInfomaniakHostname(String ipAddress);
void connectToWifi();
bool isWifiConnected();
String getCurrentAssignedIpAddress(String hostname);
#endif