

#include <iostream.h>
#include "conio.h"
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>


class Geoshape
{
	protected:
	      float dim1 , dim2;	  
	public:
	
	Geoshape()  
	{
       dim1 = dim2 = 0 ;
	}		
	Geoshape(float f1, float f2)  
	{
        dim1 = f1; dim2 = f2;
	}
	~Geoshape()
	{
		printf("destructor is calling .....\n");
	}
	
	void set_dim1(float f )  
	{
		dim1 = f ;	
	}
    float  get_dim1()  
	{
		return dim1 ;	
	}
	void set_dim2(float f )  
	{
		dim2 = f ;	
	}
    float  get_dim2()  
	{
		return dim2 ;	
	}
	virtual float calc_area()=0;


};

class Circle : protected Geoshape 
{
	private:
 			  			  
	public:
	
	Circle():Geoshape(0,0)  
	{	
	}		
	Circle(float r) : Geoshape(r,r)
	{	
	}
	~Circle()
	{
		printf("destructor is calling .....\n");
	}
	float calc_area()
	{
		return dim1*dim2*3.14  ;
	} 
    void set_rad(float f)
	{
		dim1 = dim2 = f;
	}

};

class Rect : public Geoshape 
{
	private:
			  
	public:
	
	Rect():Geoshape(0,0)  
	{}
	Rect(float w, float h)  :Geoshape(w,h)
	{}
	~Rect()
	{
		printf("destructor is calling .....\n");
	}
	virtual float calc_area()
	{
		return dim1*dim2  ; 
	}
	
};

class Square : protected Rect 
{
	private:
			  
	public:
	
	Square():Rect(0,0) 
	{}
	Square(float l)  : Rect(l,l)
	{}
	~Square()
	{
		printf("destructor is calling .....\n");
	}
	float calc_area()
	{
		return dim1*dim2  ; 
	}
    void set_length(float f)
	{
		dim1 = dim2 = f;
	}

};

class Triangle : public Geoshape 
{
	private:
			  
	public:
	
	Triangle():Geoshape(0,0)  
	{}
	Triangle(float b, float h)  :Geoshape(b,h)
	{}
	~Triangle()
	{
		printf("destructor is calling .....\n");
	}
	float calc_area()
	{
		return dim1*dim2*0.5  ; 
	}
	
};


int main()
{	
Rect  r(5,4);
Circle  c(20);
Triangle  t(10,20);
Square   s(20); 

//Geoshape g ;
Geoshape *gb ;
Rect *rb ;
//gb =&c;
//g =&r;
//g =&t;

//gb = &g;
gb = (Geoshape*) &c;
rb = (Rect*) &s;

//gb->set_dim1(40); 
//gb->set_length(40);

cout<< c.calc_area()<<endl;
cout<< s.calc_area()<<endl;

 //cout<< r.calc_area()<<endl;
 //cout<< t.calc_area()<<endl;
 //cout<< s.calc_area()<<endl;
 
 
 getch();
 return 0;

}
