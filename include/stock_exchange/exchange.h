#pragma once
#include <map>
#include <string>

// We need the full definitions for classes we hold by value (in the map)
#include "stock.h"
#include "trader.h"

// A forward declaration is okay for Order, as it's only used as a reference
class Order;

class Exchange {
 public:
  void addStock(const std::string& symbol);
  void addTrader(const Trader& trader);
  void submitOrder(const Order& order);

 private:
  std::map<std::string, Stock> stocks;
  std::map<int, Trader> traders;
};