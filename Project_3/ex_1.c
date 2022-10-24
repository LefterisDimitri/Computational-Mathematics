#include <stdio.h>
#include <math.h>

double f(int i, double x)
{
	double f;
	
	f = x*exp(2.0*x);
	
	return f;
}


int main ()
{
	int i;
	double a, b;
	double h, n;
	double X[9];
	double I1, I2;
	
	n = 1000.0;
	a = 0.0;
	b = 3.0;
	h = (b-a)/n;
		
	for(i=0; i<=n; i++)
	{
		X[i] = h*i;
		printf("%lf \n", X[i]);
    }
    
	I1 = (h/3.0)*(f(0,X[0]) + 4.0*f(1,X[1]) + 2.0*f(2,X[2]) + 4.0*f(3,X[3]) + 2.0*f(4,X[4]) + 4.0*f(5,X[5]) + 2.0*f(6,X[6]) + 4.0*f(7,X[7]) + f(8,X[8]));
	printf("I1 = %lf \n", I1);
	
	I2 = (b-a)*(f(0,X[0]) + 4.0*(1.5*exp(2.0*1.5)) + f(8,X[8]))/6.0;
	printf("I2 = %lf", I2);
	
	
	
	return 0;
}
