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
	for(i=0; args[i]!=NULL; i++)
	{
		if(args[i]==',')
			break;
	}
	
	index=i;
	if(args[0]=='-' || args[0]=='0' || args[0]=='(')
	{
		if(args[index+1]=='0')
			return 0;
		else if(args[index+1]=='(')
			return 0;
	}
	if(args[0]='$' && args[index+1]=='$')
		return 0;

	if(args[index+1]=='$')
		return 0;


	return 1;
}	
			
		
