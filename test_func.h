#include <math.h>
#include <malloc.h>
#include "amosa.h"

void DTLZ1(double *s, AMOSAType *amosaParams)
 {
   int i;
   int k;
   int mul;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

  double sum = 0;
 
  double g;
 

 //set paramaters to zero
  for (i = 0; i <amosaParams->i_totalno_var ; i++)
    var[i] = s[i];
  
      for(k=2;k<amosaParams->i_totalno_var;k++)
        {
	  sum=sum+pow((var[k]-0.5),2)-cos(20*PI*(var[k]-0.5));
	}
      g=100*(5+sum);
      amosaParams->d_eval[0]=0.5*var[0]*var[1]*(1+g);
      amosaParams->d_eval[1]=0.5*var[0]*(1-var[1])*(1+g);
      amosaParams->d_eval[2]=0.5*(1-var[0])*(1+g);	 
 
  return ;
 } 


void DTLZ110(double *s, AMOSAType *amosaParams)
{
    int i, j,k;
    int mul;
    double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

    double sum = 0;
    double f1, f2, g, h,f3;

    //set paramaters to zero
    for (i = 0; i < amosaParams->i_totalno_var; i++)
        var[i] = s[i];

    sum=0;
    for(k=9;k<14;k++)
    {
        sum=sum+pow((var[k]-0.5),2)-cos(20*PI*(var[k]-0.5));
    }
    g=100.0*(5.0+sum);
    amosaParams->d_eval[0]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*(1+g);
    amosaParams->d_eval[1]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*(1-var[8])*(1+g);
    amosaParams->d_eval[2]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*(1-var[7])*(1+g); 
    amosaParams->d_eval[3]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*(1-var[6])*(1+g);	 
    amosaParams->d_eval[4]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*(1-var[5])*(1+g);
    amosaParams->d_eval[5]=0.5*var[0]*var[1]*var[2]*var[3]*(1-var[4])*(1+g);
    amosaParams->d_eval[6]=0.5*var[0]*var[1]*var[2]*(1-var[3])*(1+g);
    amosaParams->d_eval[7]=0.5*var[0]*var[1]*(1-var[2])*(1+g);
    amosaParams->d_eval[8]=0.5*var[0]*(1-var[1])*(1+g);
    amosaParams->d_eval[9]=0.5*(1-var[0])*(1+g);
    return ;
} 

void DTLZ115(double *s, AMOSAType *amosaParams)
 {
   int i, j,k;
   int mul;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

  double sum = 0;
  double f1, f2, g, h,f3;

  //set paramaters to zero
  for (i = 0; i < amosaParams->i_totalno_var; i++)
      var[i] = s[i];

 
  sum=0;
  for(k=14;k<19;k++)
      sum=sum+pow((var[k]-0.5),2)-cos(20*PI*(var[k]-0.5));
	
  g=100.0*(5.0+sum);
        amosaParams->d_eval[0]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*var[9]*var[10]*var[11]*var[12]*var[13]*(1+g);
     amosaParams->d_eval[1]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*var[9]*var[10]*var[11]*var[12]*(1-var[13])*(1+g);
      amosaParams->d_eval[2]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*var[9]*var[10]*var[11]*(1-var[12])*(1+g);
      amosaParams->d_eval[3]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*var[9]*var[10]*(1-var[11])*(1+g);
      amosaParams->d_eval[4]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*var[9]*(1-var[10])*(1+g);
      amosaParams->d_eval[5]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*var[8]*(1-var[9])*(1+g);
      amosaParams->d_eval[6]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*var[7]*(1-var[8])*(1+g);
      amosaParams->d_eval[7]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*var[6]*(1-var[7])*(1+g); 
      amosaParams->d_eval[8]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*var[5]*(1-var[6])*(1+g);	 
      amosaParams->d_eval[9]=0.5*var[0]*var[1]*var[2]*var[3]*var[4]*(1-var[5])*(1+g);
      amosaParams->d_eval[10]=0.5*var[0]*var[1]*var[2]*var[3]*(1-var[4])*(1+g);
      amosaParams->d_eval[11]=0.5*var[0]*var[1]*var[2]*(1-var[3])*(1+g);
      amosaParams->d_eval[12]=0.5*var[0]*var[1]*(1-var[2])*(1+g);
      amosaParams->d_eval[13]=0.5*var[0]*(1-var[1])*(1+g);
      amosaParams->d_eval[14]=0.5*(1-var[0])*(1+g);
  return ;
 } 


