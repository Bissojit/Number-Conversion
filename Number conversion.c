#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function Prototypes
void convert(int choice);
int isValid(const char *num, int base);
void printBinary(long num);
void printOctal(long num);
void printHex(long num);

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\nNumber Conversion Menu:\n");
        printf("1.  Decimal to Binary\n2.  Binary to Decimal\n3.  Decimal to Octal\n4.  Octal to Decimal\n");
        printf("5.  Decimal to Hexa-Decimal\n6.  Hexa-Decimal to Decimal\n7.  Binary to Octal\n8.  Octal to Binary\n");
        printf("9.  Binary to Hexa-Decimal\n10. Hexa-Decimal to Binary\n11. Octal to Hexa-Decimal\n12. Hexa-Decimal to Octal\n13. Exit\n");
        printf("Please Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 13) {
            printf("Exited the program successfully.\n");
            exit(0);
        }

        if (choice < 1 || choice > 13) {
            printf("Invalid choice! Try again.\n");
        } else {
            convert(choice);
        }
    }
}

// Conversion Handler Function
void convert(int choice) {
    char input[50];
    long decimal;

    switch (choice) {
        case 1: // Decimal to Binary
            printf("Enter a Decimal Number: ");
            scanf("%ld", &decimal);
            printBinary(decimal);
            break;

        case 2: // Binary to Decimal
            printf("Enter a Binary Number: ");
            scanf("%s", input);
            if (isValid(input, 2)) {
                printf("Decimal number is %ld\n", strtol(input, NULL, 2));
            } else {
                printf("Invalid Binary Number!\n");
            }
            break;

        case 3: // Decimal to Octal
            printf("Enter a Decimal Number: ");
            scanf("%ld", &decimal);
            printOctal(decimal);
            break;

        case 4: // Octal to Decimal
            printf("Enter an Octal Number: ");
            scanf("%s", input);
            if (isValid(input, 8)) {
                printf("Decimal number is %ld\n", strtol(input, NULL, 8));
            } else {
                printf("Invalid Octal Number!\n");
            }
            break;

        case 5: // Decimal to Hexadecimal
            printf("Enter a Decimal Number: ");
            scanf("%ld", &decimal);
            printHex(decimal);
            break;

        case 6: // Hexadecimal to Decimal
            printf("Enter a Hexadecimal Number: ");
            scanf("%s", input);
            if (isValid(input, 16)) {
                printf("Decimal number is %ld\n", strtol(input, NULL, 16));
            } else {
                printf("Invalid Hexadecimal Number!\n");
            }
            break;

        case 7: // Binary to Octal
            printf("Enter a Binary Number: ");
            scanf("%s", input);
            if (isValid(input, 2)) {
                printOctal(strtol(input, NULL, 2));
            } else {
                printf("Invalid Binary Number!\n");
            }
            break;

        case 8: // Octal to Binary
            printf("Enter an Octal Number: ");
            scanf("%s", input);
            if (isValid(input, 8)) {
                printBinary(strtol(input, NULL, 8));
            } else {
                printf("Invalid Octal Number!\n");
            }
            break;

        case 9: // Binary to Hexadecimal
            printf("Enter a Binary Number: ");
            scanf("%s", input);
            if (isValid(input, 2)) {
                printHex(strtol(input, NULL, 2));
            } else {
                printf("Invalid Binary Number!\n");
            }
            break;

        case 10: // Hexadecimal to Binary
            printf("Enter a Hexadecimal Number: ");
            scanf("%s", input);
            if (isValid(input, 16)) {
                printBinary(strtol(input, NULL, 16));
            } else {
                printf("Invalid Hexadecimal Number!\n");
            }
            break;

        case 11: // Octal to Hexadecimal
            printf("Enter an Octal Number: ");
            scanf("%s", input);
            if (isValid(input, 8)) {
                printHex(strtol(input, NULL, 8));
            } else {
                printf("Invalid Octal Number!\n");
            }
            break;

        case 12: // Hexadecimal to Octal
            printf("Enter a Hexadecimal Number: ");
            scanf("%s", input);
            if (isValid(input, 16)) {
                printOctal(strtol(input, NULL, 16));
            } else {
                printf("Invalid Hexadecimal Number!\n");
            }
            break;
    }
}

// Function to Validate Input Based on Number System
int isValid(const char *num, int base) {
    while (*num) {
        if (base == 2 && (*num != '0' && *num != '1')) return 0;
        if (base == 8 && (*num < '0' || *num > '7')) return 0;
        if (base == 16 && !isxdigit(*num)) return 0;
        num++;
    }
    return 1;
}

// Function to Print Binary Representation
void printBinary(long num) {
    char binary[50] = "";
    int i = 0;
    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num /= 2;
    }
    if (i == 0) binary[i++] = '0'; // Special case for 0

    // Reverse the binary string
    printf("Binary number is ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");
}

// Function to Print Octal Representation
void printOctal(long num) {
    printf("Octal number is %lo\n", num);
}

// Function to Print Hexadecimal Representation
void printHex(long num) {
    printf("Hexadecimal number is %lX\n", num);
}
