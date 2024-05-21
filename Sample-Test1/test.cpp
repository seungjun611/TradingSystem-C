#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/TradingSystem.cpp"

using namespace testing;

class MockDriver : public StockBroker
{
public:
	MOCK_METHOD(void, login, (string, string), (override));
	MOCK_METHOD(void, buy, (string, int, int), (override));
	MOCK_METHOD(void, sell, (string, int, int), (override));
	MOCK_METHOD(int, getPrice, (string), (override));
};

TEST(TradingSystem, SelectStockBroker) {
	TradingSystem system;
	StockBroker* driver = new MockDriver();

	system.selectStockBroker(driver);
}

TEST(TradingSystem, SellNiceTiming)
{
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);

	EXPECT_CALL(mock, getPrice(string("Apple.Inc")))
		.WillOnce(Return(100))
		.WillOnce(Return(90))
		.WillOnce(Return(80));

	EXPECT_CALL(mock, sell(string("Apple.Inc"), 80, 100))
		.Times(1);

	system.sellNiceTiming(string("Apple.Inc"), 100);
}

TEST(TradingSystem, BuyNiceTiming)
{
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);

	EXPECT_CALL(mock, getPrice(string("Apple.Inc")))
		.WillOnce(Return(100))
		.WillOnce(Return(120))
		.WillOnce(Return(140));

	EXPECT_CALL(mock, buy(string("Apple.Inc"), 160, 100))
		.Times(1);

	system.buyNiceTiming(string("Apple.Inc"), 100);
}