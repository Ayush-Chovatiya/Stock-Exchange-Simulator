#pragma once
#include <string>
#include <vector>

#include "Order.h"

using namespace std;

class Stock {
 public:
  Stock(const string& symbol);

  // Public methods to interact with the stock
  void addOrder(const Order& order);
  void executeTrades();
  void displayOrderBook() const;
  const string& getSymbol() const { return symbol; }

 private:
  string symbol;
  vector<Order> buyOrders;
  vector<Order> sellOrders;
  double lastTradedPrice;
};