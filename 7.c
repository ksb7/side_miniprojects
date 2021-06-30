#include <stdio.h>
/* program to find a number in an array
using binary search */

int sort(int number, int size_of_array, int mijloc, int inceput, int *x)
{
    do
    {
        mijloc=(size_of_array+inceput)/2;
        if(number>x[mijloc]) inceput = mijloc+1; 
        else if (number<x[mijloc]) size_of_array = mijloc-1; 
        else if (number==x[mijloc]) return mijloc;
        else return -1; //this instruction gets ignored
        /*
        if the number is not in the array
        the program prints the last position
        regardless of the message at line #35
        */
    }while(size_of_array>inceput);
}
int main()
{
    int n, size, i, x[100];
    printf("how many numbers to input:\n");
    scanf("%d", &size);
    printf("input numbers in ascending order: \n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &x[i]);
    }
    printf ("give a number : ");
    scanf("%d", &n);
    int middle, start=0;
    if(sort(n, size, middle, start, x)==-1) printf("the number is not in the array\n");
    else printf("the number is at position %d\n", sort(n, size, middle, start, x));
}
