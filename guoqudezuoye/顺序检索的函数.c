int search(int n,int a[],int key)
int j;
for(j=n-1;(j>=0)&&(key!=a[j]);j--);
return j;

