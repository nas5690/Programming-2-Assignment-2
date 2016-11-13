/* Naveed Siddiqui
   Programming II, Assignment II
This program will allow one to enter a product and the prices on the product. It will then allow a customer to enter the budget, and then narrow down 
the products that fit their budget.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std; 
#define CUSTOMERNAME "NAVEED SIDDIQUI"

int main()
{
	vector <double> price;
	string name;
	string customer_name;
	string product;
	int amount;
	double budget;
	char answer;
	double value;
	do
	{
		system("cls");
		cout << "\n\t\t\t Store Management Project" << endl;
		cout << "\n\t\t\t Created by: Programming II Students" << endl;
		cout << "\n\t\t\t Manager Name: ";
		getline(cin, name);

		cout << "\n\t\t\t Enter the product name: ";
		getline(cin, product);

		cout << "\n\t\t\t How many prices does this product have?" << " ";
		cin >> amount;
		price.reserve(amount);

		cout << "\n\t\t\t Enter " << amount << " prices for: " << product << endl;
		for (int i = 0; i < amount; i++)
		{
			cout << "\n\t Price " << i + 1 << ": ";
			cin >> value;
			price.push_back(value);
		} 
		

		system("cls");
		cout << "\n\t\t\t Store Management Project" << endl;
		cout << "\n\t\t\t Created by: Programming II Students" << endl;
		cout << "\n\t\t\t CUSTOMER NAME: " << CUSTOMERNAME << endl;
		

		cout << "\n\t\t\t We know that you want to buy " << product << endl;

		cout << "\n\t\t\t Please enter your budget for " << product << ": ";
		cin >> budget;
		int j = 0, counter = 0;
		while (!price.empty() && j<price.size())
		{
			if (price[j] > budget)
			{
				price.erase(price.begin() + j);
				counter++;
				price.resize(amount - counter);
			}
			else
				j++;
		}

		cout << "\n\t\t\t The price(s) that fit your budget is/are: " << endl;
		for (int i = 0; i < price.size(); i++)
		{
			cout << "\n\t\t\t Price " << i + 1 << ": ";
			cout << price[i] << endl;
		}

		cout << "Do you want to find the price of another product? Y: Yes, N: No" << endl;
		cin >> answer;
		cin.ignore(1000, '\n');
		price.clear();
	} while (answer != 'N' && answer != 'n');



	return 0;
}