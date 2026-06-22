# Plano da Aula — Robótica com Arduino e Web (Web Serial)

Guia do **professor**. Os alunos recebem `ATIVIDADE-1.md`, `ATIVIDADE-2.md` e a
`FOLHA-DE-ENTREGA`.

## Objetivo

Conectar o mundo físico (LED, LDR, ultrassônico, potenciômetro) a uma **página web**,
usando um **Arduino sem Wi-Fi** ligado por **USB**. A página, aberta no **Chrome/Edge**,
fala direto com o Arduino pela tecnologia **Web Serial** — então **os alunos não instalam
nada** (sem Python, sem `pip`, sem Flask).

- **Atividade 1 (LED + LDR):** botão liga/desliga o LED → ler o LDR → luz automática com
  calibração.
- **Atividade 2 (ultrassônico):** mostrar a distância → potenciômetro ajusta a distância em
  que o LED pisca (alarme de aproximação).
- **Atividade 3 (5 LEDs):** montar uma **sequência** que roda em **loop**, com velocidade
  ajustável (efeito de letreiro / pisca-pisca).

> A montagem do circuito é a **primeira etapa de cada parte** e vai crescendo ao longo da
> atividade.

## Arquitetura (e por que GitHub Pages funciona com a turma toda)

```
GitHub Pages ──https──► Navegador do aluno (Chrome/Edge) ──Web Serial/USB──► Arduino do aluno
 (só entrega o .html)         (roda no PC do aluno)            (100% local)
```

O GitHub Pages **só serve o arquivo** da página (estático). **Não conecta** em PC nenhum: a
conversa com o Arduino é feita pelo **navegador de cada aluno**, localmente, pela USB. Por
isso:

- **30 alunos ao mesmo tempo = sem problema.** Servir um arquivo estático para muita gente é
  trivial; não há estado por usuário no servidor.
- **Os dados do Arduino não vão para a internet.** Só o download da página usa a rede (uns
  KB). Depois de carregada, **funciona até offline**.

> Alternativa 100% local (offline): em cada PC, dentro da pasta `web`, rodar
> `python3 -m http.server 8000` (só usa a biblioteca padrão do Python — **sem pip**) e abrir
> `http://localhost:8000/...`. Útil se a rede do IFSP bloquear o `github.io`.

## Tempo estimado

| Atividade | Conteúdo | Tempo |
|---|---|---|
| Ativ. 1 · Parte 1 | montar LED + botão na web | 25 min |
| Ativ. 1 · Parte 2 | montar LDR + mostrar valor | 20 min |
| Ativ. 1 · Parte 3 | luz automática + calibração | 20 min |
| Ativ. 2 · Parte 1 | montar ultrassônico + distância | 25 min |
| Ativ. 2 · Parte 2 | potenciômetro + LED piscando | 30 min |
| Ativ. 3 | 5 LEDs + sequência em loop | 30–40 min |

Cabe em ~2h ou em duas aulas (1: Atividade 1; 2: Atividade 2).

---

## Preparação ANTES da aula

### 1. Hardware por grupo

| Componente | Pino | Usado em |
|---|---|---|
| Arduino **Uno** + cabo USB | — | tudo |
| Protoboard + jumpers | — | tudo |
| **LED** + resistor 220–330 Ω | pino 13 | Ativ. 1 |
| **LED** + resistor 220–330 Ω | pino 8 | Ativ. 2 (P2) |
| **5 LEDs** + resistores 220–330 Ω | pinos 2, 3, 4, 5, 6 | Ativ. 3 |
| **LDR** + resistor 10 kΩ | A0 (divisor) | Ativ. 1 (P2–P3) |
| **HC-SR04** (ultrassônico) | TRIG=9, ECHO=10, VCC=5V, GND | Ativ. 2 (P1) |
| **Potenciômetro** 10 kΩ | A1 (meio); 5V e GND (pontas) | Ativ. 2 (P2) |

### 2. Software nos PCs dos alunos

- **Arduino IDE** (para carregar os sketches — só o professor/aluno que sobe o código).
- **Google Chrome** ou **Microsoft Edge** atualizado (para o Web Serial). **Nada além disso.**
- (Opcional, só para o modo offline) Python 3 para o `http.server` — sem instalar pacotes.

### 3. Publicar no GitHub Pages (recomendado)

1. Suba este repositório para o GitHub (público).
2. No repositório: **Settings → Pages**.
3. Em **Source**, escolha **Deploy from a branch**; **Branch: `main`**, pasta **`/ (root)`**;
   **Save**.
4. Aguarde ~1 minuto. O site fica em
   `https://SEU_USUARIO.github.io/aula-robotica-web/web/`
   (essa URL abre o **menu** `web/index.html` com as 5 páginas).
5. **Distribua aos alunos** esse link. Eles abrem no Chrome/Edge.

> Troque `SEU_USUARIO` pelo seu usuário (ex.: `tardellirs`). Se mudar o nome do repositório,
> ajuste a URL.

