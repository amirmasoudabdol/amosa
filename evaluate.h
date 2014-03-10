#include <stdlib.h>
#include <stdio.h>

#include "amosa.h"

void evaluate(double *s, AMOSAType *amosaParams)
{  
	if (!strcmp(amosaParams->c_problem, "ZDT1"))
		ZDT1(s, amosaParams);    
	else if(!strcmp(amosaParams->c_problem,"ZDT2"))
		ZDT2(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"ZDT3"))
		ZDT3(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"ZDT6"))
		ZDT6(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"SCH1"))
		SCH1(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"SCH2"))
		SCH2(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"Dev1"))
		Dev1(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"Dev2")) 
		Dev2(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"Dev3")) 
		Dev3(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"Dev4")) 
		Dev4(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ1"))
		DTLZ1(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ2"))
		DTLZ2(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ3"))
		DTLZ3(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ4"))
		DTLZ4(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ24"))
		DTLZ24(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ5"))
		DTLZ5(s, amosaParams);
	else if(!strcmp(amosaParams->c_problem,"DTLZ7"))
		DTLZ7(s, amosaParams);
	else if (!strcmp(amosaParams->c_problem,"DTLZ15"))
		DTLZ15(s, amosaParams);
	else if (!strcmp(amosaParams->c_problem,"DTLZ110"))
		DTLZ110(s, amosaParams);
	else if (!strcmp(amosaParams->c_problem,"DTLZ115"))
		DTLZ115(s, amosaParams);
	else
	{
		printf("Invalid argument for test amosaParams->c_problem given. Exiting.\n");
		exit(-1);
	}
}
