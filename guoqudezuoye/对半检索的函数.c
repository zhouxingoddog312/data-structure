int sort(a[],int n,int key){          //key为检索关键字 
	int lower,upper,j;                
	lower=0;                         //下界初值 
	upper=n-1;                      //上界初值 
	while(upper-lower>=0){          
		j=(lower+upper)/2;          //两分 
		if(key==a[j])               //找到j 
		   return j;
		else if(key>a[j])           //key在a[j+1]到a[upper]之间 
		   lower=j+1;
		else                        //key在a[lower]到a[j-1]之间 
		   upper=j-1;
	}
	return -1;                       //未找到 
}

