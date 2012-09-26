#include <iostream>

using namespace std;

void func(int * i)
{
     if(*i > 10)
           return;
     int a, b, c;
     a = *i+1;
     b = *i+2;
     c = a+b;
     cout << a << " " << b << endl;
     func(&c);
}


int main()
{
    int a =1;
    func(&a);
    system("pause");
    return 0;
}
