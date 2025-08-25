#pragma once
#include <string>

// this structure holds complete data of a single trade executed
// it is created by stock class & it is used by exchange class
struct Trade {
  int buyerTraderID;
  int sellerTraderID;
  std::string stockSymbol;
  int quantity;
  double price;
};