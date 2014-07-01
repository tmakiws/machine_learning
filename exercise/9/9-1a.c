/* 9-11.c 課題：簡易計算機*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


void a_transfer(char a[],int start,int a_len){//配列aに対し、a[start(奇数)]以下の奇数要素を1個ずつ前に詰める
	int j;
	for(j=start;j<a_len-4;j=j+2){
		a[j] = a[j+2];
		a[a_len-2] = '\0';
	}
}

void b_transfer(int b[],int start,int b_len){//配列bに対し、b[start(偶数)]以下の偶数要素を1個ずつ前に詰める
	int j;
	for(j=start;j<b_len-3;j=j+2){
		b[j] = b[j+2];
	}
}


int main(){
	int i;
	int n1;
	int n2;
	char a[100];//演算子用配列(奇数番目の要素のみ意味を持つ)
	int b[100];//整数用配列(偶数番目の要素のみ意味を持つ)
	int a_len;//計算列の長さ
	int b_len;
	
	
	while(1){
		printf("\nExpression?: ");
		scanf("%s", a);
		
		a_len = strlen(a);
		
		printf("%c",a[6]);
		
		for(i=0;i<a_len;i=i+2){
				b[i] = a[i] -'0' ;//整数部分を数字に変換して配列bへ移す
		}
		
		printf("a_len = %d\n",a_len);
		printf("b[0] = %d\nb[2] = %d\nb[4] = %d\nb[6] = %d\n",b[0],b[2],b[4],b[6]);
		
		while(a_len > 4){//演算子が複数ある時の処理
			
			for(i=0;i<a_len-2;i=i+2){//乗法、除法を先に計算
				printf("i = %d\n", i);
				if(a[i+1] == '*'){
//					printf("*\n");
					b[i] = b[i] * b[i+2];
					a_transfer(a, i+1, a_len);//計算した部分を前に詰める
					b_transfer(b, i+2, a_len);
					a_len = a_len - 2;
				}else if(a[i+1] == '/'){
					b[i] = b[i] / b[i+2];
					a_transfer(a, i+1, a_len);
					b_transfer(b, i+2, a_len);
					a_len = a_len - 2;
				}
			}
			
			if(a_len < 4) break;
			
			printf("b[0] = %d\nb[2] = %d\nb[4] = %d\n",b[0],b[2]);
			printf("a_len = %d\n", a_len);
			
			
			for(i=0;i<a_len-2;i=i+2){//次に加法、減法を計算
				
				if(a[i+1] == '+'){
					b[i] = b[i] + b[i+2];
					a_transfer(a, i+1, a_len);
					b_transfer(b, i+2, a_len);
					a_len = a_len - 2;
				}else if(a[i+1] == '-'){
					b[i] = b[i] - b[i+2];
					a_transfer(a, i+1, a_len);
					b_transfer(b, i+2, a_len);
					a_len = a_len - 2;
				}
			}
		}
		
		if(a_len<4){//演算子が１つになったときの処理
			if(a[1] == '*'){
				b[0] = b[0] * b[2];
			}else if(a[1] == '/'){
				b[0] = b[0] / b[2];
			}else if(a[1] == '+'){
				b[0] = b[0] + b[2];
			}else if(a[1] == '-'){
				b[0] = b[0] - b[2];
			}
		}
		
		printf("Answer: %d", b[0]);
	}
	
		return 0;
}
