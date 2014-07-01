/* 5-2.c 常微分方程式の解～オイラー法 */

#include<stdio.h>
#include<math.h>

double func(double x, double y){
	return y;
}

double Euler(double x0,double y){
	
	int i = 100 ;
	double h = 0.01;
	double x;
	
	for(x=x0;x<10;x=x+h,i++){
		
		if(i == 100){
			i = 0;
			printf("%lf %lf %lf %lf\r\n", x, y, exp(x), y/exp(x));
		}
		y = y + func(x,y)*h ;
		
	}
}

int main(){
	printf("x        y        exp(x)   y/exp(x)\r\n");
	Euler(0, 1);
}