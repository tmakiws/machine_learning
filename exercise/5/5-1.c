/* 5-1.c 方程式の解～ニュートン法 */

#include<stdio.h>
#include<math.h>


double func(double x, double a){
	return (x*x - a);  //関数 f(x)=x^2-a と定義
}

void Newton(double x,double a){
	double dx = 0.0001;
	double df = (func(x+dx, a) - func(x, a)) / dx;
	
	int i ;
	double w;
	for(i=0; i<100; i++){  //方程式f(x)=0の解を反復解法で求める
			if(fabs(func(x,a)/df) < 0.0000001){ //誤差の絶対値が10^(-7)以下で終了
			break;
		}
		x = x - func(x, a) / df ; //Newton法の更新式
	}
	printf("Newton's method %lf \n", x) ;
}


int main(){
	double x0;
	double a;
	double w;
	
	printf("input: a = ");
	scanf("%lf", &a);
	printf("initial value = ");
	scanf("%lf", &w);
	x0 = fabs(w);
	
	Newton(x0, a);
	
	printf("sqrt a = %lf", sqrt(a));
	return 0;
}
