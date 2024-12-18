#include <stdio.h>

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int ratio[]={6,5,4};
    int w = 50;
    int wt=0;
    int pt=0;
    for(int i=0; i<3; i++){
        if(wt+weight[i]<=w){
            wt+=weight[i];
            pt+=profit[i];
        }
        else{
            int rem=w-wt;
            int p=rem*ratio[i];
            printf("%d",p);
            pt+=p;
            break;
        }
    }
    printf("Profit = %d\n", pt);
    return 0;
}