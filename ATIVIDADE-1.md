# Atividade 1 — LED e sensor de luz (LDR)

Nesta atividade você vai **acender um LED pela página web** e, depois, **ler um sensor de
luz** e fazer o LED ligar sozinho no escuro — tudo pelo navegador, sem programar o Arduino
(o programa dele já está pronto).

> 💡 **Como funciona:** o Arduino fala com o computador pelo **cabo USB**. A página, aberta
> no **Chrome** ou **Edge**, conversa direto com o Arduino usando uma tecnologia chamada
> **Web Serial**. Não precisa instalar nada no computador.

> ⚠️ **Web Serial só funciona no Google Chrome ou no Microsoft Edge** (no computador). Não
> funciona no Firefox, no Safari, nem no celular.

---

## Antes de começar (uma vez)

**1. Carregar o programa no Arduino.** Na Arduino IDE, abra
`sketches/atividade1/atividade1.ino`, escolha **Placa: Arduino Uno** e a **Porta**, e clique
em **➜ Carregar**. (Esse mesmo programa serve para as 3 partes.)

**2. Saber abrir a página.** A página é um arquivo que abrimos no Chrome/Edge. Seu professor
vai indicar **um** destes caminhos:

- **Pela internet (mais fácil):** abra o link que o professor passar, por exemplo
  `https://tardellirs.github.io/aula-robotica-web/web/atividade1-parte1.html`
- **No próprio computador:** dentro da pasta `web`, rode `python3 -m http.server 8000` e abra
  `http://localhost:8000/atividade1-parte1.html`.

> ⚠️ **Regra de ouro:** só **um** programa por vez pode usar a porta do Arduino. Se o
> **Monitor Serial** da Arduino IDE estiver aberto, **feche-o** antes de usar a página
> (senão a página não conecta).

---

## Parte 1 — Ligar e desligar o LED pela página

### 1.1 Montar o circuito (só o LED)

Monte com o Arduino **desconectado** da USB:

```
  pino 8 ──[ resistor 220–330 Ω ]──►|──── GND
                                    LED
```

- A perna **maior** do LED é o **+** → fica do lado do resistor (que vai ao **pino 8**).
- A perna **menor** é o **−** → vai no **GND**.

> ⚠️ **Sempre com resistor!** Sem ele o LED queima.

Conecte o Arduino na USB de novo.

### 1.2 Usar a página

1. Abra a página **`atividade1-parte1.html`** (no Chrome/Edge).
2. Clique em **🔌 Conectar ao Arduino** e escolha a porta na janelinha.
3. Clique no botão grande do LED: ele **liga** e **desliga** o LED na protoboard.

> 💬 O botão chama `enviarComando("1")` para acender e `enviarComando("0")` para apagar.
> Esse `1`/`0` viaja pela USB até o Arduino, que liga/desliga o pino 8.

> 📸 **Entrega 1.1** — Uma **foto do LED aceso** na protoboard (com a página no fundo,
> mostrando o botão verde "LED ligado").

---

## Parte 2 — Mostrar o valor do sensor de luz (LDR)

### 2.1 Aumentar o circuito (adicionar o LDR)

Sem desmontar o LED, adicione o **LDR** (com o Arduino desconectado):

```
  5V ──[ LDR ]──●────────── A0
                │
             [ 10 kΩ ]
                │
               GND
```

- Uma perna do LDR no **5V**; a outra perna no **A0** **e** no resistor de **10 kΩ**.
- A outra ponta do resistor no **GND**.

Reconecte a USB.

### 2.2 Usar a página

1. Abra **`atividade1-parte2.html`** e clique em **Conectar**.
2. Aparece o **valor do LDR** (de 0 a 1023) e uma **barra** que enche conforme a luz.
3. **Tape o LDR** com a mão: o número e a barra **caem**. Aponte uma **lanterna**: **sobem**.

> 💬 Agora a página lê os dados que o Arduino envia. Cada linha é um **JSON** como
> `{"ldr":512}`. O JavaScript faz `JSON.parse` e mostra o número na tela.

> 📸 **Entrega 1.2** — Dois prints da página: um com o sensor **na luz** (valor alto) e
> outro **tapado** (valor baixo).

---

## Parte 3 — Luz automática (acende no escuro) com calibração

Sem mudar o circuito, vamos fazer o LED **acender sozinho** quando escurece — como os
postes de rua. E você vai **calibrar** o ponto de corte.

### 3.1 Usar a página

1. Abra **`atividade1-parte3.html`** e clique em **Conectar**.
2. Tape o sensor: o LED **acende**. Ilumine: o LED **apaga**. O texto mostra
   **ESCURO/CLARO**.
3. Use o **controle deslizante (calibração)** para escolher o ponto em que o LED liga.

> 💬 **Como funciona (só para entender):** a página compara o valor do LDR com o
> **limiar** do slider:
> ```javascript
> const deveAcender = dados.ldr <= limiar;   // escuro -> acende
> ```
> e só envia o comando **quando o estado muda** (para não inundar a porta).

### 3.2 Calibrar

Arraste o controle até achar o valor em que:
- com a **luz da sala**, o LED fica **apagado**;
- ao **tapar** o sensor (ou diminuir a luz), o LED **acende**.

> ✍️📸 **Entrega 1.3** — Print da página com o LED **aceso ao tapar o sensor** (texto
> "ESCURO"). Responda: **qual valor de calibração** (limiar) ficou bom na sua bancada e
> **por quê** você escolheu esse?

> 🔧 **Quer testar uma mudança exata?** Para o LED acender só em escuridão **bem maior**,
> arraste o slider para um valor **mais baixo** (ex.: 150). Para acender com pouca sombra,
> use um valor **mais alto** (ex.: 700). É só arrastar — nada de mexer no código.

---

## ✅ Checklist da Atividade 1

- [ ] Carreguei o `atividade1.ino` no Arduino
- [ ] Parte 1: montei o LED e liguei/desliguei pela página
- [ ] Parte 2: montei o LDR e vi o valor mudando na página
- [ ] Parte 3: o LED acende no escuro e apaga no claro
- [ ] Calibrei o limiar com o controle deslizante

Quando terminar, chame o professor e vá para a **Atividade 2**! 📏
