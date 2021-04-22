#include<stdio.h> 
#define N 3

void exchange(int p[N][N])
{
int temp,i,j;
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
{
temp=*(*(p+i)+j);
*(*(p+i)+j)=*(*(p+j)+i);
*(*(p+j)+i)=temp;
}
}
}

int main()
{
int i,a[N][N];
for(i=0;i<N;i++)
scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
exchange(a);
for(i=0;i<N;i++)
printf("%d%d%d",a[0][i],a[1][i],a[2][i]);
}
