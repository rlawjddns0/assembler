#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	int index;
	int i;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");

	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	for(i=0; args[i]!=NULL; i++)
	{
		if(args[i]==',')
			break;
	}
	i++;
	index=i;

	if(args[0]=='%' &&args[index+1]=='%'){
		mcode="89";
	}//reg to reg (1)

	if(args[0]=='%' &&args[index]=='0'&&args[index+1]=='x')
		mcode="a3";//reg(eax) to mem (5)


	if(args[0]=='$'){
		if(args[index+2]=='a')
		{
			mcode="b8";
		}
		else if(args[index+2]=='c')
		{
			mcode="b9";
		}
		else if(args[index+2]=='d')
		{
			mcode="ba";
		}
		else if(args[index+2]=='b')
		{
			mcode="bb";
		}
	}//immediate to reg(6)



	if(args[index]=='%'&&args[index+1]=='e' &&args[index+2]=='a')
	{
		if(args[0]=='0')
			mcode="a1";
	}//2.3

	if(args[index]=='%'){
		if(args[index-2]==')')
			mcode="a1";
	}//4

	

	
	

	return 1;	
}
