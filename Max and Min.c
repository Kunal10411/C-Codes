//finding Maximum and Minimum of n Integers
#include <stdio.h>
int main()
{
    int n,num,max,min,i;
    printf("enter the n number:\n");
    scanf("%d",&n);
    
    printf("n= %d",n);
    scanf("%d",&max);
    
    min=max;
    
    for(i=0;i<=n;i++)
    {
        scanf("%d",&num);
        if(num>max)max=num;
        if(num<min)min=num;
    }
    printf("max=%d,min=%d",max,min);
}
