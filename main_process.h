/* 

The main AMOSA process
	The process below used to generate the parato-optimal sollutions.
		It also stores the resultant points to the file named "saplot.out".
			By using gnuplot the PO font can be genarated.


-----------------------------------------------------------------------------------------

There are mainly three cases to deal with

Case 1: Current point dominates new

Case 2: Current and new point are non-dominating to each other

Case 3: New point dominates current point

-------------------------------------------------------------------------------------------

To plot the curve of PO font, Here is the steps

Step 1: Open  terminal

	Step 2: Type $ gnuplot
		
		Step 3: Type $ plot "saplot.out" 



*/

//--------------------------------------------------------------------------------------------------------------------------------------------

///-----------------------C compiler's perdefined header files--------------------------
#include <malloc.h>
#include <time.h>

#include "amosa.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------


///----------------------------------------------------------------------------------------
void RunAMOSA(AMOSAType *amosaParams)
{

// Variable declaration

//-----------------------------------------------------------------------------------------------------------      
      int    r;
      int    i;
      int    j;
      int    h;
      int    k;
      int    l;
      int    flag;
      int    pos;
      int    f;
      int    n;
      int    m;
      int    p1;
      int    p2;
      double ran2;
      double p;
      double deldom;
      double amount;
      float  ran1;
      int    count;
      int    duplicate;
      int    count1;
      int    count2;
      double **archive1;
      int    isdom;
      double *current;
      double *newsol;
      double t;
      double*func_new;
      double *func_current;
      double **area2;


      FILE *fp;

//------------------------------------------------------------------------------------------------------------------

// Main body of the mainprocess

//-----------------------------------------------------------------------------------------------------------------------------


      p2=amosaParams->i_softl+3;
      p1=amosaParams->i_archivesize-1;
      duplicate=0;
      area2= (double **)malloc(sizeof(double *)*(p2));
      current=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);
      newsol=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);
      

      for(i=0;i<(p2);i++)
       area2[i]=(double *)malloc(amosaParams->i_no_offunc*sizeof(double));
     archive1=(double **)malloc(sizeof(double *)*(p2-1));
     for(i=0;i<(p2-1);i++)
       archive1[i]=(double *)malloc(amosaParams->i_totalno_var*sizeof(double));
     func_new=(double *)malloc(amosaParams->i_no_offunc*sizeof(double));
     func_current=(double *)malloc(amosaParams->i_no_offunc*sizeof(double));
     srand(amosaParams->seed);
     if(p1>0)
     {
       r=((rand()/(RAND_MAX+1.0))*p1);
      }//End of if
      else r=0;
      for(i=0;i<amosaParams->i_totalno_var;i++)
      {
       current[i]=amosaParams->d_archive[r][i];

          }//End of for loop
          flag=1;
          pos=r;
          for(i=0;i<amosaParams->i_no_offunc;i++)
          {
            func_current[i]=amosaParams->d_func_archive[r][i];
       }//End of for loop

       for(t=amosaParams->d_tmax;t>=amosaParams->d_tmin;t=t*amosaParams->d_alpha)
       {
        printf("\n temp=%lf",t);

        for(j=1;j<=amosaParams->i_no_ofiter;j++)
        {
#ifdef DEBUG
         printf("\n amosaParams->i_no_ofiteration=%d",j);
#endif

         duplicate=0;
         for(h=0;h<amosaParams->i_totalno_var;h++)
         {
          newsol[h]=current[h];

		  }//End of for loop  
      real_mutate_ind(newsol, amosaParams);
      evaluate(newsol, amosaParams);    
      for(h=0;h<amosaParams->i_no_offunc;h++)
        func_new[h]=amosaParams->d_eval[h];
      count2=0;
      count1=0;
      for(h=0;h<amosaParams->i_no_offunc;h++)
      {
       if(func_current[h]<=func_new[h])
         count1++;
       if(func_new[h]<=func_current[h])
         count2++; 
                  }//End of for loop

//          Case1:if current dominates new
//----------------------------------------------------------------------------------------------------------
                  if(count1==amosaParams->i_no_offunc)
                  {
#ifdef DEBUG
                    printf("\n Current sol dominates New sol");
#endif
                    deldom=0.0;
                    amount=find_unsign_dom(func_current,func_new, amosaParams);

                    deldom=deldom+amount;
                    for(i=0;i<amosaParams->i_archivesize;i++)
                    {
                     count=1;
                     if(flag==0 || i!=r)
                     {
                      isdom=is_dominated(amosaParams->d_func_archive[i],func_new, amosaParams);

                      if(isdom==1)
                      {
                        count= count+1;
                        amount=find_unsign_dom(amosaParams->d_func_archive[i],func_new, amosaParams);
                        deldom=deldom+amount;
                             }//End of inner if
                          }//End of outer if
                      }//End of for loop
                     p=1.0/(1.0+exp(deldom/(t)));// The probability of Case 1

                     ran2=(rand()/(RAND_MAX+1.0)); 

                     if(p>=ran2)
                     {
                       for(f=0;f<amosaParams->i_totalno_var;f++)
                         current[f]=newsol[f];
                       for(h=0;h<amosaParams->i_no_offunc;h++)
                         func_current[h]=func_new[h];
                       flag=0;
                        }//End of if
                      }

// End of Case1
//----------------------------------------------------------------------------------------------------------


          //Case 3: if new sol dominates the current solution

//------------------------------------------------------------------------------------------------------------------


                      else if(count2==amosaParams->i_no_offunc)
                      {
                        k=0;count=0;
                        deldom=1000000;
                        printf("\n New  sol dominates current sol");

                        for(i=0;i<amosaParams->i_archivesize;i++)
                        {
                          isdom=is_dominated(amosaParams->d_func_archive[i],func_new, amosaParams);
                          if(isdom==1)
                          {
                            count=count+1;
                            amount=find_unsign_dom(amosaParams->d_func_archive[i],func_new, amosaParams);
                            if(amount<deldom)
                            {
                             deldom=amount;
                             k=i;
                            }//End of if
                       }//End of outer if
                    }//End of for loop

// Case3(a):If new point is dominated by k(k>=1) solutions in the archive

//-------------------------------------------------------------------------------------------------------		
                    if(count>0)
                    {

                   	p=1.0/(1.0+exp(-deldom));// The probability of case 3(a)

                   	ran2=(rand()/(RAND_MAX+1.0));

//Case3(a)1:Set point of the archive corresponds to deldom as current point with probability=p

//---------------------------------------------------------------------------------------------------------------

                   	if(p>=ran2)
                   	{

                      for(h=0;h<amosaParams->i_totalno_var;h++)
                      {
                        current[h]=amosaParams->d_archive[k][h];

                      		}//End of for loop
                          for(h=0;h<amosaParams->i_no_offunc;h++)
                          {
                           func_current[h]=amosaParams->d_func_archive[k][h];
                     		}//End of for loop
                     		flag=1;
                     		pos=k;
                       }


//End of case3(a)1:
//----------------------------------------------------------------------------------------------------------

//Case3(a)2: Set new point as current point


//-----------------------------------------------------------------------------------------------------------------


                       else
                       {
                         for(f=0;f<amosaParams->i_totalno_var;f++)
                           current[f]=newsol[f];
                         for(h=0;h<amosaParams->i_no_offunc;h++)
                          func_current[h]=func_new[h]; 
                        flag=0;
                      }

//End of case3(a)2:
//---------------------------------------------------------------------------------------------------------------

                    }

//End of case3(a):
//-----------------------------------------------------------------------------------------------------------------

// Case3(b): New point is non-dominating with respect to the point in the archive

//-----------------------------------------------------------------------------------------------------------------

            else if(count==0 && duplicate==0)  /* no sol in archive dominates current*/
                    {

                 if(flag==1) /* if current resides in archivehieve then remove that point */
                     {
                       for(i=pos;i<amosaParams->i_archivesize-1;i++)
                       {
                        for(h=0;h<amosaParams->i_no_offunc;h++)
                        {
                         amosaParams->d_func_archive[i][h]=amosaParams->d_func_archive[i+1][h];
                           }//End of inner for loop
                           for(h=0;h<amosaParams->i_totalno_var;h++)
                           {
                            amosaParams->d_archive[i][h]=amosaParams->d_archive[i+1][h];
                               }//End of second inner for loop
                           }//End of outer for loop
                           amosaParams->i_archivesize=amosaParams->i_archivesize-1;
                       }//End of if

                       for(i=0;i<amosaParams->i_archivesize;i++)
                       {
                         for(h=0;h<amosaParams->i_no_offunc;h++)
                         {
                          area2[i][h]=amosaParams->d_func_archive[i][h];
                        }//End of inner for loop
                        for(h=0;h<amosaParams->i_totalno_var;h++)
                        {
                         archive1[i][h]=amosaParams->d_archive[i][h];                                  
                          }//End of second inner for loop

                      }//End of outer for loop
                   k=0;  /* if newsol dominates some other sols in archivehieve
                         then remove all those*/
                   h=0;	 
                   for(i=0;i<amosaParams->i_archivesize;i++)
                   {
                     isdom=is_dominated(func_new,area2[i], amosaParams);
                     if(isdom==1)
                     {
                       k++;
                         }//End of if
                         else
                         {

                          for(n=0;n<amosaParams->i_no_offunc;n++)
                            amosaParams->d_func_archive[h][n]=area2[i][n];
                          for(n=0;n<amosaParams->i_totalno_var;n++)
                          {
                            amosaParams->d_archive[h][n]=archive1[i][n];
                               }//End of for loop
                               h++;
                        }//End of else
                     }//End of outer for loop

                     if(k>0)
                     {
                       amosaParams->i_archivesize=h;
                    }//End of if

                    amosaParams->i_archivesize++;

                    m=amosaParams->i_archivesize-1;
                    for(l=0;l<amosaParams->i_totalno_var;l++)
                    {
                     amosaParams->d_archive[m][l]=newsol[l];
                     }//End of for loop
                     for(l=0;l<amosaParams->i_no_offunc;l++)
                     {
                       amosaParams->d_func_archive[m][l]=func_new[l];
                    }//End of for loop

                  if(amosaParams->i_archivesize>amosaParams->i_softl) /* If archive size exceeds soft limit then 
					   clustering is needed*/
                    clustering(amosaParams);

                  for(f=0;f<amosaParams->i_totalno_var;f++)
                   current[f]=newsol[f];
                 for(f=0;f<amosaParams->i_no_offunc;f++)
                 {
                   func_current[f]=func_new[f];
                    }//End of for loop
                    flag=1;
                    pos=m;
                  } 

// End of case3(b)
//------------------------------------------------------------------------------------------------------------------------

                } 

//End of case3
//----------------------------------------------------------------------------------------------------------------

//Case 2: Current point and new point are non-dominating to each-other

//-----------------------------------------------------------------------------------------------------------------------------------

                else 
                {
#ifdef DEBUG
                 printf("\n\n Current sol and new sol are nondominating to each other ");
#endif
                 count=0; deldom=0.0;

                 for(i=0;i<amosaParams->i_archivesize;i++)
                 {
                    /* count total no of solution that dominates new sol*/
                  isdom=is_dominated(amosaParams->d_func_archive[i],func_new, amosaParams);
                  if(isdom==1)
                  {                               
                   count= count+1;
                   amount=find_unsign_dom(amosaParams->d_func_archive[i],func_new, amosaParams);
                   deldom=deldom+amount;
                        }// End of if
                    }// End of for loop


//---------------------------------------------------------------------------------------------------------------------------------------

//Case 2(a): New point is dominated by k(k>=1) point in the archive

//-----------------------------------------------------------------------------------------------------------------------------------------------

                    if(count>0)
                    {
                      p=1.0/(1.0+exp(deldom/(t)));// The probability of case 2(a)
                      ran2=(rand()/(RAND_MAX+1.0));
                      printf("\n p=%lf",p);
                      if(p>=ran2)
                      {
                        for(f=0;f<amosaParams->i_totalno_var;f++)
                         current[f]=newsol[f];
                       for(f=0;f<amosaParams->i_no_offunc;f++)
                       {
                        func_current[f]=func_new[f];
                             }// End of for loop
                             flag=0;
                          }// End of if 
                        }


// End of case 2(a):
//----------------------------------------------------------------------------------------------------------------------------------------------------------


// Case 2(b):New point is non-dominating with respect to all the points in the archive

//----------------------------------------------------------------------------------------------------------------------------------------------------------------



                        else if(count==0 ) 
                        {

                         for(i=0;i<amosaParams->i_archivesize;i++)
                         {
                           for(h=0;h<amosaParams->i_no_offunc;h++)
                             area2[i][h]=amosaParams->d_func_archive[i][h];
                           for(h=0;h<amosaParams->i_totalno_var;h++)
                           {
                             archive1[i][h]=amosaParams->d_archive[i][h];

                               }//End of inner for loop

                           }//End of outer for loop

                           k=0;
                           h=0;
                           for(i=0;i<amosaParams->i_archivesize;i++)
                           {
                            isdom=is_dominated(func_new,area2[i], amosaParams);
                            if(isdom==1)
                            {
                             k++;
                               }//End of if
                               else
                               {
                                for(n=0;n<amosaParams->i_no_offunc;n++)
                                  amosaParams->d_func_archive[h][n]=area2[i][n];
                                for(n=0;n<amosaParams->i_totalno_var;n++)
                                {
                                 amosaParams->d_archive[h][n]=archive1[i][n];


                                      }//End of inner for loop
                                      h++;
                                }//End of else
                           }//End of outer for loop

                           if(k>0)
                           {
                             amosaParams->i_archivesize=h;
                           }//End of if

                           amosaParams->i_archivesize++;

                           m=amosaParams->i_archivesize-1;

                           for(l=0;l<amosaParams->i_totalno_var;l++)
                           {
                            amosaParams->d_archive[m][l]=newsol[l];
                            }//End of for loop
                            for(l=0;l<amosaParams->i_no_offunc;l++)
                            {
                             amosaParams->d_func_archive[m][l]=func_new[l];
                            }//End of for loop

#ifdef DEBUG
                            printf("\n amosaParams->i_archivesize=%d",amosaParams->i_archivesize); 
#endif


                         if(amosaParams->i_archivesize>amosaParams->i_softl)// If amosaParams->i_archivesize increases from soft limit 							clustering is required
                         {
                          clustering(amosaParams);
                            }//End of if
#ifdef DEBUG
                            printf("\n amosaParams->i_archivesize=%d",amosaParams->i_archivesize);    
#endif
                            for(f=0;f<amosaParams->i_totalno_var;f++)
                             current[f]=newsol[f];
                           for(f=0;f<amosaParams->i_no_offunc;f++)
                             func_current[f]=func_new[f];
                           flag=1;
                           pos=m;
                         }



// End of case 2(b):
//-----------------------------------------------------------------------------------------------------------------------------------------------------

                       }


// End of case 2:
//----------------------------------------------------------------------------------------------------------------------------------------------------------------


                     }


// End of for loop :for(i=0;i<amosaParams->i_no_ofiter;i++)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------


                   }


// End of for loop :for(temp=amosaParams->d_tmax,;temp>amosaParams->d_tmin;temp*=amosaParams->d_alpha)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Open the file to store the resulting point (i.e the parato optimal font)

                   fp=fopen("saplot.out","w+");

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                   for(i=0;i<amosaParams->i_archivesize;i++)
                   {
                    fprintf(fp,"\n");
                    for(h=0;h<amosaParams->i_no_offunc;h++)
                      fprintf(fp,"%f\t",amosaParams->d_func_archive[i][h]);

    }//End of for loop

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  

// End of mainprocess

  } 

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

