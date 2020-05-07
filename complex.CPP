#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>

struct complex 
{
	private:
	          float  real , imag ; 
	
	public:
	
	complex()
	{
		real = imag =0 ;
	}
	complex(float f)
	{
		real = imag=f ;
	}
	
	complex(float r , float i )
	{
		real=r ; 
		imag=i ;
		printf("constructor is calling .....\n");
	}	
	~ complex()
	{
		printf("destructor is calling .....\n");
	}
	
	void set_real(float r)
	{
		real = r;
	}
	void set_imag(float i)
	{
		imag = i ;
	}
	
	float get_real()
	{
		return real;
	}
	float get_imag()
	{
		return imag;
	}
    
	void print()
	{
		if (imag < 0 )
		{
			 printf("\n%f   %f   i\n", real , imag);
		}
		else
		{
		     printf("\n%f  +  %f   i\n", real , imag);
		}
	}
	
};
complex   c1, c2 , c3 , c4;


	complex add(complex c1, complex c2)
	{
	    complex res ; 
		res.set_real(c1.get_real() + c2.get_real());
        res.set_imag(c1.get_imag() + c2.get_imag());
	
		return res;
	}
	
	complex sub(complex c1, complex c2)
	{
	    complex res; 
		res.set_real(c1.get_real() - c2.get_real());
        res.set_imag(c1.get_imag() - c2.get_imag());
		return res;
	}
	
int main()
{
float r1 ,i1 ,r2 , i2 ;
	
  do{
		clrscr();

		
		printf("enter  real part for num 1  : \n");
		scanf("%f",&r1);
		printf("enter  imag part for num 1  : \n");	 
		scanf("%f",&i1);

		printf("enter   real part for num 2 : \n");	 
		scanf("%f",&r2);
		printf("enter   imag part for num 2 : \n");
		scanf("%f",&i2);
		
		 c1.set_real(r1);
         c1.set_imag(i1);
		 
		 c2.set_real(r2);
         c2.set_imag(i2);
		 
         c3 =  add(c1 , c2);
		 c4 =  sub(c1 , c2);

		 c3.print();
		 c4.print();

				  
	}while( getch() != 27 );	
	

return 0;	
}


