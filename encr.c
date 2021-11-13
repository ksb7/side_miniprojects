#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* inputs a message, encrypts it by shifting a letter forward and decrypts it */
void encrypt(char *text, int j)
{
    int i;
    printf("encrypted text: \n");
    for(i=0; i<j; i++)
    {
        text[i]++;
        printf("%c", text[i]);
    }
    printf("\n");
}
void decrypt(char *text, int j)
{
    int i;
    printf("decrypted text: \n");
    for(i=0; i<j; i++)
    {
        text[i]--;
        printf("%c", text[i]);
    }
    printf("\n");
}
int main()
{
    printf("input text: \n");
    char *text=calloc(1, sizeof(char));
    int i=1, i2=0;
    if(text==NULL)
    {
        printf("Error");
        exit(1);
    } else {
    while(scanf("%c", text+i2)==1 && text[i2]!='\n')
    {
        i2=i++;
        text=realloc(text, i*sizeof(char));
    };};
    encrypt(text, i2);
    decrypt(text, i2);
    free(text);
    return 0;
}
