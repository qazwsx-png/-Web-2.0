#define MQ2pin (1)
#include <SoftwareSerial.h>
float sensorValue;
int piezoPin = 7;
SoftwareSerial mySerial(2, 3); // RX, TX
void setup() {
  Serial.begin(19200);
  Serial.println("Hello");
  mySerial.begin(19200); 
  mySerial.println("AT");
}

void loop() {
if (mySerial.available())
    Serial.write(mySerial.read());
if (Serial.available())
    mySerial.write(Serial.read());
  mq();
}

void mq(){
sensorValue = analogRead(MQ2pin);
Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  if(sensorValue > 300)
  {
    sms(String("Gas detected! ALARM!!!"),String("+79875063597"));
      tone(piezoPin, 1000, 5000);
  }
delay(10000); 
}


void sms(String text, String phone) {
  Serial.println("SMS send started");
  mySerial.println("AT+CMGS=\"" + phone + "\"");
  delay(1000);
  mySerial.print(text);
  delay(300);
  mySerial.print((char)26);
  delay(300);
  Serial.println("SMS send finish");
  delay(3000);
}
