#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>

class complex 
{
	private:
	          float  real , imag ; 
	          static int counter1 ;
			  static int counter2 ;
	public:
	
	complex()
	{
		real = imag = 0 ;
		counter1++;
	}
	complex(float f)
	{
		real = imag = f ;
		counter1++;
	}
	
	complex(float r , float i )
	{
		real=r ; 
		imag=i ;
		counter1++;
		printf("constructor is calling .....\n");
	}	
	~ complex()
	{
		counter2++;
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
	
	static int get_count1()
	{	
		return counter1;
	}
		
	static int get_count2()
	{	
		return counter2;
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
int complex::counter1 = 0  ;
int complex::counter2 = 0  ;
	
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

		 printf("counter1 %d : \n", complex::get_count1() );
		 printf("counter2 %d : \n", complex::get_count2() );
				  
	}while( getch() != 27 );	
	

return 0;	
}


