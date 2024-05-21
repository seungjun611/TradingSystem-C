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