/* =====================================================================
   Aula de Robótica — Sketch da ATIVIDADE 4 (jogo da cobrinha)
   ---------------------------------------------------------------------
   Controle: TECLADO MATRICIAL 4x4. O Arduino só LÊ a tecla apertada e
   ENVIA pela Serial. O jogo roda no NAVEGADOR (página atividade4.html).

   Mapeamento no jogo:
       2 = cima      8 = baixo     4 = esquerda    6 = direita
       A = novo jogo   B = pausa    C = + devagar   D = + rápido
       (*, #, e os números 1,3,5,7,9,0 ficam livres p/ você inventar)

   >>> PRECISA DA BIBLIOTECA "Keypad" <<<
   Na Arduino IDE: Ferramentas -> Gerenciar Bibliotecas -> procure "Keypad"
   (de Mark Stanley / Alexander Brevig) -> Instalar. (Só uma vez.)

   PINAGEM: os 8 pinos do teclado, da ESQUERDA para a DIREITA, vão nos
   pinos do Arduino 9, 8, 7, 6, 5, 4, 3, 2 (nessa ordem). Sem resistores
   (a biblioteca usa os resistores internos do Arduino).
   ===================================================================== */

#include <Keypad.h>

const byte LINHAS = 4;
const byte COLUNAS = 4;

// O que está escrito em cada tecla do teclado 4x4
char teclas[LINHAS][COLUNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinosLinha[LINHAS]    = {9, 8, 7, 6};   // os 4 primeiros pinos do teclado
byte pinosColuna[COLUNAS]  = {5, 4, 3, 2};   // os 4 últimos pinos do teclado

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinha, pinosColuna, LINHAS, COLUNAS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char t = teclado.getKey();   // devolve a tecla apertada (ou nada)
  if (t) {
    Serial.println(t);         // envia a tecla para o navegador
  }
}
