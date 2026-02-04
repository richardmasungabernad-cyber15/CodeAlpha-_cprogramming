#include <stdio.h>
#include <stdlib.h>

// Define the structure for an account
typedef struct {
    int accountNo;
    char name[50];
    float balance;
} Account;

// Function Prototypes
void deposit();
void withdraw();
void checkBalance();

const char* FILENAME = "account.dat";

int main() {
    int choice;

    while (1) {
        printf("\n--- 🏦 MINI BANK SYSTEM ---");
        printf("\n1. Deposit Money");
        printf("\n2. Withdraw Money");
        printf("\n3. Balance Enquiry");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: checkBalance(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}

void deposit() {
    FILE *fp = fopen(FILENAME, "rb+");
    Account acc;
    float amount;

    if (fp == NULL) {
        // Initializing account if file doesn't exist
        fp = fopen(FILENAME, "wb+");
        acc.accountNo = 101;
        printf("Enter Account Holder Name: ");
        scanf("%s", acc.name);
        acc.balance = 0;
    } else {
        fread(&acc, sizeof(Account), 1, fp);
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    acc.balance += amount;

    rewind(fp);
    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("\nSuccess! New Balance: $%.2f\n", acc.balance);
}

void withdraw() {
    FILE *fp = fopen(FILENAME, "rb+");
    Account acc;
    float amount;

    if (fp == NULL) {
        printf("\nNo account found. Please deposit first.");
        return;
    }

    fread(&acc, sizeof(Account), 1, fp);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > acc.balance) {
        printf("\nInsufficient funds! Current balance: $%.2f\n", acc.balance);
    } else {
        acc.balance -= amount;
        rewind(fp);
        fwrite(&acc, sizeof(Account), 1, fp);
        printf("\nWithdrawal successful! Remaining: $%.2f\n", acc.balance);
    }
    fclose(fp);
}

void checkBalance() {
    FILE *fp = fopen(FILENAME, "rb");
    Account acc;

    if (fp == NULL) {
        printf("\nNo account record found.");
        return;
    }

    fread(&acc, sizeof(Account), 1, fp);
    printf("\n--- Account Details ---");
    printf("\nAcc No: %d", acc.accountNo);
    printf("\nHolder: %s", acc.name);
    printf("\nBalance: $%.2f\n", acc.balance);
    fclose(fp);
}

