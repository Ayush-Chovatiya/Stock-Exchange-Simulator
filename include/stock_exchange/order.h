#pragma once
#include <string>

class Order {
 public:
  Order(int orderID, int traderID, const std::string& symbol, double price, int quantity, bool isBuy);

  // Getters
  int getOrderID() const { return orderID; }
  int getTraderID() const { return traderID; }  // Add this getter
  const std::string& getSymbol() const { return symbol; }
  double getPrice() const { return price; }
  int getQuantity() const { return quantity; }
  bool isBuyOrder() const { return isBuy; }
  

 private:
  int orderID;
  int traderID;  // The ID of the trader who placed the order
  std::string symbol;
  double price;
  int quantity;
  bool isBuy;
};