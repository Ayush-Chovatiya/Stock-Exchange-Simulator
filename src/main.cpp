#include <iostream>
using namespace std;
#include "stock_exchange/Exchange.h"
#include "stock_exchange/Trader.h"

int main() {
  // 1. Setup the Exchange
  Exchange mainExchange;
  mainExchange.addStock("AAPL");  // Add Apple stock to the exchange

  // 2. Setup the Traders
  Trader trader1(101, 50000.0);
  Trader trader2(102, 50000.0);
  trader2.addStock("AAPL", 7);  // Give trader 2 some stock to sell

  mainExchange.addTrader(trader1);
  mainExchange.addTrader(trader2);

  cout << "\n--- Initial Portfolios ---" << endl;
  trader1.viewPortfolio();
  trader2.viewPortfolio();

  // 3. Traders place their orders through the exchange
  cout << "\n--- Market is Open ---" << endl;
  trader1.placeOrder(mainExchange, "AAPL", 152.50, 10, true);   // Trader 1 wants to BUY
  trader2.placeOrder(mainExchange, "AAPL", 152.00, 10, false);  // Trader 2 wants to SELL

  // --- NEW: VERIFY FINAL PORTFOLIOS ---
  cout << "\n--- Final Portfolios ---" << endl;
  // We need to get the updated trader objects from the exchange
  mainExchange.printTraderPortfolios();

  return 0;
}