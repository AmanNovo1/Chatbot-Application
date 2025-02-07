#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESPAsyncWiFiManager.h>
#include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>

#include <FS.h>
#include <LittleFS.h>

AsyncWebServer server(100);
DNSServer dns;

// Replace with your network credentials
const char *ssid = "D-LUFFY";
const char *password = "123456789";

void setup()
{

  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) // If WiFi connected to hot spot then start mDNS
  {
    if (MDNS.begin("gemserver"))
    { // Start mDNS with name esp8266
      Serial.println("MDNS started");
    }
  }

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });

  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/style.css", "text/css"); });
  server.begin();
}

void loop()
{

  // put your main code here, to run repeatedly:
}