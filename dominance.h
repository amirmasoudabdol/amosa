#include <malloc.h>

#include "amosa.h"
/* The Following function checks whether the solution 
	 vector func1 dominates the solution vector func2  */ 

int is_dominated(double *func1,double *func2, AMOSAType *amosaParams)
{
	int i;
	int i_count_less=0,i_count_equal=0;
	double ff;
	for(i=0;i<amosaParams->i_no_offunc;i++)
	{
		ff=(func1[i]-func2[i]);
		if(func1[i]<func2[i])
			i_count_less++;
		else if(func1[i]==func2[i])
			i_count_equal++;    
	}
	if(((i_count_less+i_count_equal)==amosaParams->i_no_offunc) && i_count_less>0)
		return(TRUE);
	else 
		return(FALSE);
}



	 /* The Following function calculates the unsigned amount of domination between two solution vectors func1 and func2*/    

double find_unsign_dom(double *func1,double *func2, AMOSAType *amosaParams)
{
	int i;
	double d_dominance=1;
	for(i=0;i<amosaParams->i_no_offunc;i++)
	{
		if((func1[i]-func2[i])!=0.0)
			d_dominance=d_dominance*fabs(func1[i]-func2[i])/amosaParams->d_func_range[i];

	}
	return(d_dominance);
}


/* The Following function calculates the signed amount of domination 
	 between two solution vectors func1 and func2   */  

double find_sign_dom(double *func1,double *func2, AMOSAType *amosaParams)
{
	int i;
	double d_dominance=1;
	for(i=0;i<amosaParams->i_no_offunc;i++)
	{
		if(fabs(func1[i]-func2[i])!=0)
			d_dominance=d_dominance*(func1[i]-func2[i])/amosaParams->d_func_range[i];

	}
	return(d_dominance);
}  



