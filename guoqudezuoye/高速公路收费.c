#include <stdio.h>
enum tsort {car,truck,bus
}sort;
int i;
float mileage,price;
main(){
printf("please choose(1.car 2.truck 3.bus): ");               //选择车辆种类
scanf("%d",&i);
switch(i){
case 1:sort=car;break;
case 2:sort=truck;break;
case 3:sort=bus;
} 
printf("please input your mileage");           //输入汽车里程 
scanf("%f",&mileage);
switch(sort){
case car:price=0.50;break;
case truck:price=1.10;break;
case bus:price=2.20;
}
printf("cost=%.2f",mileage*price);
return 0;
}

