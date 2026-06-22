# Aula — Robótica com Arduino e Web (Web Serial)

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino&logoColor=white)
![Web Serial](https://img.shields.io/badge/Web%20Serial-Chrome%20%7C%20Edge-4285F4?logo=googlechrome&logoColor=white)
![HTML](https://img.shields.io/badge/HTML5-JS-E34F26?logo=html5&logoColor=white)
![Sem instalação](https://img.shields.io/badge/aluno-sem%20instalar%20nada-16a34a)
![License](https://img.shields.io/badge/License-MIT-yellow)

Uma **trilha de robótica** (IFSP) em **4 atividades**: o aluno liga sensores, LEDs e um teclado
a um **Arduino sem Wi-Fi** e controla tudo por uma **página web**, no navegador — **sem instalar
nada** (sem Python, sem `pip`, sem servidor).

> Material livre para reuso por outros professores. Sinta-se à vontade para adaptar.

## Como funciona

```
GitHub Pages ──https──► Navegador do aluno (Chrome/Edge) ──Web Serial/USB──► Arduino do aluno
 (só entrega a página)        (roda no PC do aluno)             (100% local)
```

O Arduino fala pela **USB**. A página, no **Chrome/Edge**, usa a **Web Serial API** para
conversar direto com o Arduino — **não há servidor**. O GitHub Pages só **entrega a página**; a
conexão com o Arduino é local, no PC de cada aluno (funciona com a turma toda junto, e até
offline depois de carregada).

## A trilha — 4 atividades

Faça na ordem: cada uma usa o que a anterior ensinou.

| # | Atividade | O que você monta e faz | O que aprende |
|---|---|---|---|
| **1** | [LED + sensor de luz (LDR)](ATIVIDADE-1.md) | botão liga/desliga o LED → lê o LDR → luz automática (acende no escuro) | ler um sensor e controlar um LED pela web |
| **2** | [Sensor ultrassônico](ATIVIDADE-2.md) | distância num gráfico ao vivo → potenciômetro ajusta um alarme que pisca | medir distância e ajustar um limite |
| **3** | [Sequência de 5 LEDs](ATIVIDADE-3.md) | monta uma sequência de luzes e roda em **loop**, com velocidade | listas e repetição (loop) |
| **4** | [Jogo da cobrinha](ATIVIDADE-4.md) | um **teclado 4×4** controla a cobrinha que roda no navegador | controle físico de um software |

Cada atividade começa **montando o circuito** e tem checkpoints (📸 foto / ✍️ resposta) para o
aluno registrar na **[FOLHA-DE-ENTREGA.md](FOLHA-DE-ENTREGA.md)**.

## Começando (3 passos)

1. **Carregar o programa** no Arduino (Arduino IDE): abra o sketch da atividade na pasta
   `sketches/` (Placa: **Arduino Uno**) e clique em **Carregar**. *(A Atividade 4 precisa da
   biblioteca **Keypad** — o handout explica.)*
2. **Abrir a página** no **Chrome ou Edge**: o professor passa um **link** (GitHub Pages). A
   página inicial **lista as 4 atividades** — clique na que você vai fazer.
3. Clicar em **🔌 Conectar ao Arduino** e escolher a porta.

> ⚠️ **Regra de ouro:** só um programa por vez usa a porta. **Feche o Monitor Serial** da
> Arduino IDE antes de usar a página.

## Hardware (Arduino Uno)

| Componente | Pino | Atividade |
|---|---|---|
| LED + resistor 220–330 Ω | 13 | 1 |
| LDR (divisor com resistor 10 kΩ) | A0 | 1 |
| HC-SR04 — TRIG / ECHO | 9 / 10 | 2 |
| Potenciômetro | A1 | 2 |
| LED + resistor 220–330 Ω | 8 | 2 |
| 5 LEDs + resistores 220–330 Ω | 2, 3, 4, 5, 6 | 3 |
| Teclado matricial 4×4 (biblioteca Keypad) | 9, 8, 7, 6, 5, 4, 3, 2 | 4 |

## Requisitos

- **Arduino Uno** + componentes + **Arduino IDE** (para subir o sketch).
- **Google Chrome** ou **Microsoft Edge** (o Web Serial não funciona em Firefox/Safari/celular).
- O aluno **não instala nada** no computador.

---

**Professor:** o guia completo (preparação, tempos, lista de materiais, solução de problemas e
como publicar no GitHub Pages) está em **[PLANO-DA-AULA.md](PLANO-DA-AULA.md)**.

## Licença

Distribuído sob a licença **MIT** — veja [LICENSE](LICENSE). Use, adapte e compartilhe.
