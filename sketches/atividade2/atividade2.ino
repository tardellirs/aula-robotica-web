/* =====================================================================
   Aula de Robótica — Sketch da ATIVIDADE 2 (ultrassônico + potenciômetro + LED)
   ---------------------------------------------------------------------
   Carregue este programa no Arduino UMA vez, no começo da Atividade 2.
   Serve para as duas partes.

   O que ele faz:
     1) MEDE a distância com o sensor ultrassônico (HC-SR04) e LÊ o
        potenciômetro, e ENVIA tudo pela Serial em JSON:
            {"dist":23.4,"pot":780}
     2) RECEBE comandos do LED (na protoboard, pino 8):  '1' acende, '0' apaga.

   Na PARTE 1 só o ultrassônico está montado (a página mostra a distância).
   Na PARTE 2 entram o potenciômetro e o LED.

   PINAGEM:
     HC-SR04 TRIG ... pino 9
     HC-SR04 ECHO ... pino 10   (VCC no 5V, GND no GND)
     Potenciômetro .. A1        (meio em A1; pontas em 5V e GND)
     LED ............ pino 8    (com resistor de 220-330 ohms até o GND)
   ===================================================================== */

const int PINO_TRIG = 9;
const int PINO_ECHO = 10;
const int PINO_POT  = A1;
const int PINO_LED  = 8;

void setup() {
  Serial.begin(9600);
  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  pinMode(PINO_LED, OUTPUT);
}

// Mede a distância em centímetros com o HC-SR04
float medirDistancia() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH, 30000);  // espera no máx. 30 ms
  if (duracao == 0) return -1;                      // nada detectado
  return duracao * 0.0343 / 2.0;                    // tempo -> cm (ida e volta)
}

void loop() {
  // 1) Lê os sensores e envia em JSON
  float dist = medirDistancia();
  int pot = analogRead(PINO_POT);
  Serial.print("{\"dist\":");
  Serial.print(dist, 1);
  Serial.print(",\"pot\":");
  Serial.print(pot);
  Serial.println("}");

  // 2) Recebe comando do LED
  while (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == '1') digitalWrite(PINO_LED, HIGH);
    if (comando == '0') digitalWrite(PINO_LED, LOW);
  }

  delay(80);  // atualização rápida (bom para a distância e o piscar)
}
