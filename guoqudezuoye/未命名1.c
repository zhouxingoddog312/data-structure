#include<stdio.h>

int main(){

       int i,j,k;

       for(i=0;i<2;i++) {

           printf("i=%d\n",i);

              for(j=0;j<2;j++) { 

                     printf("\t j=%d\n",j);

                     for(k=0;k<2;k++)

                            printf("\t k=%d\n",k);                

              }

       }

       return 0;

}


