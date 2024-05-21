#include "StockBroker.cpp"
#include <string>
#include <exception>
using namespace std;

class TradingSystem
{
public:
	void selectStockBrocker(string api);
	bool login(int id, int password);
	virtual bool buy(int item, int price, int count) = 0;
	bool sell(int item, int price, int count);
	virtual int getPrice(int item) = 0;
	void buyNiceTiming(int item, int price);
	void sellNiceTiming(int item, int count);

	int checkPrice3Times(int price_list[3],int item);
	int checkPriceUp(int price_list[3]);

private:
	StockBroker* _broker{ nullptr };
};

int TradingSystem::checkPrice3Times(int price_list[3],int item) {
	int priceNow = 0;
	for (int i = 0; i < 3; i++) {
		price_list[i] = getPrice(item);
		priceNow = price_list[i];
	}

	return priceNow;
}

int TradingSystem::checkPriceUp(int price_list[3]) {
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

void TradingSystem::buyNiceTiming(int item, int money)
{
	int price_list[3];
	int priceNow = 0;
	priceNow = checkPrice3Times(price_list, item);

	int priceUpCount = checkPriceUp(price_list);

	if (priceUpCount == 2) {
		buy(item, priceNow, money / priceNow);
	}
}