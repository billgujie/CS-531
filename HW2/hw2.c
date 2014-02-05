#include "hw2.h"

int main ( int argc, char **argv )
{
	Argvs cmd = ParseCommandLine ( argc, argv );
	if (cmd.mode==OP_STREAM){
		if (stream(cmd.pphrase,cmd.len)!=0){
			fprintf(stderr, "ERR: Unknown Stream error\n");
		}
	}
	free(cmd.pphrase);
	return 0;
}
