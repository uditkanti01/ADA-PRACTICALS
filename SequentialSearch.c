#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int SequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (key == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main(void) {

    int testCasesSize[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

    for (int t = 0; t < 7; t++) {
        int arrSize = testCasesSize[t];
        int arr[arrSize];
        for (int i = 0; i < arrSize; i++){
            arr[i] = i;          
        }

        //Best Case
        int key = arr[0];

        struct timeval start, end;
        gettimeofday(&start, NULL);

        SequentialSearch(arr, arrSize, key);
    
        gettimeofday(&end, NULL);

        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Best Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

        //Average Case
        key = arr[rand()%arrSize];

        gettimeofday(&start, NULL);

        SequentialSearch(arr, arrSize, key);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Average Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

        //Worst Case
        key = arrSize + 1;
    
        gettimeofday(&start, NULL);

        SequentialSearch(arr, arrSize, key);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

    }
	return 0;
}
