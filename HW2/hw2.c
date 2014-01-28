#include <stdio.h>
#include <sys/types.h>
#include <openssl/md5.h>
#include <string.h>
#include <stdlib.h>
int main ( int argc, char **argv )
{
	char p[] = "yesnomaybe";
	unsigned char md5_buf[MD5_DIGEST_LENGTH];
	MD5 (  (unsigned char*)&p, strlen ( p ), (unsigned char*)&md5_buf );
	printf ( "hello world\n" );
	return 0;
}
