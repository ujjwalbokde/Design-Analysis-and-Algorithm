#include <stdio.h>
void jobSequencing(int jobs[], int profits[], int deadlines[], int n,int dmax);
void jobSequencing(int jobs[], int profits[], int deadlines[], int n,int dmax){
    int timeslot[dmax+1];
    for (int i = 0; i <= dmax; i++) {
        timeslot[i] = 0; // Initialize all time slots to 0 (free)
    }
    int totalProfit = 0;
    for(int i=0; i<n; i++){
        int k;
        if(dmax>deadlines[i])
        k=dmax;
        else
        k=deadlines[i];
        while(k>=1){
            if(timeslot[k]==0){
                timeslot[k]=jobs[i];
                totalProfit += profits[i];
                printf("%d ", jobs[i]);
                break;
            }
            k--;
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}
int main()
{
    int jobs[] = {1, 2, 3, 4, 5}; // Job IDs (not necessary to track, but included for clarity)
    int profits[] = {50, 20, 40, 30, 10}; // Job profits (already sorted in descending order)
    int deadlines[] = {3, 1, 1, 1, 3}; // Job deadlines
    int n=sizeof(jobs)/sizeof(jobs[0]);
    jobSequencing(jobs, profits, deadlines, n,3);
    return 0;
}