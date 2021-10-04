#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

void Combine(int arr[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int leftArray[leftLength];
    int rightArray[rightLength];
    int i, j, k;

    for (i = 0; i < leftLength; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < rightLength; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    i = 0; j = 0; k = left;

    while (i < leftLength && j < rightLength) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftLength) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightLength) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = floor(left + right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);        
        Combine(arr, left, mid, right);
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

        MergeSort(arr, 0, arrSize - 1);

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

        MergeSort(arr, 0, arrSize - 1);

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

        MergeSort(arr, 0, arrSize - 1);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    }
}
