#include "stock_exchange/Order.h"
Order::Order(int orderID, int traderId, const std::string& symbol, double price, int quantity, bool isBuy)
    : orderID(orderID),
      traderID(traderId),
      symbol(symbol),
      price(price),
      quantity(quantity),
      isBuy(isBuy) {
}