// C++ code - Sensor de gás - Monitoração e Alarme
// Lucio Ferreira de Cerqueira
//
const int pinSensor = A0;    // Pino de entrada do sensor de gás
const int pinLedVerde = 12;  // Pino do LED verde
const int pinLedAmarelo = 11; // Pino do LED amarelo
const int pinLedVermelho = 10; // Pino do LED vermelho
const int pinBuzzer = 13;      // Pino do buzzer

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAmarelo, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorSensor = analogRead(pinSensor);

  // Impressão do valor do sensor para monitoramento no Serial Monitor
  Serial.print("Valor do Sensor: ");
  Serial.println(valorSensor);

  // Verifica o intervalo do valor do sensor e realiza as ações correspondentes
  if (valorSensor < 940) {
    // Baixa concentração de gás: Liga LED verde, desliga os demais
    digitalWrite(pinLedVerde, HIGH);
    digitalWrite(pinLedAmarelo, LOW);
    digitalWrite(pinLedVermelho, LOW);
    digitalWrite(pinBuzzer, LOW);
  } else if (valorSensor >= 940 && valorSensor < 980) {
    // Concentração de gás mediana: Liga LED amarelo, desliga os demais
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAmarelo, HIGH);
    digitalWrite(pinLedVermelho, LOW);
    digitalWrite(pinBuzzer, LOW);
  } else {
    // Perigo: Liga LED vermelho e buzzer, desliga os demais
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAmarelo, LOW);
    digitalWrite(pinLedVermelho, HIGH);
    digitalWrite(pinBuzzer, HIGH);
  }

  delay(1000); // Delay para evitar leituras muito frequentes
}
