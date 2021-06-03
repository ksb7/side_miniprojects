#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//scrabble

/* se da o lista ce contine puncte pentru fiecare litera a alfabetului englez
sa se determine punctajul obtinut a 2 cuvinte de la tastatura
si sa se determine care punctaj este mai mare */

void calculate (char *s1, char *s2, int sum1, int sum2)
{
    //lista de puncte respective
    int parametru[27]={1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int i, j;
    int k;
    char c, C;
    for(i=0; i<strlen(s1); i++) //trece prin primul cuvant
    {
        k=0;
        for(c='a', C='A'; c<='z', C<='Z'; c++, C++) //implementeaza pentru literele mari si mici
        {
            k++;
            if ((s1[i]==c)||(s1[i]==C)) sum1+=parametru[k-1];
            
        }
    }
    for(j=0; j<strlen(s2); j++) //trece prin al doilea cuvant
    {
        k=0;
        for(c='a', C='A'; c<='z', C<='Z'; c++, C++) //vezi randul 20
        {
            k++;
            if ((s2[j]==c)||(s2[j]==C)) sum2+=parametru[k-1];
        }
    }
    printf("suma1=%d suma2=%d\n", sum1, sum2);
    if(sum1>sum2) printf("primul cuvant are mai multe puncte\n"); else printf("al doilea cuvant are mai multe puncte\n");
};

int main()
{
    char person1[50], person2[50];
    fgets(person1, sizeof(person1), stdin); //fgets in loc de gets
    fgets(person2, sizeof(person2), stdin);
    int suma1=0, suma2=0;
    calculate(person1, person2, suma1, suma2);
    return 0;
}
