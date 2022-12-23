#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "secrets.h"
const char* ssid     = STASSID;
const char* password = STAPSK;

const char* ipify_host = "https://api.ipify.org";
const String infomaniak_host = "https://infomaniak.com/nic/update";
const uint16_t https_port = 443;

String fetchCurrentIpAddress() {
  WiFiClientSecure client;
  client.setInsecure();
  client.connect(ipify_host, https_port);
  HTTPClient http;
  
  http.begin(client, ipify_host);

  int httpResponseCode = http.GET();
  String payload = "";
  if(httpResponseCode>0) {
    Serial.print("Host queried ");
    Serial.println(ipify_host);
    Serial.print("HTTP response code ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  return payload;
}

void updateInfomaniakHostname(String ipAddress) {
  String url_str = infomaniak_host + "?hostname=" + String(INFOMANIAK_HOSTNAME) + "&myip=" + ipAddress;
  const char * url = url_str.c_str();
  WiFiClientSecure client;
  client.setInsecure();
  client.connect(url, https_port);
  HTTPClient http;
  
  http.begin(client, url);
  http.setAuthorization(INFOMANIAK_USERNAME, INFOMANIAK_PASSWORD);

  int httpResponseCode = http.GET();
  if(httpResponseCode>0) {
    Serial.print("Host queried ");
    Serial.println(url);
    Serial.print("HTTP response code ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void connectToWifi() {

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
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

bool isWifiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

String getCurrentAssignedIpAddress(String hostname) {
  IPAddress address;
  WiFi.hostByName(hostname.c_str(), address);
  return address.toString();
}