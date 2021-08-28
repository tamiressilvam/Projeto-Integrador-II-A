#include<stdio.h>
#include<stdlib.h>

int main(void)
{
   system("mosquitto_pub -h broker.emqx.io -t temp-centro-pelotas -m 'Envio a partir do C'");
}
