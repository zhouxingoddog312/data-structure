#define n 10
float a[n][n+1],x[n];      //注意，数组从零开始编下标 
void gaoss(void){
	float r;
	int i,j,k;
/*消去下三角*/
	for(i=0;i<n-1;i++)/*列控制，从0到n-2列*/
	   for(j=i+1;j<=n;j++){/*行控制，从i+1到n-1行*/
	   	r=a[j][i]/a[i][i];
	   	for(k=i;k<=n;k++)/*第j行运算，知道第n列*/
	   	a[j][k]=a[j][k]-a[i][k]*r;
	   }
/*回带求根*/
	for(i=n-1;i>=0;i--){/*从最后一个方程（n-1）行开始*/
		r=0;
		for(j=i+1;j<=n-1;j++)/*从第i+1列到n-1列求和*/
		r=r+a[i][j]*x[j];
		x[i]=(a[i][n]-r)/a[i][i];
	}
}
