#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int decimal;
    char buffer[20];

    while (1) {
        printf("Enter a decimal number between 0 and 4294967295: ");
        fgets(buffer, 20, stdin);
        decimal = (unsigned int) strtol(buffer, NULL, 10);
        
        if (decimal < 0 || decimal > 4294967295) {
            printf("Error: invalid input. Please enter a valid decimal number.\n");
        } else {
            break;
        }
    }

    unsigned char byte1 = (decimal >> 24) & 0xFF; // Extract the first byte
    unsigned char byte2 = (decimal >> 16) & 0xFF; // Extract the second byte
    unsigned char byte3 = (decimal >> 8) & 0xFF;  // Extract the third byte
    unsigned char byte4 = decimal & 0xFF;         // Extract the fourth byte

    if (byte1 < 32 || byte1 > 127 || byte2 < 32 || byte2 > 127 || byte3 < 32 || byte3 > 127 || byte4 < 32 || byte4 > 127)
    {
        printf("Error: decimal value cannot be converted to 4 ASCII characters.\n");
    }
    else
    {
        printf("ASCII characters: %c%c%c%c\n", byte1, byte2, byte3, byte4);
    }

    return 0;
}
