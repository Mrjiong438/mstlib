#include<stdio.h>
#include<dlfcn.h>

typedef struct{
	char *name;
	void *fuc;
}dyfuc;

typedef struct{
	char *path;
	void *lib;
	dyfuc *fucs;
}dylib;

/* int load_lib(dylib *dlib){ */
/* 	if (*dlib.lib != NULL) { */
/* 		dlclose(*dlib.lib); */
/* 		/1* *lib_dest = NULL; *1/ */
/* 	} */
/* 	void *templib = dlopen(dlib.path,RTLD_NOW);//will be NULL if error */

/* 	if(*templib == NULL){ */
/* 		fprintf(stderr,"ERROR: can not load %s:\n%s\n",dlib.path,dlerror()); */
/* 		return -1; */
/* 	} */
/* 	*dlib.lib = templib; */

/* 	for */
/* 	void *tempfuc = dlsym(*lib_dest,fuc_name); */
/* 	if(tempfuc == NULL){ */
/* 		fprintf(stderr,"ERROR: can not load fuc in %s:\n%s\n" ,,dlerror()); */
/* 		return -2; */
/* 	} */
/* 	return 0; */
/* } */
