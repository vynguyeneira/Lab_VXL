#include <stdio.h>
#include <string.h>
#define UNIT_ALIGN 3
#define MAX_STRING_SIZE 200

enum Unit
{
    KILO = 3,
    MEGA = 6,
    GIGA = 9,
    TERA = 12
};

void copy(char *dest, char *src)
{
    int integralLength = 0;
    while (src[integralLength] != '.')
    {
        integralLength++;
    }
    if (integralLength <= KILO)
    {
        strcpy(dest, src);
        int len = strlen(dest);
        while (dest[len - 1] == '0')
            len--;
        dest[len] = '\0';
    }

    else
    {
        int newIntegralLength = integralLength % UNIT_ALIGN;
        if (newIntegralLength == 0)
            newIntegralLength = UNIT_ALIGN;

        int i = 0;
        while (i < newIntegralLength)
        {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '.';
        while (i <= integralLength)
        {
            dest[i + 1] = src[i];
            ++i;
        }
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            ++i;
        }

        while (dest[i - 1] == '0')
            --i;

        if (KILO < integralLength && integralLength <= MEGA)
        {
            dest[i] = ' ';
            dest[i + 1] = 'K';
            dest[i + 2] = 'I';
            dest[i + 3] = 'L';
            dest[i + 4] = 'O';
            dest[i + 5] = '\0';
        }
        else if (MEGA < integralLength && integralLength <= GIGA)
        {
            dest[i] = ' ';
            dest[i + 1] = 'M';
            dest[i + 2] = 'E';
            dest[i + 3] = 'G';
            dest[i + 4] = 'A';
            dest[i + 5] = '\0';
        }
        else if (GIGA < integralLength && integralLength <= TERA)
        {
            dest[i] = ' ';
            dest[i + 1] = 'G';
            dest[i + 2] = 'I';
            dest[i + 3] = 'G';
            dest[i + 4] = 'A';
            dest[i + 5] = '\0';
        }
        else
        {
            dest[i] = ' ';
            dest[i + 1] = 'T';
            dest[i + 2] = 'E';
            dest[i + 3] = 'R';
            dest[i + 4] = 'A';
            dest[i + 5] = '\0';
        }
    }
}

void suffixWithUnit(double f, char *output)
{
    char str[MAX_STRING_SIZE];
    sprintf(str, "%lf", f);

    char result[MAX_STRING_SIZE];
    copy(&result, &str);

    strcpy(output, &result);
}

int main()
{
    char result[MAX_STRING_SIZE];
    suffixWithUnit(2364.4567, result);
    printf("%s\n", result);
}