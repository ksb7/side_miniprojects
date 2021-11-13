#include <stdio.h>

//folosind algoritmul de sortare selectie

void sort(int tablou[], int lungimea)
{
        int i = 0, j;
        while(i < lungimea)
        {
                int k = i;
                for (j = k; j < lungimea; j++)
                {
                        //gaseste daca exista un element
                        // mai mic decat cel de pe pozitia i
                        if (tablou[j] < tablou[k]) k = j;
                }
                //schimba elementul de pe pozitia i
                //cu cel mai mic element
                int temp;
                temp = tablou[i];
                tablou[i] = tablou[k];
                tablou[k] = temp;
                i++;
        }
}
int main()
{
        int x[100], n;
        printf("dati numerul de  elemente\n");
        scanf("%d", &n);
        printf("dati elementele\n");
        int i;
        for(i = 0; i < n; i++) scanf("%d", &x[i]);
        sort(x, n);
        printf("elementele in ordine crescatoare sunt\n");
        for(i = 0; i < n; i++) printf("%d ", x[i]);
        printf("\n");
        return 0;
}
