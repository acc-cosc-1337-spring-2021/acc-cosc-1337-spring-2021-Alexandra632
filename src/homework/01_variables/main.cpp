//write include statements
#include "variables.h"
#include <iostream>
#include <iomanip>
//write namespace using statement for cout
using namespace std;

int main()
{
	double meal_amount,
	tip_rate,
	tip_amount,
	tax_amount,
	total;

	cout << "How much did the meal cost? ";

	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "What is the tip rate? ";

	cin >> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tax_amount + tip_amount;

	cout << fixed << setprecision(2);
	cout << "Meal amount: " << meal_amount << "\n";
	cout << "Sales tax: " << tax_amount << "\n";
	cout << "Tip amount: " << tip_amount<< "\n";
	cout << "Total: " << total << "\n";

	return 0;
}
