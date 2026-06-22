# Atividade 2 — Sensor ultrassônico (alarme de distância)

Agora você vai **medir a distância** de um objeto com o sensor ultrassônico e montar um
**alarme**: quando algo chega perto, o LED **pisca**. E o **potenciômetro** vai deixar você
**ajustar** a distância do alarme — como um sensor de ré de carro!

> ⚠️ Lembre: páginas abertas no **Chrome/Edge**; **Monitor Serial fechado** (regra de ouro).

---

## Antes de começar (uma vez)

**Carregue o programa da Atividade 2.** Na Arduino IDE, abra
`sketches/atividade2/atividade2.ino` e clique em **➜ Carregar**. (Serve para as duas partes.)

> 💡 Pode **reaproveitar a protoboard** da Atividade 1 (onde estava o LDR). Aqui o LED é um
> LED **na protoboard** (pino 8) — diferente da Atividade 1, que usava o LED embutido (pino 13).

---

## Parte 1 — Mostrar a distância

### 1.1 Montar o circuito (sensor ultrassônico HC-SR04)

Com o Arduino **desconectado**, ligue os 4 pinos do sensor:

| Pino do HC-SR04 | Vai no Arduino |
|---|---|
| **VCC** | 5V |
| **TRIG** | pino 9 |
| **ECHO** | pino 10 |
| **GND** | GND |

Reconecte a USB.

### 1.2 Usar a página

1. Abra **`atividade2-parte1.html`** (link do professor ou `http://localhost:8000/...`).
2. Clique em **🔌 Conectar ao Arduino** e escolha a porta.
3. Aproxime e afaste a mão na frente do sensor: a **distância em cm** muda na tela.

> 💬 **Como funciona:** o sensor dispara um "pulso" de som e mede quanto tempo ele leva
> para voltar — como um morcego. O Arduino transforma esse tempo em centímetros e envia em
> JSON, ex.: `{"dist":23.4,"pot":780}`. (Se aparecer **-1**, não há nada no alcance.)

> 📸 **Entrega 2.1** — Dois prints: um com o objeto **longe** e outro **perto** do sensor,
> mostrando a distância mudando.

---

## Parte 2 — Alarme ajustável (potenciômetro + LED)

### 2.1 Aumentar o circuito (potenciômetro + LED)

Sem desmontar o sensor, adicione (com o Arduino desconectado):

**Potenciômetro:**

| Pino do potenciômetro | Vai no Arduino |
|---|---|
| ponta de um lado | 5V |
| ponta do outro lado | GND |
| **pino do meio** | A1 |

**LED** na protoboard (com resistor):

```
  pino 8 ──[ resistor 220–330 Ω ]──►|──── GND
                                    LED
```

Reconecte a USB.

### 2.2 Usar a página

1. Abra **`atividade2-parte2.html`** e clique em **Conectar**.
2. Há dois cartões: a **distância** (azul) e o **limite de alerta** (verde).
3. **Gire o potenciômetro**: o valor do cartão verde muda (de 2 a 50 cm).
4. Aproxime um objeto. Quando ele fica **mais perto que o limite**, o **LED pisca** e a
   tela mostra **🔴 ALERTA**.

> 💬 **Como funciona:** a página transforma o potenciômetro (0 a 1023) em uma distância, e
> compara com a medida do sensor. Se estiver mais perto, ela manda o LED piscar (alternando
> `1` e `0` a cada 200 ms).

> 📸 **Entrega 2.2** — Foto/print mostrando o **LED piscando** (ou a tela em 🔴 ALERTA) com
> um objeto perto, e o cartão verde com o **limite** que você escolheu no potenciômetro.

> 🔧 **Mudança exata (faça e observe):** no arquivo `atividade2-parte2.html`, ache a linha
> `}, 200);` (perto do fim) e troque **200** por **100**. Salve e atualize a página: o LED
> passa a piscar **duas vezes mais rápido**. (200 e 100 são milissegundos entre as piscadas.)

### 2.3 Fechamento

> ✍️ **Entrega 2.3** — Responda com suas palavras:
> 1. O Arduino **não tem Wi-Fi**. Então **como** os dados dele (a distância) chegaram até a
>    página?
> 2. Por que a página precisa do **navegador (Chrome/Edge)** para falar com o Arduino — por
>    que o Arduino sozinho não mostra a página?
> 3. Cite **uma ideia** de projeto que dá para fazer com sensor de distância + LED.

---

## ✅ Checklist da Atividade 2

- [ ] Carreguei o `atividade2.ino` no Arduino
- [ ] Parte 1: montei o ultrassônico e vi a distância na página
- [ ] Parte 2: montei o potenciômetro e o LED
- [ ] O potenciômetro muda o **limite** de alerta
- [ ] O LED **pisca** quando o objeto fica perto
- [ ] Fiz a mudança de 200 → 100 e vi o LED piscar mais rápido

🎉 **Parabéns!** Você criou um alarme de aproximação controlado pela web — robótica e
Internet das Coisas (IoT) na prática.
