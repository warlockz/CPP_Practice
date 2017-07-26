#include <iostream>

using namespace std;

class TestData
{
	int data;
public:
	void setData(int data)
	{
		this->data = data;
	}

	int getData()
	{
		return data;
	}

};

template<typename T>
class SmartPointers
{
public:
	// used explicit keyword to avoid conversion implictly (Cover)to directly to smart pointers type
	// since argument with default value 
	explicit SmartPointers(T *p = NULL):ptr(p)
	{

	}

	~SmartPointers()
	{
		delete(ptr);
	}

	T& operator * () { return *ptr; }

	T* operator -> () { return ptr; }

private:
	T *ptr;
};

int main(int argc, char const *argv[])
{
	TestData *test = new TestData();
	SmartPointers<TestData> sptr(test);

	sptr->setData(10);
	cout << "data : "<<(*sptr).getData() << "\n";
	return 0;
}