/* 4-1.c 標準課題：関数を用いた階乗の計算*/

#include<stdio.h>


int n ;

int factorial(n){
	static int m = 1 ;
	if(n == 0){
		m = m * 1 ;
	}
	else{
		m = n * factorial(n-1);
	}
	return m ;
}

int main(){
	printf("input: ");
	scanf("%d", &n) ;
	printf("%d", factorial(n));
}