#define HAVE_STRUCT_TIMESPEC
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <pthread.h>

#define SIZE 10000
#define SIZE1 20000
#define SIZE2 50000
#define SIZE3 100000
#define SIZE4 200000


int 10K[SIZE];
int 20K[SIZE1];
int 50K[SIZE2];
int 100K[SIZE3];
int 200K[SIZE4];

//structures to hold function parameters for pthread calls
struct mergeParams {
    int begin;
    int mid;
    int end;
};

struct insertionSortParams {
    int start;
    int end;
};

//function prototypes
void fillArray(int size,int count);
void* insertionSort(void* args);
void printArray(int* list, int size);


void Sorting10k()
{
    //fill the unsorted array
    fillArray(SIZE,0);

    
    int start1 = 0, end1 = SIZE;

   
    pthread_t threads;

    //prepare sorting params and fire off sorting threads
    struct insertionSortParams sArgs;
    sArgs.start = start1;
    sArgs.end = end1;

    auto start = std::chrono::high_resolution_clock::now();
    pthread_create(&threads, NULL, insertionSort, &sArgs); 

    pthread_join(threads, NULL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("Duration Of Sorting 10000 Elements : %f", duration.count());

}

void Sorting20k()
{
    //fill the unsorted array
    fillArray(SIZE1, 1);


    int start1 = 0, end1 = SIZE1;


    pthread_t threads;

    //prepare sorting params and fire off sorting threads
    struct insertionSortParams sArgs;
    sArgs.start = start1;
    sArgs.end = end1;

    auto start = std::chrono::high_resolution_clock::now();
    pthread_create(&threads, NULL, insertionSort, &sArgs);

    pthread_join(threads, NULL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 20000 Elements : %f", duration.count());

}

void Sorting50k()
{
    //fill the unsorted array
    fillArray(SIZE2, 2);


    int start1 = 0, end1 = SIZE2;


    pthread_t threads;

    //prepare sorting params and fire off sorting threads
    struct insertionSortParams sArgs;
    sArgs.start = start1;
    sArgs.end = end1;

    auto start = std::chrono::high_resolution_clock::now();
    pthread_create(&threads, NULL, insertionSort, &sArgs);

    pthread_join(threads, NULL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 50000 Elements : %f", duration.count());

}

void Sorting100k()
{
    //fill the unsorted array
    fillArray(SIZE3, 3);


    int start1 = 0, end1 = SIZE3;


    pthread_t threads;

    //prepare sorting params and fire off sorting threads
    struct insertionSortParams sArgs;
    sArgs.start = start1;
    sArgs.end = end1;

    auto start = std::chrono::high_resolution_clock::now();
    pthread_create(&threads, NULL, insertionSort, &sArgs);

    pthread_join(threads, NULL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 100000 Elements : %f", duration.count());

}
void Sorting200k()
{
    //fill the unsorted array
    fillArray(SIZE4, 4);


    int start1 = 0, end1 = SIZE4;


    pthread_t threads;

    //prepare sorting params and fire off sorting threads
    struct insertionSortParams sArgs;
    sArgs.start = start1;
    sArgs.end = end1;

    auto start = std::chrono::high_resolution_clock::now();
    pthread_create(&threads, NULL, insertionSort, &sArgs);

    pthread_join(threads, NULL);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    printf("\nDuration Of Sorting 200000 Elements : %f", duration.count());

}
/**
 * Main function
 */
int main() {

    printf("Sorting By Using Pthread.h\n");
    Sorting10k();
    Sorting20k();
    Sorting50k();
    Sorting100k();
    Sorting200k();

    return 0;
}


void fillArray(int size, int count) {

    if (count == 0)
    {
    int i;
    srand(time_t(NULL));
    for (i = 0; i < size; i++)
        10K[i] = rand() % 20000;
    }
    if (count == 1)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            20K[i] = rand() % 50000;
    }
    if (count == 2)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            50K[i] = rand() % 100000;
    }
    if (count == 3)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            100K[i] = rand() % 200000;
    }
    if (count == 4)
    {
        int i;
        srand(time_t(NULL));
        for (i = 0; i < size; i++)
            200K[i] = rand() % 500000;
    }
}

void* insertionSort(void* args)
{
    struct insertionSortParams* params = (struct insertionSortParams*)args;
    int start = params->start,
        end = params->end;

    int i = start, j, key;

    //everything to the left of i is sorted
    while (i <= end)
    {
        key = unsorted[i]; 

        j = i - 1;
        while (j >= start && key < unsorted[j])
        {
            unsorted[j + 1] = unsorted[j];
            j--;
        }
        //insert the element into s[j]
        unsorted[j + 1] = key;
        i++;
    }
    return NULL;
}

void printArray(int* list, int size) {
    int i;
    for (i = 0; i < size - 1; i++)
        printf("%d, ", list[i]);
    printf("%d\n", list[i]);
}
