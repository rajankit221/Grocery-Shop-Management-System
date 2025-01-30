#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

// Class definitions
class Product {
public:
    int id;
    std::string name;
    double price;
    int quantity;

    Product(int id, const std::string& name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}
};

class Supplier {
public:
    int id;
    std::string name;
    std::string contact;

    Supplier(int id, const std::string& name, const std::string& contact)
        : id(id), name(name), contact(contact) {}
};

class Customer {
public:
    int id;
    std::string name;
    std::string contact;

    Customer(int id, const std::string& name, const std::string& contact)
        : id(id), name(name), contact(contact) {}
};

class Purchase {
public:
    int productId;
    int supplierId;
    int quantity;
    double total;

    Purchase(int productId, int supplierId, int quantity, double total)
        : productId(productId), supplierId(supplierId), quantity(quantity), total(total) {}
};

class Sale {
public:
    int productId;
    int quantity;
    double total;

    Sale(int productId, int quantity, double total)
        : productId(productId), quantity(quantity), total(total) {}
};

class LoginSystem {
private:
    std::unordered_map<std::string, std::string> users;

public:
    LoginSystem() {
        // Load users from a file (for simplicity, assuming file contains username:password pairs)
        std::ifstream file("users.txt");
        std::string line;
        while (getline(file, line)) {
            size_t delimiterPosition = line.find(':');
            std::string username = line.substr(0, delimiterPosition);
            std::string password = line.substr(delimiterPosition + 1);
            users[username] = password;
        }
        file.close();
    }

    bool login(const std::string& username, const std::string& password) {
        return users.find(username) != users.end() && users[username] == password;
    }
};

// Manager classes
class ProductManager {
private:
    std::vector<Product> products;

public:
    void addProduct(int id, const std::string& name, double price, int quantity) {
        products.emplace_back(id, name, price, quantity);
    }

    void listProducts() const {
        for (const auto& product : products) {
            std::cout << "ID: " << product.id
                      << ", Name: " << product.name
                      << ", Price: " << product.price
                      << ", Quantity: " << product.quantity << std::endl;
        }
    }

    const std::vector<Product>& getProducts() const {
        return products;
    }
};

class SupplierManager {
private:
    std::vector<Supplier> suppliers;

public:
    void addSupplier(int id, const std::string& name, const std::string& contact) {
        suppliers.emplace_back(id, name, contact);
    }

    void listSuppliers() const {
        for (const auto& supplier : suppliers) {
            std::cout << "ID: " << supplier.id
                      << ", Name: " << supplier.name
                      << ", Contact: " << supplier.contact << std::endl;
        }
    }
};

class CustomerManager {
private:
    std::vector<Customer> customers;

public:
    void addCustomer(int id, const std::string& name, const std::string& contact) {
        customers.emplace_back(id, name, contact);
    }

    void listCustomers() const {
        for (const auto& customer : customers) {
            std::cout << "ID: " << customer.id
                      << ", Name: " << customer.name
                      << ", Contact: " << customer.contact << std::endl;
        }
    }
};

class PurchaseManager {
private:
    std::vector<Purchase> purchases;

public:
    void recordPurchase(int productId, int supplierId, int quantity, double total) {
        purchases.emplace_back(productId, supplierId, quantity, total);
    }

    void listPurchases() const {
        for (const auto& purchase : purchases) {
            std::cout << "Product ID: " << purchase.productId
                      << ", Supplier ID: " << purchase.supplierId
                      << ", Quantity: " << purchase.quantity
                      << ", Total: " << purchase.total << std::endl;
        }
    }

    const std::vector<Purchase>& getPurchases() const {
        return purchases;
    }
};

class SalesManager {
private:
    std::vector<Sale> sales;

public:
    void recordSale(int productId, int quantity, double total) {
        sales.emplace_back(productId, quantity, total);
    }

    void listSales() const {
        for (const auto& sale : sales) {
            std::cout << "Product ID: " << sale.productId
                      << ", Quantity: " << sale.quantity
                      << ", Total: " << sale.total << std::endl;
        }
    }

    const std::vector<Sale>& getSales() const {
        return sales;
    }
};

