#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("ex_2_b_table.dat", "w");
	int i;
	double x_i_sun_1, x_i;
	double epsilon_a, epsilon_t;
	
	x_i = -0.5;                    // first guess
	printf(" Iteration = %d  x_i = %.15lf \n", i, x_i);
	
	for(i=1; i<100; i++)
	{
		x_i_sun_1 = - sqrt(2.0*exp(x_i)/3.0);
		
		if (i==0)
		{
			epsilon_t = 100.0;
			printf(" Iteration = %d  x_i = %.15lf epsilon_t = %.15lf \n", i, x_i, epsilon_t);
			
		}
		else
		{
			epsilon_t = 100.0*(x_i_sun_1 - x_i)/x_i_sun_1;
			fprintf(fp," %d  %.15lf %.15lf \n", i, x_i, epsilon_t);
			x_i = x_i_sun_1;
		}
		//x_i = x_i_sun_1;
	}
	fclose(fp);
	return 0;
}
