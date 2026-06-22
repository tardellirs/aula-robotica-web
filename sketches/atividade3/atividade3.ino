/* =====================================================================
   Aula de Robótica — Sketch da ATIVIDADE 3 (5 LEDs em sequência)
   ---------------------------------------------------------------------
   Carregue este programa no Arduino no começo da Atividade 3.

   O que ele faz: RECEBE pela Serial uma linha com 5 dígitos (0 ou 1),
   um para cada LED, e acende/apaga os 5 de uma vez.

       Exemplos (digite no Monitor Serial e tecle Enter):
         11111  -> acende TODOS os 5 LEDs
         00000  -> apaga todos
         10100  -> acende o LED 1 e o LED 3

   Quem monta a "sequência" e faz o LOOP é a PÁGINA WEB: ela manda uma
   linha dessas a cada passo. O Arduino só obedece.

   PINAGEM (5 LEDs na protoboard, cada um com resistor de 220-330 ohms):
       LED 1 -> pino 2      LED 4 -> pino 5
       LED 2 -> pino 3      LED 5 -> pino 6
       LED 3 -> pino 4
   ===================================================================== */

const int leds[] = {2, 3, 4, 5, 6};   // os 5 LEDs, na ordem
const int N = 5;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < N; i++) pinMode(leds[i], OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String s = Serial.readStringUntil('\n');   // lê a linha, ex.: "10110"
    for (int i = 0; i < N; i++) {
      char c = (i < s.length()) ? s[i] : '0';  // dígito i (ou '0' se faltar)
      digitalWrite(leds[i], c == '1' ? HIGH : LOW);
    }
  }
}
