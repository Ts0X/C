#include <stdio.h>
#include <string.h>
#include <time.h>

int exitLoop = 0;

int main() {
    int customerChoice;
    float customerMoney;
    int ticketChoice;
    
    // Ticket prices
    float reducedSingle = 0.45;
    float regularSingle = 0.90;
    float reducedDouble = 0.80;
    float regularDouble = 1.80;
    float fourJourneyTicket = 2.50;
    
    // Ticket stock
    int stockReducedSingle = 2;
    int stockRegularSingle = 9;
    int stockReducedDouble = 6;
    int stockRegularDouble = 10;
    int stockFourJourney = 7;

    // Service mode login credentials
    char correctUsername[] = "User";
    char correctPassword[] = "pass123";
    
    char username[40], password[40];
    int serviceChoice, subServiceChoice;
    
    do {
        printf("\nTicket Vending Machine\n");
        printf("1. Purchase Ticket\n");
        printf("2. Service Mode\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &customerChoice);

        if (customerChoice == 1) {
            printf("\nEnter your money: $");
            scanf("%f", &customerMoney);
            printf("Your balance: $%.2f\n", customerMoney);
            
            do {
                printf("\nTicket Options:\n");
                printf("1. $0.45 - Reduced Single Ticket\n");
                printf("2. $0.90 - Regular Single Ticket\n");
                printf("3. $0.80 - Reduced Double Journey Ticket\n");
                printf("4. $1.80 - Regular Double Journey Ticket\n");
                printf("5. $2.50 - Four Journey Ticket\n");
                printf("6. Exit\n");
                printf("Choose an option (1-6): ");
                scanf("%d", &ticketChoice);

                switch (ticketChoice) {
                    case 1:
                        if (customerMoney >= reducedSingle && stockReducedSingle > 0) {
                            customerMoney -= reducedSingle;
                            stockReducedSingle--;
                            printf("You purchased a Reduced Single Ticket. Remaining balance: $%.2f, Tickets left: %d\n", customerMoney, stockReducedSingle);
                        } else {
                            printf("Insufficient funds or tickets out of stock.\n");
                        }
                        break;
                    case 2:
                        if (customerMoney >= regularSingle && stockRegularSingle > 0) {
                            customerMoney -= regularSingle;
                            stockRegularSingle--;
                            printf("You purchased a Regular Single Ticket. Remaining balance: $%.2f, Tickets left: %d\n", customerMoney, stockRegularSingle);
                        } else {
                            printf("Insufficient funds or tickets out of stock.\n");
                        }
                        break;
                    case 3:
                        if (customerMoney >= reducedDouble && stockReducedDouble > 0) {
                            customerMoney -= reducedDouble;
                            stockReducedDouble--;
                            printf("You purchased a Reduced Double Journey Ticket. Remaining balance: $%.2f, Tickets left: %d\n", customerMoney, stockReducedDouble);
                        } else {
                            printf("Insufficient funds or tickets out of stock.\n");
                        }
                        break;
                    case 4:
                        if (customerMoney >= regularDouble && stockRegularDouble > 0) {
                            customerMoney -= regularDouble;
                            stockRegularDouble--;
                            printf("You purchased a Regular Double Journey Ticket. Remaining balance: $%.2f, Tickets left: %d\n", customerMoney, stockRegularDouble);
                        } else {
                            printf("Insufficient funds or tickets out of stock.\n");
                        }
                        break;
                    case 5:
                        if (customerMoney >= fourJourneyTicket && stockFourJourney > 0) {
                            customerMoney -= fourJourneyTicket;
                            stockFourJourney--;
                            printf("You purchased a Four Journey Ticket. Remaining balance: $%.2f, Tickets left: %d\n", customerMoney, stockFourJourney);
                        } else {
                            printf("Insufficient funds or tickets out of stock.\n");
                        }
                        break;
                    case 6:
                        printf("Returning to main menu. Your remaining balance: $%.2f\n", customerMoney);
                        break;
                    default:
                        printf("Invalid option. Please choose again.\n");
                }
            } while (ticketChoice != 6);
        } else if (customerChoice == 2) {
            printf("\nEnter Service Mode Credentials\n");
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
            
            if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
                do {
                    printf("\n** Service Mode **\n");
                    printf("1. View Date and Time\n");
                    printf("2. Exit Service Mode\n");
                    printf("Enter your choice: ");
                    scanf("%d", &serviceChoice);

                    switch (serviceChoice) {
                        case 1:
                            time_t currentTime = time(NULL);
                            printf("Current Date and Time: %s", ctime(&currentTime));
                            break;
                        case 2:
                            printf("Exiting Service Mode...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (serviceChoice != 2);
            } else {
                printf("Incorrect credentials. Access denied.\n");
            }
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } while (exitLoop == 0);

    printf("Thank you for using the Ticket Vending Machine.\n");
    return 0;
}
