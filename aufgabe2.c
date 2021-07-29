#include <stdio.h>

int main(int argc, char const *argv[])
{
    double dings;
    int bla;
    for (int lowerer = 11; lowerer < 100; lowerer++)
    {
        for (int one = 200; one < 211-lowerer; one++)
        {
            for (int two = 200; two < 300-one-lowerer; two++)
            {
                for (int base = 500; base > 399; base--)
                {
                    bla = lowerer + one + two + base;
                    printf("%d\n", bla);
                    if (bla == 711)
                    {
                        double l = (double)lowerer / 100;
                        double o = (double)one / 100;
                        double t = (double)two / 100;
                        double b = (double)base / 100;
                        dings = l * o * t * b;
                        if (dings < 7.12 && dings > 7.10)
                        {
                            printf("%e %d %d %d %d\n", dings, lowerer, one, two, base);
                        }
                    }
                }
            }
        }
        /* code */
    }

    return 0;
}