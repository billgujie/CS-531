#include "hw2.h"

int main ( int argc, char **argv )
{
	Argvs cmd = ParseCommandLine ( argc, argv );
	//char *out = (char *)malloc(cmd.len);
	if ( cmd.mode == OP_STREAM ) {
		if ( stream ( cmd.pphrase, cmd.len, NULL, OP_STREAM ) != 0 ) {
			printerror ( "Unknown Stream error" );
		}
	} else if ( cmd.mode == OP_ENCRYPT ) {
		if ( encrypt ( cmd.pphrase, cmd.out, cmd.file1 ) != 0 ) {
			printerror ( "Unknown Encrypt error" );
		}
	}
	free ( cmd.pphrase );
	return 0;
}
