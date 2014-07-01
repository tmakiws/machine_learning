/* 6-0.c —ûK‰Û‘è‡@&‡A ƒpƒ^ƒ“ŒŸõ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int i ;
	int j ;
	int k ;
	
	printf("length of sequence(<10000) = ") ;
	scanf("%d", &k) ;
	
	FILE *fp ;
	fp = fopen("data.txt", "w") ;
	srand(time(NULL)) ;
	
	int r[10000] ;
	for(i=0; i<k; i++){
		r[i] = rand() % 10 ;
		fprintf(fp, "%d", r[i]) ;
	}
	
	fclose(fp) ;
	
	fp = fopen("data.txt", "r") ;
	
	char t[k] ;
	fread(t, sizeof(char), k, fp) ;
	
	
	for(i=0; i<k; i++){
		printf("%c", t[i]) ;
	}
	
	
	printf("\npattern = ") ;
	
	char p[100] ;
	scanf("%s", p) ;
	int m = strlen(p) ;
	
	for(i=0;i<m;i++){
		p[i] = p[i]-'0';
	}
	
	int n[k] ;
	for(i=0; i<k; i++){
		n[i] = 0 ;
		for(j=0; j<m; j++){
			if(t[i+j]-'0' != p[j]){
				break ;
			}
			n[i] = n[i] + 1 ;
		}
	}
	
	printf("\nmatch : ") ;
	
	for(i=0; i<k; i++){
		if(n[i] == m){
			printf("%d ", i) ;
		}
	}
	
	fclose(fp) ;
	
	return 0;
}