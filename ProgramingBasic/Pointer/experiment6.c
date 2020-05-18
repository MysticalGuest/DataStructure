#include<stdio.h>
#include<math.h>
#include<Windows.h>

double integral(double a, double b, double (*p)(double)){
	double area = 0, t=a, k;
	int i, n = 10000000;
	k = (b-a)/n;
	for(i=0; i<n; i++){
		t = t+k;
		area = area+(*p)(t)*k;
	}
	return area;
}
double x2(double x){
	double result;
	result = x*x;
	return result;
} 
void main(){
	printf("%.2lf\n", integral(0, 3, x2));
	printf("%.2lf\n", integral(0, 3.1415926, sin));

  system("pause");
}