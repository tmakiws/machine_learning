/* 6-1.c 標準課題① 大きなデータからのパタン検索 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int i ;
	int j ;
	int k ;
	int len ;
	
	printf("length of sequence(<100000) = ") ;
	scanf("%d", &len) ;
	
	FILE *fp ;
	fp = fopen("data.txt", "w") ;//まずは乱数をファイルに書き込み
	
	srand(time(NULL)) ;
	int r[10000] ;
	for(i=0; i<len; i++){
		r[i] = rand() % 10 ;
		fprintf(fp, "%d", r[i]) ;
	}
	
	fclose(fp) ;
	
	
	fp = fopen("data.txt", "r") ;//読み取り開始
	
	printf("\nsize of readable data: k = ") ;//一度に読み取るデータの数を指定
	scanf("%d", &k) ;
	
	printf("\npattern = ") ;//キーボードからパタンを入力
	
	char p[100] ;
	scanf("%s", p) ;
	int m = strlen(p) ;//パタンの長さm
//	printf("strlen = %d\n",m);
	
	for(i=0;i<m;i++){
		p[i] = p[i]-'0';
//		printf("%d",p[i]);
	}
	
	int loop ;
	int n[len] ;
	printf("\nrandom sequence :\n") ;
	
	for(loop=1; loop <= len/k +1; loop++){//以下読み込みと判別の繰り返し
		
//		printf("\nlooptime = %d\n",loop);
		
		char t[k] ;
		fread(t, sizeof(char), k, fp) ;
		
		for(i=0; i<k; i++){
			if(t[i] !=0){
				t[i] = t[i]-'0';
				printf("%d", t[i]) ;
			}
		}
		
		for(i=(loop-1)*k-m+1; i<loop*k; i++){//ここでずらしながら検証,切れ目もチェックする
//			printf("%d ",i);
			if(i>=(loop-1)*k && i<loop*k){
				n[i] = 0 ;//n[i]には一致した個数が入る
			}
			
			
			for(j=0; j<m; j++){
//				printf("t[%d]=%d\n",i+j-(loop-1)*k,t[i+j-(loop-1)*k]);
				if(i+j>=(loop-1)*k && i+j<loop*k && t[i+j-(loop-1)*k] == p[j]){
					n[i] = n[i] + 1 ;//一致したので1加える
//					printf("added\n");
				}
			}
			
		}
	}
	
	printf("\nmatch : ") ;
	
	for(i=0; i<len; i++){
		if(n[i] == m){//m個すべて一致した箇所を返す
			printf("%d ", i) ;
		}
	}
	
	fclose(fp) ;
	
	return 0 ;
}