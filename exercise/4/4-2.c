/* 4-2.c ‚¨‚·‚·‚ßã‹‰‰Û‘èF2•ª’Tõ */
//”z—ñ‚ªˆê”Ê‚Ìê‡

#include<stdio.h>

int n, k ;
int max, min ;
int x[100] ;


	
	
int BS(min, max){
	
	if(max == min){
		return x[max] ;
	}

	int z = (max+min)/2 ;
	
	if(x[z] > k){
		 return BS(min, z-1) ;
	}
	else if(x[z] == k){
		return k ;
	}
	else{
		 return BS(z+1, max) ;
	}
}


int main(){
	
	int i = 0 ;
	FILE *fp ;
	fp = fopen("input4-2.txt", "r") ;
	while(fscanf(fp, "%d", &x[i]) != EOF){
		i++ ;
	}
	int n = i ;

	while(1){
		printf("input: ") ;
		scanf("%d", &k) ;
		if(BS(0, n-1) == k){
			printf("YES\n");
		}
		else{
			printf("NO\n") ;
		}
	}
}

	
	

	
	
		
			