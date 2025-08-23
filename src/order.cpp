#include "stock_exchange/Order.h"
Order::Order(int orderID, const std::string& symbol, double price, int quantity, bool isBuy)
    : orderID(orderID),
      symbol(symbol),
      price(price),
      quantity(quantity),
      isBuy(isBuy) {

}