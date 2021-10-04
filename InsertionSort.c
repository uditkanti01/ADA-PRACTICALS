#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void InsertionSort (int arr[], int size){
	for (int i = 1; i < size; i++) {
        for (int j = i-1; j >= 0; j--){
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i--;
            }
            else {
                break;
            }
        }
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

        InsertionSort(arr, arrSize);

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

        InsertionSort(arr, arrSize);

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

        InsertionSort(arr, arrSize);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    }
}
