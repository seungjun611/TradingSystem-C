#include "StockBroker.cpp"
#include <string>
using namespace std;

class TradingSystem
{
public:
	void selectStockBrocker(string api);
	bool login(int id, int password);
	bool buy(int item, int price, int count);
	bool sell(int item, int price, int count);
	int getPrice(int item);

private:
	StockBroker* _broker{ nullptr };
};