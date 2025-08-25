# C++ Stock Exchange Simulator

![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)
![Build System](https://img.shields.io/badge/build-CMake-orange.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

> A command-line application that simulates a basic stock market with a real-time order matching engine. This project is built from the ground up in C++ to demonstrate core Object-Oriented Programming (OOP) principles and clean software architecture.
---

## ✨ Features

* **Centralized Exchange:** Manages all market participants and tradable stocks.
* **Order Book:** Each stock maintains its own order book with lists of buy (bid) and sell (ask) orders.
* **Matching Engine:** Automatically executes trades when the highest bid price is greater than or equal to the lowest ask price.
* **Trader Portfolio Management:** Traders have cash balances and stock portfolios that are updated in real-time as trades are executed.
* **Order Validation:** The exchange acts as a gatekeeper, rejecting orders if a trader has insufficient funds to buy or insufficient stock to sell.

---

## 🛠️ Tools & Technologies

* **Language:** C++ (using C++17 features)
* **Build System:** CMake
* **Compiler:** MinGW (g++) or Visual Studio (MSVC)

---

## 🚀 Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

* A C++17 compatible compiler (like g++ or MSVC)
* CMake (version 3.10 or higher)
* Git

### Build Instructions

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/](https://github.com/)[Your-Username]/[Your-Repository-Name].git
    cd [Your-Repository-Name]
    ```

2.  **Create and navigate to the build directory:**
    ```sh
    mkdir build
    cd build
    ```

3.  **Configure the project with CMake:**
    ```sh
    # For Visual Studio or default toolchains
    cmake ..

    # If you are using MinGW, you may need to specify the generator
    cmake -G "MinGW Makefiles" ..
    ```

4.  **Compile the project:**
    ```sh
    cmake --build .
    ```

### Running the Simulator

The executable will be created inside the `build` directory.

* On Windows:
    ```sh
    # If using Visual Studio, the executable is likely in a Debug subfolder
    .\Debug\simulator.exe

    # If using MinGW, it's likely in the build folder directly
    .\simulator.exe
    ```
* On macOS/Linux:
    ```sh
    ./simulator
    ```

---

## 🏛️ OOPs Concepts Demonstrated

This project was designed to showcase a practical application of Object-Oriented principles:

* **Encapsulation:** Each class manages its own internal state. For example, the `Trader` class encapsulates the `cashBalance` and `portfolio`, which can only be modified through public methods like `addCash()` or `removeStock()`. The `Stock` class encapsulates its own private `buyOrders` and `sellOrders`.

* **Abstraction:** The `Exchange` class provides a simple public interface (`submitOrder`, `addTrader`). A user of the `Exchange` class does not need to know the complex internal logic of how the `Stock`'s matching engine sorts orders and executes trades. They just submit an order and the system handles the rest.

* **Object Interaction:** The project is a clear example of how different objects collaborate to achieve a goal. The workflow `Trader` -> `Exchange` -> `Stock` shows a clean separation of concerns where each object has a distinct role and communicates with others to complete a transaction.

---

## 🔮 Future Improvements

* **Inheritance & Polymorphism:** Implement different order types (e.g., `MarketOrder`, `LimitOrder`, `StopLossOrder`) that inherit from a base `Order` class.
* **Handle Partial Fills:** Upgrade the matching engine to handle trades where the buy and sell quantities are not equal.
* **Interactive CLI:** Create a user-friendly command-line interface where the user can type commands in real-time to interact with the market.
* **Persistence:** Save the state of the exchange (traders, stocks, orders) to a file (e.g., JSON or CSV) and allow it to be reloaded.

---
