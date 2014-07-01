/* 2-1.c ‘f””»’è */

#include<stdio.h>

int main(){
	while(1){
	printf("input: ") ;
	int i ; 
	scanf("%d",&i) ;
		if(i <= 1){
			printf("null \n\n") ;
		}
		else{
			int k ;
			for(k=2; k<i; k++){
				if (i % k == 0) {
					printf("%d is not a prime number. \n\n" , i);
					break;
				}
			}
			if (i == k){
				printf("%d is a prime number. \n\n" , i) ;
			}
		}
	}
}