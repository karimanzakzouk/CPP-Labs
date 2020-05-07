// + , = , == COMPLEX
#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>
#include <math.h>

class complex 
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
		real = imag= f ;
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
    
	complex operator+(complex &c)
	{
        return complex(real+c.real , imag+c.imag)  ; 
	}
	
	complex& operator++()//prefix
	{
		//complex temp(*this);
		real++;
		imag++;
        //return temp  ; 
		return *this ;
	}
	
	complex operator++(int d)//postfix
	{
		complex temp(*this);
		real++;
		imag++;
        return temp; 
	}
	
	operator float()
	{
		return sqrt(real*real +imag*imag)  ;
	}
	
	complex& operator= (complex &c )
	{
        real=c.real ;
		imag=c.imag ; 
		return *this ; 
	}
	
	int operator== (complex& c )
	{
		return ((real==c.real) && (imag==c.imag )); 
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


int main()
{
complex c1, c2 , c3 ,c4;
float r1 ,i1 ,r2 , i2 ,f;
	
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
		 
		 /*
		 c1.operator=(c2) ; // c1= ??
		 c1.print();
		 
		 printf("c1 == c2 ?  %d \n",  c1.operator==(c2));
		 
		 c3 = c1.operator+(c2) ;
		 c3.print();
*/
		c4 = c1++ ;
		
		printf("\nc4 = c1++  =  \n" );
		c4.print();
		printf("\nc1  =  \n" );
		c1.print();

		c3 = ++c2 ;
		
		printf("\nc3 = ++c2 =  \n" );
		c3.print();
		printf("\nc2  =  \n" );
		c2.print();

        f = float(c2);
        printf("\nfloat = %f \n",f );
		 
	}while( getch() != 27 );	
	

return 0;	
}


