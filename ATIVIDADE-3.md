# Atividade 3 — Sequência de LEDs (em loop)

Nesta atividade você monta **5 LEDs** e cria, pela página, a **sequência** em que eles
acendem. A página roda essa sequência **em loop** — quando chega no fim, volta ao início,
sem parar. É assim que se fazem efeitos de luz (letreiros, "sobe e desce", pisca-pisca)!

> ⚠️ Páginas no **Chrome/Edge**; **Monitor Serial fechado** (regra de ouro).

---

## Antes de começar (uma vez)

**Carregue o programa.** Na Arduino IDE, abra `sketches/atividade3/atividade3.ino` e clique
em **➜ Carregar**.

> 💬 **Como funciona:** quem guarda a sequência e faz o loop é a **página**. A cada passo,
> ela manda ao Arduino um "mapa" de 5 dígitos (ex.: `10110` = LED 1 e 3 e 4 acesos). O
> Arduino só acende/apaga os 5 LEDs conforme o mapa.

---

## Parte 1 — Montar os 5 LEDs

Com o Arduino **desconectado**, monte 5 LEDs, **cada um com seu resistor**:

| LED | Pino | | LED | Pino |
|---|---|---|---|---|
| LED 1 | 2 | | LED 4 | 5 |
| LED 2 | 3 | | LED 5 | 6 |
| LED 3 | 4 | | | |

```
  pino (2…6) ──[ resistor 220–330 Ω ]──►|──── GND
                                        LED
```

- Perna **maior** (+) no lado do resistor (no pino); perna **menor** (−) no **GND**.
- Os 5 LEDs podem dividir o **mesmo GND** (use a linha azul/preta da protoboard).

> 💡 Esse mesmo esquema está **dentro da página** (no rodapé, em "🔌 Como montar o circuito").

Reconecte a USB.

### Teste rápido

Abra a página **`atividade3.html`**, clique em **🔌 Conectar** e escolha a porta. Depois
clique no preset **Pisca tudo** e em **▶ Iniciar loop**: os 5 LEDs devem piscar todos juntos.

> 📸 **Entrega 3.1** — Foto dos **5 LEDs acesos** ao mesmo tempo (preset "Pisca tudo" rodando),
> com a página no fundo.

---

## Parte 2 — Criar a sua sequência

Na página, cada **linha** é um **passo**, e os números **1 a 5** são os LEDs. Clique nos
números para escolher quais LEDs acendem em cada passo.

1. Clique em **Limpar** para começar do zero (ou use um preset como ponto de partida).
2. Monte um padrão: por exemplo, no Passo 1 acenda o LED 1; no Passo 2, o LED 2; e assim por
   diante (isso é a "escadinha").
3. Use **+ Passo** / **– Passo** para deixar a sequência mais longa ou mais curta.
4. Clique em **▶ Iniciar loop**. A barra azul mostra o passo atual descendo e **voltando ao
   início**. Ajuste a **Velocidade** (ms por passo) no controle deslizante.
5. Para parar, **⏹ Parar** (apaga todos os LEDs).

> 💬 **O loop** está nesta linha do código (no `atividade3.html`):
> ```javascript
> idx = (idx + 1) % seq.length;   // anda um passo; ao passar do último, volta ao 0
> ```
> O `% seq.length` (resto da divisão) é o truque que faz a contagem **dar a volta**.

> 📸 **Entrega 3.2** — Print da **sua sequência** (a grade montada) **+** uma foto dos LEDs
> durante o loop. ✍️ Descreva com palavras o efeito que você criou (ex.: "vai e volta").

> ✍️ **Entrega 3.3** — Responda: (a) o que acontece quando o loop chega no **último passo**?
> (b) O que muda ao **diminuir** o número da velocidade (ms por passo)?

> 🏆 **Desafio extra:** recrie o efeito **"pingue-pongue"** na mão (1→2→3→4→5→4→3→2 e repete),
> sem usar o preset. Quantos passos você precisou?

---

## ✅ Checklist da Atividade 3

- [ ] Carreguei o `atividade3.ino` no Arduino
- [ ] Montei os 5 LEDs (pinos 2 a 6), cada um com resistor
- [ ] Testei com "Pisca tudo" — os 5 acendem
- [ ] Criei a **minha** sequência clicando nos passos
- [ ] Rodei em **loop** e ajustei a **velocidade**
- [ ] Entendi que o `% seq.length` faz a sequência **voltar ao início**

🎉 **Parabéns!** Você programou um efeito de luz em loop — a base de letreiros, painéis de
LED e pisca-piscas de verdade.
