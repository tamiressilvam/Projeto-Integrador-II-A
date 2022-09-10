# Projeto-Integrador-II-A
## https://github.com/adenauery/Projeto-Integrador-II-A

#### Responsáveis:
  * Prof. Adenauer Yamin - adenauer.yamin@ucpel.edu.br
  * Profa. Alexandra Zimpeck - alexandra.zimpeck@ucpel.edu.br

#### Baguete Jornalismo Digital
* https://www.baguete.com.br/

#### Tutorial sobre o GitHub
  * [Material sobre GitHub da FullCycle](https://fullcycle.com.br/git-e-github/) - [site da FullCycle](https://fullcycle.com.br/)

#### Tutoriais sobre a Linguagem C
  * [Tutorial 1](https://pt.wikibooks.org/wiki/Programar_em_C)
  * [Tutorial 2](https://wiki.ifsc.edu.br/mediawiki/index.php/AULA_5_-_Introdu%C3%A7%C3%A3o_%C3%A0_Linguagem_C_-_FIC#INTRODU.C3.87.C3.83O)

#### Explorando o POSIX
  * Clique neste **[link](https://pt.wikipedia.org/wiki/POSIX)** para conhecer a idéia por trás do POSIX

#### Uso de Virtualização para Trabalhar com Vários Sistemas Operacionais no mesmo Equipamento
  * Um exemplo seria o **[Virtualbox](https://www.virtualbox.org/)**
  * Um exemplo de distribuição leve seria o **LinuxMint:** **[Site em Ingles](https://linuxmint.com/) - [Site em Portugues](https://linuxmint.com.br/)**
    * No caso do Linux Mint, dependendo da versão poderá ser necessário instalar o build-essential para compilar programas na Linguagem C (sudo apt install build-essential)
  * Como curiosidade instalar o MacOS no Virtual Box - **[Link](https://youtu.be/Tru8CDZkpiY)**

#### Protocolo MQTT
  * Conceitos
    * [Site de Referência do MQTT](https://mqtt.org/)
    * [Protocolo MQTT - Material Curto Circuito](https://www.curtocircuito.com.br/blog/introducao-ao-mqtt/)
    * [Slides sobre MQTT - Material UFC](https://pt.slideshare.net/MaurcioMoreiraNeto/protocolo-mqtt-redes-de-computadores)
    * [Comparação MQTT & Outros Protocolos](https://medium.com/internet-das-coisas/iot-05-dando-uma-breve-an%C3%A1lise-no-protocolo-mqtt-e404e977fbb6)
  * Plataformas de Software
    * [Mosquitto da Eclipse Foundation](https://mosquitto.org)
    * [Brokers MQTT gratuitos e pagos para utilizar em projetos da IoT](https://diyprojects.io/8-online-mqtt-brokers-iot-connected-objects-cloud/#.XzfHmEl7nUI)
    
#### Instalando o Emulador de Terminais Putty
* https://www.putty.org/

#### Principais comandos via terminal

    * ls: Lista todos os arquivos do diretório
    * cd: Acessa uma determinada pasta (diretório)
    * mkdir: Cria um diretório
    * rm: Remove um arquivo/diretório
    * cat: Abre um arquivo
    * nano: edita um arquivo


#### Instalando Clientes da Plataforma Mosquitto no Linux

* sudo apt install mosquitto-clients
* Testes: 
  * Broker utilizado: broker.emqx.io
  * mosquitto_sub -h broker.emqx.io -t pi2a  (**subscrição**)
  * mosquitto_pub -h broker.emqx.io -t pi2a -m "Primeira Conexao"   (**publicação**)

#### Lendo Dados de temperatura do Projeto Integrador (postagens a cada 2 minutos):
  * Cliente MQTT por linha de comando em um Terminal:
    * mosquitto_sub -h broker.emqx.io -t pi2a/temps
    * Cliente MQTT via Web:
  * Cliente WEB (utilizar o navegador Google Chrome):
    * http://www.emqx.io/online-mqtt-client/

#### Instalando Clientes da Plataforma Mosquitto em Outros Sistemas Operacionais

* [Link para Download](https://mosquitto.org/download/)

#### Construindo programas (ou textos) em um Terminal do Linux com o Editor Nano
* https://wowgold-seller.com/pt/stories/7610-how-to-use-nano-text-editor-in-linux-with-cheat-sheet

#### Para Compilar programas em C no Linux utilizar:
* gcc publica-mqtt.c -o publica-mqtt  (após o "-o" fica o nome do programa executável)
* Para executar o programa já compilado fazer **./\<nome-do-programa\>**, por exemplo ./publica-mqtt

### Procedimentos (programas) a serem desenvolvidos pelos Grupos no Projeto Integrador

Estes procedimentos podem se valer dos **programas base**, relacionados na próxima seção.

* Elabore um programa em C que faça **Leitura dos Participantes Ativos** (considerando a URI pi2a/nomes). Utilizar o comando MQTT a seguir como base para desenvolvimento: 
  * mosquitto_sub -h broker.emqx.io -t pi2a/nomes (considere o programa **le-anuncia-mqtt.c**)
  * considere a postagem de "????" na URI pi2a/comandos

* Construa um programa em C que **solicite a manifestação dos participantes ativos**. 
  * Empregar o comando MQTT a seguir como base: mosquitto_pub -h broker.emqx.io -t pi2a -m ???? (considere o programa **publica-mqtt.c**)

* Construa um programa que fique **exibindo as mensagens postadas para os participantes ativos**. Utilize a URI pi2a/msgs e o comando grep para filtrar as mensagens para um participante específico. Abaixo exemplo de comando:
   *  mosquitto_sub -h broker.emqx.io -t pi2a/msgs | grep "adenauer:" (neste caso, somente mensagens que contenham o nome "adenauer" serão exibidas

* Elabore um programa para **postar mensagens para os participantes ativos**. Para isto, utilizar o mosquitto_pub empregando o nome do destinatário, vide exemplo abaixo:
   *  mosquitto_pub -h broker.emqx.io -t pi2a/msgs -m "adenauer: exemplo de comando para envio de mensagens"
   *  utilize como exemplo o programa **publica-frase-mqtt.c**, o qual posta uma frase formada por várias palavras passadas como parâmetro

### Programas Base Disponíveis

Estes programas podem ser utilizados como base para desenvolvimentos dos trabalhos dos grupos. Acesse os mesmos por este **[link](https://github.com/adenauery/Projeto-Integrador-II-A/find/main)**.

* **[le-anuncia-mqtt.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/le-anuncia-mqtt.c):** este programa opera em conjunto com o mosquitto_sub. Ao ser postada a string "????" será devolvido o nome do usuário ativo.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/comandos | ./le-anuncia-mqtt
  * a string "????" deve ser postada no tópico pi2a/comandos (utilizar o código **publica-mqtt.c**)
  * a identificação de todos que estão ativos no momento será postada no tópico pi2a/nomes

* **[le-cliente_sub-exibe-conf.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/le-cliente_sub-exibe-conf.c):** este programa opera em conjunto com o mosquitto_sub. No que for postada uma temperatura, será confiramdo seu recebimento.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/temps | ./le-cliente_sub-exibe-conf
  * a confirmação será disponibilizada no tópico pi2a/temps/confirmacao

* **[le-cliente_sub-exibe.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/le-cliente_sub-exibe.c):** este programa imprime informações recebidas pelo mosquitto_sub.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/temps | ./le-cliente_sub-exibe

* **[publica-mqtt-loop.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/publica-mqtt-loop.c):** este programa fica postando em laço infinito a data e hora no broker MQTT
  * a publicação ocorre no tópico pi2a/datahora

* **[publica-mqtt.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/publica-mqtt.c):** este programa publica uma constante no broker MQTT. No caso será postada a string "????" no tópico pi2a/comandos 

* **[publica-parametro-mqtt.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/publica-parametro-mqtt.c):** este programa lê uma palavra passada como parâmetro e publica no broker MQTT.
  * a publicação acontece no tópico pi2a/comandos, deste modo pode ser emprega para disparar ações no programa **le-anuncia-mqtt.c**

* **[publica-frase-mqtt.c](https://github.com/adenauery/Projeto-Integrador-II-A/blob/main/publica-frase-mqtt.c):** este programa envia uma frase via MQTT. A publicação irá acontecer no tópico **pi2a/msgs**.
