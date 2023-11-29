  #include <EduIntro.h>
  DHT11 dht11(D7);

  int relay = 9;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  dht11.update();
  Serial.print("Humidity (%): ");
  Serial.println(dht11.readHumidity());
  Serial.print("Temperature  (C): ");
  Serial.println(dht11.readCelsius()); 

  int humidityRaw = analogRead(A1);
  int humidityReal = map(humidityRaw, 0, 950, 0, 100);
  Serial.print(humidityReal);
  
  if (humidityReal < 60)
  {
    digitalWrite(relay, HIGH);
  } else{
    digitalWrite(relay, LOW);
  }
  delay(500);
}