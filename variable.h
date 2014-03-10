//Declaring Constants.

#define PI 3.1415927
#define TRUE 1
#define FALSE 0

//Declaring Global Variables.

int i_hardl,            /* Hardlimit of the archive */
    i_softl,	          /* Softlimit of the archive */
    i_no_ofiter,        /* Number of iteration per temperature */
    i_hillclimb_no,     /* Total number of hill_climbing number */
    i_maxno_bit,        /* maximum number of bits used to encode one variable */
    i_arrsize, 	        /* Total length of each string */
    i_totalno_var,      /* Total number of variable of the functions */
    i_archivesize,      /* Stores the archive size*/
    i_no_offunc;        /* Number of function */


long l_seed; 	           /* seed for random number generation */


char c_problem[50];       /* function name to be optimized */


double d_tmax,             /* maximum temperature */
       d_tmin,             /* minimum temperature*/
       d_alpha,            /* cooling rate*/
       **d_solution,       /* data structure corresponding to binary strings*/
       **d_archive,        /* archive */
       **d_func_archive,   /* variable to store the functional values of the archive solutions */
       *d_eval,		         /* */
       *d_func_range,      /* range of the functions */
       *d_min_real_var,    /* Store minimum value of the real variables*/
       *d_max_real_var;    /* Store maximum value of the real variables*/
