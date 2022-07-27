#include <stdio.h>

//difference between sum of squares of the first natural numbers and the
//square of the sum

int main()
{
    long long int i = 0, j = 0;
    int k;

    for (k = 1; k <= 100; k++)
    {
        i += k;
        j += k * k;
    }
    i = i * i;

    printf("%lld\n", i - j);
    return 0;
}
