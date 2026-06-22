# Aula — Robótica com Arduino e Web (Web Serial)

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino&logoColor=white)
![Web Serial](https://img.shields.io/badge/Web%20Serial-Chrome%20%7C%20Edge-4285F4?logo=googlechrome&logoColor=white)
![HTML](https://img.shields.io/badge/HTML5-JS-E34F26?logo=html5&logoColor=white)
![Sem instalação](https://img.shields.io/badge/aluno-sem%20instalar%20nada-16a34a)
![License](https://img.shields.io/badge/License-MIT-yellow)

Atividade prática de **Robótica** (IFSP): os alunos conectam sensores e LEDs de um **Arduino
sem Wi-Fi** a uma **página web**, controlando e visualizando tudo pelo **navegador** — sem
instalar nada (sem Python, sem `pip`, sem servidor).

> Material livre para reuso por outros professores. Sinta-se à vontade para adaptar.

## Como funciona

```
GitHub Pages ──https──► Navegador do aluno (Chrome/Edge) ──Web Serial/USB──► Arduino do aluno
 (só entrega a página)        (roda no PC do aluno)             (100% local)
```

O Arduino fala pela **USB**. A página, aberta no **Chrome/Edge**, usa a **Web Serial API**
para conversar direto com o Arduino — **não há servidor**. O GitHub Pages só **entrega o
arquivo**; a conexão com o Arduino é local, no PC de cada aluno (funciona com a turma toda ao
mesmo tempo, e até offline depois de carregada).

## As atividades

- **[ATIVIDADE-1.md](ATIVIDADE-1.md) — LED e sensor de luz (LDR)**
  - Parte 1: um botão liga/desliga o LED embutido (pino 13).
  - Parte 2: ler o LDR e mostrar o valor.
  - Parte 3: luz automática (acende no escuro) com **calibração**.
- **[ATIVIDADE-2.md](ATIVIDADE-2.md) — Sensor ultrassônico**
  - Parte 1: mostrar a distância de um objeto.
  - Parte 2: o **potenciômetro** ajusta a distância em que o **LED pisca** (alarme).

A montagem do circuito é a **primeira etapa de cada parte** e vai crescendo. Cada parte tem
checkpoints (📸/✍️) registrados na **[FOLHA-DE-ENTREGA.md](FOLHA-DE-ENTREGA.md)**. Guia do
professor em **[PLANO-DA-AULA.md](PLANO-DA-AULA.md)**.

## Como usar

1. **Carregar o sketch** (Arduino IDE): `sketches/atividade1/atividade1.ino` ou
   `sketches/atividade2/atividade2.ino` (Placa: **Arduino Uno**).
2. **Abrir a página** no **Chrome/Edge**:
   - **GitHub Pages** (recomendado): publique o repo (Settings → Pages) e abra
     `https://SEU_USUARIO.github.io/aula-robotica-web/web/`.
   - **Offline**: `cd web && python3 -m http.server 8000` e abra `http://localhost:8000/`.
3. Clicar em **🔌 Conectar ao Arduino** e escolher a porta.

> ⚠️ Só um programa por vez usa a porta: **feche o Monitor Serial** da Arduino IDE antes de
> usar a página.

## Hardware (Arduino Uno)

| Componente | Pino |
|---|---|
| LED embutido (Atividade 1) | 13 |
| LED + resistor 220–330 Ω (Atividade 2) | 8 |
| LDR (divisor com resistor 10 kΩ) | A0 |
| HC-SR04 — TRIG / ECHO | 9 / 10 |
| Potenciômetro | A1 |

## Requisitos

- **Arduino Uno** + sensores + **Arduino IDE** (para subir o sketch).
- **Google Chrome** ou **Microsoft Edge** (o Web Serial não funciona em Firefox/Safari/celular).
- Aluno **não instala nada** no computador.

## Licença

Distribuído sob a licença **MIT** — veja [LICENSE](LICENSE). Use, adapte e compartilhe.
