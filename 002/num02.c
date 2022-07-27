#include <stdio.h>


//sum of even fib numbers not exceeding 4 million



int main()
{
    int current = 1, previous = 1, temp;
    long long int sum = 0;

    for ( ; current < 4000000; temp = current, current += previous, previous = temp)
    {

        if ((current & 1) == 0)
        {
            sum += current;
        }
    }
    printf("%lld\n", sum);

    return 0;
}


