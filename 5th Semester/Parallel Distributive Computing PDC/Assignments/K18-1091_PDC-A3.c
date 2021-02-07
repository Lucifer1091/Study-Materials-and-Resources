#include<omp.h>
#include<stdio.h>

int main()
{
  
int a[2][2]={1,2,3,4};
int b[2][2]={4,2,2,1};
int c[2][2]={0};
int i=0,j=0,k=0;
int sum=0,sum1=0,z=0;

#pragma omp parallel num_threads(2) firstprivate(sum) 
{
  

  #pragma  omp for
  	for(i=0;i<2;i++)
  	{
  		for(j=0;j<2;j++)
  		{

			 for(k=0;k<2;k++)
			 {
			   c[i][j]+=a[i][k]*b[k][j];
			 }
			 sum=sum+c[i][j];

  		}
  	}
  #pragma omp critical
    {
      sum1=sum1+sum;
}
}

for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("%d ",c[i][j]);
	}
 printf("\n");
}
 
 printf("%d\n",sum1);




}
