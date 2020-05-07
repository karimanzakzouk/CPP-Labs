
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

class String 
{
	private:
	    int size;
	    char* str; 	
			  
	public:
		String();
		String(int s);
		String(String& s);
		~String();
		
		char charAt(int index);
		int indexOf(char ch);
		int indexOf(int start, char ch);
		void resize(int s);
		
		String subString(int start );
		String subString(int start , int end);	
		String concat(String s2);
		
		String& operator=(String& s2);
		char& String::operator[](int i );
		String operator+(String s2);
		String& operator+=(String s2);
		
		static String uppercase(String &s);
		static String lowercase(String &s);
		
		friend istream& operator >> (istream& in, String& a );
		friend ostream& operator << (ostream& out,String& a);  
	
};


int main()
{
String s , s1 , s2 ;
char ch ;
int i , start , end ,op;

  do{
		clrscr();
		flushall();
		
cout<< "enter 1 to test << , >> : "  << endl;
cout<< "enter 2 to test charAt(i) : "  << endl;
cout<< "enter 3 to test indexOf(ch) : "  << endl;
cout<< "enter 4 to test indexOf(start, ch) : "  << endl;
cout<< "enter 5 to test =  : "  << endl;
cout<< "enter 6 to test subString(start) : "  << endl;
cout<< "enter 7 to test subString(start , end ) : "  << endl;
cout<< "enter 8 to test  uppercase : "  << endl;
cout<< "enter 9 to test  lowercase : "  << endl;
cout<< "enter 10 to test concatenation  : "  << endl;
cout<< "enter 11 to test  +=  : "  << endl;
cout<< "enter 12 to test  + : "  << endl;
cout<< "enter 13 to test  [] : "  << endl;
cin >> op ;

switch(op)
{
	case 1 :
		// << , >>
		cout<< "enter string : "  << endl;
		cin >> s ;
        cout<< "string : "  << endl;
		cout << s ;
        getch();
	   break ;

	case 2 :
		//charAt(i)
		cout<< "enter index : "  << endl;
		cin >> i ;
		printf("char : %c  \n", s.charAt(i));
		getch();
		break ;
		
	case 3 :	
		//indexOf(ch)
		cout<< "enter char : "  << endl;
		cin >> ch ;
		
		i =  s.indexOf(ch);
		cout<< "index = "  << i<< endl;
		getch();
		break ;
		
	case 4:
		//indexOf(start, ch)
		cout<< "enter start : "  << endl;
		cin >> start ;
		cout<< "enter char : "  << endl;
		cin >> ch ;
		
		i = s.indexOf(start, ch);
		cout<< "index = "  << i<< endl;
		getch();
		break ;
	case 5:	
		// = 
		cout<< " = : "  << endl;
	    cout<< "enter string1 : "  << endl;
		cin >> s1 ;
	    cout<< "enter string2 : "  << endl;
		cin >> s2 ;
		s1 = s2 ;
		cout<< "string1 : "  << endl;
		cout << s1 ;
        getch();
        break ;
		
	case 6:		
		// subString(start)
		cout<< "subString(start) : "  << endl;
	    cout<< "enter string : "  << endl;
		cin >> s1 ;
	    cout<< "enter start : "  << endl;
		cin >> start ;
		s =  s1.subString(start);
		cout<< "string : "  << endl;
		cout << s ;
        getch();
		break ;
		
	case 7:	
	    // subString(start , end )
		cout<< "subString(start , end ) : "  << endl;
	    cout<< "enter string : "  << endl;
		cin >> s1 ;
	    cout<< "enter start : "  << endl;
		cin >> start ;
	    cout<< "enter end : "  << endl;
		cin >> end ;
		s =  s1.subString(start , end );
		cout<< "string : "  << endl;
		cout << s ;
        getch();
		break ;
		
	case 8:
	    //uppercase
		cout<< "uppercase : "  << endl;
        cout<< "enter string : "  << endl;
		cin >> s1 ;
		s = String::uppercase(s1);
	    cout<< "string : "  << endl;
	    cout << s ;
		getch();
		break ;
		
	case 9:	
	    //lowercase
        cout<< "lowercase : "  << endl;
		cout<< "enter string : "  << endl;
		cin >> s1 ;
		s = String::lowercase(s1);
	    cout<< "string : "  << endl;
	    cout << s ;
		getch();
		break ;
	
    case 10:	
		// concat
		cout<< "concat : "  << endl;
	    cout<< "enter string1 : "  << endl;
		cin >> s1 ;
	    cout<< "enter string2 : "  << endl;
		cin >> s2 ;
	    s = s1.concat(s2);
		cout<< "string : "  << endl;
	    cout << s ;
		getch();
		break ;
		
	case 11:	
		// += 
		cout<< "+= : "  << endl;		
		cout<< "enter string1 : "  << endl;
		cin >> s1 ;
		cout<< "enter string2 : "  << endl;
		cin >> s2 ;
		s1+=s2 ;
		cout<< "string1 : "  << endl;
		cout << s1 ;
        getch();
		break ;
		
	case 12: 
	    // +
		cout<< " +  : "  << endl;
		cout<< "enter string1 : "  << endl;
		cin >> s1 ;
		cout<< "enter string2 : "  << endl;
		cin >> s2 ;
		
		s = s1 +  s2 ;
		cout<< "conc string : "  << endl;
		cout << s ;
		getch();
		break ;

	case 13:	
        // [] 
		cout<< "enter string : "  << endl;
		cin >> s ;		
	    s[0] = 't' ; 
        cout << s ;
		break ;

}
	}while( getch() != 27 );	
	

return 0;	
}

