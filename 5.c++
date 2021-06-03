#include <iostream>
using namespace std;
void calculate(char*nume, int v)
{
    //cate cifre are varsta introdusa
    int k=0;
    int m;
    while(v>0)
    {
        m=v%10; 
        k++;
        v/=10;
    }
    cout<<"varsta a lui "<<nume<<" are "<<k<<" cifre"<<endl;
}
int main()
{
    struct person
    {
        char nume[50];
        int ani;
    }p1;
    cin>>p1.nume;
    cin>>p1.ani;
    cout<<"numele persoanei "<<p1.nume<<endl;
    cout<<"varsta persoanei "<<p1.ani<<endl;
    calculate(p1.nume, p1.ani);
}
