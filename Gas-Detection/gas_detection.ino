#define MQ135_PIN A0
#define GREEN_LED 6
#define RED_LED 7
#define BUZZER 8

void setup() {
Serial.begin(9600);
pinMode(GREEN_LED, OUTPUT);
pinMode(RED_LED, OUTPUT);
pinMode(BUZZER, OUTPUT);
}

void loop() {
int gasValue = analogRead(MQ135_PIN);

Serial.print("Gas Level: ");
Serial.println(gasValue);

if (gasValue < 200) {
digitalWrite(GREEN_LED, HIGH);
digitalWrite(RED_LED, LOW);
digitalWrite(BUZZER, LOW);
Serial.println("Air Quality: GOOD");
}
else if (gasValue > 200 && gasValue < 400) {
digitalWrite(GREEN_LED, LOW);
digitalWrite(RED_LED, HIGH);
digitalWrite(BUZZER, LOW);
Serial.println("Air Quality: WARNING");
}
else {
digitalWrite(GREEN_LED, LOW);
digitalWrite(RED_LED, HIGH);
digitalWrite(BUZZER, HIGH);
Serial.println("Air Quality: DANGEROUS!");
}

delay(1000);
}
