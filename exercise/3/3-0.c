/* 3-0.c ���K�ۑ�F�t�@�C���̓ǂݏ��� */

#include<stdio.h>

int main(){
	FILE *fp ;
	float f[11] ;
	int i = 0;
	fp = fopen("input.txt", "r") ;
	while(fscanf(fp, "%f", &f[i]) != EOF) {
		i++ ;
	}
	int n = i ;
	for(i = 0; i < n; i++){
		printf("%f\r\n", f[n-i-1]) ;
	}
	fclose(fp) ;
	return 0 ;
}