String::String()
{   
	size = 20;
    str  = new char [size];		
	for(int i=0; i<size; i++)
	{
		str[i]=' ';
	}
	str[i]='\0';
}

String::String(int s)
{
    size = s;
    str  = new char [s];
			
	for(int i=0; i<size; i++)
	{
		str[i]=' ';
	}
	str[i]='\0';
}
	
String::String(String& s)
{
    size = s.size;
	str  = new char[size+1];
	
	for(int i=0; (i<size);i++)
	{
		str[i]=s.str[i];
	}
	str[i]='\0';
}

String::~String()
{
	delete [] str;
}

void String::resize(int s)
{
		char* temp; 
		temp = new char [s];
		
		for(int i=0 ; i < s ; i++)
		{
			temp[i] = str[i];
		}			
		size = s ;
		delete [] str;
		str = temp ;
}
	
char String::charAt(int index)
{
	return str[index]; 	
}

int String::indexOf(char ch)
{
	for(int i=0 ; i<size ; i++)
	{
        if(str[i] == ch)
		{   return i ; }
	}
	
	return -1;
}

int String::indexOf(int start , char ch)
{
	if(start < size)
	{
		for(int i = start ; i< size ; i++)
		{	if(str[i] == ch)
			{   return i ; }
		}
	}
	return -1;	
}

String String::subString(int start )
{
	String s ;
	if(start < size)
	{
		for(int i = start ; i<size ; i++)
		{	
			s.str[i-start] =  this->str[i];
		}
		//s.size = size - start ;
		s.resize(size - start);
		return s ;
	}
	return 0;	
}

String String::subString(int start , int end)
{
	if(start < size && end <= size)
	{
		String s ;
		for(int i = start ; i<= end ; i++)
		{	
			s.str[i-start] =  str[i];
		}
        s.str[end-start+1] = '\0';
		s.resize(end - start + 1);
		return s;	
	}
    return	0 ;
			
}

String String::concat(String s2)
{
    String s ;
    for(int i=0 ; (i< size)&&(str[i] != '\0') ; i++)
	{
		s.str[i] = str[i];
	}
	s.str[i]=' ';

    for(int j=0 ; j< (s2.size)&&(s2.str[j] != '\0') ; j++)
    {
		s.str[i+j+1] = s2.str[j];
	}
	s.str[i+j+1]='\0';	
	s.resize(i + j +1);
	return	s ;
}
	

	
String& String::operator=(String& s2) 
{
	delete [] str;
    size = s2.size;
    str = new char [size];
		
    for(int i=0; (i<size)&&(s2.str[i] != '\0') ;i++)
    {
        str[i]= s2.str[i];
    }
	str[i]= '\0';
return *this;  
	
}

char& String::operator[](int i)
{
	return str[i] ; 	
}

String String::operator + (String s2)
{
    String s ;
    for(int i=0 ; (i<size)&&(str[i] != '\0'); i++)
	{
		s.str[i] = str[i];
	}
	s.str[i]=' ';

    for(int j=0 ; (j<s2.size)&&(s2.str[j] != '\0'); j++)
    {
		s.str[i+j+1] = s2.str[j];
	}
	s.str[i+j+1]='\0';
	s.resize(i + j +1);
	return	s ;
}

String& String::operator += (String s2)
{
    for(int i=0 ; (i<size)&& (str[i] != '\0') ; i++)
    { }
	str[i] = ' ';

    for(int j=0 ; j< (s2.size)&&(s2.str[j] != '\0'); j++)
    {
		str[j+i+1] = s2.str[j];
	}
	str[j+i+1] = '\0';	
	resize(size +j +1);
	return	*this ;
}


String String::uppercase(String& s)
{	
    for(int i=0 ; i< s.size ; i++)
	{
		if(s.str[i] >= 97  &&  s.str[i] != ' ')
		{ 
           	s.str[i] = s.str[i]-32;
		}
	}
	
    return s;		
}

String String::lowercase(String &s)
{
    for(int i=0 ; i< s.size ; i++)
	{
		if(s.str[i] <  97  &&  s.str[i] != ' ')
		{
			s.str[i] = s.str[i]+32;
		}
	}
    return s;			
}
	

istream& operator >> (istream& in, String& s )
{  
	gets(s.str);
	return in;
}
	
ostream& operator << (ostream& out,String& s)
{	
    puts(s.str);
	return out;
}