void DTLZ15(double *s, AMOSAType *amosaParams)
 {
   int i, k;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

   double sum = 0;
   double f1, f2, g, h,f3;

   //set paramaters to zero
   for (i = 0; i < amosaParams->i_totalno_var; i++)
      var[i] = s[i];
   sum=0;
   for(k=4;k<9;k++)
      sum=sum+pow((var[k]-0.5),2)-cos(20*PI*(var[k]-0.5));
	
   g=100.0*(5.0+sum);
   amosaParams->d_eval[0]=0.5*var[0]*var[1]*var[2]*var[3]*(1+g);
   amosaParams->d_eval[1]=0.5*var[0]*var[1]*var[2]*(1-var[3])*(1+g);
   amosaParams->d_eval[2]=0.5*var[0]*var[1]*(1-var[2])*(1+g);
   amosaParams->d_eval[3]=0.5*var[0]*(1-var[1])*(1+g);	 
   amosaParams->d_eval[4]=0.5*(1-var[0])*(1+g);
   return ;
 } 

 void DTLZ2(double *s, AMOSAType *amosaParams)
 {
   int i;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

  
  double f1;
  double f2;
  double g;
  double f3;

 //set paramaters to zero
  for (i = 0; i < amosaParams->i_totalno_var; i++)
    var[i] = s[i];
  g=0;
  for(i=2;i<12;i++)
    g=g+pow((var[i]-0.5),2);
     
  f1 = (1+g)*cos(PI*var[0]*0.5)*cos(PI*var[1]*0.5);
  f2 = (1+g)*cos(PI*var[0]*0.5)*sin(PI*var[1]*0.5);
  f3=(1+g)*sin(0.5*var[0]*PI);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  amosaParams->d_eval[2]=f3;
  return ;
 } 



void DTLZ24(double *s, AMOSAType *amosaParams)
 {
   int i, j;
   int mul;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);

  
  double f1, f2, g, h,f3,f4;

 //set paramaters to zero
  for (i = 0; i < amosaParams->i_totalno_var; i++)
    var[i] = s[i];

 
  g=0;
  for(i=3;i<13;i++)
    g=g+pow((var[i]-0.5),2);
     
  f1 = (1+g)*cos(PI*var[0]*0.5)*cos(PI*var[1]*0.5)*cos(PI*var[2]*0.5);
  f2 = (1+g)*cos(PI*var[0]*0.5)*cos(PI*var[1]*0.5)*sin(PI*var[2]*0.5);
  f3=(1+g)*cos(PI*var[0]*0.5)*sin(PI*var[1]*0.5);
  f4=(1+g)*sin(0.5*var[0]*PI);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  amosaParams->d_eval[2]=f3;
  amosaParams->d_eval[3]=f4;
  return ;
 } 

void DTLZ3(double *s, AMOSAType *amosaParams)
 {
   int i;
   int mul;
   double f1;
   double f2;
   double g;
   double f3;
   

    
  for(i=2;i<12;i++)
  {
    g=g+pow((s[i]-0.5),2)-cos(20*PI*(s[i]-0.5));
   } 
  g=100*(10+g);    

  f1 = (1+g)*cos(PI*s[0]*0.5)*cos(PI*s[1]*0.5);
  f2 = (1+g)*cos(PI*s[0]*0.5)*sin(PI*s[1]*0.5);
  f3=(1+g)*sin(0.5*s[0]*PI);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  amosaParams->d_eval[2]=f3;
  for(i=0;i<amosaParams->i_no_offunc;i++)
    {
     if(amosaParams->d_eval[i]<0)
     {
       printf("\n amosaParams->d_eval=%lf",amosaParams->d_eval[i]);
       getchar();
      } 
    } 
  return ;
 } 

