#include <stdio.h>
#include <string.h>

struct Product {
    char name[100];
    float price;
    int quantity;
    int totalSoldQuantity;
    float totalSales;
    float discount;
};

int productCount = 0;
struct Product products[100];

int push(struct Product item)
{
    if (productCount < 100)
    {
        item.totalSoldQuantity = 0;
        item.totalSales = 0;
        products[productCount] = item;
        productCount++;
        return 1;
    }
    else
    {
        printf("\nMemory Full, No space!\n");
        return 0;
    }
}

void sellProduct(float eidDiscount)
{
    char productName[100];
    int quantity;

    printf("Enter the name of the product to sell: ");
    scanf("%s", productName);

    int i, found = 0;
    for (i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].name, productName) == 0)
        {
            found = 1;
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= products[i].quantity)
            {
                products[i].quantity -= quantity;
                float totalCost = quantity * products[i].price * (1 - eidDiscount / 100);
                products[i].totalSoldQuantity += quantity;
                products[i].totalSales += totalCost;
                printf("Sold %d units of %s successfully.\n", quantity, productName);

                printf("\n\n--Bill--\n");
                printf("Product: %s\n", productName);
                printf("Quantity: %d\n", quantity);
                printf("Price per unit: %.2f\n", products[i].price);
                printf("Discount: %.2f%%\n", eidDiscount);
                printf("Total cost after discount: %.2f\n", totalCost);

                printf("Thank you for choosing Galacticos Super Shop. Come again.\n");
            }
            else
            {
                printf("Not enough quantity of %s in stock.\n", productName);
            }
            break;
        }
    }
    if (!found)
    {
        printf("Product '%s' not found in the stock.\n", productName);
    }
}

void displaySalesReport()
{
    printf("\nSales Report:\n");
    printf("Product Name\tTotal Sold Quantity\tTotal Sales\n");
    for (int i = 0; i < productCount; i++) {
        if (products[i].totalSoldQuantity > 0)
        {
            printf("%s\t\t%d\t\t\t%.2f\n", products[i].name, products[i].totalSoldQuantity, products[i].totalSales);
        }
    }
}

void displayProducts()
{
    if (productCount > 0)
    {
        printf("\nStock Contents:\n");
        for (int i = 0; i < productCount; i++)
        {
            printf("%d: Name: %s, Price: %.2f, Quantity: %d\n", i + 1, products[i].name, products[i].price, products[i].quantity);
        }
    }
    else
    {
        printf("Stock is empty!\n");
    }
}

void deleteProductByName()
{
    char productName[100];
    printf("Enter the name of the product to delete: ");
    scanf("%s", productName);

    int i, found = 0;
    for (i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].name, productName) == 0)
        {
            found = 1;
            for (int j = i; j < productCount - 1; j++)
            {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Deleted product '%s'\n", productName);
            break;
        }
    }
    if (!found)
    {
        printf("Product '%s' not found in the stock\n", productName);
    }
}

struct Employee
{
    char name[100];
    float salary;
    int age;
    char username[100];
    char password[100];
    float bonus; 
};

int employeeCount = 0;
struct Employee employees[100];

int addEmployee(struct Employee item)
{
    if (employeeCount < 100)
    {
        employees[employeeCount] = item;
        employeeCount++;
        return 1;
    } else
    {
        printf("\nMemory Full, No space!\n");
        return 0;
    }
}

void deleteEmployeeByName()
{
    char employeeName[100];
    printf("Enter the name of the employee to delete: ");
    scanf("%s", employeeName);

    int i, found = 0;
    for (i = 0; i < employeeCount; i++)
    {
        if (strcmp(employees[i].name, employeeName) == 0)
        {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Deleted employee '%s'\n", employeeName);
            break;
        }
    }
    if (!found)
    {
        printf("Employee '%s' not found in the list\n", employeeName);
    }
}

void registerUser()
{
    struct Employee newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(newUser.username, employees[i].username) == 0)
        {
            printf("Username already exists. Please choose a different one.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter employee details:\n");
    printf("Name: ");
    scanf("%s", newUser.name);
    printf("Salary: ");
    scanf("%f", &newUser.salary);
    printf("Age: ");
    scanf("%d", &newUser.age);


    if (employeeCount < 100)
    {
        employees[employeeCount] = newUser;
        employeeCount++;
        printf("Registration successful!\n");
    }
    else
    {
        printf("\nMemory Full, No space!\n");
    }
}

int authenticateUser()
{
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(username, employees[i].username) == 0 && strcmp(password, employees[i].password) == 0)
        {
            return i;
        }
    }

    return -1;
}

void contactUs()
{
    printf("\n\n----Contact Us----\n");
    printf("Phone: 01*********\n");
    printf("Address: GALACTICOs Super Shop, Chilling Zone,Dhaka-9999\n");
    printf("Facebook: fb.com/galacticosshopbd\n");
    printf("[**Infos ,which are given , are fictional. Don't take it seriously]\n");

}

void openingTime()
{
   printf("\n\n----Opening Time----\n");
    printf("\t8:00 AM\n");  

   printf("\n\n----Break Time----\n");
    printf("\t12:50PM--1:50 PM\n");

    printf("\n\n----closing Time----\n");
    printf("\t11:00 PM\n");
}

void GALACTICOs()
{
    printf("--------------------\nGALACTICOs Super Shop\n\tG.S.S.\n---------------------\n");
}

