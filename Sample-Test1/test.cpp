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

TEST(TradingSystem, buyNiceTimingGetPrice3times) {
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);
	
	EXPECT_CALL(mock, getPrice(string("Samsung")))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30))
		;

	system.buyNiceTiming(string("Samsung"), 30);
}


TEST(TradingSystem, buyNiceTimingSuccess) {
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);

	EXPECT_CALL(mock, getPrice(string("Samsung")))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30))
		;

	EXPECT_CALL(mock, buy(string("Samsung"), 30, 1))
		.Times(1);

	system.buyNiceTiming(string("Samsung"), 30);
}

TEST(TradingSystem, buyNiceTimingFail) {
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);

	EXPECT_CALL(mock, getPrice(string("Samsung")))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(20))
		;

	system.buyNiceTiming(string("Samsung"), 30);
}


TEST(TradingSystem, buyNiceTimingException) {
	TradingSystem system;
	MockDriver mock;
	system.selectStockBroker(&mock);

	EXPECT_CALL(mock, getPrice(string("Samsung")))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(0))
		;
	
	EXPECT_THROW(system.buyNiceTiming(string("Samsung"), 30), exception);
}