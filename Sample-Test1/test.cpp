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
class TradingSystemFixture : public Test {
public:
	void SetUp() override {
		system.selectStockBroker(&STOCK_BROKER);
		assertNullException();
	}

	const string STOCK_NAME = "NONAME";
	const int STOCK_PRICE = 1000;

	TradingSystem system;
	MockDriver STOCK_BROKER;

private:
	void assertNullException() {
		EXPECT_THAT(system.getBroker(), NotNull());
	}
};

TEST_F(TradingSystemFixture, sample) {
	EXPECT_CALL(STOCK_BROKER, getPrice(_))
		.WillRepeatedly(Return(STOCK_PRICE));
	EXPECT_EQ(system.getPrice(STOCK_NAME), STOCK_PRICE);
}

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
	EXPECT_CALL(mock, getPrice(string("Apple.Inc")))
		.WillOnce(Return(100))
		.WillOnce(Return(120))
		.WillOnce(Return(140));

	EXPECT_CALL(mock, buy(string("Apple.Inc"), 160, 100))
		.Times(1);

	system.buyNiceTiming(string("Apple.Inc"), 100);
}