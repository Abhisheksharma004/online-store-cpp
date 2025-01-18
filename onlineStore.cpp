#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

// Define the Product structure
struct Product {
    int ProductID;
    string name;
    string category;
};

// Define the Order structure
struct Order {
    int orderId;
    int productId;
    int quantity;
    string customerID;
    time_t orderDate;
};

// Function to display the available products
void displayProducts(const vector<Product>& products) {
    cout << "Available Products:\n";
    cout << "ID\tName\t\tCategory\n";
    for (const auto& product : products) {
        cout << product.ProductID << "\t" << product.name << "\t" << product.category << endl;
    }
}

// Function to display recent customers
void displayRecentCustomers(const deque<string>& recentCustomers, const unordered_map<string, string>& customerData) {
    cout << "\nRecent Customers:\n";
    for (const auto& customerID : recentCustomers) {
        cout << customerID << " - " << customerData.at(customerID) << endl;
    }
}

// Function to display order history
void displayOrders(const list<Order>& ordersHistory) {
    cout << "\nOrder History:\n";
    cout << "OrderID\tProductID\tQuantity\tCustomerID\tOrderDate\n";
    for (const auto& order : ordersHistory) {
        cout << order.orderId << "\t" << order.productId << "\t\t" << order.quantity << "\t\t" 
             << order.customerID << "\t\t" << ctime(&order.orderDate);
    }
}

// Function to add a new order
void addOrder(list<Order>& ordersHistory, int& nextOrderId, int productId, int quantity, const string& customerID, map<int, int>& productStock) {
    if (productStock[productId] >= quantity) {
        ordersHistory.push_back({nextOrderId++, productId, quantity, customerID, time(0)});
        productStock[productId] -= quantity;
        cout << "Order placed successfully!\n";
    } else {
        cout << "Insufficient stock for ProductID " << productId << "!\n";
    }
}

// Function to display product stock
void displayStock(const map<int, int>& productStock) {
    cout << "\nProduct Stock:\n";
    cout << "ProductID\tStock\n";
    for (const auto& stock : productStock) {
        cout << stock.first << "\t\t" << stock.second << endl;
    }
}

// Function to display all categories
void displayCategories(const set<string>& categories) {
    cout << "\nProduct Categories:\n";
    for (const auto& category : categories) {
        cout << category << endl;
    }
}

// Main function
int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Mobile", "Electronics"},
        {103, "Shirt", "Fashion"},
        {104, "Shoe", "Fashion"},
        {105, "TV", "Electronics"}
    };

    deque<string> recentCustomers = {"C1001", "C1002", "C1003"};
    list<Order> ordersHistory;

    ordersHistory.push_back({1, 101, 1, "C1001", time(0)});
    ordersHistory.push_back({2, 102, 2, "C1002", time(0)});
    ordersHistory.push_back({3, 103, 1, "C1003", time(0)});

    set<string> categories;
    for (const auto& product : products) {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7}
    };

    unordered_map<string, string> customerData = {
        {"C1001", "John Doe"},
        {"C1002", "Abhishek"},
        {"C1003", "Alice"},
        {"C1004", "Bob"},
        {"C1005", "Charlie"}
    };

    unordered_set<int> uniqueProductIds;
    for (const auto& product : products) {
        uniqueProductIds.insert(product.ProductID);
    }

    int nextOrderId = 4;
    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Display Products\n"
             << "2. Display Recent Customers\n"
             << "3. Display Order History\n"
             << "4. Add New Order\n"
             << "5. Display Product Stock\n"
             << "6. Display Product Categories\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products);
                break;
            case 2:
                displayRecentCustomers(recentCustomers, customerData);
                break;
            case 3:
                displayOrders(ordersHistory);
                break;
            case 4: {
                int productId, quantity;
                string customerID;
                cout << "Enter ProductID: ";
                cin >> productId;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter CustomerID: ";
                cin >> customerID;
                addOrder(ordersHistory, nextOrderId, productId, quantity, customerID, productStock);
                break;
            }
            case 5:
                displayStock(productStock);
                break;
            case 6:
                displayCategories(categories);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
