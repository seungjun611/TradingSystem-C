#pragma once
#include "KiwerAPI.cpp"
#include "StockBroker.cpp"

class KiwerDriver : public StockBroker
{
public:
	void login(std::string id, std::string pw)
	{

	}
	void buy(std::string stockCode, int price, int count)
	{

	}
	void sell(std::string stockCode, int price, int count)
	{

	}
	int getPrice(std::string stockCode)
	{

	}
};