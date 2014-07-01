/* 7-1.c 課題：手書き文字認識 */

#include<stdio.h>

//まずクイックソートを行うために関数の定義をする

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);
void ShowData(int x[ ], int n);

void QSort(int x[ ], int left, int right){

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


 /* n 個のデータを表示する */
void ShowData(int x[ ], int n){
	
    int i;
	
    for (i = 0; i < n ; i++)
        printf("%d\r\n", x[i]);
}




//ここからmain関数

int main(){
	
	int i ;
	int j ;
	int l ;
	int r ;
	
	
	FILE *fp ;
	fp = fopen("data.txt", "r");
	
	if(fp==NULL) printf("error\n");
	
	int s1[390];//各データのラベル
	int s2[10*39][16*20];//各データの320次元2値ベクトル
	
	for(i=0;i<390;i++){
		int ret = fscanf(fp, "%d,", &s1[i]);
		for(j=0;j<320;j++){
			fscanf(fp, "%d,", &s2[i][j]);
//			printf("%d ", s2[i][j]);
		}
	}
	
		
	int t[10][39]; //正解率を計測したいデータ
	int d1[390]; //各データとのハミング距離(自分自身との距離は0だが、自分自身は答えに含めないので、ここでは1000とした。)
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
			
			for(i=0;i<390;i++){//各データとのハミング距離を計算する
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
			
			
			/* クイックソートからk-近傍近似則を用いる*/
			/* 小さいほうからk個表示する */
			
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