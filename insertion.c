#include <stdio.h>
#include<time.h>
int main()
{
    clock_t begin,end; 
    int arr[]={9,5,4,8,2};
    int n=sizeof(arr)/sizeof(*arr);
    int min,j;
    begin = clock();
    for(int i=1; i<n; i++){
        min=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>min){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=min;
    }
       //printArray
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    end=clock();
    printf("Starting time %f\n",begin);
    printf("Ending time %f\n",end);
    printf("Time taken %f\n",(double)(end-begin)/CLOCKS_PER_SEC);
    return 0;
}