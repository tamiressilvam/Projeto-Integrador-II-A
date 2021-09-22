# Projeto-Integrador-II-A

#### Responsáveis:
  * Prof. Adenauer Yamin e Profa. Alexandra Zimpeck

#### Tutorial sobre o GitHub
  * [Material sobre GitHub da FullCycle](https://fullcycle.com.br/git-e-github/) - [site da FullCycle](https://fullcycle.com.br/)

#### Tutoriais sobre a Linguagem C
  * [Tutorial 1](https://pt.wikibooks.org/wiki/Programar_em_C)
  * [Tutorial 2](https://wiki.ifsc.edu.br/mediawiki/index.php/AULA_5_-_Introdu%C3%A7%C3%A3o_%C3%A0_Linguagem_C_-_FIC#INTRODU.C3.87.C3.83O)

#### Explorando o POSIX
  * Clique neste **[link](https://pt.wikipedia.org/wiki/POSIX)** para conhecer a idéia por trás do POSIX

#### Uso de Virtualização para Trabalhar com Vários Sistemas Operacionais no mesmo Equipamento
  * Um exemplo seria o **[Virtualbox](https://www.virtualbox.org/)**
  * Um exemplo de distribuição leve seria o **[LinuxMint](https://linuxmint.com/)**
  * Como curiosidade instalar o MacOS no Virtual Box - [Link](https://youtu.be/Tru8CDZkpiY)

#### Protocolo MQTT
  * Conceitos
    * [Site de Referência do MQTT](https://mqtt.org/)
    * [Protocolo MQTT - Material IBM](https://www.ibm.com/developerworks/br/library/iot-mqtt-why-good-for-iot/index.html)
    * [Protocolo MQTT - Material Curto Circuito](https://www.curtocircuito.com.br/blog/introducao-ao-mqtt/)
    * [Slides sobre MQTT - Material UFC](https://pt.slideshare.net/MaurcioMoreiraNeto/protocolo-mqtt-redes-de-computadores)
    * [Comparação MQTT & Outros Protocolos](https://medium.com/internet-das-coisas/iot-05-dando-uma-breve-an%C3%A1lise-no-protocolo-mqtt-e404e977fbb6)
  * Plataformas de Software
    * [Mosquitto da Eclipse Foundation](https://mosquitto.org)
    * [Brokers MQTT gratuitos e pagos para utilizar em projetos da IoT](https://diyprojects.io/8-online-mqtt-brokers-iot-connected-objects-cloud/#.XzfHmEl7nUI)


#### Instalando Clientes da Plataforma Mosquitto no Linux

* sudo apt install mosquitto-clients
* Testes: 
  * Broker utilizado: broker.emqx.io
  * mosquitto_sub -h broker.emqx.io -t pi2a  (**subscrição**)
  * mosquitto_pub -h broker.emqx.io -t pi2a -m "Primeira Conexao"   (**publicação**)

#### Lendo Dados Disponíveis de Forma Pública

  * mosquitto_sub -h broker.emqx.io -t pi2a/temps

#### Instalando Clientes da Plataforma Mosquitto em Outros Sistemas Operacionais

* [Link para Download](https://mosquitto.org/download/)

#### Para Compilar programas em C no Linux utilizar:
* gcc publica-mqtt.c -o publica-mqtt  (após o "-o" fica o nome do programa executável)

### Procedimentos (programas) Definidos para Serem Desenvolvidos pelos Grupos

Estes procedimentos podem se valer dos **programas base**, relacionados na próxima seção.

* Elabore um programa em C que faça Leitura dos Participantes Ativos (considerando a URI pi2a/nomes). Utilizar o comando MQTT a seguir como base para desenvolvimento: 
  * mosquitto_sub -h broker.emqx.io -t pi2a/nomes (considere o programa **le-anuncia-mqtt.c**)
  * considere a postagem de "????" na URI pi2a/comandos

* Construa um programa em C que solicite a manifestação dos participantes ativos. 
  * Empregar o comando MQTT a seguir como base: mosquitto_pub -h broker.emqx.io -t pi2a -m ???? (considere o programa **publica-mqtt.c**)

* Construa um programa que fique exibindo as mensagens postadas para os participantes ativos. Utilize a URI pi2a/msgs e o comando grep para filtrar as mensagens para um participante específico. Abaixo exemplo de comando:
   *  mosquitto_sub -h broker.emqx.io -t pi2a/msgs | grep "adenauer:" (neste caso, somente mensagens que contenham o nome "adenauer" serão exibidas

### Programas Base Disponíveis

Estes programas podem ser utilizados como base para desenvolvimentos dos trabalhos dos grupos:

* **le-anuncia-mqtt.c:** este programa opera em conjunto com o mosquitto_sub. Ao ser postada a string "????" será devolvido o nome do usuário ativo.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/comandos | ./le-anuncia-mqtt
  * a string "????" deve ser postada no tópico pi2a/comandos
  * a identificação de quem está ativo será postada no tópico pi2a/nomes

* **le-cliente_sub-exibe-conf.c:** este programa opera em conjunto com o mosquitto_sub. No que for postada uma temperatura, será confiramdo seu recebimento.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/temps | ./le-cliente_sub-exibe-conf
  * a confirmação será disponibilizada no tópico pi2a/temps/confirmacao

* **le-cliente_sub-exibe.c:** este programa imprime informações recebidas pelo mosquitto_sub.
  * exemplo de uso: mosquitto_sub -h broker.emqx.io -t pi2a/temps | ./le-cliente_sub-exibe

* **publica-mqtt-loop.c:** este programa fica postando em laço infinito a data e hora no broker MQTT
  * a publicação ocorre no tópico pi2a/datahora

* **publica-mqtt.c:** este programa publica uma constante no broker MQTT. No caso será postada a string "????" no tópico pi2a/comandos 

* **publica-parametro-mqtt.c:** este programa lê uma palavra passada como parâmetro e publica no broker MQTT.
  * a publicação acontece no tópico pi2a/comandos, deste modo pode ser emprega para disparar ações no programa **le-anuncia-mqtt.c**
