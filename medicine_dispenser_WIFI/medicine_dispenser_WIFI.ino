#include <Servo.h>
#include <ESP8266WiFi.h>

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

WiFiServer server(80);
Servo servo;
int pos;
int Signal = 8;
int servopin = 9;
char data = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Signal, INPUT);
  pinMode(13, OUTPUT);
  servo.attach(servopin);
  servo.write(0); // close cap on power on
  delay(1000);
  servo.detach();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Start the server
  server.begin();
  Serial.println("Connected to WiFi. Server started.");
}

void loop() {
  int buttonState = digitalRead(Signal);
  delay(1);

  // Check for incoming WiFi connections
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char request = client.read();
        Serial.print(request);

        if (request == '1') {
          digitalWrite(13, HIGH);
        } else if (request == '0') {
          digitalWrite(13, LOW);
        }

        // Send a response back to the client
        client.println("OK");
        break;
      }
    }
    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }

  if (buttonState == 0) {
    servo.attach(servopin);
    delay(1);
    servo.write(90);
    delay(3000);
    servo.write(0);
    delay(1000);
    servo.detach();
  }
}