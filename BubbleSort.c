#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void BubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
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

        BubbleSort(arr, arrSize);

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

        BubbleSort(arr, arrSize);

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

        BubbleSort(arr, arrSize);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    }
}
