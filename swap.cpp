#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>

int a , b ;

void swap_v()
{
	int temp = a; 
	a= b ;
	b=temp;
	
}
void swap_p(int* x , int* y )
{
	int temp = *x; 
	*x=*y ;
	*y=temp;
	
}
void swap_r(int &x , int &y )
{
	int temp = x; 
	x=y ;
	y=temp;
	
}


int main()
{
int op ,n1 , n2;
int num1,num2;

  do{
		clrscr();
         printf("enter your choice\n");
		 printf("enter 1 to swap by value\n");
		 printf("enter 2 to swap by address\n");
		 printf("enter 3 to swap by  reference\n");
		 scanf("%d",&op);
		 
		 	   printf("enter n1 : \n");
			   scanf("%d",&n1);
			   printf("enter n2 : \n");
			   scanf("%d",&n2);

			   
		 switch(op)
		 {
			 case 1 :  			   
			   printf("after swapping  : \n");
			   a = n1 ; 
			   b = n2 ;
               swap_v();
		       printf("n1 : %d  \t n1 : %d  \n",a,b);
			   break;
			   
			 case 2 :  
             swap_p(&n1, &n2);
			 printf("n1 : %d  \t n1 : %d  \n",n1,n2);
			   break;
			   
			   case 3 :
			   swap_r( n1 , n2 );
			   printf("n1 : %d  \t n1 : %d  \n",n1,n2);
			   break;
	 
		 }
		   		  
	}while(  getch() != 27 );	
	

return 0;	
}