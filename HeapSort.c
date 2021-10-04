#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct MaxHeap {
    int size;
    int* array;
};

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b;  
    *b = t; 
}

void maxHeapify(struct MaxHeap* maxHeap, int idx) {
    int largest = idx; 
    int left = (idx << 1) + 1;  
    int right = (idx + 1) << 1; 

    if (left < maxHeap->size &&
        maxHeap->array[left] > maxHeap->array[largest])
        largest = left;

    if (right < maxHeap->size &&
        maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}

struct MaxHeap* createAndBuildHeap(int *array, int size) {
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size; 
    maxHeap->array = array; 

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

void HeapSort(int* array, int size) {
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;

        maxHeapify(maxHeap, 0);
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

        HeapSort(arr, arrSize);

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

        HeapSort(arr, arrSize);

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

        HeapSort(arr, arrSize);

        gettimeofday(&end, NULL);

        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - 
                                start.tv_usec)) * 1e-6;

        printf("Worst Case for %d Elements is %lf Milli Seconds\n", arrSize, time_taken*1000);
    }
}
