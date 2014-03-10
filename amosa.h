# ifndef AMOSA_INCLUDED
# define AMOSA_INCLUDED

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>

#define PI 3.1415927
#define TRUE 1
#define FALSE 0

typedef struct AMOSAType
{
	int i_hardl;				/* Hardlimit of the archive */
	int i_softl;				/* Softlimit of the archive */
	int i_no_ofiter;			/* Number of iteration per temperature */
	int i_hillclimb_no;			/* Total number of hill_climbing number */
	int i_maxno_bit;			/* maximum number of bits used to encode one variable */
	int i_arrsize;				/* Total length of each string */
	int i_totalno_var;			/* Total number of variable of the functions */
	int i_archivesize;			/* Stores the archive size */
	int i_no_offunc;			/* Number of function */

	long seed;					/* seed for random number generation */

	char c_problem[50];			/* function name to be optimized */

	double d_tmax;				/* maximum temperature */
	double d_tmin;				/* minimum temperature */
	double d_alpha;				/* cooling rate */
	double **d_solution;		/* data structure corresponding to binary strings */
	double **d_archive;			/* archive */
	double **d_func_archive;	/* variable to store the functional values of the archive solutions */
	double *d_eval; 			/* objectives function values*/
	double *d_func_range;		/* range of the functions */
	double *d_min_real_var;		/* Store minimum value of the real variables */
 	double *d_max_real_var;		/* Store maximum value of the real variables */
} AMOSAType;




# endif