#include <stdio.h>
#include<string.h>
int lcs(char *x,char *y,int m,int n){
    if(m==0||n==0)
    return 0;
    if(x[m-1]=y[n-1])
    return 1+lcs(x,y,m-1,n-1);
    else
    return lcs(x,y,m-1,n)>lcs(x,y,m,n-1)?lcs(x,y,m-1,n):lcs(x,y,m,n-1);
}
int main()
{
    char x[]="abcbcab";
    char y[]="abc";
    int m=strlen(x);
    int n=strlen(y);
    int len=lcs(x,y,m,n);
    printf("Length of LCS is %d\n",len);
    return 0;
}