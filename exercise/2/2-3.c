/* 2-3.c �v���O�����̊拭���E������*/

//*�������ɂ���
// �G���g�X�e�l�X���(�C�ӂ̐������͂��܂ł̑f����\������)

#include<stdio.h>

int main(){
	printf("input: ") ;
	int k ;
	scanf("%d" ,&k ) ;
	int i, j ;
	int p[k] ;
	for (i = 0; i < k; i++){ 
	p[i] = 0 ;    //������
	}
	p[0] = 1 ;
	for(i = 2; i <= k/2; i++){
		for(j = 2; i * j <= k; j++){
			if(p[i*j-1] == 0){
				p[i*j-1] = 1 ;   //2�̔{���A3�̔{��...�̏��ɏ��O���Ă����B
			}                    //p[������]=1,p[�f��]=0�ƂȂ�B
		}
	}
	for(i = 0; i < k; i++){
		if(p[i] == 0){
			printf("%d \n" , i+1) ;   //�f�����������o���B
		}
	}
}

