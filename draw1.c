
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
		start.setxy(0,0);
		end.setxy(0,0);
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

	void setcenter(class p)
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
point parr[2]= {(1,1),(2,2)} ;

line l(10,20,30,40) ;
line larr[2] = {{(1,1),(2,2)} , {(1,1),(2,2)}};

circle c(2,p1) ;
circle carr[2] = {{1,(2,2)} , {1,(2,2)}};

rect r(p1,p2) ;
rect rarr[2]={{(1,1),(2,2)} , {(1,1),(2,2)}};   

point* pptr;
line* lptr;
circle* cptr;
rect* rptr;

  do{
		clrscr();
		p1.printp();
		l.printl();
		c.printc();
		r.print();
		
		point p = new point; 
		p = p1 ;
		p.print();
        pptr = new point [2];
		pptr[0].print();
		
	    line ll = new line; 
		ll = l;
		ll.print();
		
        lptr = new line [2];
		lptr[0].print();
		
		circle cc = new circle; 
		cc = c;
		cc.print();
		
        carr = new circle [2];
		carr[0].print();
		
		rect r = new rect ;
		rr = r;
		rr.print();
		
		rptr = new rect [2];
		rptr[0].print();
	
	}while( getch() != 27 );	
	

return 0;	
}
