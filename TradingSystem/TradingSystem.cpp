#pragma once
#include "StockBroker.cpp"
#include "KiwerDriver.cpp"
#include "NemoDriver.cpp"
#include <string>
using namespace std;

class TradingSystem
{
public:
	void selectStockBrocker(StockBroker* broker);
	bool login(string id, string password)
	{
		return true;
	}
	bool buy(string item, int price, int count);
	bool sell(string item, int price, int count);
	int getPrice(string item);

private:
	StockBroker* _broker{ nullptr };
};

void TradingSystem::selectStockBrocker(StockBroker* broker)
{
	_broker = broker;
}