
#include "hw2.h"

int stream ( char* p, int cipher_len , unsigned char* remote, int mode)
{
	//char p[] = "yesnomaybe";
	//int cipher_len = 202;
	int cycle, remainder;
	cycle = cipher_len / STREAM_OUTPUT_LEN;
	remainder = cipher_len % STREAM_OUTPUT_LEN;
	int len = strlen ( p ) + 2 + MD5_DIGEST_LENGTH;
	char *s = malloc ( len + 1 );
	unsigned char md5_buf[MD5_DIGEST_LENGTH];
	MD5 (  (unsigned char*)p, strlen ( p ), ( unsigned char* ) &md5_buf );
	int count = 0;
	int i = 0;
	unsigned char* write_remote=remote;
	
	for ( count = 0; count < cycle; count++ ) {
		sprintf ( &s[MD5_DIGEST_LENGTH], "%02d%s", i, p );
		memcpy ( s, md5_buf, MD5_DIGEST_LENGTH );
		MD5 ( ( unsigned char* ) s, len, md5_buf );
		if (mode==OP_STREAM){
			fwrite ( md5_buf, 1, STREAM_OUTPUT_LEN, stdout );
		}
		if (mode==OP_ENCRYPT){
			memcpy ( write_remote, md5_buf, STREAM_OUTPUT_LEN );
			write_remote += STREAM_OUTPUT_LEN;
		}
		if ( ++i == 100 ) i = 0;
	}

	if ( remainder > 0 ) {
		sprintf ( &s[MD5_DIGEST_LENGTH], "%02d%s", i, p );
		memcpy ( s, md5_buf, MD5_DIGEST_LENGTH );
		MD5 ( ( unsigned char* ) s, len, md5_buf );
		if (mode==OP_STREAM){
			fwrite ( md5_buf, 1, remainder, stdout );
		}
		if (mode==OP_ENCRYPT){
			memcpy ( write_remote, md5_buf, remainder );
		}
	}
	free(s);
	return 0;
}
