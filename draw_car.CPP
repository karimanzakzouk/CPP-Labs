
#include <iostream.h>
#include "conio.h"
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>


class Shape 
{
	private:
	      int color;	  
	public:
	
	Shape()  
	{
       color=0 ;
	}		
	Shape(int c)  
	{
        color = c;
	}
	~Shape()
	{
		printf("destructor is calling .....\n");
	}
	
	void set_color(int c )  
	{
		color = c ;	
	}
    int  get_color()  
	{
		return color ;	
	}
    void  draw()
	{
		
	}	
	

};

class Point 
{
	private:
	          int x, y  ;
			 			  
	public:
	
	Point()  //int Point& p
	{
		x = y = 0 ;
	}	
	Point(int a)  
	{
		x = y = a ;
	}
	Point(int a , int b)  
	{
		x =  a ;
		y =  b ;
	}
	Point(Point &p)    
	{
		 this->x = p.x ;
         this->y = p.y;	  
	}
	
	~Point()
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
		cout<< "Point data: "<<x<<','<<y<< endl;
	}
};

class Line : public Shape 
{
	private:
	          Point start ;
			  Point  end  ;			  
	public:
	
	Line() 
	{
		start.setxy(0,0);
		end.setxy(0,0);
	}		
	Line(int x1, int y1 , int x2 , int y2)  
	{
		start.setxy(x1,y1);
		end.setxy(x2,y2);
		set_color(3);
	}
	Line(Point p1 , Point p2)  
	{
		start=p1;
		end=p2;
		set_color(3);
	}
	~Line()
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
	
	void setstart(Point p)
	{
		start = p; 	
	}
	void setend(Point p)
	{
		end = p ; 	
	}
	void setLine(Point p1 , Point p2)
	{
		start = p1 ;
		end = p2 ;
	}
	void print()
	{
		cout<<"Line data: "<< endl;
		start.print();
		end.print();	
	}
	
	void  draw()
	{
          		
	     line(start.getx() , start.gety() , end.getx() , end.gety());

	
	}
};

class Circle : public Shape 
{
	private:
	          int rad  ;
 			  Point center ;			  
	public:
	
	Circle()  
	{
		rad=0;
		center.setxy(0,0);
		set_color(3);
	}		
	Circle(int x1 , int y1,int r )  
	{
		rad = r ;
		center.setxy(x1,y1);
	}
	Circle( Point p,int r )  
	{
		rad = r ;
		center= p;
	}
	~Circle()
	{
		printf("destructor is calling .....\n");
	}
	
	void setcenter(int x , int y )
	{
		center.setxy(x,y); 	
	}

	void setcenter(Point p)
	{
		center = p; 	
	}
	void setCircle( Point c , int r )
	{
	   rad = r ;
       center = c ;	   
	}
	
	int getrad()
	{
		return rad;
	}	
	void print()
	{
		cout<<"Circle data: "<< endl;
		cout<<"rad: "<<rad<<endl;
		center.print();
	}
    void  draw()
	{
	  circle(center.getx(),center.gety(), rad );

	}
};

class Rect : public Shape 
{
	private:
	          Point p1 ;
			  Point p2  ;			  
	public:
	
	Rect()  
	{
		p1.setxy(0,0);
		p2.setxy(0,0);
	}		
	Rect(int x1, int y1 , int x2 , int y2)  
	{
		p1.setxy(x1,y1);
		p2.setxy(x2,y2);
		set_color(3);
	}
	Rect(Point pp1, Point pp2 )  
	{
		p1= pp1;
		p2= pp2;
		set_color(3);
	}
	~Rect()
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
	
	void setp1(Point p)
	{
		p1 = p; 	
	}
	void setp2(Point p)
	{
		p2 = p ; 	
	}
	void setRect(Point x , Point y )
	{
	   p1 = x ;
       p2 = y ;	   
	}
	
	void print()
	{
		cout<<"Rect data: "<< endl;
		p1.print();
		p2.print();	
	}
	void  draw()
	{
	  rectangle(p1.getx() , p1.gety() , p2.getx() , p2.gety());
	}
};

class Pic 
{
	private:
	      int nl,nc,nr ;
          Line* lp;
          Circle* cp;
          Rect* rp;		  
	public:
	
	Pic()  
	{
       nl = nc = nr =0 ;
	   lp=NULL ; cp = NULL ;  rp = NULL;
	}		
	Pic(int a, int b , int c , Line* p1 , Circle* p2 , Rect* p3)  
	{
       nl = a ;   nc = b ;  nr = c ;
	   lp= p1; cp = p2 ;  rp = p3;
	}

	~Pic()
	{
		printf("destructor is calling .....\n");
	 delete [] lp;
	 delete [] cp;
	 delete [] rp;
	}
	void setLines(int l , Line* p)
	{
			nl = l ;
			lp = p ;
    }
	void setCircles(int c , Circle* p )
	{
			nc = c ;
			cp = p ;
	}
	
	void setRects(int r , Rect* p )
	{
			nr = r ;
			rp = p ;		
	}
	void print();
    void paint();
	

};


int main()
{

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int radius = 100;

   clrscr();
   

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "\\BGI\\");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
	  cout<<"Graphics error:"<< grapherrormsg(errorcode)<<endl;
	  cout<<"Press any key to halt:"<<endl;
	  getch();
	  exit(1); /* terminate with an error code */
   }


/*************** my shape *****************************************/

		
	
	   Line l[25]={Line(0,300,640,300 ),Line(65,285,85,285),Line(115,285,185,285), 
	             Line(215,285,235,285),Line(65,285,65,260),Line(235,285,235,260),
				 Line(65,260,100,255),Line(235,260,200,255),Line(100,255,115,235),
				 Line(200,255,185,235),Line(115,235,185,235),Line(106,255,118,238),
				 Line(118,238,118,255),Line(106,255,118,255),Line(194,255,182,238),
				 Line(182,238,182,255),Line(194,255,182,255),Line(121,238,121,255),
				 Line(121,238,148,238),Line(121,255,148,255),Line(148,255,148,238),
				 Line(179,238,179,255),Line(179,238,152,238),Line(179,255,152,255),
				 Line(152,255,152,238) }  ;
	   Circle c[4]={Circle(100,285,15),Circle(200,285,15),Circle(100,285,5),
	                Circle(200,285,5)};

	   Rect r[2]={Rect(0,0,0,0),Rect(0,0,0,0)};
	   
	   Pic p(25,5,0,l,c,r);
	   p.paint();

   /* clean up */
   getch();
   closegraph();
   return 0;

}



	void Pic::print()
	{
		cout<<"Pic data: "<< endl;
		for(int i =0 ; i< nl  && lp ; i++)
		{
			lp[i].print();  
		}
		for(i =0 ; i< nc && cp; i++)
		{
			cp[i].print();
		}
		for( i =0 ; i< nr && rp; i++)
		{
			rp[i].print();
		}	
		
	}
	
	void Pic::paint()
	{
		cleardevice();
		
		//cout<<"Pic : "<< endl;
		
		for(int i =0 ; i< nl ; i++)
		{
			//colors
            setcolor( lp[i].get_color() );	
			
			lp[i].draw(); 
		}
		for( i =0 ; i< nc ; i++)
		{
			cp[i].draw();
		}
		for( i =0 ; i< nr ; i++)
		{
			rp[i].draw();
		}	
	
	
	}