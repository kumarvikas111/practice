#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=================================================================
// initial Values to be set before start programm.
//=================================================================
#define GetTime()	//need to define it.
#define glog NULL 		//need to deine it.
#define DISPLAY_BANNER() do{\
							FILE *fp = NULL;\
							char buf[80] = { 0 };\
							if (NULL != (fp = fopen("banner", "r"))) {\
								while (!feof(fp)) {\
									printf("%c", fgetc(fp));\
									memset((char *)&buf, 0, sizeof(buf));\
						        }\
								fclose(fp);\
						    }\
else {\
printf("***************************************************************\n");\
printf("*                         Welcome...                          *\n");\
printf("***************************************************************\n");\
}\
}while(0);
//==================================================================
//				Debuging & Compile Out Macros
//==================================================================

#define ENABLE_DEBUG 1 
#define DEBUG 0
#define ENABLE_LOG 0

#if DEBUG
#define PRINT printf("FILE: %s LINE %d \n", __FILE__, __LINE__)
#else
#define PRINT 
#endif

#if ENABLE_LOG
#define PRINTF(fmt, ...)	do{ if(!gdebug) { \
									fprintf(glog,"%s %s\t<%4d> "fmt,\
								GetTime() ,__FILE__,__LINE__,__VA_ARGS__);\
								}else {\
									 printf("%s  <%4d> " fmt,__FILE__,\
								 __LINE__, __VA_ARGS__); \
													\
								fprintf(glog, "%s %s\t<%4d> " fmt,GetTime(),\
										 __FILE__, __LINE__, __VA_ARGS__); }\
							  }while (0);
#elif 0
#define PRINTF(fmt, ...)	do{\
								 printf("%s\t<%4d> " fmt ,\
									__FILE__,__LINE__,__VA_ARGS__);\
								\
								fprintf(glog,"%s %s\t<%4d> " fmt ,GetTime() ,\
									__FILE__,__LINE__,__VA_ARGS__);\
							  }while (0);
#else
#define PRINTF(fmt, ...)	do{\
								 printf("%s\t<%4d> " fmt ,\
									__FILE__,__LINE__,__VA_ARGS__);\
							  }while (0);
#endif


//==================================================================
//				Used Structures & ddefine your New Here.
//==================================================================

typedef enum {
	FAIL = -1,
	SUCCESS = 0,
} ret_opt_e;

//==================================================================
//				Prototypes
//==================================================================
int get_environment_setup();
void redirect();
//char * GetTime();
int enable_debug(int argc, wchar_t * argv[]);
int disable_debug(int argc, wchar_t * argv[]);
int display_banner();
//==================================================================
