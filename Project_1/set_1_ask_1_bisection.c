#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f_x_l(double x)
{
	double f_x_low;
	
	f_x_low = exp(x) - 2.0*x*cos(x) - 3.0;
	//f_x_low = x*x + sin(x) + exp(x) - 2.0;
	
	return f_x_low;
}

double f_x_u(double x)
{
	double f_x_upper;
	
	f_x_upper = exp(x) - 2.0*x*cos(x) - 3.0;
	//f_x_upper = x*x + sin(x) + exp(x) - 2.0;
	
	return f_x_upper;
}


int main()
{
	FILE *fp;
	FILE *fp1;
	
	fp = fopen("ex_1_table.dat", "w");
	fp1 = fopen("ex_1_1.dat", "w");
	
	int n, i;
	//double f_1, f_2, x;
	double x_l, x_u, x_r;
	double epsilon_a, epsilon_s, x_r_new, x_r_old;
	//double true_value, approximation;
	
	x_l = 0.01; // first guess
	x_u = 0.99; // first guess
	
	f_x_l(x_l);
	f_x_u(x_u);
	
	//printf("f_x_l = %lf \n f_x_u = %lf \n", f_x_l(x_l), f_x_u(x_u));
	
	//x_r = (x_l + x_u)/2.0;
	//printf(" x_r = %lf \n", x_r);

	//f_1_x_l = exp(x_l) - 2.0*x*cos(x_l) - 3.0;               // x --> (0,2)
	//f_1_x_u = exp(x_u) - 2.0*x*cos(x_u) - 3.0;
	
	//f_2 = x*x + sin(x) + exp(x) - 2.0;                    // x --> (0,1)
	
	//true_value = 0.0;
	n = 10; // 10 significant digits
	epsilon_s = 0.5*pow(10,2-n); //0.5/(10.0*10.0*10.0*10.0*10.0*10.0*10.0*10.0); //0.5/(10.0*10.0*10.0*10.0*10.0*10.0*10.0*10.0*10.0*10.0);
	epsilon_a = 100.0;
	printf(" epsilon_s = %.20lf \n", epsilon_s);
	
	
	i = 1;
	do
	{	    
	    x_r = (x_l + x_u)/2.0;
	    
	    if(i==1)
	    {
	    	x_r_old = x_r;
		}
	    
	    if(i>=2)
	    {
	    	x_r_new = x_r;
	    	epsilon_a = 100.0*fabs((x_r_new-x_r_old)/x_r_new);
	    	x_r_old = x_r_new;
	    }
	    fprintf(fp, "%d %.15lf %.15lf %.15lf %.15lf \n", i, x_l, x_u, x_r, epsilon_a);
	    fprintf(fp1,"%d %.15lf %.15lf %.15lf \n", i, x_u - x_l, x_r, f_x_u(x_r));
	   
	    if (f_x_l(x_l)*f_x_u(x_r) < 0.0)
	    {
	    	x_u = x_r;
	    }
	    else if (f_x_l(x_l)*f_x_u(x_r) > 0.0)
	    {
		    x_l = x_r;
	    }
	    else if (f_x_l(x_l)*f_x_u(x_r) == 0.0)
	    {
		    printf("The root is x_r = %lf", x_r);
		    return 1;
	    }
	    i = i + 1; 
	    //system("pause");
	}while(epsilon_a > epsilon_s); //epsilon_a > epsilon_s fabs(f_x_u(x_r)) > 5.0*pow(10,-10)
	printf("%.15lf", f_x_u(1.304630181016983));
	fclose(fp);
	fclose(fp1);
	
	return 0;
}
