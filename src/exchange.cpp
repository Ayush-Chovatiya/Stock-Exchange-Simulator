#include "stock_exchange/exchange.h"

#include <iostream>
#include <vector>

#include "stock_exchange/order.h"
#include "stock_exchange/stock.h"
#include "stock_exchange/trader.h"
using namespace std;

void Exchange::addStock(const string& symbol) {
  stocks.emplace(symbol, Stock(symbol));
}

void Exchange::addTrader(const Trader& trader) {
  traders.emplace(trader.getID(), trader);
}

void Exchange::submitOrder(const Order& order) {
  auto traderIt = traders.find(order.getTraderID());
  if (traderIt == traders.end()) {
    cout << "[Exchange] REJECTED: Order from unknown trader "
         << order.getTraderID() << endl;
    return;
  }

  const Trader& trader = traderIt->second;
  double totalCost = order.getPrice() * order.getQuantity();

  if (order.isBuyOrder()) {
    // Check for sufficient funds
    if (trader.getCashBalance() < totalCost) {
      cout << "\n[Exchange] REJECTED: Trader " << trader.getID()
           << " has insufficient funds to buy." << endl;
      return;
    }
  } else {
    // Check for sufficient stock
    if (trader.getStockQuantity(order.getSymbol()) < order.getQuantity()) {
      cout << "\n[Exchange] REJECTED: Trader " << trader.getID()
           << " has insufficient stock to sell." << endl;
      return;
    }
  }

  cout << "\n[Exchange] ACCEPTED: Order " << order.getOrderID()
       << " from Trader " << trader.getID() << endl;

  auto stockIt = stocks.find(order.getSymbol());
  if (stockIt != stocks.end()) {
    Stock& stock = stockIt->second;
    stock.addOrder(order);

    vector<Trade> completedTrades = stock.executeTrades();

    for (const auto& trade : completedTrades) {
      auto buyerIt = traders.find(trade.buyerTraderID);
      auto sellerIt = traders.find(trade.sellerTraderID);

      if (buyerIt != traders.end() && sellerIt != traders.end()) {
        Trader& buyer = buyerIt->second;
        Trader& seller = sellerIt->second;
        double cost = trade.price * trade.quantity;

        buyer.removeCash(cost);
        seller.addCash(cost);
        buyer.addStock(trade.stockSymbol, trade.quantity);
        seller.removeStock(trade.stockSymbol, trade.quantity);

        cout << "[Exchange] Portfolios updated for trade of "
             << trade.quantity << " " << trade.stockSymbol << " shares."
             << endl;
      }
    }
  } else {
    cout << "Error: Cannot place order for unknown stock symbol "
         << order.getSymbol() << endl;
  }
}

void Exchange::printTraderPortfolios() const {
  for (const auto& pair : traders) {
    pair.second.viewPortfolio();
  }
}