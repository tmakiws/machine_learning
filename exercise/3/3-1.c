/* 3-1.c �W���ۑ�F���l��̐���(�\�[�g)�̃v���O���� */

#include<stdio.h>

int main(){
	FILE *fp ;
	float f[100] ;
	int i = 0;
	fp = fopen("input.txt", "r") ;
	while(fscanf(fp, "%f", &f[i]) != EOF) {
		i++ ;
	}
	int n = i ;
	int j ;
	float k ;
	for(i = 0; i < n; i++){
		for(j = 1; j < n; j++){
			if(f[j] < f[j-1]){
				k = f[j] ;
				f[j] = f[j-1] ;
				f[j-1] = k ;
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("%f\r\n", f[i]) ;
	}
	fclose(fp) ;
}
