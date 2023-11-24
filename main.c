#include <stdio.h>
#include <stdlib.h>
typedef struct dictionar
{
    char *w;
    int pri;
} dict;
dict *nou(char *a)
{
    dict *p = (dict*)malloc(sizeof(dict));
    p->w = strdup(a);
    p->pri = 0;
    return p;
}
dict *neww(char *a)
{
    dict *p = (dict*)malloc(sizeof(dict));
    p->w = strdup(a);
    p->pri = 1;
    return p;
}
void ordonare(dict **d, int n)
{
    int i, j;
    char cuv[20];
    for(i = 0; i < n - 1; i++)
    {
        for(j = i; j < n; j++)
        {
            if(strcmp(d[j]->w, d[i]->w) == -1)
            {
                strcpy(cuv, d[i]->w);
                strcpy(d[i]->w, d[j]->w);
                strcpy(d[j]->w, cuv);
            }
        }
    }
}
int find(char *s, dict **d, int n)
{
    int i, k = 0, poz = 0;
    char cuv[20] = "zzzzzzzzzzzzzzzzzzzz";
    for(i = 0; i < n; i++)
    {
        if(strcmp(s,d[i]->w) == -1 || strcmp(s, d[i]->w) == 0)
        {
            if(d[i]->pri >= poz)
                if(strcmp(d[i]->w, cuv) == -1 || strcmp(d[i]->w, cuv) == 0)
                {
                    strcpy(cuv, d[i]->w);
                    k = i;
                    poz = d[i]->pri;
                }
        }
    }
    if(strstr(cuv, s))
        return k;
    else return -1;
}
int main()
{
    dict **v;
    int cap = 5000, x, star = 0;
    int n, m, i, nr;
    char cuv[20], c[20], r[20];
    scanf("%d", &n);
    nr = n;
    getchar();
    v = (dict**)malloc(n*sizeof(dict*));
    for(i = 0; i < n; i++)
    {
        scanf("%s", cuv);
        v[i] = nou(cuv);
        //printf("%s  %d\n", v[i]->w, v[i]->pri);
    }
    //ordonare(v, n);
    scanf("%d", &m);
    getchar();
    for(i = 0; i < m; i++)
    {
        scanf("%s", c);
        star = 0;
        //printf("%s/ ", c);
        if(strstr(c,"*"))
        {
            star = 1;
            c[strlen(c) - strlen(strstr(c,"*"))] = NULL;
        }
        if(strchr(c,'.') || strchr(c,',') ||strchr(c,':') ||strchr(c,'!') ||strchr(c,'?'))
            printf("%s ", c);
        else
        {
            find(c, v, n);
            x = find(c, v, n);
            //printf("%d ", x);
            if(x != -1)
            {
                if(star == 0)
                {
                    v[x]->pri++;
                    printf("%s ", v[x]->w);
                }
                else
                    printf("%s ", c);
            }
            else
            {
                // adaug cuvinta in dictionar
                nr++;
                //printf("%d/", nr);
                //printf("%s/ ", c);
                //v = (dict**)realloc(v, nr*sizeof(dict*));
                //v[nr - 1] = neww(c);
                printf("%s ", c);
            }
        }
        //printf("%d %s\n", x, v[x]->w);
        //if(star == 1)

    }
    //printf("%d\n", nr);
    return 0;
}
