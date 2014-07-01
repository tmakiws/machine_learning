/* 3-2 �����Ȑ���A���S���Y���� */

//1.�����Ȑ���A���S���Y���̎���

//* �N�C�b�N�\�[�g

#include  <stdio.h>

void QSort(float x[ ], int left, int right);
void Swap(float x[ ], int i, int j);
void ShowData(float x[ ], int n);
int main(void);

  /* �N�C�b�N�\�[�g���s�� */
void QSort(float x[ ], int left, int right)
{
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
void Swap(float x[ ], int i, int j)
{
    float temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}


  /* n �̃f�[�^��\������ */
void ShowData(float x[ ], int n)
{
    int i;

    for (i = 0; i < n ; i++)
        printf("%f\r\n", x[i]);
}

int main(void){
	/* �\�[�g����z�� */
	FILE *fp ;
	float x[100] ;
	int i = 0;
	fp = fopen("inputint.txt", "r") ;
	while(fscanf(fp, "%f", &x[i]) != EOF) {
		i++ ;
	}
    int n = i ;
	int k ;

    QSort(x, 0, n - 1);
	printf("homework 3-2 no.1\r\n");
	ShowData(x, n);
	printf("\r\n homework 3-2 no.2\r\n");
	printf("%d", n);
	printf("input: k= ");
	scanf("%d", &k);
	if(0 < k && k <= n){
		ShowData(x, k);
	}
	else{
		printf("error");
	}
	return 0;
}

//2.�������ق�����k(�萔)�̗v�f�����o��


