#include <iostream>

using namespace std;

int func_one(int a, int b){return a+b;}
int func_two(int a, int b){return a*b;}
int func_three(int(*func)(int, int), int a, int b)
{
    a++;
    b++;
    return func(a,b);
}
    
void implementation();

int main()
{
    implementation();
    
    system("pause");
    
    return 0;
}


void implementation()
{
    int(*x)(int, int);
    int a = 2;
    int b = 3;
    
    cout << "------------Details------------------" << endl;
    x = func_one;
    cout << "value returned by func_one = " << func_one(a,b) << endl;
    cout << "address of the function = " << (void*)x << endl;
        
    x = func_two;
    cout << "value returned by func_two = " << func_two(a,b) << endl;
    cout << "address of the function = " << (void*)x << endl;
    
    cout << "value returned by func_three with func_one implemetation = " << func_three(func_one,a,b) << endl;

    cout << "value returned by func_three with func_two implemetation  = " << func_three(func_two,a,b) << endl;    
    
    
}
