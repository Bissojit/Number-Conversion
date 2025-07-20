#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>  // for sleep()

// ANSI Color Codes
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define CLEAR() printf("\033[2J\033[1;1H")

// Function Prototypes
void welcomeScreen();
void loadingBar();
void displayMenu();
void convert(int choice);
int isValid(const char *num, int base);
void printBinary(long num);
void printOctal(long num);
void printHex(long num);

// Main Function
int main() {
    int choice;
    welcomeScreen();

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 13) {
            printf(GREEN "\nExited the program successfully.\n" RESET);
            break;
        }

        if (choice < 1 || choice > 13) {
            printf(RED "Invalid choice! Try again.\n" RESET);
        } else {
            loadingBar();
            convert(choice);
        }

        printf(YELLOW "\nPress Enter to continue..." RESET);
        while (getchar() != '\n');
        getchar();
    }

    return 0;
}

// Welcome Screen
void welcomeScreen() {
    CLEAR();
    printf(CYAN "╔══════════════════════════════════════════════╗\n");
    printf("║" RESET GREEN "         Welcome to Number Converter         " CYAN "║\n");
    printf("║" RESET "  A terminal-based converter made in pure C  " CYAN "║\n");
    printf("╚══════════════════════════════════════════════╝\n" RESET);
    sleep(1);
    loadingBar();
}

// Loading animation
void loadingBar() {
    printf(YELLOW "\nLoading");
    for (int i = 0; i < 3; i++) {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    printf("\n" RESET);
}

// Display Menu
void displayMenu() {
    CLEAR();
    printf(CYAN "┌──────────────────────────────────────────────┐\n" RESET);
    printf(CYAN "│" RESET GREEN "           Number Conversion Menu           " CYAN "│\n" RESET);
    printf(CYAN "├──────────────────────────────────────────────┤\n" RESET);
    printf(CYAN "│" RESET " 1.  Decimal to Binary                     " CYAN "│\n");
    printf(CYAN "│" RESET " 2.  Binary to Decimal                     " CYAN "│\n");
    printf(CYAN "│" RESET " 3.  Decimal to Octal                      " CYAN "│\n");
    printf(CYAN "│" RESET " 4.  Octal to Decimal                      " CYAN "│\n");
    printf(CYAN "│" RESET " 5.  Decimal to Hexa-Decimal               " CYAN "│\n");
    printf(CYAN "│" RESET " 6.  Hexa-Decimal to Decimal               " CYAN "│\n");
    printf(CYAN "│" RESET " 7.  Binary to Octal                       " CYAN "│\n");
    printf(CYAN "│" RESET " 8.  Octal to Binary                       " CYAN "│\n");
    printf(CYAN "│" RESET " 9.  Binary to Hexa-Decimal                " CYAN "│\n");
    printf(CYAN "│" RESET "10.  Hexa-Decimal to Binary                " CYAN "│\n");
    printf(CYAN "│" RESET "11.  Octal to Hexa-Decimal                 " CYAN "│\n");
    printf(CYAN "│" RESET "12.  Hexa-Decimal to Octal                 " CYAN "│\n");
    printf(CYAN "│" RESET "13.  Exit                                  " CYAN "│\n");
    printf(CYAN "└──────────────────────────────────────────────┘\n" RESET);
    printf(YELLOW "Please enter your choice: " RESET);
}

// Conversion Handler Function
void convert(int choice) {
    char input[50];
    long decimal;

    switch (choice) {
        case 1:
            printf(BLUE "Enter a Decimal Number: " RESET);
            scanf("%ld", &decimal);
            printBinary(decimal);
            break;
        case 2:
            printf(BLUE "Enter a Binary Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 2)) {
                printf(GREEN "Decimal: %ld\n" RESET, strtol(input, NULL, 2));
            } else {
                printf(RED "Invalid Binary Number!\n" RESET);
            }
            break;
        case 3:
            printf(BLUE "Enter a Decimal Number: " RESET);
            scanf("%ld", &decimal);
            printOctal(decimal);
            break;
        case 4:
            printf(BLUE "Enter an Octal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 8)) {
                printf(GREEN "Decimal: %ld\n" RESET, strtol(input, NULL, 8));
            } else {
                printf(RED "Invalid Octal Number!\n" RESET);
            }
            break;
        case 5:
            printf(BLUE "Enter a Decimal Number: " RESET);
            scanf("%ld", &decimal);
            printHex(decimal);
            break;
        case 6:
            printf(BLUE "Enter a Hexadecimal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 16)) {
                printf(GREEN "Decimal: %ld\n" RESET, strtol(input, NULL, 16));
            } else {
                printf(RED "Invalid Hexadecimal Number!\n" RESET);
            }
            break;
        case 7:
            printf(BLUE "Enter a Binary Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 2)) {
                printOctal(strtol(input, NULL, 2));
            } else {
                printf(RED "Invalid Binary Number!\n" RESET);
            }
            break;
        case 8:
            printf(BLUE "Enter an Octal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 8)) {
                printBinary(strtol(input, NULL, 8));
            } else {
                printf(RED "Invalid Octal Number!\n" RESET);
            }
            break;
        case 9:
            printf(BLUE "Enter a Binary Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 2)) {
                printHex(strtol(input, NULL, 2));
            } else {
                printf(RED "Invalid Binary Number!\n" RESET);
            }
            break;
        case 10:
            printf(BLUE "Enter a Hexadecimal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 16)) {
                printBinary(strtol(input, NULL, 16));
            } else {
                printf(RED "Invalid Hexadecimal Number!\n" RESET);
            }
            break;
        case 11:
            printf(BLUE "Enter an Octal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 8)) {
                printHex(strtol(input, NULL, 8));
            } else {
                printf(RED "Invalid Octal Number!\n" RESET);
            }
            break;
        case 12:
            printf(BLUE "Enter a Hexadecimal Number: " RESET);
            scanf("%s", input);
            if (isValid(input, 16)) {
                printOctal(strtol(input, NULL, 16));
            } else {
                printf(RED "Invalid Hexadecimal Number!\n" RESET);
            }
            break;
    }
}

// Input Validator
int isValid(const char *num, int base) {
    while (*num) {
        if (base == 2 && (*num != '0' && *num != '1')) return 0;
        if (base == 8 && (*num < '0' || *num > '7')) return 0;
        if (base == 16 && !isxdigit(*num)) return 0;
        num++;
    }
    return 1;
}

// Print Binary (No prefix)
void printBinary(long num) {
    char binary[65];
    int i = 0;

    if (num == 0) {
        printf(GREEN "Binary: 0\n" RESET);
        return;
    }

    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num /= 2;
    }

    printf(GREEN "Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n" RESET);
}

// Print Octal (No prefix)
void printOctal(long num) {
    printf(GREEN "Octal: %lo\n" RESET, num);
}

// Print Hexadecimal (No prefix)
void printHex(long num) {
    printf(GREEN "Hexadecimal: %lX\n" RESET, num);
}
