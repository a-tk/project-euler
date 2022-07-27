#include <stdio.h>
#include <stdlib.h>

long long int paths(long long int **a, int w, int h, int cw, int ch)
{
    
    if (cw >= w || ch >= h)
    {
        //printf("d1: returned 0 for cw = %lld, ch = %lld\n", cw, ch);
        return 0L;
    }

    if (a[cw][ch] != -1)
    {
        //printf("d2: returned %lld for cw = %lld, ch = %lld\n", a[cw][ch], cw, ch);
        return a[cw][ch];
    }

    if (cw == w - 1 || ch == h - 1)
    {

        //printf("d3: returned 1 for cw = %d, ch = %d\n", cw, ch);
        a[cw][ch] = 1L;
        return a[cw][ch];
        
    }else
    {

        a[cw][ch] = paths(a, w, h, cw + 1, ch) + paths(a, w, h, cw, ch + 1);
        //printf("d4: returned %d for cw = %d, ch = %d\n", a[cw][ch], cw, ch);
        return  a[cw][ch];
    }



}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <lattice width> <lattice height>\n", argv[0]);
        return -1;
    }


    int w = atoi(argv[1]), h = atoi(argv[2]), i = 0, j = 0;
    printf("%d\t%d\n", w, h);

    //printf("sizeof(long int) = %d, int = %d, long long = %d\n", sizeof(long int), sizeof(int), sizeof(long long int));

    long long int **a = (long long int **) malloc(w * sizeof(long long int *));
    for ( ; i < w ; i++ )
    {
        a[i] = (long long int *) malloc(h * sizeof(long long int));
    }

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j ++)
        {
            a[i][j] = -1L;
        }
    }


    long long int result = paths(a, w, h, 0, 0);
    
    for (i = 0; i < w; i ++)
    {
        free(a[i]);
    }
    free(a);

    printf("%lld\n", result);

    return 0;
}

