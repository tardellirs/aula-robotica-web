/* =====================================================================
   Aula de Robótica — Sketch da ATIVIDADE 1 (LED + LDR)
   ---------------------------------------------------------------------
   Carregue este programa no Arduino UMA vez, no começo da Atividade 1.
   Ele serve para as três partes (o circuito vai crescendo, mas o
   programa é o mesmo).

   O que ele faz:
     1) LÊ o sensor de luz (LDR) no pino A0 e ENVIA pela Serial (USB),
        no formato JSON:   {"ldr":512}
     2) RECEBE comandos para o LED (na protoboard, pino 8):
            '1'  -> acende o LED
            '0'  -> apaga o LED

   Na PARTE 1 só o LED está montado (a página ignora o valor do LDR).
   A partir da PARTE 2 o LDR entra no circuito.

   PINAGEM:
     LED ...... pino 8  (com resistor de 220-330 ohms até o GND)
     LDR ...... A0      (divisor de tensão com resistor de 10k)
   ===================================================================== */

const int PINO_LED = 8;    // LED na protoboard
const int PINO_LDR = A0;   // sensor de luz

void setup() {
  Serial.begin(9600);
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  // 1) Lê o LDR e envia como JSON
  int luz = analogRead(PINO_LDR);
  Serial.print("{\"ldr\":");
  Serial.print(luz);
  Serial.println("}");

  // 2) Recebe comando do LED (lê tudo o que chegou)
  while (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == '1') digitalWrite(PINO_LED, HIGH);
    if (comando == '0') digitalWrite(PINO_LED, LOW);
  }

  delay(100);  // ~10 envios por segundo
}
