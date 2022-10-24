#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double t;
double h;

double f(int i, double t, double *X)
{
	double f;
	
	f = X[i]*t*t - 1.1*X[i];
	
	return f;
}
int main()
{
	FILE *fp;
	fp = fopen("ask_1_set_3.dat","w");
	
	int i, N;
	double X[2000];
	double Xn[2000];
	h = 0.001;
	N = 2000; //8
	t = 0.0;
	X[0] = 1.0;
	fprintf(fp,"%lf %lf \n", t, X[0]);
	for(i=0; i<N; i++)
	{
		t = t + 0.001;
		X[i+1] = X[i] + f(i,t,X)*h;
		fprintf(fp,"%lf %lf \n", t, X[i]);
	}
	
	fclose(fp);
	return 0;
}