### 4. Carregar os sketches

Cada Arduino precisa do sketch da atividade carregado (Arduino IDE → abrir o `.ino` →
**Placa: Arduino Uno** → **Porta** → **Carregar**):

- Atividade 1: `sketches/atividade1/atividade1.ino`
- Atividade 2: `sketches/atividade2/atividade2.ino`
- Atividade 3: `sketches/atividade3/atividade3.ino`

### 5. ⚠️ Teste antes, num PC do IFSP

- Confirme **Chrome/Edge** e que a janelinha de portas aparece ao clicar em Conectar.
- **Arduino clone** (chip CH340) pode pedir **driver**. Uno original não precisa.
- Faça o fluxo completo num PC: carregar sketch → fechar Monitor Serial → abrir a página →
  Conectar → LED/sensor funcionando.

---

## Pontos-chave (para conduzir)

- **Regra de ouro:** só um programa por porta. Monitor Serial aberto é a causa nº 1 de "não
  conecta". Mande fechar.
- **Conectar a cada página:** ao trocar de parte/página, é preciso clicar em **Conectar** e
  escolher a porta de novo (proteção do navegador — só acessa a USB com um clique do usuário).
- **Atividade 1:** o `1`/`0` que o botão envia é o mesmo que liga o pino 13 (o LED da protoboard; o LED embutido acende junto). Na Parte 3, o
  "só enviar quando muda de estado" evita inundar a porta.
- **Atividade 2:** o piscar é feito **pela página** (alterna `1`/`0` a cada 200 ms). Bom
  momento para falar de "limiar" e de mapear o potenciômetro (0–1023) para centímetros.
- **Atividade 3:** a página guarda a sequência e a percorre em loop; o `% seq.length` é o que
  faz a contagem "dar a volta". O Arduino recebe um mapa de 5 dígitos por passo (ex.: `10110`).
- **Conceito-chave para fechar:** sem Wi-Fi, os dados vêm pela **USB/Serial**; quem mostra a
  página é o **computador (navegador)**, não o Arduino.

---

## Solução de problemas

| Sintoma | Causa / solução |
|---|---|
| Não aparece a janela de portas / `navigator.serial is undefined` | Não é Chrome/Edge, ou a página foi aberta como `file://`. Use o link do GitHub Pages (https) ou `python3 -m http.server` (localhost). |
| Clicou em Conectar e **não há portas** | Cabo/porta ou falta de **driver CH340** (clones). Confirme a porta na Arduino IDE. |
| "Porta ocupada" / não conecta | **Monitor Serial** aberto. Feche-o. |
| Conecta mas **nada muda** | Sketch não carregado, ou velocidade ≠ 9600. Recarregue o `.ino` e clique em Conectar de novo. |
| Distância mostra **-1** | Nada no alcance (timeout do HC-SR04). Normal; aproxime um objeto. |
| LED não acende | Confira o **resistor** e a **polaridade** (perna maior = +). Na Atividade 1 o LED fica no **pino 13**; na Atividade 2, no **pino 8**. (No pino 13, o LED embutido também deve acender.) |
| Página "travou" ao reconectar | Atualize (F5) e clique em Conectar de novo. |

---

## Arquivos deste projeto

```
aula-robotica-web/
├── sketches/
│   ├── atividade1/atividade1.ino     # LDR -> JSON; LED no pino 13 <- '1'/'0'
│   ├── atividade2/atividade2.ino     # ultrassônico+pot -> JSON; LED <- '1'/'0'
│   └── atividade3/atividade3.ino     # 5 LEDs <- mapa "10110"
├── web/                              # páginas (Web Serial — Chrome/Edge)
│   ├── style.css                     # estilo compartilhado
│   ├── serial.js                     # ajudante: conectarArduino() e enviarComando()
│   ├── index.html                    # menu das 5 páginas
│   ├── atividade1-parte1.html        # botão liga/desliga o LED
│   ├── atividade1-parte2.html        # mostra o valor do LDR
│   ├── atividade1-parte3.html        # luz automática + calibração
│   ├── atividade2-parte1.html        # mostra a distância (gráfico)
│   ├── atividade2-parte2.html        # potenciômetro ajusta o alarme (LED pisca)
│   ├── atividade3.html               # sequenciador: 5 LEDs em loop
│   └── chart.umd.min.js              # Chart.js (cópia local, offline)
├── ATIVIDADE-1.md                    # handout do aluno (Entregas 1.1–1.3)
├── ATIVIDADE-2.md                    # handout do aluno (Entregas 2.1–2.3)
├── ATIVIDADE-3.md                    # handout do aluno (Entregas 3.1–3.3)
├── FOLHA-DE-ENTREGA.md               # folha para o grupo entregar
├── GABARITO.md                       # respostas (NÃO vai pro GitHub — .gitignore)
├── PLANO-DA-AULA.md                  # este guia
└── LICENSE                           # MIT
```
