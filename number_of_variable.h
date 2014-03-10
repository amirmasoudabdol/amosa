#include "amosa.h"

int number_of_variable(AMOSAType *amosaParams)
{

    int value;	

     if (!strcmp(amosaParams->c_problem, "ZDT1"))
        value=30;
    else if(!strcmp(amosaParams->c_problem,"ZDT2"))
        value=30;
    else if(!strcmp(amosaParams->c_problem,"ZDT3"))
        value=30;
    else if(!strcmp(amosaParams->c_problem,"ZDT6"))
        value=10;
    else if(!strcmp(amosaParams->c_problem,"SCH1"))
        value=1;
     else if(!strcmp(amosaParams->c_problem,"SCH2"))
        value=1;
    else if(!strcmp(amosaParams->c_problem,"Dev1"))
        value=2;
    else if(!strcmp(amosaParams->c_problem,"Dev2")) 
        value=2;
    else if(!strcmp(amosaParams->c_problem,"Dev3")) 
        value=2;
    else if(!strcmp(amosaParams->c_problem,"Dev4")) 
        value=2;
    else if(!strcmp(amosaParams->c_problem,"DTLZ1"))
        value=7;
    else if(!strcmp(amosaParams->c_problem,"DTLZ2"))
        value=12;
    else if(!strcmp(amosaParams->c_problem,"DTLZ3"))
        value=12;
    else if(!strcmp(amosaParams->c_problem,"DTLZ4"))
        value=12;
    else if(!strcmp(amosaParams->c_problem,"DTLZ24"))
        value=13;
    else if(!strcmp(amosaParams->c_problem,"DTLZ5"))
        value=12;
    else if(!strcmp(amosaParams->c_problem,"DTLZ7"))
        value=22;
    else if (!strcmp(amosaParams->c_problem,"DTLZ15"))
        value=9;
    else if (!strcmp(amosaParams->c_problem,"DTLZ110"))
        value=14;
    else if (!strcmp(amosaParams->c_problem,"DTLZ115"))
        value=19;
    else
    {
        printf("Invalid argument for test amosaParams->c_problem given. Exiting.\n");
        exit(-1);
    }
    return value;        
}
