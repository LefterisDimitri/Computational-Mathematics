#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x)
{
	double f_x;
	
	f_x = exp(-x) - x;
	
	return f_x;
}


int main()
{
	FILE *fp;
	fp = fopen("ex_1_b_table.dat", "w");
	
	int i;
	double x_i, x_i_sun_1;
	double epsilon_t;
	
	//x_i = M_PI/6.0;            // first guess
	x_i = 0.0;
	printf(" Iteration = %d  x_i = %.20lf \n", 0, x_i);
	x_i_sun_1 = x_i - (exp(-x_i) - x_i)/(-exp(-x_i) - 1.0);
	//x_i_sun_1 = x_i - (x_i*x_i + sin(x_i) + exp(x_i) -2.0)/(2.0*x_i + cos(x_i) + exp(x_i));
	
	//x_i_sun_1 = x_i - (exp(-x_i) - x_i)/(-exp(-x_i) - 1.0);
	//x_i_sun_1 = x_i - (exp(x_i) - 2.0*x_i*cos(x_i) - 3.0)/(exp(x_i) - 2.0*cos(x_i) + 2.0*x_i*sin(x_i));
	x_i = x_i_sun_1;
	for(i=1; i<10; i++)
	{
		//x_i_sun_1 = x_i - (exp(x_i) - 2.0*x_i*cos(x_i) -3.0)/(exp(x_i) - 2.0*cos(x_i) + 2.0*x_i*sin(x_i));
		//x_i_sun_1 = x_i - (x_i*x_i + sin(x_i) + exp(x_i) -2.0)/(2.0*x_i + cos(x_i) + exp(x_i));
		if (i == 1)
		{
		x_i_sun_1 = x_i - (exp(-x_i) - x_i)/(-exp(-x_i) - 1.0);
		//x_i_sun_1 = x_i - (x_i*x_i + sin(x_i) + exp(x_i) -2.0)/(2.0*x_i + cos(x_i) + exp(x_i));
			//epsilon_t = 100.0;
			//printf("\n Iteration = %d  x_i = %.20lf epsilon_t = %.20lf \n", i, x_i, epsilon_t);
			//x_i_sun_1 = x_i - (exp(x_i) - 2.0*x_i*cos(x_i) - 3.0)/(exp(x_i) - 2.0*cos(x_i) + 2.0*x_i*sin(x_i));
			
			//x_i_sun_1 = x_i - (exp(-x_i) - x_i)/(-exp(-x_i) - 1.0);
			//epsilon_t = 100.0*fabs((x_i_sun_1 - x_i)/x_i_sun_1);
		}
		else if (i >= 1)
		{
			//x_i_sun_1 = x_i - (exp(x_i) - 2.0*x_i*cos(x_i) - 3.0)/(exp(x_i) - 2.0*cos(x_i) + 2.0*x_i*sin(x_i));
			
			//x_i_sun_1 = x_i - (x_i*x_i + sin(x_i) + exp(x_i) -2.0)/(2.0*x_i + cos(x_i) + exp(x_i));
			x_i_sun_1 = x_i - (exp(-x_i) - x_i)/(-exp(-x_i) - 1.0);
			
			//epsilon_t = 100.0*fabs((x_i_sun_1 - x_i)/x_i_sun_1;
			//printf(" Iteration = %d  x_i = %.20lf epsilon_t = %.20lf \n", i, x_i, epsilon_t);
		}
		//printf("\n Iteration = %d  x_i = %.20lf epsilon_t = %.20lf \n", i, x_i, epsilon_t);
		 
		epsilon_t = 100.0*fabs((x_i_sun_1 - x_i)/x_i_sun_1);
		printf("\n %d  %.15lf %.15lf \n", i, x_i, epsilon_t);
		x_i = x_i_sun_1;
	}
	
	fclose(fp);
	
	return 0;
}
