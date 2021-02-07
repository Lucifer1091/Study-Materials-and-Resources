#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc,char *args[])
{
	int row=3,column=3;
	int solve_row_no=1;
	int no_of_rows=0;
	int arrA[row][column]={9,8,7,6,5,4,3,2,1};
	int arrB[row][column]={1,2,3,4,5,6,7,8,9};
	int arrC[row][column]={0};

	int rank,size;

	MPI_Init(&argc,&args);

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank==0)
	{
		no_of_rows=row/size;

		int i=1;
		if(size>1)
		{
			for(i=1;i<size-1;i++)
		{
			int index=i*no_of_rows;
			solve_row_no=index;
			MPI_Send(&index,1,MPI_INT,i,0,MPI_COMM_WORLD);

			MPI_Send(&solve_row_no,1,MPI_INT,i,0,MPI_COMM_WORLD);

			MPI_Send(&arrA,
					row*column,
					MPI_INT, i, 0,
					MPI_COMM_WORLD);

			MPI_Send(&arrB,row*column,MPI_INT,i,0,MPI_COMM_WORLD);
		}


		int index=i*no_of_rows;
		solve_row_no=row-1;

			MPI_Send(&index,1,MPI_INT,i,0,MPI_COMM_WORLD);

			MPI_Send(&solve_row_no,1,MPI_INT,i,0,MPI_COMM_WORLD);

			MPI_Send(&arrA,
					row*column,
					MPI_INT, i, 0,
					MPI_COMM_WORLD);

			MPI_Send(&arrB,row*column,MPI_INT,i,0,MPI_COMM_WORLD);

		for(int i=0;i<1;i++)

			for(int j=0;j<column;j++)
				arrC[i][j]=arrA[i][j]+arrB[i][j];

	}
	else
	{
		for(int i=0;i<row;i++)

			for(int j=0;j<column;j++)
				arrC[i][j]=arrA[i][j]+arrB[i][j];
	}

		for(int i=1;i<size;i++)
		{
			int start=0,end=0;
			MPI_Recv(&start,1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			MPI_Recv(&end,1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			MPI_Recv(&arrC[start][0],((end-start)+1)*column,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		}


		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++)
				{
					cout<<arrC[i][j]<<" ";
				}
				cout<<endl;
			}
			
	}
	else
	{
		int start=0,end=0;
		MPI_Recv(&start,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&end,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&arrA,row*column,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&arrB,row*column,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

		for(int i=start;i<=end;i++){

		for(int j=0;j<column;j++)
			{
				arrC[i][j]=arrA[i][j]+arrB[i][j];
			}
		}


		MPI_Send(&start,1,MPI_INT,0,0,MPI_COMM_WORLD);
		MPI_Send(&end,1,MPI_INT,0,0,MPI_COMM_WORLD);
		MPI_Send(&arrC[start][0],((end-start)+1)*column,MPI_INT,0,0,MPI_COMM_WORLD);

	}

	MPI_Finalize();
	return 0;

}
