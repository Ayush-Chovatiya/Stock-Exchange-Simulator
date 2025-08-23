#include "stock_exchange/Trader.h"

#include <bits/stdc++.h>
using namespace std;

Trader::Trader(int traderID, double initialBalance)
    : traderID(traderID), cashBalance(initialBalance) {
}

void Trader::viewPortfolio() const {
  cout << "--- Trader " << traderID << " Portfolio ---" << endl;
  cout << "Cash Balance: $" << cashBalance << endl;
  if (portfolio.empty()) {
    cout << "No stocks owned." << endl;
  } else {
    for (const auto& pair : portfolio) {
      cout << "Stock: " << pair.first << " | Quantity: " << pair.second << endl;
    }
  }
  cout << "--------------------------" << endl;
}