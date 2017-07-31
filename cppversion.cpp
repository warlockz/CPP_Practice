#include <iostream>

using namespace std;

int main()
{
    if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
    else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
    else if( __cplusplus == 1 ) std::cout << "pre-standard C++\n" ;
    cout<<"C++ version default : "<<(int)__cplusplus<<endl;
 return 0;   
}
