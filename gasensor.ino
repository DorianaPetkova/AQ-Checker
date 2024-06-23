#include <Wire.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define GAS_SENSOR_PIN 34  //use whichever pin you want, just remember what you've set it to

float t = 0;
String apiKey = "ZEAKJ2XCEX18MVFN";  

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("AQ Checker");
  delay(3000); // Add delay for readability
  lcd.clear();
  
  pinMode(GAS_SENSOR_PIN, INPUT);
  Serial.begin(115200);  

  Serial.println("Connecting to WiFi...");
  WiFi.begin("103", "tK<VN5cqR9"); 

  lcd.setCursor(0, 0);
  lcd.print("Connecting to");
  lcd.setCursor(0, 1);
  lcd.print("WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    lcd.setCursor(0, 0);
    lcd.print("Connecting to");
    lcd.setCursor(0, 1);
    lcd.print("WiFi...");
  }

  Serial.println("Connected to WiFi");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connected to");
  lcd.setCursor(0, 1);
  lcd.print("WiFi");
  delay(3000); // Add delay for readability
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Processing :");
}

void loop() {
  t = analogRead(GAS_SENSOR_PIN);  // Read sensor value and store in t

  Serial.print("Air quality = ");
  Serial.println(t);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality:");
  lcd.setCursor(0, 1);
  lcd.print(t);
  delay(3000); // Add delay for readability

  esp_8266();

  // ThingSpeak needs 16 seconds delay between updates
  delay(16000);
}

void esp_8266() {
  WiFiClient client;

  if (!client.connect("184.106.153.149", 80)) {
    Serial.println("Connection to ThingSpeak failed");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connection to");
    lcd.setCursor(0, 1);
    lcd.print("ThingSpeak Failed");
    delay(3000); // Add delay for readability
    return;
  }

  String url = "/update?api_key=";
  url += apiKey;
  url += "&field1=";
  url += String(t);

  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.thingspeak.com\r\n" +
               "Connection: close\r\n\r\n");

  delay(1000); // Wait for the request to complete

  Serial.println("Data sent to ThingSpeak");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Data sent to");
  lcd.setCursor(0, 1);
  lcd.print("ThingSpeak");
  delay(3000); // Add delay for readability
}
