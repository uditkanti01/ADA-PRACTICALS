#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition (int arr[], int start, int end) { 
    int pivot = arr[end];  
    int i = (start - 1); 
    for (int j = start; j <= end - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1); 
} 

void QuickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = Partition(arr, start, end);

        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
}

int main(void) {

    int testCasesSize[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

    for (int t = 0; t < 7; t++) {
        int arrSize = testCasesSize[t];
        int arr[arrSize];

        //Best Case
        for (int i = 0; i < arrSize; i++){
            arr[i] = i;     
        }

        struct timeval start, end;
        gettimeofday(&start, NULL);

        QuickSort(arr, 0, arrSize - 1);

        gettimeofday(&end, NULL);

        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Best Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);

        //Average Case
        for (int i = 0; i < arrSize; i++){
            arr[i] = rand()%arrSize;     
        }

        gettimeofday(&start, NULL);

        QuickSort(arr, 0, arrSize - 1);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Average Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    
        //Worst Case
        for (int i = 0; i < arrSize; i++){
            arr[i] = arrSize-i;     
        }

        gettimeofday(&start, NULL);

        QuickSort(arr, 0, arrSize - 1);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    }
}
