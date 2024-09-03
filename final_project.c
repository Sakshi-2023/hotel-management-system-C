#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char name[50];
    int age;
    long long int contact;
    char room[50];
    int room_number;
    int days;
} x[100];

struct Customer
{
    char name[50];
    char phoneNumber[15];
    float usage;
    float totalBill;
    char plan[30];
};

struct Customer customers[100];    // Array to store customer data
int customerCount = 0; // Variable to keep track of the number of customers
int sum = 0;

// Function prototypes
void enter_choice();
void add();
void exit_webpage();
void view();
void search();
void halls();
void availability();
void payment();
void edit();
void information();
void booking_cancellation();
void billing();
void house_keeping();
void guest_services();
void front_desk();
void travel_and_tourism();
void addRecord();
void viewRecords();
void modifyRecord(char phoneNumber[]);
void viewPayment(char phoneNumber[]);
void deleteRecord(char phoneNumber[]);
void displayMenu();
int plan_initialize(char phoneNumber[]);
void view_plans();
void data_plan(char phoneNumber[], int y);
void top_up(char phoneNumber[], int y);
void display_food_menu();
void breakfast_order();
void lunch_order();
void dinner_order();
void snacks_order();
void beverages_order();
void desserts_order();


int main(int argc, char const *argv[])
{
    system("cls");
    int n;
    printf("WHAT DO YOU WISH TO DO\n");
    printf("1. FOR VISITING PALM HOTEL PARADISE \n");
    printf("2. FOR VISITING TELECOM BILLING SYSTEM\n");
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        for (int i = 0; i < 127; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < 39; i++)
        {
            printf(" ");
        }
        printf("WELCOME TO HOTEL PALM PARADISE\n");
        for (int i = 0; i < 127; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < 39; i++)
        {
            printf(" ");
        }
        enter_choice();
    }
    else if (n == 2)
    {
        int choice;
        char phoneNumber[15];
        while (1)
        {
            displayMenu();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                printf("\nEnter phone number to modify record: ");
                scanf("%s", phoneNumber);
                modifyRecord(phoneNumber);
                break;
            case 4:
                printf("\nEnter phone number to view payment: ");
                scanf("%s", phoneNumber);
                viewPayment(phoneNumber);
                break;
            case 5:
                printf("\nEnter phone number to delete record: ");
                scanf("%s", phoneNumber);
                deleteRecord(phoneNumber);
                break;
            case 6:
                view_plans();
                break;
            case 7:
                printf("\nEnter the number in which you want to add a plan");
                scanf("%s", phoneNumber);
                int x = plan_initialize(phoneNumber);
                if (x == -1)
                {
                    continue;
                }
                else if (x != -1)
                {
                    printf("\nEnter the plan you want to add");
                    printf("\n1. Data plan");
                    printf("\n2. Top up\n");
                    int plan;
                    scanf("%d", &plan);
                    switch (plan)
                    {
                    case 1:
                        data_plan(phoneNumber, x);
                        break;
                    case 2:
                        top_up(phoneNumber, x);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
            }
        }
        return 0;
    }
    else
        printf("invalid input");
    return 0;
}


void enter_choice()
{
    printf("Kindly Enter Your Choice Below\n");
    printf("1. View available rooms\n");
    printf("2. Add Information\n");
    printf("3. View Information\n");
    printf("4. Search Information\n");
    printf("5. Edit Information\n");
    printf("6. Billing and payment\n");
    printf("7. Housekeeping\n");
    printf("8. Guest Services\n");
    printf("9. Front Desk\n");
    printf("10.Travel and Tourism Services\n");
    printf("11. About function halls\n");
    printf("12. Function halls availability\n");
    printf("13. Food Service\n");
    printf("14. For booking cancellation\n");
    printf("15. Exit\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        information();
        break;
    case 2:
        add();
        break;
    case 3:
        view();
        break;
    case 4:
        search();
        break;
    case 5:
        edit();
        break;
    case 6:
        billing();
        break;
    case 7:
        house_keeping();
        break;
    case 8:
        guest_services();
        break;
    case 9:
        front_desk();
        break;
    case 10:
        travel_and_tourism();
        break;
    case 11:
        halls();
        break;
    case 12:
        availability();
        break;
    case 13:
        display_food_menu();
        break;
    case 14:
        booking_cancellation();
        break;
    case 15:
        exit_webpage();
        break;
    default:
        printf("Invalid choice. Please enter a valid option.\n");
        enter_choice();
        break;
    }
}


void exit_webpage()
{
    system("cls");
    printf("Are you sure you want to exit?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("Thank you for visiting our website!\n");
        exit(0);
    }
    else if (n == 2)
    {
        system("cls");
        enter_choice();
    }
}


