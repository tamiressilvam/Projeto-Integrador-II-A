#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[ ] )
{
	int cont;
        char linha[256];
	char comando[256];

	for(cont=1; cont < argc; cont++){
                strcat(linha,argv[cont]);
		strcat(linha," ");
	}
	strcat(comando, "mosquitto_pub -h broker.emqx.io -t pi2a/msgs -m '");
	strcat(comando, linha);
	strcat(comando, "'");
        system(comando);
	return 0;
}
