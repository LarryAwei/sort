//
// Created by awei on 2019/10/8.
//
#include <iostream>

void selectSort(int *arr,int n){

    for(int i=0;i<n;i++){


        int min=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j;

        std::swap(arr[i],arr[min]);
    }
}
void quickSort(int *arr, int l, int r){
    int i = l;
    int j = r;
    int tmp = arr[i];
    if(i<j){
        while(i<j){
            while(i<j && arr[j]>=tmp)
                j--;
            if(i<j){
                arr[i++]=arr[j];
            }
            while(i<j && arr[i]<=tmp)
                i++;
            if(i<j){
                arr[j--]=arr[i];
            }
        }
        arr[i]=tmp;
        quickSort(arr, l, i-1);
        quickSort(arr, i+1, r);
    }
}
void building(int *arr, int rootPosition, int size){
    if (rootPosition < size) {
        int left = 2 * rootPosition;
        int right = 2 * rootPosition + 1;

        int max = rootPosition;

        if (left < size) {

            if (arr[max] < arr[left]) {
                max = left;
            }
        }
        if (right < size) {

            if (arr[max] < arr[right]) {
                max = right;
            }
        }

        if (max != rootPosition) {
            std::swap(arr[rootPosition], arr[max]);

            building(arr, max, size);
        }
    }
}
void heapSort(int *arr, int size)
{
    //building
    for(int i=size/2 - 1; i >= 0; i--)
    {
        building(arr, i, size);
    }

    //exchange
    for(int i = size - 1; i >= 1; i--)
    {
        std::swap(arr[0], arr[i]);
        building(arr, 0, i);
    }
}
int main() {
    int a[7]={1,5,2,9,4,3,6};
    //selectSort(a, 7);
    //quickSort(a, 0, 6);
    heapSort(a, 7);
    for(int i=0;i<7;i++){
        std::cout << a[i]<< std::endl;
    }

    return 0;
}




