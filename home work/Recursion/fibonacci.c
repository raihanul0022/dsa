#include<stdio.h>
int fib(int n,int a,int b){
    if(n==0)
    return 0;
    else{
        printf(" %d",a);
        return fib(n-1,b,a+b);
    }
}

int main(){
    int n,first,second;
    printf("Enter the lenght of the series: ");
    scanf("%d",&n);
    first = 0;
    second = 1;
    fib(n,first,second);
    return 0;
}