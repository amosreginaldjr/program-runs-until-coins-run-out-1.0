#include<iostream>
#include<Windows.h>
#include"RandomNumber.h"
using namespace std;

class Coins
{
private:
	int mCoins; //the total amount of coins that the user currently has actively runnning
	int mBankedCoins; //the amount of coins that the program has banked
	float mTaxPercentage; //the percentage that will be decucted every timeToTax iterations
	int mTimeToTax; //after every n iterations, itll apply a tax
	int mRandomNumber; //the current random number
	float mInterest; //const
public:
	Coins();
	void applyInterestCeling(); //should the user be allowed to set the interest amount as a parameter
	void applyInterestFloor();
	void depositCoinsAutomatically(int numberOfCoinsToDeposit);
	void applyTaxes();
	void bankCoins(); /*should the user be allowed to determine after how many 
						stored coins, how many will be banked*/
	void outputRandomNumber();
	void outputRemainingCoinsLeft();
	void setCoins(int initalValueOfCoins);
	int getCoins();
public:
	void delay(int delayMS); //take in as a pameter how long the delay will be in ms
};

Coins::Coins()
{
	mCoins = 10;
	mBankedCoins = 0;
	mTaxPercentage = 0.08875f;
	mTimeToTax = 10;
	mRandomNumber = 0;
	mInterest = 1.5f;
}

void Coins::applyInterestCeling() { this->mBankedCoins *= ceil(mInterest); }
void Coins::applyInterestFloor() { this->mBankedCoins *= floor(mInterest); }

void Coins::depositCoinsAutomatically(int numberOfCoinsToDeposit)
{
	if (this->mCoins == numberOfCoinsToDeposit)
	{
		this->mBankedCoins = numberOfCoinsToDeposit;
		this->mCoins -= numberOfCoinsToDeposit;
	}
}

void Coins::applyTaxes()
{

}

void Coins::bankCoins()
{

}

void Coins::outputRandomNumber() { cout << mCoins; }
void Coins::outputRemainingCoinsLeft() { cout << mRandomNumber; }
void Coins::setCoins(int initalValueOfCoins) { mCoins = initalValueOfCoins; }
int Coins::getCoins() { return this->mCoins; }

void Coins::delay(int delayMS) { Sleep(delayMS); }

int main()
{
	RandomNumber rn(1, 10);
	int incrementer = 100;
	int coins = 10;
	int randomNumber = rn.getRandomNumber();

	int bank = 100;
	int delay = 1000;
	int time = 10;

	int taxTime = 20;
	float tax = 1.5;

	while (coins)
	{
		randomNumber = rn.getRandomNumber();
		cout << "randomNumber: " << randomNumber << "|||" << "coins: " << coins << endl;
		if (randomNumber == 6)
			coins += 8;
		else
			coins--;
		

		if (!coins && bank)
		{
			cout << "BANKED COINS USED\n";
			coins = bank;
			bank = 0;
		}

		if (coins > 5)
			delay = 10;
		else
			delay = 500;

		if (coins > 50)
		{
			cout << "COINS STORED IN THE BANK\n";
			bank += coins / 2;
			coins = coins / 2;
			cout << "COINS: " << coins << endl;
			cout << "BANK: " << bank << endl;
		}

		if (!time)
		{
			cout << "INTEREST APPLIED\n";
			cout << "BANK: " << bank << endl;
			bank = ceil(bank * 1.2);
			time = 10;
		}
		time--;

		if (!taxTime)
		{
			cout << "PAY TAXES\n";
			cout << "BANK: " << bank << endl;
			bank = ceil(bank / tax);
			taxTime = 20;
		}
		taxTime--;

		Sleep(delay);
	}
	cout << "COINS: " << coins << endl;
	cout << "BANK: " << bank << endl;
	cout << endl;
	return 0;
}