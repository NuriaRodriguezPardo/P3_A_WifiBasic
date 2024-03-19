#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void handle_root();

// SSID & Password
const char* ssid = "RedmiNuria"; // Enter your SSID here
const char* password = "Patata123"; //Enter your Password here

WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)

void setup(){
    Serial.begin(115200);
    Serial.println("Conectando a la red WiFi...");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conexión WiFi establecida");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());

    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100);
}

void loop() {
    server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";
// Handle root url (/)

void handle_root() {
    server.send(200, "text/html", HTML);
}