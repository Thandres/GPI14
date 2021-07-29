#include <stdio.h>
// Initialze with zeros because Strings are terminated with 0
void initArray(char *array)
{
    for (int i = 0; i < 100; i++)
    {
        array[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    char inputs[100];
    initArray(inputs);
    char input = 10;
    int isLowercase = 1;
    int isUppercase = 1;
    int showMessage = 1;
    int i = 0;
    // a-z=97-122 A-Z= 65-90
    while (i < 100 && (isLowercase || isUppercase || input == 10))
    {
        if (showMessage)
        {
            printf("Noch %d Buchstaben eingeben:\n", 99-i);
            showMessage = 0;
        }
        input = getchar();
        isUppercase = (input > 64 && input < 91);
        isLowercase = (input > 96 && input < 123);
        if (isLowercase || isUppercase)
        {
            inputs[i++] = input;
        }else
        {
            showMessage = 1;
        }
    }

    printf("%s\n", inputs);
    return 0;
}
