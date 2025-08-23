#include <iostream>

#include "stock_exchange/Exchange.h"
#include "stock_exchange/Trader.h"

using namespace std;

int main() {
  // Setup exchange
  Exchange mainExchange;
  mainExchange.addStock("AAPL");

  // Setup traders
  Trader trader1(101, 50000.0);
  Trader trader2(102, 50000.0);
  mainExchange.addTrader(trader1);
  mainExchange.addTrader(trader2);

  // Place orders
  trader1.placeOrder(mainExchange, "AAPL", 152.50, 10, true);   // buy
  trader2.placeOrder(mainExchange, "AAPL", 152.00, 10, false);  // sell

  // More orders
  trader1.placeOrder(mainExchange, "AAPL", 150.00, 10, true);
  trader2.placeOrder(mainExchange, "AAPL", 155.00, 10, false);

  return 0;
}
