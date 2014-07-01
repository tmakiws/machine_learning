/* 6-1.c �W���ۑ�@ �傫�ȃf�[�^����̃p�^������ */

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
	fp = fopen("data.txt", "w") ;//�܂��͗������t�@�C���ɏ�������
	
	srand(time(NULL)) ;
	int r[10000] ;
	for(i=0; i<len; i++){
		r[i] = rand() % 10 ;
		fprintf(fp, "%d", r[i]) ;
	}
	
	fclose(fp) ;
	
	
	fp = fopen("data.txt", "r") ;//�ǂݎ��J�n
	
	printf("\nsize of readable data: k = ") ;//��x�ɓǂݎ��f�[�^�̐����w��
	scanf("%d", &k) ;
	
	printf("\npattern = ") ;//�L�[�{�[�h����p�^�������
	
	char p[100] ;
	scanf("%s", p) ;
	int m = strlen(p) ;//�p�^���̒���m
//	printf("strlen = %d\n",m);
	
	for(i=0;i<m;i++){
		p[i] = p[i]-'0';
//		printf("%d",p[i]);
	}
	
	int loop ;
	int n[len] ;
	printf("\nrandom sequence :\n") ;
	
	for(loop=1; loop <= len/k +1; loop++){//�ȉ��ǂݍ��݂Ɣ��ʂ̌J��Ԃ�
		
//		printf("\nlooptime = %d\n",loop);
		
		char t[k] ;
		fread(t, sizeof(char), k, fp) ;
		
		for(i=0; i<k; i++){
			if(t[i] !=0){
				t[i] = t[i]-'0';
				printf("%d", t[i]) ;
			}
		}
		
		for(i=(loop-1)*k-m+1; i<loop*k; i++){//�����ł��炵�Ȃ��猟��,�؂�ڂ��`�F�b�N����
//			printf("%d ",i);
			if(i>=(loop-1)*k && i<loop*k){
				n[i] = 0 ;//n[i]�ɂ͈�v������������
			}
			
			
			for(j=0; j<m; j++){
//				printf("t[%d]=%d\n",i+j-(loop-1)*k,t[i+j-(loop-1)*k]);
				if(i+j>=(loop-1)*k && i+j<loop*k && t[i+j-(loop-1)*k] == p[j]){
					n[i] = n[i] + 1 ;//��v�����̂�1������
//					printf("added\n");
				}
			}
			
		}
	}
	
	printf("\nmatch : ") ;
	
	for(i=0; i<len; i++){
		if(n[i] == m){//m���ׂĈ�v�����ӏ���Ԃ�
			printf("%d ", i) ;
		}
	}
	
	fclose(fp) ;
	
	return 0 ;
}