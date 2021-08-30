# Projeto-Integrador-II-A

### Segundo Encontro - 28/08/2021 - Prof. Adenauer Yamin

#### Explorando o POSIX
  * Clique neste **[link](https://pt.wikipedia.org/wiki/POSIX)** para conhecer a idéia por trás do POSIX

#### Uso de Virtualização
  * Um exemplo seria o **[Virtualbox](https://www.virtualbox.org/)**
  * Um exemplo de distribuição leve seria o **[LinuxMint](https://linuxmint.com/)**
  * Como curiosidade instalar o MacOS no Virtual Box - [Linux](https://youtu.be/Tru8CDZkpiY)

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
* gcc publica-mqtt.c -o publica-mqtt  (após o "-o" fica o nome do programa executável

#### Procedimentos Definidos
* Elabore um programa em C que faça Leitura dos Participantes Ativos. Utilizar o comando MQTT a seguir como base: mosquitto_sub -h broker.emqx.io -t pi2a/nomes
* Construa um programa em C que solicite a manifestação dos participantes ativos. Empregar o comando MQTT a seguir como base: mosquitto_pub -h broker.emqx.io -t pi2a -m ????
* Criar um programa em C que imprima o nome do participante (considerando a URI pi2a/nomes) a partir da postagem de "????" na URI pi2a/comandos
