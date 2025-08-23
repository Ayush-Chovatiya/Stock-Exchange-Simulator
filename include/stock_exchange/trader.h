#pragma once
#include <map>
#include <string>
using namespace std;

class Exchange;

class Trader {
 public:
  Trader(int traderID, double initialBalance);

  // Public methods
  void placeOrder();  // We'll implement this later
  void viewPortfolio() const;
  int getID() const { return traderID; }
  void placeOrder(Exchange& exchange, const std::string& symbol, double price, int quantity, bool isBuy);

 private:
  int traderID;
  double cashBalance;
  map<string, int> portfolio;  // Maps stock symbol to quantity owned
};