#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    struct pasapoarte
    {
        char model[25];
        int capacitate; 
    };
    struct pasapoarte nr_auto[20];
    int n;
    cout<<"introduceti numarul automobilelor"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"model "<<i+1<<endl;
        cin>>nr_auto[i].model;
        cout<<"capacitate "<<i+1<<endl;
        cin>>nr_auto[i].capacitate;
    }
    ofstream automobil;
    automobil.open("automobile.txt");
    if(automobil.fail())
    {
        cout<<"error";
        exit(1);
    }
    for(int i=0; i<n; i++)
    {
        automobil << "model "<<i+1<<" :"<< endl;
        automobil << nr_auto[i].model;
        automobil << endl;
        automobil << "capacitate "<<i+1<<" :"<<endl;
        automobil << nr_auto[i].capacitate;
        automobil << endl;
    }
    automobil.close();
    return 0;
}
