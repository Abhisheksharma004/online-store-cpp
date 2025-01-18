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

using namespace std;

struct Product {
    int ProductID;
    string name;
    string category;

};

struct Order {
    int orderId;
    int productId;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {
    // Create a vector of Product objects
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Mobile", "Electronics"},
        {103, "Shirt", "Fashion"},
        {104, "Shoe", "Fashion"},
        {105, "TV", "Electronics"}
    };

    // Create a deque of Order objects
    deque<string> recentCustomers = {"C1001", "C1002", "C1003"};

    recentCustomers.push_front("C1004");
    recentCustomers.push_back("C1005");

    // Create a list of Order objects
    list<Order> ordersHistory;

    ordersHistory.push_back({1, 101, 1, "C1001", time(0)});
    ordersHistory.push_back({2, 102, 2, "C1002", time(0)});
    ordersHistory.push_back({3, 103, 1, "C1003", time(0)});

    set<string> catogeries;

    for(const auto &product: products){
        catogeries.insert(product.category);
    }

    map<int, int> productStock ={
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7}
    };

    multimap<string, Order> customerOrders;

    for(const auto &order: ordersHistory){
        customerOrders.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData ={
        {"C1001", "John Doe"},
        {"C1002", "Abhishek"},
        {"C1003", "Alice"},
        {"C1004", "Bob"},
        {"C1005", "Charlie"},
    };

    unordered_set<int> uniqueProductIds;

    for(const auto &product: products){
        uniqueProductIds.insert(product.ProductID);
    };

    return 0;
}