#include<cstdio>
#include<cmath>
using namespace std;
float f(float x,float y,float z)
{
	float a=x*x+9.0/4.0*y*y+z*z-1;
	return a*a*a-x*x*z*z*z-9.0/80.0*y*y*z*z*z;
}
float h(float x,float z)
{
	for(float y=1.0;y>=0.0;y-=0.001)
	{
		if(f(x,y,z)<=0.0)return y;
	}
	return 0.0;
}
int main()
{
	for(float z=1.5;z>-1.5;z-=0.05)
	{
		for(float x=-1.5;x<1.5;x+=0.025)
		{
			float v=f(x,0.0,z);
			if(v<=0.0)
			{
				float y0=h(x,z);
				float ny=0.01;
				float nx=h(x+ny,z)-y0;
				float nz=h(x,z+ny)-y0;
				float nd=1.0/sqrt(nx*nx+ny*ny+nz*nz);
				float d=(nx+ny-nz)*nd*0.5+0.5;
				putchar(".:-=+*#%@"[(int)(d*5.0f)]);
			}
			else
				putchar(' ');
		}
		puts("");
	}
	return 0;
}
