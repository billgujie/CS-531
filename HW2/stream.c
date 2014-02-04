
#include "hw2.h"

int stream ( char* pphrase, int cipher_len )
{
	char p[] = "vcrypto";
	int size = 202;
	int cycle, remainder;
	cycle = size / 8;
	remainder = size % 8;
	int len = strlen ( p ) + 2 + MD5_DIGEST_LENGTH;
	char *s = malloc ( len + 1 );
	unsigned char md5_buf[MD5_DIGEST_LENGTH];
	MD5 (  ( unsigned char* ) &p, strlen ( p ), ( unsigned char* ) &md5_buf );
	int count = 0;
	int i = 0;
	//int wlen = 8;
	for ( count = 0; count < cycle; count++ ) {
		sprintf ( &s[MD5_DIGEST_LENGTH], "%02d%s", i, p );
		memcpy ( s, md5_buf, MD5_DIGEST_LENGTH );
		MD5 ( ( unsigned char* ) s, len, md5_buf );
		fwrite ( md5_buf, 1, 8, stdout );
		if ( ++i == 100 ) i = 0;
	}

	if ( remainder > 0 ) {
		sprintf ( &s[MD5_DIGEST_LENGTH], "%02d%s", i, p );
		memcpy ( s, md5_buf, MD5_DIGEST_LENGTH );
		MD5 ( ( unsigned char* ) s, len, md5_buf );
		fwrite ( md5_buf, 1, remainder, stdout );
	}

	return 0;
}
