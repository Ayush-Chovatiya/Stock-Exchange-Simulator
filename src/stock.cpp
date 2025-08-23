#include "stock_exchange/Stock.h"

#include <bits/stdc++.h>

Stock::Stock(const std::string& symbol)
    : symbol(symbol), lastTradedPrice(0.0) {
}

void Stock::addOrder(const Order& order) {
  if (order.isBuyOrder()) {
    buyOrders.push_back(order);
  } else {
    sellOrders.push_back(order);
  }
}

void Stock::executeTrades() {
  std::cout << "Trade execution logic will be implemented here." << std::endl;
  // We will build the matching engine here in the next phase.
}

void Stock::displayOrderBook() const {
  std::cout << "--- Order Book for " << symbol << " ---" << std::endl;
  std::cout << "SELL ORDERS:" << std::endl;
  for (const auto& order : sellOrders) {
    std::cout << "ID: " << order.getOrderID() << " | Price: " << order.getPrice()
              << " | Qty: " << order.getQuantity() << std::endl;
  }
  std::cout << "--------------------------" << std::endl;
  std::cout << "BUY ORDERS:" << std::endl;
  for (const auto& order : buyOrders) {
    std::cout << "ID: " << order.getOrderID() << " | Price: " << order.getPrice()
              << " | Qty: " << order.getQuantity() << std::endl;
  }
  std::cout << "--------------------------" << std::endl;
}