class ReportGenerator {
public:
    void generateProductReport(const std::vector<Product>& products) const {
        std::cout << "Product Report:" << std::endl;
        for (const auto& product : products) {
            std::cout << "ID: " << product.id
                      << ", Name: " << product.name
                      << ", Price: " << product.price
                      << ", Quantity: " << product.quantity << std::endl;
        }
    }

    void generateSalesReport(const std::vector<Sale>& sales) const {
        std::cout << "Sales Report:" << std::endl;
        for (const auto& sale : sales) {
            std::cout << "Product ID: " << sale.productId
                      << ", Quantity: " << sale.quantity
                      << ", Total: " << sale.total << std::endl;
        }
    }

    void generatePurchaseReport(const std::vector<Purchase>& purchases) const {
        std::cout << "Purchase Report:" << std::endl;
        for (const auto& purchase : purchases) {
            std::cout << "Product ID: " << purchase.productId
                      << ", Supplier ID: " << purchase.supplierId
                      << ", Quantity: " << purchase.quantity
                      << ", Total: " << purchase.total << std::endl;
        }
    }
};

// Main menu function
void mainMenu() {
    ProductManager productManager;
    SupplierManager supplierManager;
    CustomerManager customerManager;
    PurchaseManager purchaseManager;
    SalesManager salesManager;
    ReportGenerator reportGenerator;

    int choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Add Product\n"
                  << "2. List Products\n"
                  << "3. Add Supplier\n"
                  << "4. List Suppliers\n"
                  << "5. Add Customer\n"
                  << "6. List Customers\n"
                  << "7. Record Purchase\n"
                  << "8. List Purchases\n"
                  << "9. Record Sale\n"
                  << "10. List Sales\n"
                  << "11. Generate Product Report\n"
                  << "12. Generate Sales Report\n"
                  << "13. Generate Purchase Report\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                std::string name;
                double price;
                std::cout << "Enter product ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline character
                std::cout << "Enter product name: ";
                std::getline(std::cin, name);
                std::cout << "Enter product price: ";
                std::cin >> price;
                std::cout << "Enter product quantity: ";
                std::cin >> quantity;
                productManager.addProduct(id, name, price, quantity);
                break;
            }
            case 2:
                productManager.listProducts();
                break;
            case 3: {
                int id;
                std::string name, contact;
                std::cout << "Enter supplier ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline character
                std::cout << "Enter supplier name: ";
                std::getline(std::cin, name);
                std::cout << "Enter supplier contact: ";
                std::getline(std::cin, contact);
                supplierManager.addSupplier(id, name, contact);
                break;
            }
            case 4:
                supplierManager.listSuppliers();
                break;
            case 5: {
                int id;
                std::string name, contact;
                std::cout << "Enter customer ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline character
                std::cout << "Enter customer name: ";
                std::getline(std::cin, name);
                std::cout << "Enter customer contact: ";
                std::getline(std::cin, contact);
                customerManager.addCustomer(id, name, contact);
                break;
            }
            case 6:
                customerManager.listCustomers();
                break;
            case 7: {
                int productId, supplierId, quantity;
                double total;
                std::cout << "Enter product ID: ";
                std::cin >> productId;
                std::cout << "Enter supplier ID: ";
                std::cin >> supplierId;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter total cost: ";
                std::cin >> total;
                purchaseManager.recordPurchase(productId, supplierId, quantity, total);
                break;
            }
            case 8:
                purchaseManager.listPurchases();
                break;
            case 9: {
                int productId, quantity;
                double total;
                std::cout << "Enter product ID: ";
                std::cin >> productId;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter total cost: ";
                std::cin >> total;
                salesManager.recordSale(productId, quantity, total);
                break;
            }
            case 10:
                salesManager.listSales();
                break;
            case 11:
                reportGenerator.generateProductReport(productManager.getProducts());
                break;
            case 12:
                reportGenerator.generateSalesReport(salesManager.getSales());
                break;
            case 13:
                reportGenerator.generatePurchaseReport(purchaseManager.getPurchases());
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                break;
        }
    } while (choice != 0);
}

int main() {
    LoginSystem loginSystem;
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (loginSystem.login(username, password)) {
        std::cout << "Login successful!" << std::endl;
        mainMenu();
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}