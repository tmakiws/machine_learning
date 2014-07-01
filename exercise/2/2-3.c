/* 2-3.c プログラムの頑強化・高速化*/

//*高速化について
// エラトステネスの篩(任意の整数入力ｋまでの素数を表示する)

#include<stdio.h>

int main(){
	printf("input: ") ;
	int k ;
	scanf("%d" ,&k ) ;
	int i, j ;
	int p[k] ;
	for (i = 0; i < k; i++){ 
	p[i] = 0 ;    //初期化
	}
	p[0] = 1 ;
	for(i = 2; i <= k/2; i++){
		for(j = 2; i * j <= k; j++){
			if(p[i*j-1] == 0){
				p[i*j-1] = 1 ;   //2の倍数、3の倍数...の順に除外していく。
			}                    //p[合成数]=1,p[素数]=0となる。
		}
	}
	for(i = 0; i < k; i++){
		if(p[i] == 0){
			printf("%d \n" , i+1) ;   //素数だけを取り出す。
		}
	}
}

