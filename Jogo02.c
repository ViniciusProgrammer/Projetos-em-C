#include <stdio.h>

//Trabalhando com Arrays(listas) em C.

int main()
{
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");
    palavrasecreta[8] = '\0';

    printf("%s\n", palavrasecreta);

    return 0;
}
