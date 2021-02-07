#include<omp.h>
#include<stdio.h>

int main()
{
	int a[6]={5,2,8,7,6,12},b[6]={8,4,14,5,9,18},c[6]={54,8,24,45,11,12};
	float sum=0,sum1=0;
	int i;

    #pragma omp parallel reduction(+:sum1) num_threads(3)
    {
       #pragma omp sections
	{
	    	#pragma omp section
	    	{
		   for(i=0;i<6;i++)
		   {
		      sum=sum+a[i];
		   }
		   sum1=sum/6;
	    	}
	    	#pragma omp section
	 	{   	
		   for(i=0;i<6;i++)
		   {
		      sum=sum+b[i];
		   }
		   sum1=sum/6;
	 	}  	
	    	#pragma omp section
		{
	    	
		   for(i=0;i<6;i++)
		   {
		      sum=sum+c[i];
		   }
		   sum1=sum/6;
		}
	}
}	 
printf("%f\n\n",sum1/3);
}
