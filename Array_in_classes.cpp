#include <iostream>
#include <string>
using namespace std;

class Billing_bill
{
    string item_name[100];     // Array to store item names
    int item_price[100];       // Array to store item prices
    int item_quantity[100];    // Array to store item quantities
    int counter;               // Counter to track number of items

public:
    void initcounter() { counter = 0; }  // Initialize counter to 0
    void setTotal_price(void);           // Function to set item details
    void displayTotal_price(void);       // Function to display total bill
};

void Billing_bill::setTotal_price(void)
{
    // Prompt for and store item name, quantity, and price
    cout << "Enter item name: ";
    cin >> item_name[counter];
    cout << "Enter number of items: ";
    cin >> item_quantity[counter];
    cout << "Enter item price: ";
    cin >> item_price[counter];
    counter++;  // Increment counter after each item is added
}

void Billing_bill::displayTotal_price(void)
{
    int total_price = 0;
    
    // Loop through each item and display details
    for (int i = 0; i < counter; i++)
    {
        cout << "Item: " << item_name[i] 
             << ", Quantity: " << item_quantity[i] 
             << ", Price per item: " << item_price[i] << endl;
        
        // Calculate total price for all items
        total_price += item_quantity[i] * item_price[i];
    }
    
    // Display the final total price
    cout << "Total Price: " << total_price << endl;
}

int main()
{
    Billing_bill bill;  // Create an object of the class Billing_bill
    bill.initcounter(); // Initialize the item counter

    // Loop to allow user to enter multiple items
    while (true)
    {
        bill.setTotal_price();  // Add item details
        cout << "Do you have more items? [y/n]: ";
        string more_items;
        cin >> more_items;
        if (more_items != "y")
        {
            break;  // Exit the loop if the user inputs anything other than 'y'
        }
    }

    // Display the total bill with all items
    bill.displayTotal_price();
    return 0;
}
// #include <iostream>
// using namespace std;

// class Shop
// {
//     int itemId[100];
//     int itemPrice[100];
//     int counter;

// public:
//     void initCounter(void) { counter = 0; }
//     void setPrice(void);
//     void displayPrice(void);
// };

// void Shop ::setPrice(void)
// {
//     cout << "Enter Id of your item no " << counter + 1 << endl;
//     cin >> itemId[counter];
//     cout << "Enter Price of your item" << endl;
//     cin >> itemPrice[counter];
//     counter++;
// }

// void Shop ::displayPrice(void)
// {
//     for (int i = 0; i < counter; i++)
//     {
//         cout << "The Price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
//     }
// }

// int main()
// {
//     Shop dukaan;
//     dukaan.initCounter();
//     dukaan.setPrice();
//     dukaan.setPrice();
//     dukaan.setPrice();
//     dukaan.displayPrice();
//     return 0;
// }
