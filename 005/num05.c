#include <stdio.h>
//smallest num evenly divisible by 1..20
int main()
{
    
    long long try = 1;
    int i, b;
    for ( ; ; try++)
    {
        b = 0;
        for (i = 20 ; i > 10 && !b; i--)
        {
            //printf("%lld\n", try);
            b = try % i || b;
        }
        if (!b)
        {
            printf("%lld\n", try);
            return 0;
        }
    }

    return 0;

}
