#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    //run with just 1 comand-line argument (remember argc counts all the arguments in command line)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //transform string into int
    int k = atoi(argv[1]);
    //prompt user for plain text
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int j = 0; j < strlen(text); j++)
    {
        //rotate it with the int called k if its a letter
        if (isupper(text[j]))
        {
            printf("%c", (text[j] - 65 + k) % 26 + 65);
        }
        else if (islower(text[j]))
        {
            printf("%c", (text[j] - 97 + k) % 26 + 97);
        }
        //if its anything but a letter leave it like that
        else
        {
            printf("%c", text[j]);
        }
    }
    printf("\n");
    return 0;
}