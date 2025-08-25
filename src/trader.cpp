#include "stock_exchange/Trader.h"

#include <bits/stdc++.h>

#include "stock_exchange/Exchange.h"
using namespace std;

Trader::Trader(int traderID, double initialBalance) : traderID(traderID), cashBalance(initialBalance) {}

void Trader::viewPortfolio() const {
  cout << "--- Trader " << traderID << " Portfolio ---" << endl;
  cout << "Cash Balance: $" << cashBalance << endl;

  if (portfolio.empty()) {
    cout << "No stocks owned." << endl;
  } else {
    for (const auto& p : portfolio) {
      cout << "Stock: " << p.first << " | Qty: " << p.second << endl;
    }
  }

  cout << "--------------------------" << endl;
}

static int currentOrderID = 1;
void Trader::placeOrder(Exchange& exchange, const string& symbol, double price, int quantity, bool isBuy) {
  Order newOrder(currentOrderID++, this->traderID, symbol, price, quantity, isBuy);
  cout << "Trader " << traderID << " is placing an order to "
       << (isBuy ? "BUY" : "SELL") << " " << quantity << " "
       << symbol << " @ $" << price << endl;

  exchange.submitOrder(newOrder);
}

void Trader::addCash(double amount) {
  cashBalance += amount;
}

void Trader::removeCash(double amount) {
  cashBalance -= amount;
}

void Trader::addStock(const string& symbol, int qty) {
  portfolio[symbol] += qty;
}

void Trader::removeStock(const string& symbol, int qty) {
  portfolio[symbol] -= qty;
  if (portfolio[symbol] <= 0) portfolio.erase(symbol);
}

double Trader::getCashBalance() const {
  return cashBalance;
}

int Trader::getStockQuantity(const string& symbol) const {
  auto it = portfolio.find(symbol);
  if (it == portfolio.end()) return 0;
  return it->second;
}