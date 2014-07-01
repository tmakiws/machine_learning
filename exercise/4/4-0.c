/* 4-0.c —ûK‰Û‘è*/

#include<stdio.h>

/*
int recursion(){
	static int i = 0 ;
	
	printf("called\n");
	i++ ;
	if(i == 10){
		return ;
	}
	recursion() ;
}
int main(){
	printf("%d", recursion()) ;
}
*/

int main(){
	int m = 1 ;
	int n ;
	printf("input: ") ;
	scanf("%d", &n) ;
	while(n != 0){
		m = m * n ;
		n-- ;
		}
	printf("%d", m) ;
}