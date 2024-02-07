#pragma once
#include<iostream>

class RandomNumber
{
protected:
	int mUserMinValue;
	int mUserMaxValue;
	//int mCurrentRandomNumber;
public:
	RandomNumber(int userMinValue, int userMaxValue);
	void setUserMinValue(int userMinValue); //if needed, you can still use these but not necessary!
	void setUserMaxValue(int userMaxValue);	//if needed, you can still use these but not necessary!
	int getRandomNumber();
};