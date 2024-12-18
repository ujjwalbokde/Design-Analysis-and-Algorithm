#include <stdio.h>
#include<time.h>

int main()
{
    clock_t begin,end; 
    int arr[]={9,5,4,8,2};
    int n=sizeof(arr)/sizeof(*arr);
    begin = clock();

    //bubble sort
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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