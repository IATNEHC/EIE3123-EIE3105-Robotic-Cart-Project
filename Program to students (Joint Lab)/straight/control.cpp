#include <math.h>

int CL = 0;
int CR = 0;

int ECL = 0;
int ECR = 0;

int errorL = 0;
int errorR = 0;

int errorL_Last = 116;
int errorR_Last = 84;

int L_inter = 0;
int R_inter = 0;

int SD = 0;
int SD_Last = 0;

int N = 1;
int i = 1;

int L_Last = 15000;
int R_Last = 15000;

void control(int &left, int &right) 
{
	// default speed
	//left = 15000;
	//right = 15000;
	
	if(i < 100)
	{
		CL += left;
		CR += right;
		
		ECL += (130*(1-exp(-0.05*N)));
		ECR += (95*(1-exp(-0.05*N)));
		
		left = L_Last;
		right = R_Last;
		
		i++;
		N++;
	}
	else
	{
		CL += left;
		CR += right;
		
		ECL += (130*(1-exp(-0.05*N)));
		ECR += (95*(1-exp(-0.05*N)));
		
		errorL = (ECL - CL)/100;
		errorR = (ECR - CR)/100;
		
		L_inter = (L_Last + 2243*(errorL) - 2237*(errorL_Last));
		R_inter = (R_Last + 3166*(errorR) - 3158*(errorR_Last));
		
		SD	= (L_inter + R_inter);
		
		left = (12000 - (0.5*SD - 0.4996*SD_Last));
		L_Last = left;
		
		right = (12000 + (0.505*SD - 0.4996*SD_Last));
		R_Last = right;
		
		errorL_Last = errorL;
		errorR_Last = errorR;
		
		SD_Last = SD;
		
		N++;
		i = 0;
		CL = 0;
		CR = 0;
		ECL = 0;
		ECR = 0;
	}
}
