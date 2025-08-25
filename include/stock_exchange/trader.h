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

  void addCash(double amount);
  void removeCash(double amount);
  void addStock(const string& symbol, int quantity);
  void removeStock(const string& symbol, int quantity);

  double getCashBalance() const;
  int getStockQuantity(const std::string& symbol) const;

 private:
  int traderID;
  double cashBalance;
  map<string, int> portfolio;  // Maps stock symbol to quantity owned
};