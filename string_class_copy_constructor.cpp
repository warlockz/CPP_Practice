#include <iostream>
#include <cstring>
#include <stdio.h>
#include <sstream>

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
	//Coversion Opertor to typename of(char*)
	
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

private:
	char *str;
	
};

int main(int argc, char const *argv[])
{
	String str("123");
	cout << "Functor String operator () : ";

	cout << str() <<"\n";
	cout <<"Conversion operator : "<< str <<"\n";
	//char * explicitstr = str;
	//cout << "Exp str " << explicitstr;
	str.setStr("321");
	
	cout << "String getstr : ";
	cout << str.getStr() <<"\n";


	return 0;
}
