#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <stdexcept>

using namespace std;

// Base class representing a product
class Product {
protected:
    string name;
    double price;
public:
    Product(const string& name, double price) : name(name), price(price) {}
    virtual double calculateDiscount() const = 0; // Pure virtual function for calculating discount
    virtual void displayInfo() const {
        cout << "Product: " << name << ", Price: " << price << " RS" << endl;
    }
    double getPrice() const {
        return price;
    }
    string getName() const {
        return name;
    }
};

// Intermediate class representing a discounted product
class DiscountedProduct : public Product {
public:
    DiscountedProduct(const string& name, double price) : Product(name, price) {}
    double calculateDiscount() const override {
        // Default discount for discounted products
        return price * 0.05;
    }
    void displayInfo() const override {
        cout << "Discounted Product: " << name << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing a book
class Book : public DiscountedProduct {
    string author;
public:
    Book(const string& name, double price, const string& author) : DiscountedProduct(name, price), author(author) {}
    double calculateDiscount() const override {
        // Books have a 10% discount
        return price * 0.1;
    }
    void displayInfo() const override {
        cout << "Book: " << name << ", Author: " << author << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing an electronic device
class ElectronicDevice : public DiscountedProduct {
    string manufacturer;
public:
    ElectronicDevice(const string& name, double price, const string& manufacturer) : DiscountedProduct(name, price), manufacturer(manufacturer) {}
    double calculateDiscount() const override {
        // Electronic devices have a 5% discount
        return price * 0.05;
    }
    void displayInfo() const override {
        cout << "Electronic Device: " << name << ", Manufacturer: " << manufacturer << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing clothing
class Clothing : public DiscountedProduct {
    string size;
public:
    Clothing(const string& name, double price, const string& size) : DiscountedProduct(name, price), size(size) {}
    double calculateDiscount() const override {
        // Clothing items have a 15% discount
        return price * 0.15;
    }
    void displayInfo() const override {
        cout << "Clothing: " << name << ", Size: " << size << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing watches
class Watch : public DiscountedProduct {
    string brand;
public:
    Watch(const string& name, double price, const string& brand) : DiscountedProduct(name, price), brand(brand) {}
    double calculateDiscount() const override {
        // Watches have a 7% discount
        return price * 0.07;
    }
    void displayInfo() const override {
        cout << "Watch: " << name << ", Brand: " << brand << ", Price: " << price << " Rs" << endl;
    }
};

// Derived class representing sports items
class SportsItem : public DiscountedProduct {
    string sport;
public:
    SportsItem(const string& name, double price, const string& sport) : DiscountedProduct(name, price), sport(sport) {}
    double calculateDiscount() const override {
        // Sports items have a 12% discount
        return price * 0.12;
    }
    void displayInfo() const override {
        cout << "Sports Item: " << name << ", Sport: " << sport << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing home appliances
class HomeAppliance : public DiscountedProduct {
    string type;
public:
    HomeAppliance(const string& name, double price, const string& type) : DiscountedProduct(name, price), type(type) {}
    double calculateDiscount() const override {
        // Home appliances have a 8% discount
        return price * 0.08;
    }
    void displayInfo() const override {
        cout << "Home Appliance: " << name << ", Type: " << type << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing beauty products
class BeautyProduct : public DiscountedProduct {
    string brand;
public:
    BeautyProduct(const string& name, double price, const string& brand) : DiscountedProduct(name, price), brand(brand) {}
    double calculateDiscount() const override {
        // Beauty products have a 10% discount
        return price * 0.10;
    }
    void displayInfo() const override {
        cout << "Beauty Product: " << name << ", Brand: " << brand << ", Price: " << price << " Rs" << endl;
    }
};

// Derived class representing furniture
class Furniture : public DiscountedProduct {
    string material;
public:
    Furniture(const string& name, double price, const string& material) : DiscountedProduct(name, price), material(material) {}
    double calculateDiscount() const override {
        // Furniture has a 12% discount
        return price * 0.12;
    }
    void displayInfo() const override {
        cout << "Furniture: " << name << ", Material: " << material << ", Price: " << price << " Rs" << endl;
    }
};

// Derived class representing kitchen appliances
class KitchenAppliance : public DiscountedProduct {
    string type;
public:
    KitchenAppliance(const string& name, double price, const string& type) : DiscountedProduct(name, price), type(type) {}
    double calculateDiscount() const override {
        // Kitchen appliances have a 9% discount
        return price * 0.09;
    }
    void displayInfo() const override {
        cout << "Kitchen Appliance: " << name << ", Type: " << type << ", Price: " << price << " RS" << endl;
    }
};

// Derived class representing outdoor furniture
class OutdoorFurniture : public DiscountedProduct {
    string material;
public:
    OutdoorFurniture(const string& name, double price, const string& material) : DiscountedProduct(name, price), material(material) {}
    double calculateDiscount() const override {
        // Outdoor furniture has a 11% discount
        return price * 0.11;
    }
    void displayInfo() const override {
        cout << "Outdoor Furniture: " << name << ", Material: " << material << ", Price: " << price << " Rs" << endl;
    }
};

// Template function to display information of a vector of products
template<typename T>
void displayProducts(const vector<T*>& products, bool showNumbers = false) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (showNumbers) {
            cout << i + 1 << ". ";
        }
        products[i]->displayInfo();
    }
}

// Template function to calculate the total cost of products in the cart
template<typename T>
double calculateTotalCost(const vector<T*>& products) {
    double totalCost = 0.0;
    for (const auto& product : products) {
        double discount = product->calculateDiscount();
        double finalPrice = product->getPrice() - discount;
        totalCost += finalPrice;
    }
    return totalCost;
}

// Struct to store customer information
struct CustomerInfo {
    string name;
    string mobileNumber;
    int points;
};

int main() {
    // Create some products
    Book book1("The Catcher in the Rye", 15.99, "J.D. Salinger");
    Book book2("1984", 12.99, "George Orwell");
    Book book3("To Kill a Mockingbird", 14.99, "Harper Lee");
    Book book4("The Great Gatsby", 13.99, "F. Scott Fitzgerald");

    ElectronicDevice device1("iPhone 12", 999.99, "Apple");
    ElectronicDevice device2("Dell XPS 15", 1299.99, "Dell");
    ElectronicDevice device3("Samsung QLED TV", 799.99, "Samsung");
    ElectronicDevice device4("Sony PlayStation 5", 499.99, "Sony");

    Clothing shirt1("T-Shirt", 19.99, "Medium");
    Clothing shirt2("T-Shirt", 19.99, "Large");
    Clothing pants1("Jeans", 29.99, "Medium");
    Clothing pants2("Jeans", 29.99, "Large");
    Clothing dress1("Summer Dress", 39.99, "Small");
    Clothing dress2("Winter Dress", 49.99, "Large");

    Watch watch1("Omega Seamaster", 4999.99, "Omega");
    Watch watch2("Rolex Submariner", 7999.99, "Rolex");
    Watch watch3("Tissot Le Locle", 2999.99, "Tissot");

    SportsItem sports1("Basketball", 29.99, "Basketball");
    SportsItem sports2("Soccer Ball", 24.99, "Soccer");
    SportsItem sports3("Tennis Racket", 49.99, "Tennis");
    SportsItem sports4("Golf Clubs", 99.99, "Golf");

    HomeAppliance appliance1("Refrigerator", 999.99, "Fridge");
    HomeAppliance appliance2("Washing Machine", 799.99, "Washer");
    HomeAppliance appliance3("Air Conditioner", 1299.99, "AC");
    HomeAppliance appliance4("Microwave Oven", 199.99, "Oven");

    BeautyProduct beauty1("Shampoo", 9.99, "L'Or al");
    BeautyProduct beauty2("Moisturizer", 14.99, "Nivea");
    BeautyProduct beauty3("Face Cream", 19.99, "Olay");
    BeautyProduct beauty4("Perfume", 29.99, "Chanel");

    Furniture furniture1("Sofa", 1999.99, "Leather");
    Furniture furniture2("Dining Table", 999.99, "Wood");
    Furniture furniture3("Bed", 1499.99, "Metal");
    Furniture furniture4("Desk", 499.99, "Glass");

    KitchenAppliance kitchenAppliance1("Toaster", 49.99, "Electric");
    KitchenAppliance kitchenAppliance2("Blender", 69.99, "Electric");
    KitchenAppliance kitchenAppliance3("Coffee Maker", 99.99, "Electric");
    KitchenAppliance kitchenAppliance4("Stand Mixer", 149.99, "Electric");

    OutdoorFurniture outdoorFurniture1("Patio Set", 299.99, "Wicker");
    OutdoorFurniture outdoorFurniture2("Garden Bench", 99.99, "Wood");
    OutdoorFurniture outdoorFurniture3("Hammock", 149.99, "Fabric");
    OutdoorFurniture outdoorFurniture4("Picnic Table", 199.99, "Wood");

    // Create a vector to hold products
    vector<Product*> products = {&book1, &book2, &book3, &book4, &device1, &device2, &device3, &device4, &shirt1, &shirt2, &pants1, &pants2, &dress1, &dress2, &watch1, &watch2, &watch3, &sports1, &sports2, &sports3, &sports4, &appliance1, &appliance2, &appliance3, &appliance4, &beauty1, &beauty2, &beauty3, &beauty4, &furniture1, &furniture2, &furniture3, &furniture4, &kitchenAppliance1, &kitchenAppliance2, &kitchenAppliance3, &kitchenAppliance4, &outdoorFurniture1, &outdoorFurniture2, &outdoorFurniture3, &outdoorFurniture4};

    // Customer information map
    map<int, CustomerInfo> customers;

    // Get customer information
    cout << "ENTER CUSTOMER NAME: ";
    string customerName;
    getline(cin, customerName);

    int shoppingID;
    while (true) {
        try {
            cout << "ENTER CUSTOMER SHOPPING ID: ";
            string idInput;
            cin >> idInput;
            shoppingID = stoi(idInput);  // Convert string to int
            if (customers.find(shoppingID) != customers.end()) {
                throw invalid_argument("Customer ID already exists.");
            }
            break;
        } catch (invalid_argument& e) {
            cout << "Invalid input or Customer ID already exists. Please enter a valid number." << endl;
        }
    }

    string mobileNumber;
    while (true) {
        try {
            cout << "ENTER CUSTOMER MOBILE NO.: ";
            cin >> mobileNumber;
            if (mobileNumber.size() != 10) {
                throw invalid_argument("Mobile number must be 10 digits.");
            }
            break;
        } catch (invalid_argument& e) {
            cout << "Invalid mobile number. " << e.what() << endl;
        }
    }

    // Store customer information
    customers[shoppingID] = {customerName, mobileNumber, 0};

    // Display available products with numbering
    cout << "\nAvailable Products:" << endl;
    displayProducts(products, true);

    // Ask user for selection
    int choice;
    vector<Product*> cart;
    while (true) {
        try {
            cout << "Enter the number of the product you want to buy (0 to finish): ";
            string choiceInput;
            cin >> choiceInput;
            choice = stoi(choiceInput);  // Convert string to int

            if (choice == 0) {
                break;
            }

            if (choice < 1|| choice > products.size()) {
                throw out_of_range("Choice is out of valid range.");
            }

            // Add the selected product to cart
            cart.push_back(products[choice - 1]);
            cout << "Added " << products[choice - 1]->getName() << " to cart." << endl;
        } catch (invalid_argument& e) {
            cout << "Invalid input. Please enter a number." << endl;
        } catch (out_of_range& e) {
            cout << "Invalid choice. " << e.what() << endl;
        }
    }

    // Display cart and total cost
    cout << "\nCart Summary:" << endl;
    cout << left << setw(20) << setfill(' ') << "Product"
         << left << setw(10) << setfill(' ') << "Price"
         << left << setw(10) << setfill(' ') << "Discount"
         << left << setw(10) << setfill(' ') << "Final Price" << endl;

    double totalCost = 0.0;
    for (const auto& product : cart) {
        double discount = product->calculateDiscount();
        double finalPrice = product->getPrice() - discount;
        totalCost += finalPrice;
        cout << left << setw(20) << setfill(' ') << product->getName()
             << left << setw(10) << setfill(' ') << fixed << setprecision(2) << product->getPrice()
             << left << setw(10) << setfill(' ') << fixed << setprecision(2) << discount
             << left << setw(10) << setfill(' ') << fixed << setprecision(2) << finalPrice << endl;
    }

    // Update customer points based on number of items purchased
    customers[shoppingID].points += cart.size() * 10;

    cout << "\nTotal cost of items in your cart: " << fixed << setprecision(2) << totalCost << " Rst" << endl;
    cout << "You have earned " << cart.size() * 10 << " points." << endl;

    // Option to check customer details by entering ID
    while (true) {
        try {
            cout << "\nEnter an ID to check customer details (0 to exit): ";
            string idInput;
            cin >> idInput;
            choice = stoi(idInput);  // Convert string to int

            if (choice == 0) {
                break;
            }

            if (customers.find(choice)!= customers.end()) {
                const CustomerInfo& customer = customers[choice];
                cout << "\nCustomer Details:" << endl;
                cout << "Name: " << customer.name << endl;
                cout << "Mobile Number: " << customer.mobileNumber << endl;
                cout << "Points: " << customer.points << endl;
            } else {
                throw invalid_argument("Customer ID not found.");
            }
        } catch (invalid_argument& e) {
            cout << "Invalid input. " << e.what() << endl;
        }
    }

    return 0;
}