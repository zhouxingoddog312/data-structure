#define n 10
float a[n][n+1],x[n];      //ע�⣬������㿪ʼ���±� 
void gaoss(void){
	float r;
	int i,j,k;
/*��ȥ������*/
	for(i=0;i<n-1;i++)/*�п��ƣ���0��n-2��*/
	   for(j=i+1;j<=n;j++){/*�п��ƣ���i+1��n-1��*/
	   	r=a[j][i]/a[i][i];
	   	for(k=i;k<=n;k++)/*��j�����㣬֪����n��*/
	   	a[j][k]=a[j][k]-a[i][k]*r;
	   }
/*�ش����*/
	for(i=n-1;i>=0;i--){/*�����һ�����̣�n-1���п�ʼ*/
		r=0;
		for(j=i+1;j<=n-1;j++)/*�ӵ�i+1�е�n-1�����*/
		r=r+a[i][j]*x[j];
		x[i]=(a[i][n]-r)/a[i][i];
	}
}
