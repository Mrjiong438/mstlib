/*
 * this program well ganerate a header file with the macro
 * that you can use to generates a regularly repeating string
 *
 * as example:
 * (first,include the header file ofcurse
 * the code on the left will turn into the right one
 *
 * ============================================================================
 * 								|	
 * #define STR(n) foo(n);		|	
 *								|	
 * STRLOOP(3,STR)				|	foo(1);foo(2);foo(3);
 * 								|	
 * ============================================================================
 *
 * ofcurse if you don't want any argument
 *
 * ============================================================================
 * #define STR(n) foo();		|	
 *								|	
 * STRLOOP(3,STR)				|	foo();foo();foo();
 * 								|	
 * ============================================================================
 * #define STR(n) int a##n;		|	
 *								|	
 * STRLOOP(3,STR)				|	int a1;int a2;int a3;
 * 								|	
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OUTPUT_NAME "loopstr.h"
#define EXE_NAME "loopstr_generater.out"
#define OUTPUT_PATH_LEN (int)strlen(argv[0])-strlen(EXE_NAME)+strlen(OUTPUT_NAME)
#define EXE_PATH_LEN (int)strlen(argv[0])
#define PATH_LEN (int)strlen(argv[0])-strlen(EXE_NAME)

int main(int argc,char *argv[]){
	char *filepath=NULL;
	filepath=(char *)malloc(OUTPUT_PATH_LEN+1);
	strncpy(filepath,argv[0],PATH_LEN);
	strcpy(filepath+PATH_LEN,OUTPUT_NAME);
	filepath[OUTPUT_PATH_LEN]='\0';

	int looptime=atoi(argv[1]);

	FILE *fp=NULL;

	fp=fopen(filepath,"w");
	fprintf(fp,
				"#ifndef LOOPSTR_H\n"
				"#define LOOPSTR_H\n"
				"\n"
				"#define STRLOOP(n,s) LOOP##n(s)\n"
				"\n"
				"#define LOOP1(s) s(1)\n");
	for(int i=2;i<=looptime;i++)
		fprintf(fp,"#define LOOP%d(s) LOOP%d(s) s(%d)\n",i,i-1,i);
	fprintf(fp,
				"\n"
				"#endif\n");

	return 0;
}
