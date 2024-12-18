#include <stdio.h>
void merge(int arr[],int l,int mid,int r);
void mergeSort(int arr[], int l, int r ){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void merge(int arr[],int l,int mid,int r){
    int temp[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    for (i = 0; i < (r - l + 1); i++) {
        arr[l + i] = temp[i];
    }

   
}
int main()
{
    int arr[]={9,5,4,8,2};
    int n=sizeof(arr)/sizeof(*arr);
    mergeSort(arr,0,n-1);
     for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}