int main() {
    GALACTICOs();

    push((struct Product){"Rice", 600, 100, 0, 0});
    push((struct Product){"Chips", 20, 200, 0, 0});
    push((struct Product){"Biscuit", 15, 200, 0, 0});
    push((struct Product){"Shampoo", 350, 100, 0, 0});
    push((struct Product){"Soap", 55, 100, 0, 0});
    push((struct Product){"Juice", 20, 200, 0, 0});
    push((struct Product){"Soybean", 550, 100, 0, 0});
    push((struct Product){"Spices", 200, 300, 0, 0});
    push((struct Product){"Cleaner", 230, 100, 0, 0});
    push((struct Product){"Clothes", 500, 150, 0, 0});

    addEmployee((struct Employee){"Fahim", 50000, 21, "fahimcoo", "1168"});
    addEmployee((struct Employee){"Wakil", 50000, 21, "wakilcfo", "1254"});
    addEmployee((struct Employee){"Mehedy", 50000, 21, "mehedyceo", "1202"});
    addEmployee((struct Employee){"Jubayer", 50000, 22, "jubayercoo", "1362"});

    int choice;
    int loggedInEmployeeIndex = -1;
    float eidDiscount = 0; 

    while (1)
    {
        if (loggedInEmployeeIndex == -1)
        {
            printf("\nChoose an option:\n");
            printf("1. Register\n");
            printf("2. Login\n");
            printf("0. Exit\n");
            scanf("%d", &choice);

            if (choice == 1)
            {
                registerUser();
            }
            else if (choice == 2)
            {
                loggedInEmployeeIndex = authenticateUser();
                if (loggedInEmployeeIndex != -1)
                {
                    printf("Login successful!\n");
                }
                else
                {
                    printf("Invalid username or password. Please try again.\n");
                }
            }
            else if (choice == 0)
            {
                printf("Exiting...\n");
                break;
            }
            else
            {
                printf("Invalid choice\n");
            }
        }
        else
        {
            printf("\nChoose an option:\n");
            printf("1. Add a Product\n");
            printf("2. Sell a Product\n");
            printf("3. Display Products\n");
            printf("4. Delete a Product by Name\n");
            printf("5. Add an Employee\n");
            printf("6. Display Employees\n");
            printf("7. Delete an Employee by Name\n");
            printf("8. Sales Report\n");
            printf("9. Set Eid Discount\n"); 
            printf("10. Set Employee Eid Bonus\n"); 
            printf("11. Contact Us\n");
            printf("12. Opening & Closing Time\n");           
            printf("0. Logout\n");
            printf("Your choice:\t");
            scanf("%d", &choice);

            if (choice == 1)
            {
                struct Product newProduct;
                printf("Enter product name: ");
                scanf("%s", newProduct.name);
                printf("Enter product price: ");
                scanf("%f", &newProduct.price);
                printf("Enter product quantity: ");
                scanf("%d", &newProduct.quantity);
                printf("Enter product discount percentage: "); 
                scanf("%f", &newProduct.discount);
                push(newProduct);
            }
            else if (choice == 2)
            {
                sellProduct(eidDiscount); 
            }
            else if (choice == 3)
            {
                displayProducts();
            }
            else if (choice == 4)
            {
                deleteProductByName();
            }
            else if (choice == 5)
            {
                struct Employee newEmployee;
                printf("Enter employee name: ");
                scanf("%s", newEmployee.name);
                printf("Enter employee salary: ");
                scanf("%f", &newEmployee.salary);
                printf("Enter employee age: ");
                scanf("%d", &newEmployee.age);
                printf("Enter employee username: ");
                scanf("%s", newEmployee.username);
                printf("Enter employee password: ");
                scanf("%s", newEmployee.password);

                addEmployee(newEmployee);
            }
            else if (choice == 6)
            {
               printf("\nEmployees List:\n");
                for (int i = 0; i < employeeCount; i++)
                {
                    printf("%d: Name: %s, Salary: %.2f,Salary with Bonus: %.2f, Age: %d, Username: %s, Bonus: %.2f\n", i + 1, employees[i].name,employees[i].salary, employees[i].salary + employees[i].bonus, employees[i].age, employees[i].username, employees[i].bonus);
                }
            }
            else if (choice == 7)
            {
                deleteEmployeeByName();
            }
            else if (choice == 8)
            {
                displaySalesReport();
            }
            else if (choice == 9)
            {
                printf("Enter Eid discount percentage: ");
                scanf("%f", &eidDiscount);
                printf("Eid discount set to %.2f%%\n", eidDiscount);
            }
            else if (choice == 10)
            {
                int employeeIndex;
                printf("Enter employee index to set Eid bonus: ");
                scanf("%d", &employeeIndex);
                if (employeeIndex >= 1 && employeeIndex <= employeeCount)
                {
                    printf("Enter Eid bonus for employee '%s': ", employees[employeeIndex - 1].name);
                    scanf("%f", &employees[employeeIndex - 1].bonus);
                    printf("Eid bonus set for employee '%s': %.2f\n", employees[employeeIndex - 1].name, employees[employeeIndex - 1].bonus);
                }
                else
                {
                    printf("Invalid employee index\n");
                }
            }
            else if (choice == 11)
            {
                contactUs();
            }
            else if (choice == 12)
            {
                openingTime();
            }
            else if (choice == 0)
            {
                loggedInEmployeeIndex = -1;
                printf("Logged out successfully.\n");
            }
            else
            {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}