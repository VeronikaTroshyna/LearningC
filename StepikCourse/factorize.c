#include <stdio.h>
void factorize(int n, int *a, int *b)
{
    int dil;
    *a = 1;
    *b = n;
    for (dil = 2; dil <= n / 2; dil++)
    {
        if (n % dil == 0)
        {
            *a = dil;
            *b = n / dil;
            break;
        }
    }
}

int main(void)
{
    int x = 0, y = 0;
    for (int zuf = 0; zuf <= 100; zuf++)
    {
        factorize(zuf, &x, &y);
        printf("%d = %d * %d\n", zuf, x, y);
    }
}