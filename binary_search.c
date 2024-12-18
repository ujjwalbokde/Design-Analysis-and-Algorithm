#include <stdio.h>
#include<time.h>
int main()
{
    clock_t begin,endy; 
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(*arr);
    int mid,beg,end,key=8;
    beg=0;
    end=n-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==key){
            printf("Found at index %d\n",mid);
            break;
        }
        else if(arr[mid]<key)
            beg=mid+1;
        else
            end=mid-1;
    }
    return 0;
}