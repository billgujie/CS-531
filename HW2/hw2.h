#ifndef HW2_H
#define HW2_H

#include <stdio.h>
#include <sys/types.h>
#include <openssl/md5.h>
#include <string.h>
#include <stdlib.h>


#define STREAM_OUTPUT_LEN		8
#define OP_STREAM					1
#define OP_ENCRYPT				2
#define OP_MERGE					3
#define OP_DECRYPT				4
#define MAX_BUFLEN				1024
#define OPTION_HEAD_LEN1			3	// -p=  -l=
#define OPTION_HEAD_LEN2			5  // -out=

typedef struct ArgvsTag {
	int mode;
	char* pphrase;
	int len;
	char* out;
	char* file1;
	char* file2;
} Argvs;

#endif

/*
 * functions called
 */
 Argvs ParseCommandLine ( int argc, char **argv );
 int stream ( char* p, int cipher_len );
