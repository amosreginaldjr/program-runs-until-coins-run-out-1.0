#include"RandomNumber.h"
#include<stdlib.h>     /* srand, rand */
#include<time.h>       /* time */
using namespace std;

RandomNumber::RandomNumber(int userMinValue, int userMaxValue)
{
	srand(time(NULL));
	mUserMinValue = userMinValue;
	mUserMaxValue = userMaxValue;
}

void RandomNumber::setUserMinValue(int userMinValue) { this->mUserMinValue = mUserMinValue; }
void RandomNumber::setUserMaxValue(int userMaxValue) { this->mUserMaxValue = userMaxValue; }
int RandomNumber::getRandomNumber()
{
	if (mUserMinValue == mUserMaxValue)
	{
		cout << "Your minimum value is " << mUserMinValue << " and your maximum value is " << mUserMaxValue;
		return -1;
	}
	return rand() % mUserMaxValue + mUserMinValue;
}