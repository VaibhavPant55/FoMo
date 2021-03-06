#include "header.h"
#include <cmath>

const int eqx=120;
const int eqy=50;
const int eqz=100;

void builtingrid(const int x, const int y, const int z, tgrid grid)
{
// x, y, z are the number of pixels in the respective direction (usually you'd want to use eqx, eqy, eqz)
	double mmperpixel=.5;
	for (int i=0; i<x; i++)
		for (int j=0; j<y; j++)
			for (int k=0; k<z; k++)
			{
				grid[0].push_back((i-x/2.)*mmperpixel*1000.);
				grid[1].push_back((j-y/2.)*mmperpixel*1000.);
				grid[2].push_back((k)*mmperpixel*1000.);
			}
};

double density(const double r, const double phi, const double z)
{
	double value;
	if (2*r/width/1000.<1-thickness/2) value=rhoint*(1-alpha*sin(M_PI*z));
	else if (2*r/width/1000.>1+thickness/2) value=rhoint/contrast*(1-alpha*sin(M_PI*z));
	else value=rhoint/2*(1-alpha*sin(M_PI*z))*((1+1/contrast)-(1-1/contrast)*sin(M_PI/thickness*(2*r/width/1000.-1)));
	value*=1000000000; // put the density in per cm^3
	return value;
};

double temperature(const double r, const double phi, const double z)
{
	return 1000000.;
};

