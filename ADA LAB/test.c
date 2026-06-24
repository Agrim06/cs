#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n , count =0;

void merge(int *arr, int beg , int mid , int end){

    int n1=  mid - beg +1;
    int n2 = end-mid;

    int left[n1], right[n2];

    for(int i = 0 ; i < n1; i++){
        left[i] = arr[beg+i];
    }
    for(int i = 0 ; i < n2; i++){
        right[i] = arr[mid+i+1];
    }

    int i =0, j=0;k=beg;

    while(i < n1 && j < n2){
        count++;
        if(left[i] <= right[j]){
            arr[k]  = left[i++];
        }
        else
            arr[k] = right[j++];
    
        k++;
    }

    while(i < n1){
        arr[k++] = left[i++];
    }
    while(j < n2){
        arr[k++] = right[j++];
    }
}

void mergersort(int *arr, int beg , int end){
    while(beg < end){
        int mid = (end+beg)/2;
        mergersort(arr, beg, mid);
        mergersort(arr, mid+1, end);
        merge(arr, beg , mid,  end);
    }
}

void worst(int *arr, int beg, int end){
    int mid = (end + beg)/2;

    int n1 = mid - beg + 1;
    int n2 = end-mid;

    int a[n1], b[n2];

    for(int i = 0; i < n1; i++){
        a[i] = arr[2*i];
    }

    for(int j =0 ; j < n2; j++){
        b[j] = arr[2*j+1];
    }

    worst(a, beg, mid);
    worst(b, mid+1, end);

    

}