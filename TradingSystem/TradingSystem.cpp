#include "StockBroker.cpp"
#include <string>
#include <deque>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

class TradingSystem
{
public:
	void selectStockBroker(StockBroker* broker) {
		_broker = broker;
	}
	bool login(string id, string password) {
		_broker->login(id, password);
		return true;
	}
	bool buy(string stockCode, int price, int count) {
		_broker->buy(stockCode, price, count);
		return true;
	}
	bool sell(string stockCode, int price, int count) {
		_broker->sell(stockCode, price, count);
		return true;
	}
	int getPrice(string stockCode) {
		return _broker->getPrice(stockCode);
	}
	StockBroker* getBroker() {
		return _broker;
	}

	void sellNiceTiming(std::string stockCode, int count) {
		std::deque<int> prices;
		for (int i = 0; i < 3; ++i) {
			int current_price = _broker->getPrice(stockCode);
			std::cout << "Current price: " << current_price << std::endl;

			if (!prices.empty() && current_price > prices.back()) {
				prices.clear();
			}

			prices.push_back(current_price);

			if (prices.size() == 3) {
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		if (prices.size() == 3 && std::is_sorted(prices.rbegin(), prices.rend())) {
			_broker->sell(stockCode, prices.back(), count);
			std::cout << "Sold " << count << " of " << stockCode << " at price " << prices.back() << std::endl;
		}
		else {
			std::cout << "No sell." << std::endl;
		}
	}

private:
	StockBroker* _broker{ nullptr };
};
