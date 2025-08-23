#pragma once  // Prevents the file from being included multiple times
#include <string>
using namespace std;

// Enum for order type
enum class OrderType { GOOD_TILL_CANCEL,
                       FILL_AND_KILL };

class Order {
 public:
  // Constructor
  Order(int orderID, const string& symbol, double price, int quantity, bool isBuy);

  // Getters
  int getOrderID() const { return orderID; }
  const string& getSymbol() const { return symbol; }
  double getPrice() const { return price; }
  int getQuantity() const { return quantity; }
  bool isBuyOrder() const { return isBuy; }

 private:
  int orderID;
  string symbol;  // e.g., "AAPL"
  double price;
  int quantity;
  bool isBuy;  // true for buy order, false for sell order
};