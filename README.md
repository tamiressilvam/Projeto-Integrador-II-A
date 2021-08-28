# Projeto-Integrador-II-A

### Segundo Encontro - 28/08/2021 - Prof. Adenauer Yamin

#### Explorando o POSIX
  * Clique neste **[link](https://pt.wikipedia.org/wiki/POSIX)** para conhecer a idéia por trás do POSIX

#### Uso de Virtualização
  * Um exemplo seria o **[Virtualbox](https://www.virtualbox.org/)**
  * Um exemplo de distribuição leve seria o **[LinuxMint](https://linuxmint.com/)**

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

#### Instalando Clientes da Plataforma Mosquitto em Outros Sistemas Operacionais

* [Link para Download](https://mosquitto.org/download/)
