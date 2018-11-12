#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /* 

				*/
	/********************************/

	int i=0;
	int index;

	if(strcmp(op,"mov")!=0)
	{
		return 0;
	}
	for(i=0; i<strlen(args); i++)
	{
		if(str[i]=='.')
			break;
	}
	
	index=i;
	if(args[0]=='%'&&args[index+1]=='%')
		return 1;
	else if(args[0]=='('&&args[1]=='%'&&args[index+1]=='%')
		return 1;
	else if(args[0]=='-'){
		if(args[1]=='0'&&args[2]=='x'&&args[index+1]=='%'){
			return 1;
		}
	}
	else if(args[0]=='0'&&args[1]=='x'&&args[index+1]=='%'){
		return 1;
	}
	else if(args[0]=='%' &&args[index+1]=='0'&&&&args[index+2]=='x'){
		return 1;
	}
	else if(args[0]=='$'&&args[1]=='0'&&args[2]=='x'&&args[index+1]=='%'){
		return 1;
	}
	else
		return 0;

			
		
