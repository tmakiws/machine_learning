/* 2-0.c —ûK‰Û‘è ‹ô””»’è */

#include<stdio.h>


int main(){
	while(1){
	printf("input: ") ;
	int i ;
	scanf("%d" , &i) ;
	if (i % 2 == 0){
	printf (" %d can be divided by 2. \n\n " , i) ;
	}
	else{
	printf (" %d can not be divided by 2. \n\n " , i) ;
	}
	}
}