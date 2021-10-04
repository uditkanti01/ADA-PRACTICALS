#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

int BinarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = floor((high + low)/2);
        if (key == arr[mid]) {
            return mid;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(void) {

    int testCasesSize[] = {10000, 20000, 40000, 80000, 160000, 320000, 640000};
    
    // int test[] = {1,2,3,5,6,7,8,32,};
    // int result = BinarySearch(test, 8, 35);
    // printf("%d",result);

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

        BinarySearch(arr, arrSize, key);
    
        gettimeofday(&end, NULL);

        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Best Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

        //Average Case
        key = arr[rand()%arrSize];

        gettimeofday(&start, NULL);

        BinarySearch(arr, arrSize, key);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Average Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

        //Worst Case
        key = arrSize + 1;
    
        gettimeofday(&start, NULL);

        BinarySearch(arr, arrSize, key);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Micro Seconds\n", arrSize, time_taken);

    }
	return 0;
}
