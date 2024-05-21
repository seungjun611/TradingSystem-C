#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/TradingSystem.cpp"

using namespace testing;

class MockTrading : public TradingSystem {
public:
	MOCK_METHOD(int, getPrice, (int item), (override));
	MOCK_METHOD(bool, buy, (int item,int price, int count), (override));
};


TEST(TradingSystem, buyNiceTimingGetPrice3times) {
	MockTrading system;

	EXPECT_CALL(system, getPrice(1))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30))
		;

	system.buyNiceTiming(1, 30);
}


TEST(TradingSystem, buyNiceTimingSuccess) {
	MockTrading system;

	EXPECT_CALL(system, getPrice(1))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30))
		;

	EXPECT_CALL(system, buy(1, 30, 1))
		.WillOnce(Return(true));

	system.buyNiceTiming(1, 30);
}

TEST(TradingSystem, buyNiceTimingFail) {
	MockTrading system;

	EXPECT_CALL(system, getPrice(1))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(20))
		;

	system.buyNiceTiming(1, 30);
}


TEST(TradingSystem, buyNiceTimingException) {
	MockTrading system;

	EXPECT_CALL(system, getPrice(1))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(0))
		;
	
	EXPECT_THROW(system.buyNiceTiming(1, 30), exception);
}