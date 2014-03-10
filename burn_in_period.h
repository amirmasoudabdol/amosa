//Declaring Pre Defined Header Files Of C Compiler.
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

#include "amosa.h"

/* Function to initialize Tmax which is the maximum temperature */

// void burn_in_period()
void burn_in_period(AMOSAType *amosaParams)
{

// variable declaration
//------------------------------------------------------------------------------------------------------
 int r;
 int i,h;
 int i_count=0;
 double *d_newsol,d_energy,d_pos_energy=0;
 double *func,*func1;

//--------------------------------------------------------------------------------------------------------


// Body of the burn_in_period function	

//---------------------------------------------------------------------------------------------------------

 amosaParams->seed=67644288;	
 srand(amosaParams->seed);
	//i=1;
 d_newsol=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);
 func=(double *)malloc(sizeof(double)*amosaParams->i_no_offunc);
 func1=(double *)malloc(sizeof(double)*amosaParams->i_no_offunc);
 while(i_count<20)
 {
          r=(rand()%amosaParams->i_archivesize);	/* Finding a random number between 0 and archivesize*/

   for( h=0;h<amosaParams->i_no_offunc;h++ )
     func1[h]=amosaParams->d_func_archive[r][h];	

   for(h=0;h<amosaParams->i_totalno_var;h++)
    d_newsol[h]=amosaParams->d_archive[r][h];
          real_mutate_ind(d_newsol, amosaParams);   /* Function performimg mutation on individual string */
          evaluate(d_newsol, amosaParams);     /* This function calls different evaluation functions*/
  for(h=0;h<amosaParams->i_no_offunc;h++)
   func[h]=amosaParams->d_eval[h];
 d_energy=find_sign_dom(func,func1, amosaParams);
 if(d_energy>0)
 {
   d_pos_energy+=d_energy;
   i_count++;
	    }  //end of inner if loop
	}   //end of outer while loop
  d_pos_energy=(d_pos_energy/i_count);
  amosaParams->d_tmax=(d_pos_energy/log(2));
  printf("\n The maximum temperature is=%lf",amosaParams->d_tmax);

}	
//------------------------------------------------------------------------------------------------------------------------

// End of burn_in_period function
//---------------------------------------------------------------------------------------------------------------------
