int sort(a[],int n,int key){          //keyΪ�����ؼ��� 
	int lower,upper,j;                
	lower=0;                         //�½��ֵ 
	upper=n-1;                      //�Ͻ��ֵ 
	while(upper-lower>=0){          
		j=(lower+upper)/2;          //���� 
		if(key==a[j])               //�ҵ�j 
		   return j;
		else if(key>a[j])           //key��a[j+1]��a[upper]֮�� 
		   lower=j+1;
		else                        //key��a[lower]��a[j-1]֮�� 
		   upper=j-1;
	}
	return -1;                       //δ�ҵ� 
}

