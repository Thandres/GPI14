#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct complex
{
    double re;
    double im;
};
typedef void (*PFCCV)(struct complex *, struct complex *);

void printZahl(struct complex *c)
{
    if (c->im < 0.0)
    {
        printf("%lf %lf i\n", c->re, c->im);
    }
    else
    {
        printf("%lf + %lf i\n", c->re, c->im);
    }
}

void addComplex(struct complex *c1, struct complex *c2)
{
    struct complex result = {c1->re + c2->re, c1->im + c2->im};
    printZahl(&result);
}

void subtractComplex(struct complex *c1, struct complex *c2)
{
    struct complex result = {c1->re - c2->re, c1->im - c2->im};
    printZahl(&result);
}

void multComplex(struct complex *c1, struct complex *c2)
{
    double re = c1->re * c2->re - c1->im * c2->im;
    double im = c1->re * c2->im + c1->im * c2->re;
    struct complex result = {re, im};
    printZahl(&result);
}

void divideComplex(struct complex *c1, struct complex *c2)
{
    double re = c1->re * c2->re + c1->im * c2->im;
    re /= c2->re * c2->re + c2->im * c2->im;
    double im = c1->re * c2->im + c1->im * c2->re;
    im /= c2->re * c2->re - c2->im * c2->im;
    struct complex result = {re, im};
    printZahl(&result);
}

void wrongOP(struct complex *c1, struct complex *c2)
{
    // do nothing
}

PFCCV getArithmeticFunction(const char *op)
{
    if (!strcmp("+:", op))
    {
        return addComplex;
    }
    else if (!strcmp("-", op))
    {
        return subtractComplex;
    }
    else if (!strcmp("*", op))
    {
        return multComplex;
    }
    else if (!strcmp("/", op))
    {
        return divideComplex;
    }
    printf("falscher Operand angegeben\nEntweder '+:','-','*','/' war '%s'\n", op);
    return wrongOP;
}

int main(int argc, char const *argv[])
{
    if (argc != 6)
    {
        printf("Rechner muss mit 5 argumenten aufgerufen werden, es wurden %d angegeben\n \
        '*' muss für die eingabe mit \\ escaped werden\n", argc - 1);
        return 0;
    }
    double re1 = atof(argv[1]);
    double im1 = atof(argv[2]);
    struct complex c1 = {re1, im1};

    double re2 = atof(argv[4]);
    double im2 = atof(argv[5]);
    struct complex c2 = {re2, im2};
    PFCCV arithFunktion = getArithmeticFunction(argv[3]);
    arithFunktion(&c1, &c2);
    return 0;
}
