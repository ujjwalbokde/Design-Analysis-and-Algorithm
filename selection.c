#include <stdio.h>
#include<time.h>
int main()
{
    clock_t begin,end; 
    int arr[]={9,5,4,8,2};
    int n=sizeof(arr)/sizeof(*arr);
    begin = clock();

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
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