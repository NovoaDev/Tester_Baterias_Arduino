#include <LiquidCrystal.h>

#define ANALOGICA_BATERIA 0
#define DIGITAL_LEDVERDE 4
#define DIGITAL_LEDAMARILLO 3
#define DIGITAL_LEDROJO 2

int iValorAnalogoBateria = 0;
float fVoltaje = 0;
int iDelaCiclo = 2000;

//Valores de rangos de las luces en voltios 
float fValorParaLedVerde = 1.5;
float fValorParaLedAmarillo = 1.2;
float fValorParaLedRojo = 0.4;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);

  pinMode(DIGITAL_LEDVERDE, OUTPUT);
  pinMode(DIGITAL_LEDAMARILLO, OUTPUT);
  pinMode(DIGITAL_LEDROJO, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Battery Tester");
  lcd.setCursor(0, 1);
  lcd.print("By: Lola");
  delay(iDelaCiclo);
}

void loop() {
  delay(iDelaCiclo);
  iValorAnalogoBateria = analogRead(ANALOGICA_BATERIA);

  // Obtenemos el voltaje a partir del valor analogico.
  fVoltaje = 0.0048 * iValorAnalogoBateria;

  lcd.clear(); 

  if(iValorAnalogoBateria > 10){
    lcd.setCursor(0, 0);
    lcd.print("Voltaje : "+String(fVoltaje));
    lcd.setCursor(0, 1);
    lcd.print("V.Analog: "+String(iValorAnalogoBateria));
    
    if (fVoltaje >= fValorParaLedVerde){
      digitalWrite(DIGITAL_LEDVERDE, HIGH);
    }
    else if (fVoltaje < fValorParaLedVerde && fVoltaje > fValorParaLedAmarillo){
      digitalWrite(DIGITAL_LEDAMARILLO, HIGH);
    }
    else if (fVoltaje < fValorParaLedAmarillo && fVoltaje > fValorParaLedRojo){
      digitalWrite(DIGITAL_LEDROJO, HIGH);
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Battery Tester");
    lcd.setCursor(0, 1);
    lcd.print("Waiting...");
    digitalWrite(DIGITAL_LEDVERDE, LOW);
    digitalWrite(DIGITAL_LEDAMARILLO, LOW);
    digitalWrite(DIGITAL_LEDROJO, LOW);
  }
}
