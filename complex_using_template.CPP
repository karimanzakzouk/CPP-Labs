
#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>
#include <math.h>



class Complex 
{
	private:
	          float  real , imag ; 	
	public:
	
	Complex()
	{
		real = imag =0 ;
	}
	Complex(float f)
	{
		real = imag= f ;
	}
	
	Complex(float r , float i )
	{
		real=r ; 
		imag=i ;
		printf("constructor is calling .....\n");
	}	
	~ Complex()
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
    
	Complex operator+(Complex &c)
	{
        return Complex(real+c.real , imag+c.imag)  ; 
	}
	
	Complex& operator++()//prefix
	{
		//Complex temp(*this);
		real++;
		imag++;
        //return temp  ; 
		return *this ;
	}
	
	Complex operator++(int d)//postfix
	{
		Complex temp(*this);
		real++;
		imag++;
        return temp; 
	}
	
	operator float()
	{
		return sqrt(real*real +imag*imag)  ;
	}
	
	Complex& operator= (Complex &c )
	{
        real=c.real ;
		imag=c.imag ; 
		return *this ; 
	}
	
	int operator== (Complex& c )
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


template <class T>

class Stack 
{
	private:
	          int size , tos ; 
			  T *stk;			  
	          static int counter1 ;
			  static int counter2 ;
	public:	
	            Stack(Stack &s);
				
				Stack()
				{
					size = 10;
					tos = 0;
					stk = new T [size];
					counter1++;
				}
				Stack(int s)
				{
					size = s;
					tos = 0;
					stk = new T [size];
					counter1++;
				}
				~ Stack()
				{
					counter2++;
					if(stk)   
					delete [] stk;
				}
				int isempty();
				int isfull();
				int push(T data);
				int pop(T &data);
				friend void viewcontent(Stack &s);// &
	
	static int get_count1()
	{	
		return counter1;
	}
		
	static int get_count2()
	{	
		return counter2;
	}
	
	Stack& operator=(Stack &s);
	
	
};


int main()
{
Complex  C1(1.1,2.2) , C2(3.3,4.4)	;

Stack<Complex>  s1(2) ;
  
		clrscr();
		s1.push(C1);
		s1.push(C2);
	
		//viewcontent(s1);
		//cout<< s1.get_count1() <<endl;	
		//out<< s1.get_count2() <<endl;
		
            //C1.print();	
			//C2.print();	
			
			
			
			//cout<< s1.get_real() <<endl;
			//cout<< s1.get_imag() <<endl;
			
	    //cout<< Stack<int>::get_count1() <<endl;
		
		
		cout<<".................................."<<endl;	
			
	
	do{			  
	}while( getch() != 27 );	
	

return 0;	
}



template <class T>
int Stack<T>::counter1=0;
template <class T>
int Stack<T>::counter2=0;


template <class T>
Stack<T>::Stack(Stack<T> &s)
{
		size = s.size;
		tos = s.tos;
		stk = new T [size];
		counter1++;
}	
	
template <class T>	
int Stack<T>::push(T data)
{
		if( isfull( ))   return 0;
		stk[tos] = data;
		tos++;
		return 1 ;
}
	
	
template <class T>	
int Stack<T>::pop(T &data)
{
		if( isempty( ))   return 0;
		tos--;
		data = stk[tos] ;
		return 1 ;
}
	
template <class T>	
void viewcontent(Stack<T> &s)// &
{
		for(int i =0 ; i< s.tos ; i++ )
		{			 
				 cout<< s.stk[i] << endl;
		}
		if(s.tos == 0)
			printf("empty Stack\n") ;	
}


template <class T>		
	Stack<T>& operator=(Stack<T> &s)
	{
		tos = s.tos;
		size = s.size;
		delete [] stk ;
		stk = new T [size];
		for(int i =0 ; i< tos ; i++)
		{
			stk[i] = s.stk[i];	
		}
		return *this ;
	}

template <class T>	
	int Stack<T>::isempty()
	{
		return !tos;
		
	}
template <class T>	
	int Stack<T>::isfull()
	{
		return (tos == size);
		
	}	