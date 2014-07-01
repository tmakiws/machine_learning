/* 9-11.c 課題：簡易計算機*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



int main(){
	while(1){

		int i;
		int j;
		int n = 0;
		char a[100];//演算子用配列(奇数番目の要素のみ意味を持つ)
		int b[100];//整数用配列(偶数番目の要素のみ意味を持つ)
		int c[100]={0};//途中計算を入れておく
		int a_len;//計算列の長さ
		int b_len;
		int answer = 0;//答えは四捨五入して整数型（しかできませんでした）
	
		printf("\nExpression?: ");
		scanf("%s", a);
		
		a_len = strlen(a);
		
		for(i=0;i<a_len;i=i+2){
				b[i] = a[i] -'0' ;//整数部分を数字に変換して配列bへ移す
		}
		
		printf("a_len = %d\n",a_len);
		printf("b[0] = %d\nb[2] = %d\nb[4] = %d\nb[6] = %d\n",b[0],b[2],b[4],b[6]);
		
		c[0] = b[0];
		
		for(i=0;i<a_len-2;i=i+2){//乗法、除法を先に計算
			printf("i = %d\n", i);
			if(a[i+1] == '*'){
				c[i/2-n] = c[i/2-n] * b[i+2];
				for(j=0;j<n-1;j++){
					c[i/2-n] = 0;
				}
				n = n+1 ;
			}else if(a[i+1] == '/'){
				c[i/2-n] = c[i/2-n] / b[i+2];
				for(j=0;j<n-1;j++){
					c[i/2-n] = 0;
				}
				c[i/2+1] = 0;
				n = n+1 ;
			}else if(a[i+1] == '+'){
				c[i/2+1] = b[i+2];
				n = 0 ;
			}else if(a[i+1] == '-'){
				c[i/2+1] = b[i+2]* (-1);
				n = 0 ;
			}
		}
		
		printf("c[0] = %d\nc[1] = %d\nc[2] = %d\nc[3] = %d\n",c[0],c[1],c[2],c[3]);
		

/*		if(a_len<4){//演算子が１つになったときの処理
			if(a[1] == '*'){
				b[0] = b[0] * b[2];
			}else if(a[1] == '/'){
				b[0] = b[0] / b[2];
			}else if(a[1] == '+'){
				b[0] = b[0] + b[2];
			}else if(a[1] == '-'){
				b[0] = b[0] - b[2];
			}
		}*/
		
		for(i=0;i<(a_len+1)/2;i++){
			answer = answer + c[i];
		}
		printf("Answer: %d", answer);
	}
	
		return 0;
}
