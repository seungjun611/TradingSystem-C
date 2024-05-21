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

	int checkPrice3Times(int price_list[3], string item) {
		int priceNow = 0;
		for (int i = 0; i < 3; i++) {
			price_list[i] = getPrice(item);
			priceNow = price_list[i];
		}

		return priceNow;
	}

	int checkPriceUp(int price_list[3]) {
		int priceUpCount = 0;
		for (int i = 1; i < 3; i++) {
			if (price_list[i - 1] == 0 || price_list[i] == 0) {
				throw exception("Item Price is 0!!");
			}

			if (price_list[i - 1] < price_list[i]) {
				priceUpCount++;
			}
		}

		return priceUpCount;
	}

	void buyNiceTiming(string item, int money)
	{
		int price_list[3];
		int priceNow = 0;
		priceNow = checkPrice3Times(price_list, item);

		int priceUpCount = checkPriceUp(price_list);

		if (priceUpCount == 2) {
			buy(item, priceNow, money / priceNow);
		}
	}

private:
	StockBroker* _broker{ nullptr };
};

