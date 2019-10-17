//Drew Lukens final C++ project
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//new Class for accounts
class account {

public:
	//Variables
	string owner;
	double amount;
	int pin;
	//Constructor
	account(const string &name, double initialDeposit, int pinNumber) :
		owner(name), amount(initialDeposit), pin(pinNumber) {}
	account() = default; //default constructor
	//Get functions
	double getBalance() const { return amount; }
	string getOwner() const { return owner; }
	int getPin() const { return pin; }
};

//Need to overload the << function for later use to print everything out!!!
ostream& operator<<(ostream& os, const account& accountValue)
{
	os << "Name: " << accountValue.getOwner() << endl
		<< "Balance: " << accountValue.getBalance() << endl << endl;
	return os;
}

//functions that were removed due to time constraint. I couldn't get them to work.

//void withdraw(account ownerA, double removeAmount) {
	//ownerA.amount = ownerA.getBalance() - removeAmount;

//}
//void deposit(account ownerA, double amountDeposit){
  //ownerA.amount = ownerA.getBalance() + amountDeposit;
//}

//void transfer(account ownerA, account ownerB, double transferValue) {
	//ownerA.amount = ownerA.getBalance() - transferValue;
	//ownerB.amount = ownerB.getBalance() + transferValue;
	//function to transfer from one account to another
//}

//Find account function used to return index of the account in the vector.
int findAccount(vector<account> a, string s) {
	int c = 0;
	auto itrBegin = a.begin();
	auto itrEnd = a.end();
	account newValue;

	while (itrBegin != itrEnd) {
		newValue = *itrBegin;
		if (newValue.getOwner() == s) {
			return c;
		}
		itrBegin++;
		c++;
	}
	return c; //Returns the inital value in the string isn't found. Talked about Known error section of write up.
}
	void mainScreen() {
		cout << endl << "Banking Management System" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 | Create New Account" << endl;
		cout << "2 | Deposit Funds" << endl;
		cout << "3 | Withdraw Funds" << endl;
		cout << "4 | Transfer Funds Between Accounts" << endl;
		cout << "5 | Close Account" << endl;
		cout << "6 | List Accounts" << endl;
    cout << "7 | Bank Stats" << endl;
		cout << "8 | End Program" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Please type the number of what option you want to select!!!" << endl << endl;
	}

	//Main Function!!!
	int main() {

		//Creating the Bank Vector.
		vector<account> bankA;
		bankA.reserve(10);

		//Variables
		string name;
		double deposit;
		int pinNumber;
		string a;
		double b;
		string c;
		int input;
		account dummyAccountA;
		bool continueValue = true;

		do{
			//Run the mainScreen function.
			mainScreen();
			cin >> input;
			//  Runs if user selects to open a new account
			if (input == 1) {
				cout << "Please type the owner name for the Account." << endl;
				cin >> name;
				cout << "Please type the amount of money that you would like to deposit." << endl;
				cin >> deposit;
				cout << "Please type the Pin Number for the account." << endl;
				cin >> pinNumber;
				//Creates the new account and adds to the Bank.
				account obj(name, deposit, pinNumber);
				bankA.push_back(obj);
			}

			// Runs if user wants to deposit money
			if (input == 2) {
				cout << "Which account would you like to deposit your money into?" << endl;
				cin >> a;
				cout << "how much $$$ would you like to deposit?" << endl;
				cin >> b;
				cout << "You have deposited  $ " << b << " into " << a << "'s account." << endl;

				bankA[findAccount(bankA, a)].amount = bankA[findAccount(bankA, a)].getBalance() + b;
				//deposit(dummyAccountA,b);
				cout << dummyAccountA.getBalance() + b;

			}
			// Runs if user wants to Withdraw money. Requires PIN
			if (input == 3) {
				cout << "Which account would you like to withdraw money from?" << endl;
				cin >> a;
				cout << "How much $$$ would you like to withdraw?" << endl;
				cin >> b;
				cout << "Please type the accounts Pin to confirm the transaction." << endl;
				cin >> pinNumber;
				// Test if pin is correct...
				if (pinNumber == bankA[findAccount(bankA, a)].getPin()) {
					bankA[findAccount(bankA, a)].amount = bankA[findAccount(bankA, a)].getBalance() - b;
				}
				//If pin is incorrect
				else {
					cout << "The Pin provided doesn't match the pin for the account." << endl;
				}
			}

			// Runs if user wants to transfer money to a different account
			if (input == 4) {
				cout << "Which account would you like to transfer money from?" << endl;
				cin >> a;
				cout << "Which account would you like to transfer money to?" << endl;
				cin >> c;
				cout << "How much $$$ would you like to transfer?" << endl;
				cin >> b;

				//transfer(bankA[findAccount(bankA, a)], bankA[findAccount(bankA, c)], b);
				bankA[findAccount(bankA, a)].amount = bankA[findAccount(bankA, a)].getBalance() - b;
				bankA[findAccount(bankA, c)].amount = bankA[findAccount(bankA, c)].getBalance() + b;

				cout << "You have transfered  $ " << b << " into " << c << "'s account from "
					<< a << "'s account. ";
			}

			if (input == 5) {
				cout << "Which account would you like to close? Please type the owner's name" << endl;
				cin >> a;
				cout << "Please type the accounts pin to confirm." << endl;
				cin >> pinNumber;
				// Test if pin is correct...
				if (pinNumber == bankA[findAccount(bankA, a)].getPin()) {
					bankA[findAccount(bankA, c)] = dummyAccountA;
				}
			}
			if (input == 6) {
				auto itrBeginVector = bankA.begin();
				auto itrEndVector = bankA.end();
				while (itrBeginVector != itrEndVector) {
					cout << *itrBeginVector; // Need to change this....
					itrBeginVector++;
				}
			}
      if (input == 7) {
        auto itrbankBeg = bankA.begin();
        auto itrbankEnd = bankA.end();
        double sum = 0;
        account value;

        while (itrbankBeg != itrbankEnd) {
          value = *itrbankBeg;
          sum = sum + value.getBalance();
          itrbankBeg++;
        };
        cout << "The total Amount in the bank is $ " << sum << endl;
        cout << "If banks are required to have 10% in reserves, This bank would have $" << sum * .1 << " in liquid assets." << endl;
      }
			if (input == 8) {
				continueValue = false;
			}
			input = 100;

		} while (continueValue == true); // returns you to the main screen after the option is done running. As long as it wasn't option 7 "End Program"
	}
