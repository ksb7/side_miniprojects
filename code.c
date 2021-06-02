#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nr_cuvinte(char *t, int c)
{
    int i; 
    for (i=0; i<=strlen(t); i++)
    {
        if (t[i]==' ' || t[i]=='\n') c++; //uneori adauga 1 cuvant in plus idk why tho      
    }
    printf("mesajul introdus are %d cuvinte\n", c);
    return c; 
}
int nr_litere(char *t, int l)
{
    int i;
    for(i=0; i<strlen(t); i++)
    {
        if((t[i]>=97 && t[i]<=122)||(t[i]>=65 &&t[i]<=90)) l++;
    }
    printf("mesajul introdus are %d litere\n", l);
    return l;
}
int nr_propozitii(char *t, int p)
{
    int i;
    for(i=0; i<strlen(t); i++)
    {
        if((t[i]=='.' || t[i]=='?')||t[i]=='!') p++;
    }
    printf("mesajul introdus are %d propozitii\n", p);
    return p;
}

int main()
{
    /* numara cate litere, cuvinte si propozitii
    are textul introdus de utilizator de la tastatura
    pana la apasarea tastei ENTER */
    int cuvinte=0, litere=0, propozitii=0; 
    char *text=calloc(1, sizeof(char));
    int i=1, ii=0;
    printf("mesajul introdus:\n");
    while((scanf("%c", text+ii)==1)&&(text[ii]!='\n'))
    {
        ii=i++;
        text=realloc(text, i+sizeof(char));
    }
    cuvinte=nr_cuvinte(text, cuvinte);
    litere=nr_litere(text, litere);
    propozitii=nr_propozitii(text, propozitii);
    free(text);
    return 0;
}
