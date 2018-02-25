#include "ESP8266WiFi.h"

#define led_pin D0

const char* ssid = "Virgin Wi-Fi true";         // Название  WiFi сети
const char* password = "181181181181";          // Пароль WiFi сети

const char *server = "192.168.1.193";
const int port = 9090;

char msg[2000];

WiFiClient client;

void radnomize(){
  for(int i=0; i<2000; i++)
    msg[i] = rand();  
}

void blink_led(){
  digitalWrite(led_pin, LOW);
  delay(200);
  digitalWrite(led_pin, HIGH);
  }

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    blink_led();
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void connect(){
  
  if (!client.connect(server, port)) {
    Serial.println("connection failed");
    return;
  }
}

void setup() {
  
  Serial.begin(115200);
  
  pinMode(led_pin, OUTPUT);

  setup_wifi();
  digitalWrite(led_pin, LOW);
  
  radnomize();
  
  connect();
  client.setNoDelay(true);
}

void loop() {
  client.print(msg);
  
 // delay(1000);
}

