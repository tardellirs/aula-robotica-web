# Atividade 4 — Jogo da Cobrinha (controle pelo teclado 4×4)

A atividade final junta tudo: um **controle físico** (teclado matricial 4×4) que comanda um
**jogo da cobrinha** rodando no navegador. Você aperta as teclas, o Arduino manda pela USB, e
a cobrinha obedece. 🐍

> ⚠️ Página no **Chrome/Edge**; **Monitor Serial fechado** (regra de ouro).

---

## Antes de começar (uma vez)

**1. Instalar a biblioteca Keypad.** Na Arduino IDE: **Ferramentas → Gerenciar Bibliotecas**,
procure **"Keypad"** (de *Mark Stanley / Alexander Brevig*) e clique em **Instalar**. (Só uma vez.)

**2. Carregar o programa.** Abra `sketches/atividade4/atividade4.ino` e clique em **➜ Carregar**.

> 💬 **Como funciona:** o Arduino só **lê a tecla** apertada e a **envia** pela Serial. Todo o
> jogo (a cobrinha, a comida, os pontos) está no **navegador**. O controle é o teclado.

---

## Parte 1 — Montar o teclado 4×4

O teclado tem **8 pinos** numa fileira. Ligue-os, **da esquerda para a direita**, nos pinos do
Arduino **9, 8, 7, 6, 5, 4, 3, 2** (em sequência) — com o Arduino **desconectado**:

| Pino do teclado (da esquerda) | Arduino |
|---|---|
| 1º | 9 |
| 2º | 8 |
| 3º | 7 |
| 4º | 6 |
| 5º | 5 |
| 6º | 4 |
| 7º | 3 |
| 8º (último) | 2 |

> 💡 **Sem resistores!** A biblioteca Keypad usa os resistores internos do Arduino.
> O esquema também está **dentro da página** (no rodapé, "🔌 Como montar...").

Reconecte a USB.

### Teste rápido

Abra `atividade4.html`, clique em **🔌 Conectar** e escolha a porta. Depois aperte teclas no
teclado 4×4 e veja: **2** move para cima, **8** baixo, **4** esquerda, **6** direita.

> 📸 **Entrega 4.1** — Foto do **teclado montado** + print do jogo na tela (com a cobrinha).
> Mostre que as teclas **2/4/6/8** movem a cobrinha.

---

## Parte 2 — Jogar

| Tecla | Função |
|---|---|
| **2 / 8 / 4 / 6** | cima / baixo / esquerda / direita |
| **A** | novo jogo (ou recomeçar depois do "Fim") |
| **B** | pausar / continuar |
| **C** | deixar mais devagar |
| **D** | deixar mais rápido |

Aperte **A** para começar. Coma os quadradinhos vermelhos para crescer e fazer pontos. O jogo
acaba se a cobrinha bater na **parede** ou **nela mesma**.

> 💡 Sem o Arduino, dá para jogar pelas **setas** do teclado do PC (espaço = pausa, Enter = novo).
> Assim você testa o jogo antes de montar o circuito.

> 📸 **Entrega 4.2** — Print da tela de **"Fim!"** mostrando a sua **maior pontuação**.

> ✍️ **Entrega 4.3** — Explique o **caminho de uma tecla** até a cobrinha virar: o que faz o
> teclado, o Arduino, a Serial (USB) e o navegador. E responda: por que a cobrinha **não
> consegue dar meia-volta** de uma vez? (Dica: veja a função `setDir` no código.)

> 🏆 **Desafio extra:** as teclas **`*`** e **`#`** estão livres. Que função você daria a elas?
> (Ex.: `#` reinicia os pontos, `*` muda a cor.) Descreva a sua ideia.

---

## ✅ Checklist da Atividade 4

- [ ] Instalei a biblioteca **Keypad** e carreguei o `atividade4.ino`
- [ ] Montei o teclado 4×4 (8 pinos nos pinos 9 a 2)
- [ ] Conectei e as teclas **2/4/6/8** movem a cobrinha
- [ ] Joguei, comi a comida e fiz pontos
- [ ] Usei **A** (novo), **B** (pausa), **C/D** (velocidade)
- [ ] Entendi o caminho: teclado → Arduino → Serial → navegador → jogo

🎉 **Parabéns!** Você construiu um **controle de videogame** de verdade e ligou o mundo físico
ao software — exatamente o que a robótica e a computação física fazem.
