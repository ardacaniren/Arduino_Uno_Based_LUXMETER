#include <LiquidCrystal.h> //Burada LCD ekranımızın kütüphanesini sisteme yükledik.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorValue = 0; // LDR sensöründen okunan değeri saklamak için değişken tanımladık.
int led = 7; //LED’in bağlı olduğu pini tanımladık.
void setup() {
  pinMode(led, OUTPUT); //LED’in pinini çıkış olarak ayrladık.
  pinMode(A0, INPUT); // LDR’nin bağlı olduğu pini giriş olarak ayarladık.
  Serial.begin(9600);
  lcd.begin(16, 2); //LCD ekranı başlattık.
  lcd.setCursor(0, 0);
  lcd.print("");
}
void loop() {
  lcd.setCursor(0, 1);
  lcd.print("ISIK: "); //LCD ekranda alt kısıma “ISIK” yazdırdık
  sensorValue = analogRead(A0); //LDR sensörünün analog değerinin okunmasını sağladık.
  Serial.println(sensorValue);
  float luminance = calculateLuminance(sensorValue); // LDR değerini lümen cinsinden hesapladık
  lcd.setCursor(6, 1);
lcd.print(luminance);
  lcd.print(" lx   "); //Ekranda lümen değerinin sayısal değerinden sonra lx yazdırdık.
  delay(100);
   if (sensorValue < 750) { //LDR’nin değeri 750’den küçükse ortamın karanlık olduğunu ve LED’in yanması gerektiğini tanımladık.
    lcd.setCursor(0, 0);
    lcd.print("LED ON     ");
    digitalWrite(led, HIGH);
    delay(100);
  } else { //Tersi durumda yani LDR’nin değerinin 750’den büyük olduğu durumlarda LED’in kapanması gerekitğini tanımladık.
    lcd.setCursor(0, 0);
    lcd.print("LED OFF    ");
    digitalWrite(led, LOW);
    delay(100);
  }
}
float calculateLuminance(int sensorValue) {
  float luminance = map(sensorValue, 0, 1023, 0, 1000); // 
  return luminance;
}
