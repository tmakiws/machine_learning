/* 9-11.c �ۑ�F�ȈՌv�Z�@*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


void a_transfer(char a[],int start,int a_len){//�z��a�ɑ΂��Aa[start(�)]�ȉ��̊�v�f��1���O�ɋl�߂�
	int j;
	for(j=start;j<a_len-4;j=j+2){
		a[j] = a[j+2];
		a[a_len-2] = '\0';
	}
}

void b_transfer(int b[],int start,int b_len){//�z��b�ɑ΂��Ab[start(����)]�ȉ��̋����v�f��1���O�ɋl�߂�
	int j;
	for(j=start;j<b_len-3;j=j+2){
		b[j] = b[j+2];
	}
}


int main(){
	int i;
	int n1;
	int n2;
	char a[100];//���Z�q�p�z��(��Ԗڂ̗v�f�݈̂Ӗ�������)
	int b[100];//�����p�z��(�����Ԗڂ̗v�f�݈̂Ӗ�������)
	int a_len;//�v�Z��̒���
	int b_len;
	
	
	while(1){
		printf("\nExpression?: ");
		scanf("%s", a);
		
		a_len = strlen(a);
		
		printf("%c",a[6]);
		
		for(i=0;i<a_len;i=i+2){
				b[i] = a[i] -'0' ;//���������𐔎��ɕϊ����Ĕz��b�ֈڂ�
		}
		
		printf("a_len = %d\n",a_len);
		printf("b[0] = %d\nb[2] = %d\nb[4] = %d\nb[6] = %d\n",b[0],b[2],b[4],b[6]);
		
		while(a_len > 4){//���Z�q���������鎞�̏���
			
			for(i=0;i<a_len-2;i=i+2){//��@�A���@���Ɍv�Z
				printf("i = %d\n", i);
				if(a[i+1] == '*'){
//					printf("*\n");
					b[i] = b[i] * b[i+2];
					a_transfer(a, i+1, a_len);//�v�Z����������O�ɋl�߂�
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
			
			
			for(i=0;i<a_len-2;i=i+2){//���ɉ��@�A���@���v�Z
				
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
		
		if(a_len<4){//���Z�q���P�ɂȂ����Ƃ��̏���
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
