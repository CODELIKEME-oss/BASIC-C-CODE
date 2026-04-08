#include <stdio.h>
int add(void);//prototype
int main(){
    int sum;
    sum=add();
    printf("\n sum of two num is=%d",sum);
    return 0;
}
int add(){//definition
    int a,b,c;
    printf("\nenter two number");
    scanf("%d %d",&a,&b,&c);
    c=a+b;
    return c;
}
