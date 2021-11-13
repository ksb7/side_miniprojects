#include <stdio.h>
#include <stdlib.h>
#define true 1
//determina in cat timp va creste un nr de populatie
int main ()
{
    int n;
    do
    {
        printf("numarul populatiei de inceput\n");
        scanf("%d", &n);
        if (n>9)  {printf ("\n");break;} else {printf ("numarul populatiei nu poate fi mai mic de 9\n");
        continue;}
    } while (true);
    int m;
    do
    {
        printf("numarul populatiei finale\n");
        scanf("%d", &m);
        if (m>9)  break; else {printf ("numarul populatiei nu poate fi mai mic sau egal cu 9\n");
        continue;}
    } while (true);
    int k=0;
    while(n<=m)
    {
        n=n+(n/3)-(n/4);
        k++;
    }
    printf ("%d ani ii va lua sa creasca\n", k);
    return 0;
}
