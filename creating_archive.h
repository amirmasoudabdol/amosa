// Declaring User Defined Header Files.

#include <malloc.h>

#include "amosa.h"

/* Function creating the archive */
void creating_archive(AMOSAType *amosaParams)
{

// variable declaration
//------------------------------------------------------------------------------------------------------
  int i,j,h;
  int g=0;
  int count,count1;
  int *i_flag;
  double **d_area;

//--------------------------------------------------------------------------------------------------------


// Body of the creating_archive function	

//---------------------------------------------------------------------------------------------------------
  i_flag=(int *)malloc(amosaParams->i_softl*sizeof(int));
  d_area=(double **) malloc(sizeof(double*)*amosaParams->i_softl);
  for(i=0;i<amosaParams->i_softl;i++)
    d_area[i]=(double *) malloc(amosaParams->i_no_offunc*sizeof(double));
  for(i=0;i<amosaParams->i_softl;i++)
  {
            evaluate(amosaParams->d_solution[i], amosaParams);   /* This function calls different evaluation functions */

    for(j=0;j<amosaParams->i_no_offunc;j++)
     d_area[i][j]=amosaParams->d_eval[j];
   i_flag[i]=1;
 }   

 for(j=0;j<amosaParams->i_softl-1;j++)
 {
   if(i_flag[j]==1)
   {
    for(i=j+1;i<amosaParams->i_softl && i_flag[j]==1;i++)
    {
     if(i_flag[i]==1)
     {
      count=0;
      count1=0;
      for(h=0;h<amosaParams->i_no_offunc;h++)
      {
        if(d_area[j][h]>=d_area[i][h]) 
         count++;

       else if(d_area[j][h]<=d_area[i][h])
         count1++;

                          }  //end of 4th inner for loop
                          if(count==amosaParams->i_no_offunc)
                            i_flag[j]=0;
                          else if(count1==amosaParams->i_no_offunc)
                            i_flag[i]=0;
                      }     //end of 3rd inner if loop

                  }    //end of 2nd inner for loop
             }    //end of 1st inner if loop
           }    //end of outer for loop
           for(i=0;i<amosaParams->i_softl;i++)
           {
             if(i_flag[i]==1)
             {
               for(h=0;h<amosaParams->i_totalno_var;h++)
                amosaParams->d_archive[g][h]=amosaParams->d_solution[i][h];

              for(h=0;h<amosaParams->i_no_offunc;h++)
               amosaParams->d_func_archive[g][h]=d_area[i][h];

             g++;
              }  //end of inner if loop
        }  //end of outer for loop

        amosaParams->i_archivesize=g;  
      }
//------------------------------------------------------------------------------------------------------------------------
    // End of creating_archive function
//---------------------------------------------------------------------------------------------------------------------
