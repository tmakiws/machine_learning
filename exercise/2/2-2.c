/* 2-2.c ‘f”—ñ‹“ */

#include<stdio.h>

int main(){
	while(1){
		printf("input: ") ;
		int i ;
		scanf("%d" ,&i) ;
		if(i <= 1){
			printf("null \n\n") ;
		}
		else{
			int j ;
			int k ;
			printf("2") ;
			for(j = 3; j <= i; j++){
				for(k = 2; k < j; k++){
					if(j % k == 0){
						break;
					}
				}
				if(j == k){
					printf(", %d" , j) ;
				}
			}
		}
		printf("\n") ;
	}
}