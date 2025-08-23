#pragma once
#include <string>
#include <vector>

#include "Order.h"

class Stock {
 public:
  Stock(const std::string& symbol);

  // Public methods to interact with the stock
  void addOrder(const Order& order);
  void executeTrades();
  void displayOrderBook() const;
  const std::string& getSymbol() const { return symbol; }

 private:
  std::string symbol;
  std::vector<Order> buyOrders;
  std::vector<Order> sellOrders;
  double lastTradedPrice;
};