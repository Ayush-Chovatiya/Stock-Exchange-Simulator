#pragma once
#include <map>
#include <string>

class Trader {
 public:
  Trader(int traderID, double initialBalance);

  // Public methods
  void placeOrder();  // We'll implement this later
  void viewPortfolio() const;

 private:
  int traderID;
  double cashBalance;
  std::map<std::string, int> portfolio;  // Maps stock symbol to quantity owned
};