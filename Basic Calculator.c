#include <stdio.h>
int main() {
    char op;
    double num1, num2;
    char choice;
do {
        printf("\nBasic Calculator\n");
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op); // Note the space before %c to clear the buffer
        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);
        switch (op) {
            case '+':// Addition 
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case '-': // Subtraction 
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case '*':// Multiplication 
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case '/'://Division 
                // Logical check to prevent division by zero
                if (num2 != 0) {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                } else {
                    printf("Error! Division by zero is not allowed.\n");
                }
                break;
            default: // Handle invalid operator input
                printf("Error! Operator is not correct.\n");
        }
         // 4. Ask if the user wants to continue
        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program exited. Goodbye!\n");

    return 0;
}
