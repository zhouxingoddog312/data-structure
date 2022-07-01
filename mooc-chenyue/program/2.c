#include <stdio.h>
int main(void)
{
    int all_negative_flag=1;
    int current_sum,max_sum;
    int index,array_len;
    scanf("%d",&array_len);
    int array[array_len];
    for(index=0;index<array_len;index++)
        scanf("%d",&array[index]);
    current_sum=max_sum=0;
    for(index=0;index<array_len;index++)
    {
        if(array[index]>=0)
            all_negative_flag=0;
        current_sum+=array[index];
        if(current_sum>max_sum)
            max_sum=current_sum;
        else if(current_sum<0)
            current_sum=0;
    }
    int i,j;
    for(i=0;i<array_len;i++)
    {
        current_sum=0;
        for(j=i;j<array_len;j++)
        {
            current_sum+=array[j];
            if(current_sum==max_sum)
                goto here;
        }
    }
    here:
    if(all_negative_flag==1)
        printf("%d %d %d",max_sum,array[0],array[array_len-1]);
    else
        printf("%d %d %d",max_sum,array[i],array[j]);
    return 0;
}
