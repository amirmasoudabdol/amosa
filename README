# About this version

This version is a _Refactored_ version of the original AMOSA code in order to make the code structure more portable. Several changes have been made:

1. The `AMOSAType` type has been defined in order to encapsulate all the necessary parameters of the AMOSA. This will reduce the number of _external_ variables, in addition, it will reduce the possible conflict when it uses within another routine.
2. The `amosaParams` type which defines in the `amosa_real.c` will pass to all the functions during the process.
3. Functions name are changed for clarification
    - `ReadParameters` reads the commands lines and write the problem dependents variables in `amosaParams`.
    - `InitAMOSA` initializes all the variables
    - `RunAMOSA` starts the optimization 

#### In order to optimize your problem, follow this instructions

1. Define a new _objective function_ and make it accessible to other files.
2. Modify the `number_of_variables` and `number_of_functions` functions to return the correct number of variables and objectives. Or rewrite the `ReadParamters` to read the inputs from your problem configuration file.
3. Initialize the algorithm variables.
4. Consider defining a new type to carry your problem parameters which are necessary for computing your objective function; however, you could either rewrite the `main_process` and other function to work with your type or provide a `double *s` to AMOSA native functions which will then automatically update in each iteration.
5. Run the algorithm.
6. Write a `ReportResult` (optional)

# About the Algorithm

The real-coded _Archived Multi Objective Simulated Annealing (AMOSA)_ is introduced and develop by the writers of the following paper:

- Authors: Sanghamitra Bandyopadhyay, Sriparna Saha, Ujjwal Maulik and Kalyanmoy Deb.
- Paper Title: A Simulated Annealing Based Multi-objective Optimization Algorithm: AMOSA
- Journal: IEEE Transaction on Evolutionary Computation, Volume 12, No. 3, JUNE 2008, Pages 269-283.

The original code is available for the download from Sriparna Saha's website at: http://www.isical.ac.in/~sriparna_r

**Please contact the authors if you have any comments, suggestions or questions about this file or _Archived Multi-objective Genetic Algorithm (AMOSA)_** via: sriparna_r@isical.ac.in/sanghami@isical.ac.in/  

# How to Compile and Run

To compile, just run:
    `make`

Run the program as:
     `./amosa problem`

For instance if you want to run ZDT1 function then write in the terminal as 
- ./amosa ZDT1

The Output functional values will be in "saplot.out".

To plot the curve of Pareto Optimal font, Here is the steps

    Step 1: Open terminal
	   Step 2: Type gnuplot
		  Step 3: Type plot "saplot.out"`			

