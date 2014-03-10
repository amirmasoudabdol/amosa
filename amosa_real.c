/* 	AMOSA: archived Multi Objective Simulated Annealing 		*/



// Importing the test problems
#include "test_func.h"

// Declaring User Defined Header Files.
#include "amosa.h"

#include "number_of_variable.h"
#include "evaluate.h"
#include "number_of_functions.h"
#include "clustering.h"
#include "real_mutate_ind.h"
#include "init_sol.h"
#include "dominance.h"
#include "main_process.h"
#include "creating_archive.h"
#include "burn_in_period.h"

AMOSAType amosaParams;
time_t t1, t2;


/* Initialize the parmaters and read the inputs */
void InitAMOSA(AMOSAType *amosaParams){
  int i;
  (void) time (&t1);    /* time() gives the current time, in seconds, elapsed since 00:00:00 GMT, January
                           1, 1970. It stores that value in the location *t1, provided that t1 is
                           not a null pointer. */



  amosaParams->i_hillclimb_no = 20;		/* setting hill climd number to 10 */
  amosaParams->d_solution = (double **) malloc (amosaParams->i_softl * sizeof (double *));	/* memory allocation for storing solution in a variable named solution. */
  for (i = 0; i < amosaParams->i_softl; i++)
    amosaParams->d_solution[i] = (double *) malloc (amosaParams->i_totalno_var * sizeof (double));

  amosaParams->d_archive = (double **) malloc ((amosaParams->i_softl + 3) * sizeof (double *));	/* memory allocation for archive */
  for (i = 0; i < (amosaParams->i_softl + 3); i++)
  	amosaParams->d_archive[i] = (double *) malloc (amosaParams->i_totalno_var * sizeof (double));

  amosaParams->d_min_real_var = (double *) malloc (amosaParams->i_totalno_var * sizeof (double));	/* memory allocation to store the minimum value of real variables in the functions */
  if (amosaParams->d_min_real_var == NULL){/* if there is any allocation error then report it and exit */
      printf ("\n Error in allocation");
      exit (1);
    }

  amosaParams->d_max_real_var = (double *) malloc (amosaParams->i_totalno_var * sizeof (double));	/* memory allocation to store the maximum value of real variables in the functions */
  if (amosaParams->d_max_real_var == NULL){/* if there is any allocation error then report it and exit */
      printf ("\n Error in allocation");
      exit (1);
    }
  
  for (i = 0; i < amosaParams->i_totalno_var; i++){
      printf ("\n Enter minimum value of real-variable %d: ", i);
      scanf ("%lf", &amosaParams->d_min_real_var[i]);
      printf ("Enter maximum value of real-variable %d: ", i);
      scanf ("%lf", &amosaParams->d_max_real_var[i]);
      // amosaParams->d_min_real_var[i]=0;
      // amosaParams->d_max_real_var[i]=1;
    }
    printf("\n");

  amosaParams->d_func_archive = (double **) malloc ((amosaParams->i_softl + 3) * sizeof (double *));	/* allocating memory for func_archive */
  for (i = 0; i < (amosaParams->i_softl + 3); i++)
    amosaParams->d_func_archive[i] = (double *) malloc (amosaParams->i_no_offunc * sizeof (double));
  amosaParams->d_eval = (double *) malloc (amosaParams->i_no_offunc * sizeof (double));

  initialize_sol (amosaParams);		/* Initializing the archive by calling this function */
  creating_archive (amosaParams);		/* Creation the archive */
//      burn_in_period();   /* Computing maximum temperature(declared as amosaParams->d_tmax) using burn in period */


}

void ReadParameters(int argc, char *argv[], AMOSAType *amosaParams){
  amosaParams->d_tmax = 100.;

  int i;

  if (argc != 2){   /* Checks whether the command given to run the program is wrong or not */
      printf ("\n Wrong Usages");
      printf ("\n It should be ./amosa problem\n \n");
      exit (1);
    }

  printf("%s\n", argv[1]);
  sprintf (amosaParams->c_problem, "%s", argv[1]);
  printf ("\n %s ", amosaParams->c_problem);

  amosaParams->i_no_offunc = number_of_functions(amosaParams);
  printf ("\nNumber of functions in %s is %d", amosaParams->c_problem, amosaParams->i_no_offunc);

  printf ("\n Give me the values of Hard-limit and Soft-limit: ");
  scanf ("%d %d", &amosaParams->i_hardl, &amosaParams->i_softl);
  // printf ("\n softl=%d", amosaParams->i_softl);

  amosaParams->i_no_ofiter = 500;     /* number of iterations per temperature i sset to 100 */
  amosaParams->d_tmin      = 0.0000025;   /* the minimum temperature is set to 0.0000025 */

  amosaParams->d_func_range = (double *) malloc (amosaParams->i_no_offunc * sizeof (double)); /* dynamically allocating memory to store the functional values of the archive solutions */
  for (i = 0; i < amosaParams->i_no_offunc; i++){
      printf ("\n Enter range of %d th function: ", (i + 1));
      scanf ("%lf", &amosaParams->d_func_range[i]);
  }

  printf ("\n Enter the value of cooling rate: ");
  scanf ("%lf", &amosaParams->d_alpha);

  amosaParams->i_totalno_var = number_of_variable(amosaParams);
  printf ("\n Total number of variables in %s is %d", amosaParams->c_problem, amosaParams->i_totalno_var);

  amosaParams->seed = 67644288;
  srand (amosaParams->seed);
}


int
main (int argc, char *argv[])
{
  ReadParameters(argc, argv, &amosaParams);
	InitAMOSA(&amosaParams);

  RunAMOSA (&amosaParams);     /* calling mainprocess() which runs the main algorithm proposed in AMOSA */
  (void) time (&t2);    /* time() gives the current time, in seconds, elapsed since 00:00:00 GMT, January
                  1, 1970. It stores that value in the location *t2, provided that t2 is
                  not a null pointer. */

  printf ("\n Total number of iterations: %d", amosaParams.i_no_ofiter );
  printf ("\n Total time needed=%d", (int) (t2 - t1));  /* Displaying the time taken to run the AMOSA process */
  printf ("\n Total processor time taken by a program is=%f", (float) (clock () / CLOCKS_PER_SEC)); /* Displaying the number of clock ticks since program start */
  // return 0;

}
