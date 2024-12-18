#include <stdio.h>
int partition(int arr[],int si,int ei);
void quickSort(int arr[],int si,int ei);
void quickSort(int arr[],int si,int ei){
    if(si<ei){
        int pIdx=partition(arr,si,ei);
        quickSort(arr,si,pIdx-1);
        quickSort(arr,pIdx+1,ei);
    }
}

int partition(int arr[],int si,int ei){
    int pivot=arr[ei];
    int i=si-1;
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    int temp=arr[i+1];
    arr[i+1]=pivot;
    arr[ei]=temp;
    return i+1;
}

int main()
{
    int arr[]={9,5,4,8,2};
    int n=sizeof(arr)/sizeof(*arr);
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}