//pass by value
#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>

class stack 
{
	private:
	          int size , tos ; 
			  int *stk;
			  
	          static int counter1 ;
			  static int counter2 ;
	public:
	
				stack();
				stack(int s);
				~ stack();
				int isempty();
				int isfull();
				int push(int data);
				int pop(int &data);
				friend void viewcontent(stack s);
	
	static int get_count1()
	{	
		return counter1;
	}
		
	static int get_count2()
	{	
		return counter2;
	}
	
	
};


int stack::counter1 = 0  ;
int stack::counter2 = 0  ;

int main()
{
stack  s1(3);
int t ;	
  
		clrscr();
		
         if (s1.push(1) ==0 )
			 printf("stack is full...\n" ) ;
		 else
			 printf("done....\n" ) ;
		 
		 viewcontent(s1);
		 if (s1.push(2) ==0 )
			 printf("stack is full...\n" ) ;
		 else
			 printf("done....\n" ) ;
		 
		  viewcontent(s1);

		 if (s1.pop(t) ==0 )
		 {
  			  printf("stack is empty...\n" ) ;
	          
		 }
		 else
		 {    printf("pop : %d \n", t );
			  printf("done....\n" ) ;
		 }
		 
		 viewcontent(s1);
		 
		 		 if (s1.pop(t) ==0 )
		 {
  			  printf("stack is empty...\n" ) ;
	          
		 }
		 else
		 {    printf("pop : %d \n", t );
			  printf("done....\n" ) ;
		 }
		 		 if (s1.pop(t) ==0 )
		 {
  			  printf("stack is empty...\n" ) ;
	          
		 }
		 else
		 {    printf("pop : %d \n", t );
			  printf("done....\n" ) ;
		 }
		 
		 viewcontent(s1);
		
		 printf("counter1 : %d  \n", stack::get_count1() );
		 printf("counter2 : %d  \n", stack::get_count2() );
		 
		 
		
	do{			  
	}while( getch() != 27 );	
	

return 0;	
}


	stack::stack()
	{
		size = 10;
		tos = 0;
		stk = new int[size];
		counter1++;
	}
	stack::stack(int s)
	{
		size = s ;
		tos = 0 ;
		stk = new int[size];
		counter1++;
	}

	stack::~stack()
	{
		counter2++;
		printf("destructor is calling .....\n");
		printf("counter2 : %d  \n", stack::get_count2() );
		getch();
		if(stk)   delete[]stk;
		}
	
	int stack::isempty()
	{
		return !tos;
		
	}
	int stack::isfull()
	{
		return (tos == size);
		
	}
	int stack::push(int data)
	{
		if( isfull( ))   return 0;
		stk[tos] = data;
		tos++;
		return 1 ;
	}
    int stack::pop(int &data)
	{
		if( isempty( ))   return 0;
		
		tos--;
		data = stk[tos] ;
		return 1 ;
	}
	
	
	void viewcontent(stack s)
	{
		for(int i =0 ; i< s.tos ; i++ )
		{
				 printf("%d  \n", s.stk[i] );
		}
		if(s.tos == 0)
			printf("empty stack\n")      ;
		
	}
	