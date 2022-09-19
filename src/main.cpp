#include <Arduino.h>

#define PIN_LED_VERDE 4
#define PIN_LED_AMARELO 7 
#define PIN_LED_VERMELHO 8

long tempoAnterior = 0;

void setup() {
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_AMARELO, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
}

void loop() {

  long tempoRecente = millis();
  long variacaoTempo = tempoRecente - tempoAnterior;

  int tempoLedVerde = 1000;
  int tempoLedAmarelo = 3000;
  int tempoLedVermelho = 5000;

  if(variacaoTempo == tempoLedVerde) {
    digitalWrite(PIN_LED_VERMELHO, LOW);
    digitalWrite(PIN_LED_VERDE, HIGH);
  }
  
  if(variacaoTempo == tempoLedAmarelo) {
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_AMARELO, HIGH);
  }
  
  if(variacaoTempo == tempoLedVermelho) {
    digitalWrite(PIN_LED_AMARELO, LOW);
    digitalWrite(PIN_LED_VERMELHO, HIGH);
    tempoAnterior = tempoRecente;
  }

}