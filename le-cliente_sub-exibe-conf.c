#include <stdio.h>
#include <stdlib.h>

int main (void) {
   char linha[100];

   while (1) 
   {
   scanf ("%[^\n]", linha);
   printf ("PRGM C: %s\n", linha);
   setbuf(stdin, NULL);
   system("mosquitto_pub -h broker.emqx.io -t temp-centro-pelotas-conf -m 'Temperatura Recebida'");
   }
   return EXIT_SUCCESS;
}
