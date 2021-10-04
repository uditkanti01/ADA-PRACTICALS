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
    int n, Amount;
    printf("Enter the Amount to make change: ");
    scanf("%d", &Amount);
    printf("Enter the number of denominations: ");
    scanf("%d", &n);
    int denominations[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Denomination of Coin %d: ", i+1);
        scanf("%d", &denominations[i]);
    }

    MergeSort(denominations, 0, n - 1);

    int count;

    while (1) {
        if (Amount >= denominations[n-1]) {
            Amount = Amount - denominations[n-1];
            count++;
        }
        else {
            n--;
        }

        if (Amount == 0) {
            printf("Number of Coins Required: %d", count);
            break;
        }

        if (n <= 0) {
            printf("Change Not Possible");
            break;
        }
    }
    
    return 0;
}
