#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include<chrono>

#define SIZE 10000
#define SIZE1 20000
#define SIZE2 50000
#define SIZE3 100000
#define SIZE4 200000

struct Compare { int val; int index; };
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

int unsorted[SIZE];
int unsorted1[SIZE1];
int unsorted2[SIZE2];
int unsorted3[SIZE3];
int unsorted4[SIZE4];

void insertionsort(int* arr, int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        struct Compare max;
        max.val = arr[i];
        max.index = i;
        #pragma omp parallel for reduction(maximum:max)
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > max.val)
            {
                max.val = arr[j];
                max.index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = max.val;
        arr[max.index] = tmp;
    }
}

void fillArray(int size, int count) {

    if (count == 0)
    {
    int i;
    srand(time_t(NULL));
    for (i = 0; i < size; i++)
        unsorted[i] = rand() % 20000;
    }
    if (count == 1)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            unsorted1[i] = rand() % 50000;
    }
    if (count == 2)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            unsorted2[i] = rand() % 100000;
    }
    if (count == 3)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            unsorted3[i] = rand() % 200000;
    }
    if (count == 4)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            unsorted4[i] = rand() % 500000;
    }
}

void Element10000Sorting()
{
    //fill the unsorted array
    fillArray(SIZE,0);
	auto start = std::chrono::high_resolution_clock::now();
	
	insertionsort(unsorted,100000);
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 10000 Elements : %f", duration.count());
}

void Element20000Sorting()
{
    //fill the unsorted array
    fillArray(SIZE1, 1);
	auto start = std::chrono::high_resolution_clock::now();
	
	insertionsort(unsorted1,100000);
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 20000 Elements : %f", duration.count());

}

void Element50000Sorting()
{
    //fill the unsorted array
    fillArray(SIZE2, 2);
	auto start = std::chrono::high_resolution_clock::now();
	
	insertionsort(unsorted2,100000);
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 50000 Elements : %f", duration.count());
}

void Element100000Sorting()
{
    //fill the unsorted array
    fillArray(SIZE3, 3);
	auto start = std::chrono::high_resolution_clock::now();
	
	insertionsort(unsorted3,100000);
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 100000 Elements : %f", duration.count());
}
void Element200000Sorting()
{
    //fill the unsorted array
    fillArray(SIZE4, 4);
	auto start = std::chrono::high_resolution_clock::now();
	
	insertionsort(unsorted4,100000);
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 200000 Elements : %f", duration.count());

}

void printArray(int* list, int size) 
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
		
	printf("%d, ", list[i]);
		
	}
    printf("%d\n", list[i]);
}
int main()
{
	printf("Insertion Sort With OpenMP\n");
    Element10000Sorting();
    Element20000Sorting();
    Element50000Sorting();
    Element100000Sorting();
    Element200000Sorting();
    return 0;
}
