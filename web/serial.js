/* =====================================================================
   serial.js — ajudante de Web Serial para a aula de Robótica.
   ---------------------------------------------------------------------
   A "mágica" desta aula: o PRÓPRIO navegador conversa com o Arduino pela
   porta USB, sem precisar de Python nem de servidor. Isso é o Web Serial.

   ⚠️ Funciona só no CHROME e no EDGE (no computador, não no celular).

   Este arquivo dá duas funções prontas para usar nas páginas:

     conectarArduino(aoReceberLinha)
         Abre a janelinha para o aluno escolher a porta e, a partir daí,
         chama a sua função 'aoReceberLinha(linha)' a cada linha que o
         Arduino enviar.

     enviarComando(texto)
         Envia um texto para o Arduino (ex: "1", "0" ou "2,1\n").
   ===================================================================== */

let porta = null;   // guarda a conexão com o Arduino

// --- Conecta no Arduino e fica lendo o que ele envia ---
async function conectarArduino(aoReceberLinha) {
  // 1) Pede para o usuário escolher a porta (abre a janela do navegador)
  porta = await navigator.serial.requestPort();
  // 2) Abre na MESMA velocidade do Arduino (Serial.begin(9600))
  await porta.open({ baudRate: 9600 });

  // 3) Prepara a leitura: transforma os bytes que chegam em texto
  const decodificador = new TextDecoderStream();
  porta.readable.pipeTo(decodificador.writable).catch(() => {});
  const leitor = decodificador.readable.getReader();

  // 4) Fica lendo para sempre, juntando os pedaços e separando por linha
  let buffer = "";
  while (true) {
    const { value, done } = await leitor.read();
    if (done) break;
    buffer += value;
    const linhas = buffer.split("\n");
    buffer = linhas.pop();            // o último pedaço pode estar incompleto
    for (const linha of linhas) {
      aoReceberLinha(linha.trim());   // entrega cada linha pronta para a página
    }
  }
}

// --- Envia um comando para o Arduino ---
async function enviarComando(texto) {
  if (!porta) {
    alert("Conecte ao Arduino primeiro!");
    return;
  }
  const escritor = porta.writable.getWriter();
  await escritor.write(new TextEncoder().encode(texto));
  escritor.releaseLock();   // libera para a próxima escrita
}

// --- Diz se já há um Arduino conectado (para a página não tentar enviar sem conexão) ---
function estaConectado() { return porta !== null; }
