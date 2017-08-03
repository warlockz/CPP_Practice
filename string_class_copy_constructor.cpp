#include <iostream>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <exception>

using namespace std;

class String
{
public:
	String(const char* str = NULL)
	{
		this->str = new char[strlen(str) + 1];
		strcpy(this->str,str);	
	}

	~String()
	{
		if(str)
		{
			delete [] str;
		}
	}

	String(const String& s)
	{
		this->str = new char[strlen(s.str) + 1];
		strcpy(this->str,s.str);
	}


	static char* IntToStr(int value)
	{
		//using sprintf
		char *temp = new char[16]; // assuming size as 16 byte
		sprintf(temp,"%d",value);
		return temp;
	}

	static char* to_string(int value)
	{
		//using stringstream class
		stringstream ss;
		ss<<value;
		char *temp = new char[strlen(ss.str().c_str()) + 1];
		ss>>temp;
		return temp;
	}

	char* getStr() const
	{
		return this->str;
	}

	void setStr(const char* str)
	{
		delete [](this->str);
		this->str = new char[strlen(str) + 1];
		strcpy(this->str,str);
	}

	String& operator = (const String& s)
	{
		if(this != &s)
		{
			this->str = new char[strlen(s.str) + 1];
			strcpy(this->str,s.str);
		}
		return *this;
	}

	//Functors operattor
	char* operator()() const
	{
		return (this->str);
	}

	//Coversion Opertor to typename of(char*) if we overload << insertion operator it will be called 
	// in such case conversion operator will not be called
	operator char* () const
	{
		return (this->str);
	}
	
	/*
	//To avoid Class String compare or assign with char* variable directly so use explicit keyword
	//eg:
	// String str("A");
	// char* s1 = "D";
	// : if(str == s1)
	//if you wantto compare then type cast it
	// if(str == static_cast<String>s1)
	
	explicit operator char* () const
	{
		return (this->str);
	}

	*/

	// Overloading operator << insertion operator as friend global function
	friend ostream& operator << (ostream& out,const String& s)
	{
		out << "Internal string : ";
		out << s.getStr();
		return out;
	}

	//return char at certain position overloading subscript operator
	char& operator [] (int index)
	{
		class StringIndexInvalidException : public exception
		{

		public:
			const char* what()
			{
				cout << "String Index Out of Bound exception \n";
			}

		};

		try
		{
			if(index >= strlen(str))
			{
				StringIndexInvalidException e;
				throw e;
			}
			else
			{
				return str[index];
			}
		}
		catch(StringIndexInvalidException& e)
		{
			cout << e.what();
		}
	}

private:
	char *str;
	
};

// Overloading operator >> extraction operator as without friend global function
istream& operator >> (istream & in,String& s)
{
	cout << "Please enter string ? : \n";
	char *str =  new char[256];
	in >> str;
	s.setStr(str);
	return in;
}

int main(int argc, char const *argv[])
{
	String str("123");
	cout << "Functor String operator () : ";

	cout << str() <<"\n";
	char *val = str;
	cout <<"Conversion operator : "<< val <<"\n";
	//char * explicitstr = str;
	//cout << "Exp str " << explicitstr;
	str.setStr("321");
	
	cout << "String getstr : ";
	cout << str.getStr() <<"\n";

	cout << "Overloading Extraction >> operator : ";
	cin >> str;

	cout << "Overloading Insertion  << operator : ";
	cout << str << endl;


	cout << "Overloading subscript [] operator : ";
	cout << "Enter index to change char ? :";
	int index = 0;
	cin >> index;
	try 
	{
		str[index] = 'q';
	}
	catch(...)
	{
		cout << "exception  caught default"; 
	}
	cout << str << endl;


	return 0;
}
