/* 5-1.c �������̉��`�j���[�g���@ */

#include<stdio.h>
#include<math.h>


double func(double x, double a){
	return (x*x - a);  //�֐� f(x)=x^2-a �ƒ�`
}

void Newton(double x,double a){
	double dx = 0.0001;
	double df = (func(x+dx, a) - func(x, a)) / dx;
	
	int i ;
	double w;
	for(i=0; i<100; i++){  //������f(x)=0�̉��𔽕���@�ŋ��߂�
			if(fabs(func(x,a)/df) < 0.0000001){ //�덷�̐�Βl��10^(-7)�ȉ��ŏI��
			break;
		}
		x = x - func(x, a) / df ; //Newton�@�̍X�V��
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
