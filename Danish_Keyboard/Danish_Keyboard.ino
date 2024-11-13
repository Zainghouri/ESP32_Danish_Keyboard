
//WARNING: This sketch should be used when USB is in OTG mode
#include <Arduino.h>
#include <USB.h>
#include "USBHIDKeyboard.h"
#include <WiFi.h>


const char *ssid = "ESP32-Access-Point";
const char *password = "12345";

const uint8_t KEY_NUM_0 = 0xEA;
const uint8_t KEY_NUM_1 = 0xE1;
const uint8_t KEY_NUM_2 = 0xE2;
const uint8_t KEY_NUM_3 = 0xE3;
const uint8_t KEY_NUM_4 = 0xE4;
const uint8_t KEY_NUM_5 = 0xE5;
const uint8_t KEY_NUM_6 = 0xE6;
const uint8_t KEY_NUM_7 = 0xE7;
const uint8_t KEY_NUM_8 = 0xE8;
const uint8_t KEY_NUM_9 = 0xE9;

WiFiServer server(80);
USBHIDKeyboard Keyboard;


void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  Serial.print("Starting AP...");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.println("IP address: ");
  Serial.println("WiFi connected.");
  
  server.begin();
  delay(100);
  Keyboard.begin();
  USB.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.print("New Client.");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        // Handle Danish characters
        switch (c) {
          case 0x9: // : TAB
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_0);
            delay(5);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x22: // : Quotation mark
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x23: // # Hash
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x24: // $ Dollar
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x25: // %
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_7);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x26: // & And
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_8);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x27: // ' Apostrophe
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x28: // ( Open bracket
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_0);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x29: // ) Close bracket
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2A: // * Asterix
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_2);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2B: // + Plus
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2C: // , Comma
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2D: // - Dash
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2E: // . Full Stop
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x2F: // / Slash
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_7);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xC5: // Å
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xC6: // Æ
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xE5: // å
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xD8: // Ø
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.write(KEY_NUM_7);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xF8: // ø
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xE6: // æ
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3A: // : colon
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.write(KEY_NUM_8);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3B: // ; semicolon
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3C: // < Less than
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.write(KEY_NUM_0);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3D: // = Equal sign
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3E: // > Greater than
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.write(KEY_NUM_2);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x3F: // ? Question mark
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.write(KEY_NUM_3);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x5C: // \ Backslash
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.write(KEY_NUM_2);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x5E: // ^ Caret
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.write(KEY_NUM_4);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x5F: // _ Underscore
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0x60: // ` Grave accent
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_9);
            delay(5);
            Keyboard.write(KEY_NUM_6);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          case 0xAF: // Right-pointed double angle quation mark
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write(KEY_NUM_1);
            delay(5);
            Keyboard.write(KEY_NUM_7);
            delay(5);
            Keyboard.write(KEY_NUM_5);
            delay(5);
            Keyboard.release(KEY_LEFT_ALT);
            Keyboard.releaseAll();
            break;
          default:
            Keyboard.write(c);
            break;
        }

        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.print("HTTP/1.1 200 OK\r\n");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
    Serial.print("Client Disconnected.");
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
  }
}