void DTLZ4(double *s, AMOSAType *amosaParams)
 {
   int i;
   int mul;
  double f1;
  double f2;
  double g;
  double f3;
  double sum;


  g=0;
  
  for(i=2;i<12;i++)
  {
    g=g+pow((s[i]-0.5),2);
   } 
    
  f1 = (1+g)*cos(PI*pow(s[0],100)*0.5)*cos(PI*pow(s[1],100)*0.5);
  f2 = (1+g)*cos(PI*pow(s[0],100)*0.5)*sin(PI*pow(s[1],100)*0.5);
  f3=(1+g)*sin(0.5*pow(s[0],100)*PI);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  amosaParams->d_eval[2]=f3;
  return ;
 }  


void DTLZ5(double *s, AMOSAType *amosaParams)
 {
   int i;
   int mul;
   double *var=(double *)malloc(sizeof(double)*amosaParams->i_totalno_var);
   double *theta=(double *)malloc(amosaParams->i_totalno_var*sizeof(double));
  
  double f1, f2, g, h,f3;

  //set paramaters to zero
  for (i = 0; i < amosaParams->i_totalno_var; i++)
   {
    var[i] = s[i];
    theta[i]=0;
    }

  
  g=0;
  for(i=2;i<12;i++)
    g=g+pow((var[i]-0.5),2);
  
  theta[1]=(PI*(1+2*g*var[1]))/(4*(1+g));
  theta[0]=var[0];
        
  f1 = (1+g)*cos(PI*theta[0]*0.5)*cos(theta[1]);
  f2 = (1+g)*cos(PI*theta[0]*0.5)*sin(theta[1]);
  f3=(1+g)*sin(0.5*theta[0]*PI);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  amosaParams->d_eval[2]=f3;
  return ;
 }  



void DTLZ7(double *s, AMOSAType *amosaParams)
 {
   int i;
   double  *func,g, h,f3,sum;

   func=(double *)malloc(amosaParams->i_no_offunc*sizeof(double));   
 
   for(i=0;i<(amosaParams->i_no_offunc-1);i++)
     func[i]=s[i];
        
   sum=0;
   for(i=2;i<22;i++)
      sum=sum+s[i];
   g=(9.0*sum)/20.0;
   sum=0;
   for(i=0;i<(amosaParams->i_no_offunc-1);i++)
     sum=sum+ (func[i]*(1+sin(3*PI*func[i])))/(1+g);
   h=amosaParams->i_no_offunc-sum;  
   func[2]=(1+g)*h;
   amosaParams->d_eval[0]=func[0];
   amosaParams->d_eval[1]=func[1];
   amosaParams->d_eval[2]=func[2];
   return ;
 }  

void Dev1(double *s, AMOSAType *amosaParams)
 {
     double func2,func1;
     func1=s[0];
     func2=2.0-exp(-pow(((s[1]-0.2)/0.004),2))-0.8*exp(-pow(((s[1]-0.6)/0.4),2));
     func2=func2/s[0];
     amosaParams->d_eval[0]=func1;
     amosaParams->d_eval[1]=func2;
     return;
   }  
 
     

void Dev2(double *s, AMOSAType *amosaParams)
{
  int i;
  int total_sub=4;
  int *length;
  int j;
  int *val;
  int count=0;
  int *fung;
  int sum;
  double f1;
  double f2;
  length=(int *)malloc(total_sub*sizeof(int));
  length[0]=10;
  length[1]=5;
  length[2]=5;
  length[3]=5;
  val=(int *)malloc(total_sub*sizeof(int));
  fung=(int *)malloc((total_sub-1)*sizeof(int));
  for(i=0;i<total_sub;i++)
   {
    val[i]=0;
   }
  for(i=0;i<(total_sub-1);i++)
   {
    fung[i]=0;
   }
  for(i=0;i<total_sub;i++)
   {
    if(i!=0)
     { 
       sum=0;
       for(j=0;j<i;j++)
        {
          sum=sum+length[j];
         }
      }
     else sum=0;
     for(j=0;j<length[i];j++)
      {
       if(s[sum+j]==1) 
	val[i]++;
      }
   }
  sum=0;
  for(i=1;i<total_sub;i++)
   {
     if(val[i]<length[i])
       {
         fung[i-1]=2+val[i];
       }
     else if(val[i]==length[i])
            fung[i-1]=1;
     sum=sum+fung[i-1];
   }
  f1=1+val[0];
  f2=(sum/f1);
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return;
  
 }   

