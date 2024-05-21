#include "StockBroker.cpp"
#include <string>
using namespace std;

class TradingSystem
{
public:
	void selectStockBroker(StockBroker* broker) {
		_broker = broker;
	}
	bool login(string id, string password) {
		_broker->login(id, password);
	}
	bool buy(string stockCode, int price, int count) {
		_broker->buy(stockCode, price, count);
	}
	bool sell(string stockCode, int price, int count) {
		_broker->sell(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		_broker->getPrice(stockCode);
	}

private:
	StockBroker* _broker{ nullptr };
};