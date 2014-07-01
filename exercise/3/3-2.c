/* 3-2 高速な整列アルゴリズム等 */

//1.高速な整列アルゴリズムの実装

//* クイックソート

#include  <stdio.h>

void QSort(float x[ ], int left, int right);
void Swap(float x[ ], int i, int j);
void ShowData(float x[ ], int n);
int main(void);

  /* クイックソートを行う */
void QSort(float x[ ], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */

    pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

    while (1) {                    /* 無限ループ */

        while (x[i] < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */

        while (pivot < x[j])       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */

        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }

    if (left < i - 1)              /* 基準値の左に 2 以上要素があれば */
        QSort(x, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)            /* 基準値の右に 2 以上要素があれば */
        QSort(x, j + 1, right);    /* 右の配列を Q ソートする */
}

  /* 配列の要素を交換する */
void Swap(float x[ ], int i, int j)
{
    float temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}


  /* n 個のデータを表示する */
void ShowData(float x[ ], int n)
{
    int i;

    for (i = 0; i < n ; i++)
        printf("%f\r\n", x[i]);
}

int main(void){
	/* ソートする配列 */
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

//2.小さいほうからk(定数)個の要素を取り出す


