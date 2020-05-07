
#include <stdio.h>
#include <stdlib.h>
#include <DOS.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>
#include <math.h>

class point 
{
	private:
	          int x, y  ;
			 			  
	public:
	
	point()  
	{
		x = y = 0 ;
	}	
	point(int a)  
	{
		x = y = a ;
	}
	point(int a , int b)  
	{
		x =  a ;
		y =  b ;
	}
	point(point &p)    
	{
		 this->x = p.x ;
         this->y = p.y;	  
	}
	
	~point()
	{
		printf("destructor is calling .....\n");
	}
	
	void setx(int a)
	{
		x = a ; 	
	}
	void sety(int a)
	{
		y = a ; 	
	}
	
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	void setxy(int a , int b )
	{
		x = a;
		y =b;
	}
	void print()
	{
		cout<< "point data: "<<x<<','<<y<< endl;
	}
};

class line 
{
	private:
	          point start ;
			  point  end  ;			  
	public:
	
	line()  
	{
		start.setxy(0,0);
		end.setxy(0,0);
	}		
	line(int x1, int y1 , int x2 , int y2)  
	{
		start.setxy(x1,y1);
		end.setxy(x2,y2);
	}
	~line()
	{
		printf("destructor is calling .....\n");
	}
	
	void setstart(int x , int y )
	{
		start.setxy(x,y); 	
	}
	void setend(int x , int y )
	{
		end.setxy(x,y); 	
	}
	
	void setstart(point p)
	{
		start = p; 	
	}
	void setend(point p)
	{
		end = p ; 	
	}
	void setline(point p1 , point p2)
	{
		start = p1 ;
		end = p2 ;
	}
	void print()
	{
		cout<<"line data: "<< endl;
		start.print();
		end.print();	
	}
};

class circle 
{
	private:
	          int rad  ;
 			  point center ;			  
	public:
	
	circle()  
	{
		rad=0;
		center.setxy(0,0);
	}		
	circle(int r, int x1 , int y1 )  
	{
		rad = r ;
		center.setxy(x1,y1);
	}
	~circle()
	{
		printf("destructor is calling .....\n");
	}
	
	void setcenter(int x , int y )
	{
		center.setxy(x,y); 	
	}

	void setcenter(point p)
	{
		center = p; 	
	}
	void setcircle(int r , point c )
	{
	   rad = r ;
       center = c ;	   
	}
	
	void print()
	{
		cout<<"circle data: "<< endl;
		cout<<"rad: "<<rad<<endl;
		center.print();
	}
	
	
};

class rect 
{
	private:
	          point p1 ;
			  point p2  ;			  
	public:
	
	rect()  
	{
		p1.setxy(0,0);
		p2.setxy(0,0);
	}		
	rect(int x1, int y1 , int x2 , int y2)  
	{
		p1.setxy(x1,y1);
		p2.setxy(x2,y2);
	}
	~rect()
	{
		printf("destructor is calling .....\n");
	}
	
	void setp1(int x , int y )
	{
		p1.setxy(x,y); 	
	}
	void setp2(int x , int y )
	{
		p2.setxy(x,y); 	
	}
	
	void setp1(point p)
	{
		p1 = p; 	
	}
	void setp2(point p)
	{
		p2 = p ; 	
	}
	void setrect(point x , point y )
	{
	   p1 = x ;
       p2 = y ;	   
	}
	
	void print()
	{
		cout<<"rect data: "<< endl;
		p1.print();
		p2.print();	
	}
};

int main()
{
point p1(5,7) , p2(8,9)  ;
point parr[2];
point* p;
line * ll;
circle* cc;
rect* rr;

line l;
line larr[2] ;

circle c;
circle carr[2] ;

rect r ;
rect rarr[2];  


point* pptr;
line* lptr;
circle* cptr;
rect* rptr;

 
		clrscr();
	
	parr[0]= p1;
    parr[1]= p2;

	larr[0] = l;
	larr[1] = l;
	
	carr[0]=c ;
	carr[1]=c ;
		
	rarr[0]= r;
    rarr[1]= r;
	
	
	
	    l.setline(p1 , p2);
		c.setcircle(2,p1) ;
        r.setrect(p1,p2);
		
 printf("static object\n"); 
		p1.print();
		l.print();
		c.print();
		r.print();
     	getch();
	
	 printf("static array\n"); 
	 parr[0] = p1;
	 parr[1] = p2;
		parr[0].print();
		parr[1].print();
		
	larr[0] = l;
larr[1]	=l;
		larr[0].print();
		larr[1].print();
	
	carr[0]=c;
	carr[1]=c;
		carr[0].print();
		carr[1].print();
	
rarr[0]=r;
rarr[1]	=r;
		rarr[0].print();
		rarr[1].print();
     	getch();
		
  printf("point dynamic\n"); 
  printf("object\n");
		p = new point;
		p[0] = p1 ;
		p[0].print();
  printf("array\n");
		pptr = new point [2];
		pptr[0] = p1 ;
		pptr[1] = p2 ;
		pptr[0].print();
		pptr[1].print();
  getch();


	  printf("line object\n");	
		ll = new line;
		ll[0] = l;
		ll[0].print();
	printf("array\n");
		lptr = new line [2];
		lptr[0] = l;
		lptr[1] = l;
		lptr[0].print();
        lptr[1].print();
getch();
		
		 printf("circle object\n");
		cc = new circle;
		cc[0] = c;
		cc[0].print();
		printf("array\n");
		cptr = new circle [2];
		cptr[0] = c;
		cptr[1] = c;
		cptr[0].print();
		cptr[1].print();
getch();


printf("rect object\n");
		rr = new rect ;
		rr[0] = r;
		rr[0].print();
		printf("array\n");
		rptr = new rect [2];
		rptr[0] = r; 
		rptr[1] = r;
		rptr[0].print();
	    rptr[1].print();
	
	
	 do{
	}while( getch() != 27 );


return 0;
}
