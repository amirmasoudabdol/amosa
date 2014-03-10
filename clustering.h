/* 	If the size of the archive is greater than Soft Limit (SL) then the clustering process is 		done to reduce the size of the archive to Hard Limit (HL).
-----------------------------------------------------------------------------------------------------

Here "Single Linkage Clustering" mechanism is used.

-----------------------------------------------------------------------------------------------------
*/


//-----------------------------------------------------------------------------------------------------	
//The function clustering clusters by "Single Linkage Clustering" mechanism.

//-------------------------------------------------------------------------------------------------------------------

///---------------C compiler's predefined header files---------------------------------------

#include <malloc.h>
#include <time.h>
#include <math.h>

#include "amosa.h"

///-------------------------------------------------------------------------------------------
void clustering(AMOSAType *amosaParams)
{

// variable declaration
//------------------------------------------------------------------------------------------------------	
  int    i;
  int    j;
  int    k;
  int    l;
  int    h;
  int    p;
  int    g2;
  int    g;
  int    pp;
  double **area2;
  int    *point1;
  int    *point2;
  int    u=0;
  int    v=0;
  int    w;
  int    m;
  double *dist;
  int    min; 
  double **distance;
  int    no_clus;
  int    *flag;
  int    *cluster;
  double **archive2;

//--------------------------------------------------------------------------------------------------------


// Body of the clustering function	

//---------------------------------------------------------------------------------------------------------
  no_clus=amosaParams->i_archivesize;
  cluster=(int *)malloc(sizeof(int)*(amosaParams->i_softl+1));	
  archive2=(double **)malloc((amosaParams->i_softl+2)*sizeof(double *));
  for(i=0;i<amosaParams->i_softl+2;i++)
    archive2[i]=(double *)malloc(amosaParams->i_totalno_var*sizeof(double));

  area2=(double **)malloc((amosaParams->i_softl+2)*sizeof(double));
  for(i=0;i<(amosaParams->i_softl+2);i++)
    area2[i]=(double *)malloc(amosaParams->i_no_offunc*sizeof(double)); 
  point1=(int *)malloc(sizeof(int)*(amosaParams->i_softl+1));
  point2=(int *)malloc(sizeof(int)*(amosaParams->i_softl+1));
  dist=(double *)malloc(sizeof(double)*amosaParams->i_softl);

  distance=(double **)malloc((amosaParams->i_softl+1)*sizeof(double *));
  k=amosaParams->i_archivesize;

#ifdef DEBUG  
  printf("\n IN CLUSTERING");
  printf("\n amosaParams->i_archivesize=%d",amosaParams->i_archivesize); 
#endif
  
  for(i=0;i<(amosaParams->i_softl+1);i++)
    distance[i]=(double *)malloc((amosaParams->i_softl+1)*sizeof(double));
  for(i=0;i<amosaParams->i_archivesize;i++)
    cluster[i]=i;
  for(i=0;i<k;i++)
  {
    distance[i][i]=2000000;
    for(j=i+1;j<k;j++)
    {
      distance[i][j]=0.0;
      for(p=0;p<amosaParams->i_no_offunc;p++)
      {
        distance[i][j]=distance[i][j]+pow((amosaParams->d_func_archive[i][p]-amosaParams->d_func_archive[j][p]),2);
      } 
      distance[j][i]=sqrt(distance[i][j]);
    }

  }


  flag=(int *)malloc((amosaParams->i_softl+1)*sizeof(int));
  while(no_clus>amosaParams->i_hardl)
  {
    min=2000000;
    for(i=0;i<amosaParams->i_archivesize;i++)
    {
      flag[i]=0;
    }
    for(i=0;i<k;i++)
    {
      for(j=0;j<k;j++)
      {
        if(j!=k)
        { 
          if(min>distance[i][j])
          {
            min=distance[i][j];
            u=i;
            v=j;
          }
        }
      }
    } 
    if(cluster[u]==u && cluster[v]==v)
    {        
      cluster[u]=v;
      cluster[v]=u;
    }
    else if(cluster[u]==u)
    {
      j=cluster[v];
      while(cluster[j]!=v)
      {
        j=cluster[j];
      }
      cluster[j]=u;
      cluster[u]=v;
    }
    else if(cluster[v]==v)
    {
      j=cluster[u];
      while(cluster[j]!=u)
      {
        j=cluster[j];
      }
      cluster[j]=v;
      cluster[v]=u;
    }
    else 
    {
      j=cluster[u];
      while(cluster[j]!=u)
      {
        j=cluster[j];
      }
      cluster[j]=v;
      p=cluster[v];
      while(cluster[p]!=v)
      {
        p=cluster[p];
      }
      cluster[p]=u;
    }
    no_clus=no_clus-1;
    g=0;
    point1[g]=u;
    j=cluster[u];
    while(j!=u)
    {
      g++;
      point1[g]=j;
      j=cluster[j];
    }
    for(i=0;i<=g;i++)
    {
      w=point1[i];
      flag[w]=1;
      for(j=i+1;j<=g;j++)
      {

        m=point1[j];
        flag[m]=1;
        distance[m][w]= distance[w][m]=2000000;

      }
    }
    for(i=0;i<amosaParams->i_archivesize;i++)
    {
      if(flag[i]==0)
      {  
        if(cluster[i]==i)
        {
          w=point1[0];
          min=distance[w][i];
          for(j=1;j<=g;j++)
          {
            m=point1[j];
            if(min>distance[m][i])
              min=distance[m][i];
          }
          for(j=0;j<=g;j++)
          {
            m=point1[j];
            distance[m][i]=min;
          }
          flag[i]=1;
        }
        else
        {
          g2=0;
          point2[g2]=i;j=cluster[i];
          while(j!=i)
          {
            g2++;
            point2[g2]=j;
            j=cluster[j];
          }
          w=point1[0];
          m=point2[0];
          min=distance[w][m];
          for(j=0;j<=g;j++)
          {
            w=point1[j];
            for(p=0;p<=g2;p++)
            {
              m=point2[p];
              if(min>distance[w][m])
                min=distance[w][m];
            }
          }
          for(j=0;j<=g;j++)
          {
            for(p=0;p<=g2;p++)
            {
              w=point1[j];
              m=point2[p];
              distance[m][w]=distance[w][m]=min;
              flag[m]=1;
            }
          }

        }                  
      }                            
    }
  }  
  for(i=0;i<amosaParams->i_archivesize;i++)
  {
    for(h=0;h<amosaParams->i_totalno_var;h++)
    {
      archive2[i][h]=amosaParams->d_archive[i][h];
    }
    for(h=0;h<amosaParams->i_no_offunc;h++)
    {
      area2[i][h]=amosaParams->d_func_archive[i][h];
    } 

  } 
  for(i=0;i<amosaParams->i_archivesize;i++)
  {
    flag[i]=0;
  }
  k=0;
  for(i=0;i<amosaParams->i_archivesize;i++)
  {
    if(flag[i]==0)
    {
      if(cluster[i]!=i)
      {
        g=0;
        point1[g]=i;
        flag[i]=1;
        j=cluster[i];
        while(j!=i)
        {
          g++;
          point1[g]=j;
          flag[j]=1;
          j=cluster[j];     

        }

        for(j=0;j<=g;j++)
        {
          dist[j]=0;
          w=point1[j];
          for(p=0;p<=g;p++)
          {
            if(p!=j)
            {
              m=point1[p];
              for(pp=0;pp<amosaParams->i_no_offunc;pp++)
                dist[j]=dist[j]+pow((amosaParams->d_func_archive[w][pp]-amosaParams->d_func_archive[m][pp]),2);
              dist[j]=sqrt(dist[j]);  
            }
          } 
        }

        min=dist[0];
        w=point1[0];
        for(j=1;j<=g;j++)
        {
          if(min>dist[j])
          {
            min=dist[j];
            w=point1[j];
          }
        }
        for(h=0;h<amosaParams->i_totalno_var;h++)
          amosaParams->d_archive[k][h]=archive2[w][h];
        for(h=0;h<amosaParams->i_no_offunc;h++)
          amosaParams->d_func_archive[k][h]=area2[w][h];    

        k++;
      }
      else
      {
        for(h=0;h<amosaParams->i_no_offunc;h++)
          amosaParams->d_func_archive[k][h]=area2[i][h];

        for(h=0;h<amosaParams->i_totalno_var;h++)
          amosaParams->d_archive[k][h]=archive2[i][h];
        k++;
      }       
    }
  } 
  amosaParams->i_archivesize=k;

  #ifdef DEBUG
    printf("\n archivesize=%d",amosaParams->i_archivesize);
    printf("\n afterclustering:");
  #endif

}


//------------------------------------------------------------------------------------------------------------------------

// End of clustering function
//---------------------------------------------------------------------------------------------------------------------
