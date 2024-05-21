#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/TradingSystem.cpp"
#include "../TradingSystem/StockBroker.cpp"

using namespace std;
using namespace testing;

class MockDriver : public StockBroker
{
public:
	MOCK_METHOD(void, login, (string, string), (override));
	MOCK_METHOD(void, buy, (string, int, int), (override));
	MOCK_METHOD(void, sell, (string, int, int), (override));
	MOCK_METHOD(int, getPrice, (string), (override));
};

TEST(TradingSystem, CreateMockDriver) {
	TradingSystem system;
	MockDriver driver;

	EXPECT_CALL(driver, login(string("Fake Name"), string("1234")))
		.Times(0);

	system.selectStockBrocker(&driver);

	system.login(string("Fake Name"), string("1234"));
}