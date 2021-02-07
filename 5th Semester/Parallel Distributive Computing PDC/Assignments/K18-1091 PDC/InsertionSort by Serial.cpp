#include <iostream> 
#include <chrono>
#include <fstream>
#include <stdio.h>

using namespace std;


void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}  

int main()
{
    cout << "Sorting Normally..\n";
    int *arr = new int[10000];
    int count = 0;

    ifstream obj;
    obj.open("10k.txt");
    if (obj.is_open())
    {
        while (!obj.eof())
        {
            obj >> arr[count];
            count += 1;
        }
    }
    else
    {
        cout << "File Not Found\n";
    }
    obj.close();

    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, 10000);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    printf("Duration Of Sorting 10000 Elements : %f seconds", duration.count());
    
    // printArray(arr1, 10000);  

    delete[] arr;

    count = 0;
    arr = new int[20000];

    obj.open("20k.txt");
    if (obj.is_open())
    {
        while (!obj.eof())
        {
            obj >> arr[count];
            count += 1;
        }
    }
    else
    {
        cout << "File Not Found\n";
    }
    obj.close();

    auto start1 = std::chrono::high_resolution_clock::now();
    insertionSort(arr, 20000);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration1 = end1 - start1;
    printf("\nDuration Of Sorting 20000 Elements : %f seconds", duration1.count());

    delete[] arr;


    arr = new int[50000];
    count = 0;

    obj.open("50k.txt");
    if (obj.is_open())
    {
        while (!obj.eof())
        {
            obj >> arr[count];
            count += 1;
        }
    }
    else
    {
        cout << "File Not Found\n";
    }
    obj.close();

    auto start2 = std::chrono::high_resolution_clock::now();
    insertionSort(arr, 50000);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration2 = end2 - start2;
    printf("\nDuration Of Sorting 50000 Elements : %f seconds", duration2.count());

    delete[] arr;

    arr = new int[100000];
    count = 0;

    obj.open("100k.txt");
    if (obj.is_open())
    {
        while (!obj.eof())
        {
            obj >> arr[count];
            count += 1;
        }
    }
    else
    {
        cout << "File Not Found\n";
    }
    obj.close();

    auto start3 = std::chrono::high_resolution_clock::now();
    insertionSort(arr, 100000);
    auto end3 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration3 = end3 - start3;
    printf("\nDuration Of Sorting 100000 Elements : %f seconds", duration3.count());

    delete[] arr;

    arr = new int[200000];
    count = 0;

    obj.open("200k.txt");
    if (obj.is_open())
    {
        while (!obj.eof())
        {
            obj >> arr[count];
            count += 1;
        }
    }
    else
    {
        cout << "File Not Found\n";
    }
    obj.close();

    auto start4 = std::chrono::high_resolution_clock::now();
    insertionSort(arr, 200000);
    auto end4 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration4 = end4 - start4;
    printf("\nDuration Of Sorting 200000 Elements : %f seconds", duration4.count());

    delete[] arr;
    return 0;
}
