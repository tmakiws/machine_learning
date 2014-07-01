/* 7-1.c �ۑ�F�菑�������F�� */

#include<stdio.h>

//�܂��N�C�b�N�\�[�g���s�����߂Ɋ֐��̒�`������

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);
void ShowData(int x[ ], int n);

void QSort(int x[ ], int left, int right){

	int i, j;
	int pivot;
	
	i = left;                      /* �\�[�g����z��̈�ԏ������v�f�̓Y�� */
	j = right;                     /* �\�[�g����z��̈�ԑ傫���v�f�̓Y�� */
	
	pivot = x[(left + right) / 2]; /* ��l��z��̒����t�߂ɂƂ� */
	
	while (1) {                    /* �������[�v */
	
		while (x[i] < pivot)       /* pivot ���傫���l�� */
			i++;                   /* �o��܂� i �𑝉������� */
		
		while (pivot < x[j])       /* pivot ��菬�����l�� */
            j--;                   /*  �o��܂� j ������������ */
		if (i >= j)                /* i >= j �Ȃ� */
            break;                 /* �������[�v���甲���� */
	
        Swap(x, i, j);             /* x[i] �� x[j]������ */
        i++;                       /* ���̃f�[�^ */
        j--;
    }

    if (left < i - 1)              /* ��l�̍��� 2 �ȏ�v�f������� */
        QSort(x, left, i - 1);     /* ���̔z��� Q �\�[�g���� */
    if (j + 1 <  right)            /* ��l�̉E�� 2 �ȏ�v�f������� */
        QSort(x, j + 1, right);    /* �E�̔z��� Q �\�[�g���� */
}

  /* �z��̗v�f���������� */
void Swap(int x[ ], int i, int j){
    int temp;
	
	temp = x[i];
    x[i] = x[j];
    x[j] = temp;
	
	/*
	x[i] ^= x[j];
	x[j] ^= x[i];
	x[i] ^= x[j]
	*/
}


 /* n �̃f�[�^��\������ */
void ShowData(int x[ ], int n){
	
    int i;
	
    for (i = 0; i < n ; i++)
        printf("%d\r\n", x[i]);
}




//��������main�֐�

int main(){
	
	int i ;
	int j ;
	int l ;
	int r ;
	
	
	FILE *fp ;
	fp = fopen("data.txt", "r");
	
	if(fp==NULL) printf("error\n");
	
	int s1[390];//�e�f�[�^�̃��x��
	int s2[10*39][16*20];//�e�f�[�^��320����2�l�x�N�g��
	
	for(i=0;i<390;i++){
		int ret = fscanf(fp, "%d,", &s1[i]);
		for(j=0;j<320;j++){
			fscanf(fp, "%d,", &s2[i][j]);
//			printf("%d ", s2[i][j]);
		}
	}
	
		
	int t[10][39]; //���𗦂��v���������f�[�^
	int d1[390]; //�e�f�[�^�Ƃ̃n�~���O����(�������g�Ƃ̋�����0�����A�������g�͓����Ɋ܂߂Ȃ��̂ŁA�����ł�1000�Ƃ����B)
	int d2[390];
//	printf("input line (1<=l<=39) = ");
//	scanf("%d",&l);
//	printf("input row (1<=r<=10) = ");
//	scanf("%d", &r);
	
	int right = 0 ;
	int wrong = 0 ;
	int k ;
	
	printf("\ninput: k= ");
	scanf("%d", &k);

	for(l=1;l<=10;l++){
		for(r=1;r<=39;r++){
			
			for(i=0;i<390;i++){//�e�f�[�^�Ƃ̃n�~���O�������v�Z����
			d1[i] = 0 ;
			d2[i] = 0 ;
				for(j=0;j<320;j++){
					if(s2[39*(l-1)+r-1][j] != s2[i][j]){
						d1[i] = d1[i] + 1 ;
						d2[i] = d2[i] + 1 ;
					}
				}
			}
	
			//for(i=0;i<390;i++){
			//	printf("%d ", d1[i]);
			//}
			
			
			/* �N�C�b�N�\�[�g����k-�ߖT�ߎ�����p����*/
			/* �������ق�����k�\������ */
			
			QSort(d2, 0, 390-1);
			if(0 < k && k <= 390){
			//	ShowData(d2, k);
			}
			else{
				printf("error");
			}
			
			int c ;
			int a1 ;
			int a2 ;
			int u1[k] ;
			int u2[k] ;
			
			for(i=0;i<k;i++){
				u1[i] = 100 ;
				u2[i] = 100 ;
			}
			
			for(i=0;i<390;i++){
				if(d2[i] > 0 && d1[i] <= d2[k-1]){
					c = s1[i] ;
					u1[c] = u1[c] - 1 ;
					u2[c] = u2[c] - 1 ;
				}
				if(d1[i] == 0){
					a2 = s1[i] ;
				}
			}
			
			QSort(u2, 0, k-1);
			printf("inffered pattern = ");
			for(i=0;i<k;i++){
				if(u1[i] == u2[0]){
					a1 = i ;
					printf("%d ", a1);
				}
			}
			
			printf("\nactual pattern = %d\n", a2);
			
			if(a1 == a2){
				printf("right\n");
				right = right + 1 ;
			}else{
				printf("wrong\n");
				wrong = wrong + 1 ;
			}
		}
	}
	
	float percentage = (float)right/((float)right+(float)wrong)*100 ;
	printf("a percentage of correct answers = %f (if k = %d)", percentage, k);
	
	return 0;
	
}