#include <stdio.h>
#include<limits.h>
int matrixchain(int *arr, int n){
    int m[n][n];
    int i,j,k,l;
    for(int i=0; i<n; i++){
        m[i][i]=0;
    }
    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                }
            }
        }
    }
     return m[1][n-1];
}
int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res=matrixchain(arr, n);
    printf("Minimum number of multiplications is %d",res);
    return 0;
}