void Dev3(double *s, AMOSAType *amosaParams)
{
  
  int i;
  double *var;
  double sum = 0;
  double f1; 
  double f2;
  double g;
  double h;
  double alpha;

 f1 =4*s[0];
 if(var[1]<0.4)
   {
    g=4-3*exp(pow((-(s[1]-0.2)/0.02),2));
   }
  else 
   {
    g=4-2*exp(pow((-(s[1]-0.7)/0.2),2));
   }
  alpha=0.25+3.75*(g-1)/(2-1);
  if(f1<=g) 
  h=1-pow((f1/g),alpha);
  else h=0;
  f2=g*h;
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return;

}

void Dev4(double *s, AMOSAType *amosaParams)
{
  
  int i;
  double sum = 0;
  double f1;
  double f2;
  double g;
  double h;

  f1 =s[0];
  g=1+10*s[1];
  h=1-pow((f1/g),2)-(f1/g)*sin(2*3.14*4*f1);
  f2=g*h;
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return;

}

void SCH1(double *s, AMOSAType *amosaParams)
 {
    double value;
	
	double func1,func2;
   
    value     = s[0];
    func1     = value*value;
    func2     = (value-2.0)*(value-2.0);
    amosaParams->d_eval[0] = func1;
    amosaParams->d_eval[1] = func2;
    return;
 } 

void SCH2(double *s, AMOSAType *amosaParams)
 {
   double value;
   double func1,func2;
   value=s[0];
   if (value <= 1.0)
        func1 = -value;
   else if ((value>1.0)&&(value<=3.0))
       func1 = -2.0+value;
   else if ((value>3.0)&&(value<=4.0))
        func1 = 4.0-value;
   else
        func1 = -4.0+value;
   func2= (value-5.0)*(value-5.0);
   amosaParams->d_eval[0]=func1;
   amosaParams->d_eval[1]=func2;
   return;
 }  

void ZDT1(double *s, AMOSAType *amosaParams)
 {
   int i;
   double sum = 0;
   double f1, f2, g, h;
   f1 = s[0];
   for (i = 1; i < amosaParams->i_totalno_var ; i++)
	sum += s[i];
   g = 1 + (9*sum)/29.0;
   h = 1 - sqrt(f1/g);
   f2 = g*h;
   amosaParams->d_eval[0]=f1;
   amosaParams->d_eval[1]=f2;
   return ;
 }


void ZDT2(double *s, AMOSAType *amosaParams)
 {
  int i;
  double sum = 0;
  double f1, f2, g, h;

  f1 = s[0];
  for (i = 1; i < amosaParams->i_totalno_var ; i++)
	sum += s[i];
  g = 1 + (9*sum)/29.0;
  h = 1 - pow((f1/g),2);
  f2 = g*h;
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return;
  }


void ZDT3(double *s, AMOSAType *amosaParams)
 {
  int i, j;
  int mul;
  double sum = 0;
  double f1, f2, g, h;
  f1 = s[0];
  for (i = 1; i < amosaParams->i_totalno_var; i++)
	sum += s[i];
  g = 1 + (9*sum)/29.0;
  h = 1 - sqrt(f1/g)-(f1/g)*(sin(10*3.14*f1));
  f2 = g*h;
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return;
} 


void ZDT6(double *s, AMOSAType *amosaParams)
{
  int i;
  double sum = 0;
  double f1, f2, g, h;

  f1 =  1-exp(-4*s[0])*pow(sin((6*22*s[0])/7),6);
  for (i = 1; i < amosaParams->i_totalno_var; i++)
	sum += s[i];
  g = 1 + (9*pow((sum/9),0.25));
  h = 1 - pow((f1/g),2);
  f2 = g*h;
  amosaParams->d_eval[0]=f1;
  amosaParams->d_eval[1]=f2;
  return; 
}