void add()
{
    system("cls");
    printf("Number of rooms already booked: %d\n", sum);
    int num;
    printf("Enter number of people checking in: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter name of the person: ");
        fflush(stdin);
	    fgets(x[i].name, 51, stdin);
        printf("Enter contact number of the person: ");
        scanf("%lld", &x[i + sum].contact);
        printf("Enter age of the person: ");
        scanf("%d", &x[i + sum].age);
        printf("Enter number of days you wish to stay: ");
        scanf("%d", &x[i + sum].days);
        printf("Enter the type of room you wish: ");
        scanf("%s", x[i + sum].room);
        // Room allotment based on room type

        if (strcmp(x[i + sum].room, "Superior") == 0)
        {
            x[i + sum].room_number = 1 + (rand() % 40);
        }
        else if (strcmp(x[i + sum].room, "Deluxe") == 0)
        {
            x[i + sum].room_number = 41 + (rand() % 20);
        }
        else if (strcmp(x[i + sum].room, "Business") == 0)
        {
            x[i + sum].room_number = 61 + (rand() % 20);
        }
        else if (strcmp(x[i + sum].room, "Suite") == 0)
        {
            x[i + sum].room_number = 81 + (rand() % 20);
        }

        printf("Room alloted to you is: %d\n\n", x[i + sum].room_number);

    }
    sum += num;
    printf("Your rooms are booked.\n");
    printf("Thank you!\n\n");
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void view()
{
    system("cls");
    if (sum == 0)
    {
        printf("Sorry! There are no guests right now.\n");
    }
    else
    {
        printf("Here are the details of all the people checking in:\n");
        for (int i = 0; i < sum; i++)
        {
            fflush(stdin);
            printf("Name of the person: %s", x[i].name);
            printf("Contact number of the person: %lld\n", x[i].contact);
            printf("Age of the person: %d\n", x[i].age);
            printf("Days of stay of the person: %d\n", x[i].days);
            printf("Room type of the person: %s\n", x[i].room);
            printf("Room number of the person: %d\n", x[i].room_number);
            printf("\n");
        }
    }
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void edit()
{
    system("cls");
    printf("Hello! Here you can edit your information\n");
    printf("Kindly enter your room number: ");

    int room_number;
    scanf("%d", &room_number);

    printf("What details do you wish to edit?\n");
    printf("1. Name of the person\n");
    printf("2. Contact number of the person\n");
    printf("3. Age of the person\n");
    printf("4. Days of stay of the person\n");
    printf("5. Room type of the person\n");

    int choice;
    scanf("%d", &choice);
    for (int i = 0; i < sum; i++)
    {
        if (x[i].room_number == room_number)
        {
            switch (choice)
            {
            case 1:
                fflush(stdin);
                printf("Enter your new name: ");
                fflush(stdin);
	            fgets(x[i].name, 51, stdin);
                break;
            case 2:
                printf("Enter your new contact number: ");
                scanf("%lld", &x[i].contact);
                break;
            case 3:
                printf("Enter your new age: ");
                scanf("%d", &x[i].age);
                break;
            case 4:
                printf("Enter your new days of stay: ");
                scanf("%d", &x[i].days);
                break;
            case 5:
                printf("Enter your new type of room: ");
                scanf("%s", x[i].room);
                break;
            default:
                printf("Invalid choice.\n");
            }
            printf("Your details are changed.\n");
            break;
        }
    }
    printf("\nDo you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void search()
{
    system("cls");
    printf("Hello! Here you can search for your information\n");
    printf("Kindly enter how you want to search:\n");
    printf("1. Name of the person\n");
    printf("2. Contact number of the person\n");
    printf("3. Days of stay of the person\n");
    printf("4. Room number of the person\n");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        char search_name[50];
        printf("Enter the name of the person: ");
        fflush(stdin);
	    fgets(search_name, 51, stdin);
        for (int i = 0; i < sum; i++)
        {
            if (strcmp(search_name, x[i].name) == 0)
            {
                fflush(stdin);
                printf("Name of the person: %s", x[i].name);
                printf("Contact number of the person: %lld\n",x[i].contact);
                printf("Age of the person: %d\n", x[i].age);
                printf("Days of stay of the person: %d\n", x[i].days);
                printf("Room number of the person: %d\n", x[i].room_number);
            }
        }
        break;
    }
    case 2:
    {
        long long int search_contact;
        printf("Enter the contact number of the person: ");
        scanf("%lld", &search_contact);
        for (int i = 0; i < sum; i++)
        {
            if (search_contact == x[i].contact)
            {
                fflush(stdin);
                printf("Name of the person: %s", x[i].name);
                printf("Contact number of the person: %lld\n",x[i].contact);
                printf("Age of the person: %d\n", x[i].age);
                printf("Days of stay of the person: %d\n", x[i].days);
                printf("Room number of the person: %d\n", x[i].room_number);
                printf("\n");
            }
        }
        break;
    }
    case 3:
    {
        int search_days;
        printf("Enter the days of stay of the person: ");
        scanf("%d", &search_days);
        for (int i = 0; i < sum; i++)
        {
            if (search_days == x[i].days)
            {
                fflush(stdin);
                printf("Name of the person: %s", x[i].name);
                printf("Contact number of the person: %lld\n",x[i].contact);
                printf("Age of the person: %d\n", x[i].age);
                printf("Days of stay of the person: %d\n", x[i].days);
                printf("Room number of the person: %d\n", x[i].room_number);
            }
        }
        break;
    }
    case 4:
    {
        int search_room;
        printf("Enter the room number of the person: ");
        scanf("%d", &search_room);
        for (int i = 0; i < sum; i++)
        {
            if (search_room == x[i].room_number)
            {
                fflush(stdin);
                printf("Name of the person: %s", x[i].name);
                printf("Contact number of the person: %lld\n",x[i].contact);
                printf("Age of the person: %d\n", x[i].age);
                printf("Days of stay of the person: %d\n", x[i].days);
                printf("Room number of the person: %d\n", x[i].room_number);
                break;
            }
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
    }
    printf("\nDo you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void information()
{
    system("cls");
    printf("Here is the list of various types of rooms available and their costs per night:\n");
    printf("1. Superior room\n");
    printf("\t2 semi double beds or 1 king bed\n");
    printf("\tRoom size: 29 m2/312 ft2\n");
    printf("\tCity view\n");
    printf("\tRs.11,535\n\n");
    printf("2. Deluxe room\n");
    printf("\t2 semi double beds or 1 king bed\n");
    printf("\tRoom size: 32 m2/344 ft2\n");
    printf("\tGarden view\n");
    printf("\tRs.12,888\n\n");
    printf("3. Business Class\n");
    printf("\tSemi double beds or 1 king bed\n");
    printf("\tRoom size: 44 m2/474 ft2\n");
    printf("\tCity view\n");
    printf("\tRs.13,788\n\n");
    printf("4. Suite\n");
    printf("\t1 king bed\n");
    printf("\tRoom size: 54 m2/581 ft2\n");
    printf("\tPool view\n");
    printf("\tRs.16,700\n\n");
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}

void booking_cancellation(){
    system("cls");
    int room_number;
    printf("Enter the room number of the guest who wants to cancel the booking: ");
    scanf("%d", &room_number);

    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (x[i].room_number == room_number) {
            found = 1;
            printf("Details of the guest:\n");
            printf("Name: %s\n", x[i].name);
            printf("Contact number: %lld\n", x[i].contact);
            printf("Age: %d\n", x[i].age);
            printf("Days of stay: %d\n", x[i].days);
            printf("Room type: %s\n", x[i].room);
            printf("Room number: %d\n", x[i].room_number);
            printf("\nAre you sure you want to cancel this booking? (1.Yes / 2.No): ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                // Remove the guest's information who have booked
                for (int j = i; j < sum - 1; j++) {
                    strcpy(x[j].name, x[j+1].name);
                    x[j].age = x[j+1].age;
                    x[j].contact = x[j+1].contact;
                    strcpy(x[j].room, x[j+1].room);
                    x[j].room_number = x[j+1].room_number;
                    x[j].days = x[j+1].days;
                }
                sum--;
                // Update the total number of booked rooms
                printf("Reservation for room %d has been canceled.\n", room_number);
                printf(">>> >>>--------------------------------------_VISITE ____AGAIN_----------------------------------->>> >>>");
                printf("\n");
                printf(">>>------------------------------------------_PLEASURE TO MEET YOU_------------------------------->>> >>>");
                                                                     
            
            } else {
                printf("Reservation cancellation aborted.\n");
                printf(">>> >>>-------------------------------------THANK YOU----------------------------------------------->>> >>>");
            }
            break;
        }
    }
    

    if (!found) {
        printf("Guest with room number %d not found.\n", room_number);
        
        printf(">>> >>>--------------------------------------------THANKS FOR VISIT-------------------------------------->>> >>>");
            
    }

    printf("\n");
    printf("Do you wish to continue or exit the site?\n");
    printf("1.To continue on the site\n");
    printf("2.To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1) {
        system("cls");
        enter_choice();
        
    } else {
        exit_webpage();
    }
}


void billing()
{
    system("cls");
    int room_number;
    printf("\nWelcome to the billing and payment system:\n");
    printf("Kindly enter the room number: ");
    scanf("%d", &room_number);
    int amount;
    for (int i = 0; i < sum; i++)
    {
        if (x[i].room_number == room_number)
        {
            if (strcmp(x[i].room, "Superior") == 0)
            {
                amount = 11535;
            }
            else if (strcmp(x[i].room, "Deluxe") == 0)
            {
                amount = 12888;
            }
            else if (strcmp(x[i].room, "Business") == 0)
            {
                amount = 13788;
            }
            else if (strcmp(x[i].room, "Suite") == 0)
            {
                amount = 16700;
            }
            int nd = x[i].days;
            float total;
            int m;
            printf("Price of room: %d.00\n", amount);
            printf("Number of days stayed: %d\n", nd);
            printf("Select payment method:\n");
            printf("1. Cash\n");
            printf("2. Credit card\n");
            printf("Enter your choice: ");
            scanf("%d", &m);
            switch (m)
            {
            case 1:
                amount = amount + 1036;
                total = amount * nd;
                break;
            case 2:
                amount = amount + 1036;
                amount = amount + (amount * 0.005);
                total = amount * nd;
                break;
            default:
                printf("Invalid choice.\n");
                total = 0;
            }
            printf("\nBill generated:\n\n");
            for (int a = 1; a <= 9; a++)
            {
                for (int b = 1; b < 40 - a * 2; b++)
                {
                    printf(" ");
                }
                for (int c = 1; c <= 2 * a - 1; c++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            printf("\n");
            printf("-----------------------------HOTEL PALM PARADISE--------------------------------\n");
            printf("-----------------------------Thanks for visiting--------------------------------\n");
            printf("------------------------Hope you enjoyed your stay here--------------------------\n");
            printf("\nName of the person: %s", x[i].name);
            printf("Contact number of the person: %lld\n", x[i].contact);
            printf("Age of the person: %d\n", x[i].age);
            printf("Days of stay of the person: %d\n", x[i].days);
            printf("Room number of the person: %d\n", x[i].room_number);
            printf("\nRoom price: %d.00\n", amount);
            printf("Lux stay: 887.00\n");
            printf("Service tax: 89.00\n");
            printf("Service charge: 40.00\n");
            printf("Telephone: 20.00\n");
            printf("Payment tax: 0.005\n");
            printf("Amount paid: %.2f\n", total);
            printf("Charges imposed including all applicable taxes\n");
            printf("Food related charges are excluded\n");
            printf("\n----------------------------------Visit again-------------------------------------\n\n");
            break;
        }
    }
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void halls()
{
    system("cls");
    printf("HALLS AVAILABLE");
    printf("\n");
    printf("\n****1.THE BLISS****");
    printf("\n");
    printf("\nINTRODUCTION");
    printf("\nWhen it is time to exchange the vows or have a celebration, we are the most trustworthy option to choose from .");
    printf("\nHotel Paradise Bliss Banquet Hall has a magnificent and spacious area, just enough to accommodate for the wedding ");
    printf("\nday and the other chores. We are strategically placed and professionalism is our key. Grandeur and capaciousness");
    printf("\nare the key points of our satisfied customers.");
    printf("\n");
    printf("Hotel Paradise Bliss Banquet Hall is an air-conditioned hall with a seating capacity of 300 and a floating capacity of 450.");
    printf("\nThe Dining capacity of Hotel Paradise Bliss Banquet Hall is 100. ");
    printf("\nThe Function Hall is on the First floor. Lift access is available to reach the function hall easily.");
    printf("\nA parking facility is available for 20 cars and 40 bikes. You can contact us via Matrimony Mandap for the best venues under your budget.");
    printf("\n");
    printf("        PROPERTY TYPE ");
    printf("\n");
    printf("        Banquet Hall");
    printf("\n");
    printf("        MAXIMUM CAPACITY");
    printf("\n");
    printf("        450 guests (Banquet Hall) ");
    printf("\n");
    printf("        EVENT AREAs ");
    printf("        \nHotel Palm Paradise Bliss Banquet Hall");
    printf("        \n300 - Fixed capacity");
    printf("        \n450 - Floating capacity");
    printf("        \nACCOMODATION");
    printf("\n");
    printf("        97 rooms available ");
    printf("        \nDECOR POLICY ");
    printf("\n");
    printf("        Outside decorators not allowed");
    printf("\n");
    printf("        \nALCOHOL POLICY");
    printf("\n");
    printf("        Outside Alcohol not allowed");
    printf("\n");
    printf("        \nPARKING FACILITY");
    printf("\n");
    printf("        Parking Facility for 20 cars ");
    printf("\n");
    printf("\n");
    printf("****2.CARNIVAL****");
    printf("\n");
    printf("\nThe Board Room at the HOTEL PALM PARADISE has been designed keeping in mind the needs of the modern day business meeting.");
    printf("\nThe meeting hall is equipped with all contemporary amenities, high-speed internet and conference facility.");
    printf("\nThis boardroom is one of the finest meeting venues.");
    printf("\n");
    printf("The Board Room can accommodate:");
    printf("\n");
    printf("        Seating Layout	    Theatre	    Cocktail	   Banquet	    U-Shape 	Boardroom	    Hollow Square ");
    printf("\n");
    printf("        No. of Guests	    32	         20            20	        17	        18	            18                   ");
    printf("Thank you!\n\n");
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void house_keeping()
{
    // Function to handle housekeeping services
    system("cls");
    printf("Housekeeping Services\n");
    printf("1. Request Room Cleaning\n");
    printf("2. Request Towels\n");
    printf("3. Request Toiletries\n");
    printf("4. Request Bedding Change\n");
    printf("5. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Room cleaning requested!\n");
        break;
    case 2:
        printf("Towels requested!\n");
        break;
    case 3:
        printf("Toiletries requested!\n");
        break;
    case 4:
        printf("Bedding change requested!\n");
        break;
    case 5:
        exit_webpage();
    default:
        printf("Invalid choice.\n");
    }
    printf("\nDo you wish to continue housekeeping services or exit the site?\n");
    printf("1. To continue housekeeping services\n");
    printf("2. To continue on the site\n");
    printf("3. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        house_keeping();
    }
    else if (n == 2)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        system("cls");
        exit_webpage();
    }
}


void availability()
{
    system("cls");
    int dd, mm, avb;
    printf("Enter the date(DD) of function  :");
    scanf("%d", &dd);
    printf("\n");
    printf("Enter the month(MM) of function :");
    scanf("%d", &mm);
    avb = mm % 2;
    if (avb == 0)
    {
        printf("The Bliss and Carnival both are available");
        payment();
    }
    else
    {
        if (dd % 2 == 1)
        {
            printf("The Bliss is already booked and Carnival isn't");
            payment();
        }
        else
            printf("The Bliss and Carnival are already booked");
    }
    printf("\n");
    printf("Thank you!\n\n");
    printf("Do you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void payment()
{
    int p, h, pay;
    printf("\n");
    printf("1.The bliss");
    printf("\n");
    printf("2.Carnival");
    printf("\nEnter the number of hall                 :");
    scanf("%d", &p);
    if (p == 1)
    {
        printf("\nNumber of guests attending           :");
        scanf("%d", &h);
        pay = 2500000 + h * 700 + 400000 + 600000;
        printf("\nHall price          = 2500000");
        printf("\nFood served         = %d", h * 700);
        printf("\nPhotoshoot service  = 600000");
        printf("\nOthers and taxes    = 400000");
        printf("\nRequired to pay     = %d", pay);
    }
    else
    {
        pay = 500000 + 30 * 700 + 100000;
        printf("\nHall price          = 500000");
        printf("\nFood served         = %d", 30 * 700);
        printf("\nOthers and taxes    = 100000");
        printf("\nRequired to pay     = %d", pay);
    }
}


void guest_services()
{
    // Function to handle guest services
    system("cls");
    printf("Guest Services\n");
    printf("1. Request Wake-up Call\n");
    printf("2. Request Luggage Assistance\n");
    printf("3. Request Taxi\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Wake-up call requested!\n");
        break;
    case 2:
        printf("Luggage assistance requested!\n");
        break;
    case 3:
        printf("Taxi requested!\n");
        break;
    case 4:
        exit_webpage();
    default:
        printf("Invalid choice.\n");
    }
    printf("\nDo you wish to continue guest services or exit the site?\n");
    printf("1. To continue guest services\n");
    printf("2. to continue on the site\n");
    printf("3. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        guest_services();
    }
    else if (n == 2)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        system("cls");
        exit_webpage();
    }
}


void front_desk()
{
    // Function to handle front desk services
    system("cls");
    printf("Front Desk Services\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Change Room\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        billing();
        break;
    case 3:
        edit();
        break;
    case 4:
        exit_webpage();
    default:
        printf("Invalid choice.\n");
    }
    printf("\nDo you wish to continue front desk services or exit the site?\n");
    printf("1. To continue front desk services\n");
    printf("2. To continue on the webpage\n");
    printf("3. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        front_desk();
    }
    else if (n == 2)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        system("cls");
        exit_webpage();
    }
}


void travel_and_tourism()
{
    // Function to handle travel and tourism services
    system("cls");
    printf("Travel and Tourism Services\n");
    printf("1. Book a Tour\n");
    printf("2. Car Rental\n");
    printf("3. Airport Shuttle\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Tour booked!\n");
        break;
    case 2:
        printf("Car rental requested!\n");
        break;
    case 3:
        printf("Airport shuttle requested!\n");
        break;
    case 4:
        exit_webpage();
    default:
        printf("Invalid choice.\n");
    }
    printf("\nDo you wish to continue travel and tourism services or exit the site?\n");
    printf("1. To continue travel and tourism services\n");
    printf("2. To continue on the webpage\n");
    printf("3. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        travel_and_tourism();
    }
    else if (n == 2)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        system("cls");
        exit_webpage();
    }
}


// Function to add a new customer record
void addRecord()
{
    if (customerCount < 100)
    {
        printf("\nEnter name: ");
        scanf(" %[^\n]s", customers[customerCount].name);
        printf("Enter phone number: ");
        scanf("%s", customers[customerCount].phoneNumber);
        printf("Enter usage (in minutes): ");
        scanf("%f", &customers[customerCount].usage);
        customers[customerCount].totalBill = customers[customerCount].usage * 0.1;
        customerCount++;
        printf("\nRecord added successfully!\n");
    }
    else
    {
        printf("\nMaximum number of records reached!\n");
    }
}


// Function to view the list of customer records
void viewRecords()
{
    printf("\nName\tPhone Number\tUsage(min)\tTotal "
           "Bill(Rs)\tPlan\n");
    for (int i = 0; i < customerCount; i++)
    {
        printf("%s\t%s\t%.2f\t\t%.2f\t\t%s\n", customers[i].name,
               customers[i].phoneNumber, customers[i].usage,
               customers[i].totalBill, customers[i].plan);
    }
}


// Function to modify a customer record
void modifyRecord(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
        {
            printf(
                "\nEnter new usage (in minutes) for %s: ",
                customers[i].name);
            scanf("%f", &customers[i].usage);
            customers[i].totalBill = customers[i].usage * 0.1;
            printf("\nRecord modified successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}


// Function to view payment for a customer
void viewPayment(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
        {
            printf(
                "%s\t%s\t%.2f\t\t%.2f\n", customers[i].name,
                customers[i].phoneNumber,
                customers[i].usage, customers[i].totalBill);
        }
        return;
    }
    printf("\nRecord not found!\n");
}


// Function to delete a customer record
void deleteRecord(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
        {
            for (int j = i; j < customerCount - 1; j++)
            {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}


// Function to display menu options
void displayMenu()
{
    printf("\n1. Add New Record\n");
    printf("2. View List of Records\n");
    printf("3. Modify Record\n");
    printf("4. View Payment\n");
    printf("5. Delete Record\n");
    printf("6. View Plans\n");
    printf("7. Add a Plan\n");
    printf("8. Exit\n");
}


// Function to get the customer number from phone number
int plan_initialize(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
        {
            return i;
        }
    }
    printf("\nRecord not found!\n");
    return -1;
}


// function to view plans
void view_plans()
{
    printf("1.Data plans\n");
    printf("2.Top up plans\n");
    printf("3.Exit\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Plan 1-\n");
        printf("	Data     - Unlimited\n");
        printf("	Validity- 1 day \n");
        printf("	Price    - Rs 39\n");
        printf("Plan 2-\n");
        printf("	Data     - 12 GB\n");
        printf("	Validity - Existing \n");
        printf("	Price    - Rs 129\n");
        printf("Plan 3-\n");
        printf("	Data     - Unlimited\n");
        printf("	Validity - 2 day \n");
        printf("	Price    - Rs 79\n");
        printf("Plan 4-\n");
        printf("	Data     - 2GB\n");
        printf("	Validity - 1 day\n ");
        printf("	Price    - Rs 29\n");
        break;
    case 2:
        printf("Plan 1-\n");
        printf("	Talktime - Rs 7.74 \n");
        printf("	Price    - Rs 10\n");
        printf("Plan 2-\n");
        printf("	Talktime - Rs 14.95\n ");
        printf("	Price    - Rs 20\n");
        printf("Plan 3-\n");
        printf("	Talktime - Rs 81.75 \n");
        printf("	Price    - Rs 100\n");
        printf("Plan 4-\n");
        printf("	Talktime - Rs 423.73\n");
        printf("	Price    - Rs 500\n");
        break;
    case 3:
        return;
    default:
        printf("enter a valid choice\n");
        view_plans();
    }
}
void data_plan(char phoneNumber[], int y)
{
    int n;
    printf("Enter your plan:\n");
    scanf("%d", &n);
    printf("Plan %d has been added to the mobile number %s \n", n, phoneNumber);
    switch (n)
    {
    case 1:
        strcpy(customers[y].plan, "Data plan 1");
        break;
    case 2:
        strcpy(customers[y].plan, "Data plan 2");
        break;
    case 3:
        strcpy(customers[y].plan, "Data plan 3");
        break;
    case 4:
        strcpy(customers[y].plan, "Data plan 4");
        break;
    default:
        strcpy(customers[y].plan, "Data plan");
        break;
    }
    return;
}


void top_up(char phoneNumber[], int y)
{
    int n, r;
    r = y;
    printf("Enter your plan:\n");
    scanf("%d", &n);
    printf("Plan %d has been added to the mobile number %s\n", n, phoneNumber);
    switch (n)
    {
    case 1:
        strcpy(customers[r].plan, "Top up plan 1");
        return;
    case 2:
        strcpy(customers[r].plan, "Top up plan 2");
        return;
    case 3:
        strcpy(customers[r].plan, "Top up plan 3");
        return;
    case 4:
        strcpy(customers[r].plan, "Top up plan 4");
        return;
    default:
        strcpy(customers[r].plan, "Top up plan");
        return;
        return;
    }
}


void display_food_menu()
{
    system("cls");
    printf("Food Menu\n");
    printf("1. Breakfast\n");
    printf("2. Lunch\n");
    printf("3. Dinner\n");
    printf("4. Snacks\n");
    printf("5. Beverages\n");
    printf("6. Desserts\n");
    printf("7. Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nBreakfast Menu\n");
        printf("1. Idli - Rs. 60.00 for 2 Idlis with Sambhar\n");
        printf("2. Masala Dosa - Rs. 80.00 per Dosa\n");
        printf("3. Upma - Rs. 50.00 per serving\n");
        printf("4. Poha - Rs. 40.00 per serving\n");
        printf("5. Aloo Paratha - Rs. 70.00 per Paratha\n");
        printf("6. Poori Bhaji - Rs. 65.00 for 2 Pooris with Bhaji\n");
        printf("7. Medu Vada - Rs. 40.00 for two Vadas\n");
        printf("8. Uttapam - Rs. 70.00 per Uttapam\n");
        printf("9. Vegetable Sandwich - Rs. 50.00 per Sandwich\n");
        printf("10. Bread Omelette - Rs. 40.00 per serving\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n1;
        scanf("%d", &n1);
        n1 == 1 ? breakfast_order() : display_food_menu();
        break;
    case 2:
        printf("\nLunch Menu\n");
        printf("1. Chicken Biryani - Rs. 250.00\n");
        printf("2. Paneer Tikka Masala - Rs. 220.00\n");
        printf("3. Butter Chicken - Rs. 280.00\n");
        printf("4. Dal Makhani - Rs. 180.00\n");
        printf("5. Aloo Gobi - Rs. 200.00\n");
        printf("6. Palak Paneer - Rs. 230.00\n");
        printf("7. Chole Bhature - Rs. 180.00\n");
        printf("8. Tandoori Roti - Rs. 20.00 per piece\n");
        printf("9. Naan - Rs. 30.00 per piece\n");
        printf("10. Raita - Rs. 60.00\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n2;
        scanf("%d", &n2);
        n2 == 1 ? lunch_order() : display_food_menu();
        break;
    case 3:
        printf("\nDinner Menu\n");
        printf("1. Chicken Tikka Masala - Rs. 280.00\n");
        printf("2. Mutton Rogan Josh - Rs. 320.00\n");
        printf("3. Fish Curry - Rs. 250.00\n");
        printf("4. Vegetable Biryani  - Rs. 200.00\n");
        printf("5. Malai Kofta - Rs. 240.00\n");
        printf("6. Chicken Curry - Rs. 260.00\n");
        printf("7. Shahi Paneer - Rs. 230.00\n");
        printf("8. Dum Aloo  - Rs. 220.00\n");
        printf("9. Roti Basket - Rs. 100.00 per piece\n");
        printf("10. Jeera Rice - Rs. 120.00 per piece\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n3;
        scanf("%d", &n3);
        n3 == 1 ? dinner_order() : display_food_menu();
        break;
    case 4:
        printf("\nSnacks Menu\n");
        printf("1. Samosa - Rs. 20.00 per piece\n");
        printf("2. Pakora  - Rs. 30.00 per plate\n");
        printf("3. Bhel Puri - Rs. 40.00 per serving\n");
        printf("4. Aloo Tikki  - Rs. 25.00 per piece\n");
        printf("5. Paneer Tikka - Rs. 50.00 per serving\n");
        printf("6. Vada Pav - Rs. 35.00 per serving\n");
        printf("7. Papdi Chaat - Rs. 45.00 per plate\n");
        printf("8. Dahi Vada  - Rs. 60.00 per plate\n");
        printf("9. Kachori - Rs. 25.00 per piece\n");
        printf("10. Dhokla - Rs. 40.00 for a serving\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n4;
        scanf("%d", &n4);
        n4 == 1 ? snacks_order() : display_food_menu();
        break;
    case 5:
        printf("\nBeverages Menu\n");
        printf("1. Masala Chai - Rs. 20.00 per cup\n");
        printf("2. Filter Coffee - Rs. 30.00 per cup\n");
        printf("3. Lassi - Rs. 40.00 per glass\n");
        printf("4. Nimbu Pani  - Rs. 25.00 per glass\n");
        printf("5. Jal Jeera - Rs. 35.00 per glass\n");
        printf("6. Thandai - Rs. 50.00 per glass\n");
        printf("7. Coconut Water - Rs. 30.00 per glass\n");
        printf("8. Sugarcane Juice - Rs. 40.00 per glass\n");
        printf("9. Badam Milk - Rs. 45.00 per glass\n");
        printf("10. Aam Panna  - Rs. 40.00 per glass\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n5;
        scanf("%d", &n5);
        n5 == 1 ? beverages_order() : display_food_menu();
        break;
    case 6:
        printf("\nDesserts Menu\n");
        printf("1. Gulab Jamun - Rs. 40.00 for 2 pieces\n");
        printf("2. Rasgulla - Rs. 30.00 for 2 pieces\n");
        printf("3. Rasmalai - Rs. 50.00 for 2 pieces\n");
        printf("4. Jalebi  - Rs. 25.00 per serving\n");
        printf("5. Kheer - Rs. 40.00 per serving\n");
        printf("6. Gajar Ka Halwa - Rs. 60.00 per serving\n");
        printf("7. Kulfi - Rs. 35.00 per serving\n");
        printf("8. Shahi Tukda - Rs. 50.00 per serving\n");
        printf("9. Malai Peda - Rs. 40.00 for 2 pieces\n");
        printf("10. Moong Dal Halwa  - Rs. 70.00 per serving\n");
        printf("\nPress 1 for order and 2 for menu.\n");
        int n6;
        scanf("%d", &n6);
        n6 == 1 ? desserts_order() : display_food_menu();
        break;
    case 7:
        enter_choice();
    default:
        printf("Invalid choice. Please try again.\n");
        display_food_menu();
    }
    printf("\nDo you wish to continue or exit the site?\n");
    printf("1. To continue on the site\n");
    printf("2. To exit the site\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        system("cls");
        enter_choice();
    }
    else
    {
        exit_webpage();
    }
}


void breakfast_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nBreakfast Menu\n");
    printf("1. Idli - Rs. 60.00 for 2 Idlis with Sambhar\n");
    printf("2. Masala Dosa - Rs. 80.00 per Dosa\n");
    printf("3. Upma - Rs. 50.00 per serving\n");
    printf("4. Poha - Rs. 40.00 per serving\n");
    printf("5. Aloo Paratha - Rs. 70.00 per Paratha\n");
    printf("6. Poori Bhaji - Rs. 65.00 for 2 Pooris with Bhaji\n");
    printf("7. Medu Vada - Rs. 40.00 for two Vadas\n");
    printf("8. Uttapam - Rs. 70.00 per Uttapam\n");
    printf("9. Vegetable Sandwich - Rs. 50.00 per Sandwich\n");
    printf("10. Bread Omelette - Rs. 40.00 per serving\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of pieces you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 30.00;
            }
            break;
        case 2:
            printf("Enter number of Dosas you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 80.00;
            }
            break;
        case 3:
            printf("Enter number of servings you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 50.00;
            }
            break;
        case 4:
            printf("Enter number of servings you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 5:
            printf("Enter number of Parathas you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 70.00;
            }
            break;
        case 6:
            printf("Enter number of Pooris you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 32.50;
            }
            break;
        case 7:
            printf("Enter number of Vadas you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 8:
            printf("Enter number of Uttapams you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 70.00;
            }
            break;
        case 9:
            printf("Enter number of pieces you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 50.00;
            }
            break;
        case 10:
            printf("Enter number of servings you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}


void lunch_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nLunch Menu\n");
    printf("1. Chicken Biryani - Rs. 250.00\n");
    printf("2. Paneer Tikka Masala - Rs. 220.00\n");
    printf("3. Butter Chicken - Rs. 280.00\n");
    printf("4. Dal Makhani - Rs. 180.00\n");
    printf("5. Aloo Gobi - Rs. 200.00\n");
    printf("6. Palak Paneer - Rs. 230.00\n");
    printf("7. Chole Bhature - Rs. 180.00\n");
    printf("8. Tandoori Roti - Rs. 20.00 per piece\n");
    printf("9. Naan - Rs. 30.00 per piece\n");
    printf("10. Raita - Rs. 60.00\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of plates you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 250.00;
            }
            break;
        case 2:
            printf("Enter number of plates you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 220.00;
            }
            break;
        case 3:
            printf("Enter number of plates you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 280.00;
            }
            break;
        case 4:
            printf("Enter number of plates you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 180.00;
            }
            break;
        case 5:
            printf("Enter number of plates you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 200.00;
            }
            break;
        case 6:
            printf("Enter number of plates you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 230.00;
            }
            break;
        case 7:
            printf("Enter number of plates you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 180.00;
            }
            break;
        case 8:
            printf("Enter number of pieces you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 9:
            printf("Enter number of pieces you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 30.00;
            }
            break;
        case 10:
            printf("Enter number of cups you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 60.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}


void dinner_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nDinner Menu\n");
    printf("1. Chicken Tikka Masala - Rs. 280.00\n");
    printf("2. Mutton Rogan Josh - Rs. 320.00\n");
    printf("3. Fish Curry - Rs. 250.00\n");
    printf("4. Vegetable Biryani  - Rs. 200.00\n");
    printf("5. Malai Kofta - Rs. 240.00\n");
    printf("6. Chicken Curry - Rs. 260.00\n");
    printf("7. Shahi Paneer - Rs. 230.00\n");
    printf("8. Dum Aloo  - Rs. 220.00\n");
    printf("9. Roti Basket - Rs. 100.00 per piece\n");
    printf("10. Jeera Rice - Rs. 120.00 per piece\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of plates you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 280.00;
            }
            break;
        case 2:
            printf("Enter number of plates you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 320.00;
            }
            break;
        case 3:
            printf("Enter number of plates you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 250.00;
            }
            break;
        case 4:
            printf("Enter number of plates you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 200.00;
            }
            break;
        case 5:
            printf("Enter number of plates you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 240.00;
            }
            break;
        case 6:
            printf("Enter number of plates you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 260.00;
            }
            break;
        case 7:
            printf("Enter number of plates you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 230.00;
            }
            break;
        case 8:
            printf("Enter number of plates you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 220.00;
            }
            break;
        case 9:
            printf("Enter number of baskets you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 100.00;
            }
            break;
        case 10:
            printf("Enter number of plates you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 120.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}


void snacks_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nSnacks Menu\n");
    printf("1. Samosa - Rs. 20.00 per piece\n");
    printf("2. Pakora  - Rs. 30.00 per plate\n");
    printf("3. Bhel Puri - Rs. 40.00 per serving\n");
    printf("4. Aloo Tikki  - Rs. 25.00 per piece\n");
    printf("5. Paneer Tikka - Rs. 50.00 per serving\n");
    printf("6. Vada Pav - Rs. 35.00 per serving\n");
    printf("7. Papdi Chaat - Rs. 45.00 per plate\n");
    printf("8. Dahi Vada  - Rs. 60.00 per plate\n");
    printf("9. Kachori - Rs. 25.00 per piece\n");
    printf("10. Dhokla - Rs. 40.00 for a serving\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of pieces you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 2:
            printf("Enter number of plates you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 30.00;
            }
            break;
        case 3:
            printf("Enter number of servings you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 4:
            printf("Enter number of pieces you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 25.00;
            }
            break;
        case 5:
            printf("Enter number of servings you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 50.00;
            }
            break;
        case 6:
            printf("Enter number of servings you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 35.00;
            }
            break;
        case 7:
            printf("Enter number of plates you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 45.00;
            }
            break;
        case 8:
            printf("Enter number of plates you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 60.00;
            }
            break;
        case 9:
            printf("Enter number of pieces you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 25.00;
            }
            break;
        case 10:
            printf("Enter number of servings you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}


void beverages_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nBeverages Menu\n");
    printf("1. Masala Chai - Rs. 20.00 per cup\n");
    printf("2. Filter Coffee - Rs. 30.00 per cup\n");
    printf("3. Lassi - Rs. 40.00 per glass\n");
    printf("4. Nimbu Pani  - Rs. 25.00 per glass\n");
    printf("5. Jal Jeera - Rs. 35.00 per glass\n");
    printf("6. Thandai - Rs. 50.00 per glass\n");
    printf("7. Coconut Wate - Rs. 30.00 per glass\n");
    printf("8. Sugarcane Juice - Rs. 40.00 per glass\n");
    printf("9. Badam Milk - Rs. 45.00 per glass\n");
    printf("10. Aam Panna  - Rs. 40.00 per glass\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of cups you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 2:
            printf("Enter number of cups you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 30.00;
            }
            break;
        case 3:
            printf("Enter number of glass you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 4:
            printf("Enter number of glass you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 25.00;
            }
            break;
        case 5:
            printf("Enter number of glass you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 35.00;
            }
            break;
        case 6:
            printf("Enter number of glass you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 50.00;
            }
            break;
        case 7:
            printf("Enter number of glass you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 30.00;
            }
            break;
        case 8:
            printf("Enter number of glass you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 9:
            printf("Enter number of glass you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 45.00;
            }
            break;
        case 10:
            printf("Enter number of glass you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}


void desserts_order()
{
    printf("Enter room number: ");
    int x;
    scanf("%d", &x);
    printf("\nDesserts Menu\n");
    printf("1. Gulab Jamun - Rs. 40.00 for 2 pieces\n");
    printf("2. Rasgulla - Rs. 30.00 for 2 pieces\n");
    printf("3. Rasmalai - Rs. 50.00 for 2 pieces\n");
    printf("4. Jalebi  - Rs. 25.00 per serving\n");
    printf("5. Kheer - Rs. 40.00 per serving\n");
    printf("6. Gajar Ka Halwa - Rs. 60.00 per serving\n");
    printf("7. Kulfi - Rs. 35.00 per serving\n");
    printf("8. Shahi Tukda - Rs. 50.00 per serving\n");
    printf("9. Malai Peda - Rs. 40.00 for 2 pieces\n");
    printf("10. Moong Dal Halwa  - Rs. 70.00 per serving\n");
    printf("11. Exit\n");
    float totalFoodBill = 0.0;
    int choice;
    do
    {
        printf("\nEnter your choice (1-11): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of pieces you want to order: ");
            int a1;
            scanf("%d", &a1);
            for (int i = 0; i < a1; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 2:
            printf("Enter number of pieces you want to order: ");
            int a2;
            scanf("%d", &a2);
            for (int i = 0; i < a2; i++)
            {
                totalFoodBill += 15.00;
            }
            break;
        case 3:
            printf("Enter number of pieces you want to order: ");
            int a3;
            scanf("%d", &a3);
            for (int i = 0; i < a3; i++)
            {
                totalFoodBill += 25.00;
            }
            break;
        case 4:
            printf("Enter number of servings you want to order: ");
            int a4;
            scanf("%d", &a4);
            for (int i = 0; i < a4; i++)
            {
                totalFoodBill += 25.00;
            }
            break;
        case 5:
            printf("Enter number of servings you want to order: ");
            int a5;
            scanf("%d", &a5);
            for (int i = 0; i < a5; i++)
            {
                totalFoodBill += 40.00;
            }
            break;
        case 6:
            printf("Enter number of servings you want to order: ");
            int a6;
            scanf("%d", &a6);
            for (int i = 0; i < a6; i++)
            {
                totalFoodBill += 60.00;
            }
            break;
        case 7:
            printf("Enter number of servings you want to order: ");
            int a7;
            scanf("%d", &a7);
            for (int i = 0; i < a7; i++)
            {
                totalFoodBill += 35.00;
            }
            break;
        case 8:
            printf("Enter number of servings you want to order: ");
            int a8;
            scanf("%d", &a8);
            for (int i = 0; i < a8; i++)
            {
                totalFoodBill += 50.00;
            }
            break;
        case 9:
            printf("Enter number of pieces you want to order: ");
            int a9;
            scanf("%d", &a9);
            for (int i = 0; i < a9; i++)
            {
                totalFoodBill += 20.00;
            }
            break;
        case 10:
            printf("Enter number of servings you want to order: ");
            int a10;
            scanf("%d", &a10);
            for (int i = 0; i < a10; i++)
            {
                totalFoodBill += 70.00;
            }
            break;
        case 11:
            printf("\nExiting food menu.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);
    printf("Total Food Bill: Rs. %.2f\n", totalFoodBill);
    printf("The order will reach room %d in few minutes.\n", x);
}
