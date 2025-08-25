#include "stock_exchange/Stock.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

Stock::Stock(const string& symbol) : symbol(symbol), lastTradedPrice(0.0) {}

void Stock::addOrder(const Order& order) {
  if (order.isBuyOrder()) {
    buyOrders.push_back(order);  // add buy
  } else {
    sellOrders.push_back(order);  // add sell
  }
}

vector<Trade> Stock::executeTrades() {
  // Sort: buys high→low, sells low→high
  sort(buyOrders.begin(), buyOrders.end(),
       [](const Order& a, const Order& b) {
         return a.getPrice() > b.getPrice();
       });
  sort(sellOrders.begin(), sellOrders.end(),
       [](const Order& a, const Order& b) {
         return a.getPrice() < b.getPrice();
       });

  // Match as long as best buy >= best sell
  vector<Trade> trades_done;
  while (!buyOrders.empty() && !sellOrders.empty() &&
         buyOrders.front().getPrice() >= sellOrders.front().getPrice()) {
    Order& buy = buyOrders.front();
    Order& sell = sellOrders.front();

    cout << "\n--- Match Found! ---" << endl;
    cout << "Executing trade for " << symbol << " at price $" << sell.getPrice() << endl;

    trades_done.push_back({buy.getTraderID(), sell.getTraderID(), symbol, buy.getQuantity(), sell.getPrice()});

    // Simple: remove both (ignores partial qty)
    buyOrders.erase(buyOrders.begin());
    sellOrders.erase(sellOrders.begin());
  }

  return trades_done;
}

void Stock::displayOrderBook() const {
  cout << "--- Order Book for " << symbol << " ---" << endl;

  cout << "SELL ORDERS:" << endl;
  for (const auto& order : sellOrders) {
    cout << "ID: " << order.getOrderID()
         << " | Price: " << order.getPrice()
         << " | Qty: " << order.getQuantity() << endl;
  }

  cout << "--------------------------" << endl;
  cout << "BUY ORDERS:" << endl;
  for (const auto& order : buyOrders) {
    cout << "ID: " << order.getOrderID()
         << " | Price: " << order.getPrice()
         << " | Qty: " << order.getQuantity() << endl;
  }
  cout << "--------------------------" << endl;
}