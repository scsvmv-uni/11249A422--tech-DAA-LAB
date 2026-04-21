#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ls(int a1[], int begin, int stop, int search)
{
    if(begin == stop)
        printf("Element not found\n");
    else if(a1[begin] == search)
        printf("Element found at position %d\n", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}

int main()
{
    int a[10000], n = 10000, key, i;
    clock_t start, end;

    // Generate random numbers
    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    // Ensure key is present in array
    key = a[rand() % n];

    printf("Key to be searched: %d\n", key);

    // Start time
    start = clock();

    // Call linear search
    ls(a, 0, n, key);

    // End time
    end = clock();

    // Display time taken
    printf("Total time taken for execution: %lf\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
