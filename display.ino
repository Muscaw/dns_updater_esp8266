#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32

#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

void setupScreen() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
}

void displayPublicIpAddress(String publicIpAddress) {
  display.fillRect(0, 8, OLED_WIDTH, 8, BLACK);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.print("IP: ");
  display.println(publicIpAddress);

  display.display();
}

void displayWifiStatus(bool connected) {
  display.fillRect(0, 0, OLED_WIDTH, 8, BLACK);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("WiFi: ");
  display.println(connected ? "Ok" : "Connecting");

  display.display();
}

void displayCurrentInfomaniakAddress(String currentIpAddress) {
  display.fillRect(0, 16, OLED_WIDTH, 16, BLACK);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 16);
  display.println("InfoManiak IP: ");
  display.println(currentIpAddress);

  display.display();
}