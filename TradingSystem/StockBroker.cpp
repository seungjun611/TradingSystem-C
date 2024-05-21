#include <string>

class StockBroker
{
public:
	virtual void login(std::string id, std::string pw) = 0;
	virtual void buy(std::string stockCode, int price, int count) = 0;
	virtual void sell(std::string stockCode, int price, int count) = 0;
	virtual int getPrice(std::string stockCode) = 0;
};