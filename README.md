# 🛒 Shopping Cart Billing System Using Object Oriented Concepts

A complete **Shopping Cart Billing System** built using **Object-Oriented Programming (OOP)** principles in **C++**.  
The system allows customers to view multiple product categories, add items to a shopping cart, apply product-specific discounts, generate a final bill, and earn loyalty points.

---

## 🧠 OOP Concepts Demonstrated

### 🔹 Abstraction
- Implemented through the **abstract base class `Product`**, which defines the common interface (`calculateDiscount()` and `displayInfo()`).

### 🔹 Encapsulation
- Sensitive data members such as product **name** and **price** are declared `protected` and accessed only through **getter methods**.

### 🔹 Inheritance
- Specialized product categories (`Book`, `ElectronicDevice`, `Clothing`, `Watch`, etc.) inherit from the base `Product` class via an intermediate `DiscountedProduct` class.

### 🔹 Polymorphism
- Uses **virtual functions** for discount calculation and display — allowing different product types to implement category-specific logic.

### 🔹 Modularity
- The program separates logic cleanly using multiple classes:
  - `Product` → base class  
  - `DiscountedProduct` → intermediate discount logic  
  - Derived product types → specialized classes  
  - `CustomerInfo` → manages customer data and loyalty points

---

## 💰 Billing and Discount Logic

Each product category offers a **different discount rate**:

| Category | Discount |
|:----------|:----------:|
| Book | 10% |
| Electronic Device | 5% |
| Clothing | 15% |
| Watch | 7% |
| Sports Item | 12% |
| Home Appliance | 8% |
| Beauty Product | 10% |
| Furniture | 12% |
| Kitchen Appliance | 9% |
| Outdoor Furniture | 11% |

### 🎁 Loyalty Points
- Each product purchased earns **10 loyalty points**.
- Customer information (name, mobile, and points) is stored in a map using a **unique shopping ID**.

---

## 🧪 Functional Flow

1. 🧍 Customer enters:
   - Name  
   - Shopping ID  
   - Mobile Number  
2. 🛍️ System displays all available products (numbered list).  
3. 🧾 Customer selects products to add to their **shopping cart**.  
4. 💵 System calculates **category-based discounts** and shows:
   - Product name  
   - Original price  
   - Discount  
   - Final price after discount  
5. 🧠 Total cost is displayed with earned loyalty points.  
6. 📱 Customer data can be retrieved later using their **shopping ID**.

---


