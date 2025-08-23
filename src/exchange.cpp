#include "stock_exchange/exchange.h"

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
  // Find the correct stock and add the order
  auto it = stocks.find(order.getSymbol());
  if (it != stocks.end()) {
    it->second.addOrder(order);
    // After adding the order, immediately try to execute trades for that stock
    it->second.executeTrades();
    // NOTE: We will add logic here later to update traders after a trade
  }
}