#include "NemoAPI.cpp"
#include "StockBroker.cpp"

class NemoDriver : public StockBroker
{
public:
	void login(std::string id, std::string pw)
	{
		Nemo.certification(id, pw);
	}
	void buy(std::string stockCode, int price, int count)
	{
		Nemo.purchasingStock(stockCode, price, count);
	}
	void sell(std::string stockCode, int price, int count)
	{
		Nemo.sellingStock(stockCode, price, count);
	}
	int getPrice(std::string stockCode)
	{
		Nemo.getMarketPrice(stockCode, 0);
	}
private:
	NemoAPI Nemo;
};