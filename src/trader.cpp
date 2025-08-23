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
  Order newOrder(currentOrderID++, symbol, price, quantity, isBuy);
  cout << "Trader " << traderID << " is placing an order to "
       << (isBuy ? "BUY" : "SELL") << " " << quantity << " "
       << symbol << " @ $" << price << endl;

  exchange.submitOrder(newOrder);
}