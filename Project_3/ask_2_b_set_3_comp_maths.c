#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double t;
double h;


void RK(double t, double* X, double* Xn)  
{
	int l;
	double k1[1];
	double k2[1];
	double k3[1];
	double k4[1];
	double dotX[1];
	double Y[1];
	
	for(l=0; l<1; l++)
	{
	   Y[l] = X[l];
    }

	for(l=0; l<1; l++)
	{
		derivatives(t, Y, dotX);
		k1[l] = h*dotX[l];
	}

	for(l=0; l<1; l++)
	{	 
	   Y[l] = X[l] + 0.5*k1[l];
	}
		
	for(l=0; l<1; l++)
	{
		derivatives(t, Y, dotX);
	    k2[l] = h*dotX[l];
	}

	for(l=0; l<1; l++)
	{
	   Y[l] = X[l] + 0.5*k2[l];
	}

	for(l=0; l<1; l++)
	{
		derivatives(t, Y, dotX);
	    k3[l] = h*dotX[l];
	}

	for(l=0; l<1; l++)
	{
	   Y[l] = X[l] + k3[l];
	}
	
	for(l=0; l<1; l++)
	{
		derivatives(t, Y, dotX);
	    k4[l] = h*dotX[l];
	}
	
	for(l=0; l<1; l++)
	{
		Xn[l] = X[l] + (k1[l] + 2.0*k2[l] + 2.0*k3[l] + k4[l])/6.0;
	}
			
}

void derivatives(double t, double* Y, double* dotX)
{
	dotX[0] = Y[0]*t*t - 1.1*Y[0];	
}


int main()
{
	FILE *fp;
	fp = fopen("ask_2_set_3.dat","w");
	
	int i, N;
	double X[1];
	double Xn[1];
	h = 0.001;
	N = 2000; //8
	t = 0.0;
	X[0] = 1.0;
	fprintf(fp,"%lf %lf \n", t, X[0]);
	for(i=0; i<N; i++)
	{
		t = t + 0.001;
		RK(t,X,Xn);
		X[0] = Xn[0];
		fprintf(fp,"%lf %lf \n", t, X[0]);
	}
	
	fclose(fp);
	return 0;
}
