/* 4-1.c �W���ۑ�F�֐���p�����K��̌v�Z*/

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