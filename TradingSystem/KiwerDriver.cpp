#include "KiwerAPI.cpp"
#include "StockBroker.cpp"
#include <string>


class KiwerDriver : public StockBroker
{
private:
	KiwerAPI kiwerAPI;

public:
	KiwerDriver()
	{

	}

	void login(std::string id, std::string pw) override
	{
		kiwerAPI.login(id, pw);
	}
	void buy(std::string stockCode, int price, int count) override
	{
		kiwerAPI.buy(stockCode, price, count);
	}
	void sell(std::string stockCode, int price, int count) override
	{
		kiwerAPI.sell(stockCode, price, count);
	}
	int getPrice(std::string stockCode) override
	{
		kiwerAPI.currentPrice(stockCode);
	}
};