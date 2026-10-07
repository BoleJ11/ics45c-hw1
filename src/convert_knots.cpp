#include "convert_knots.hpp"
#include <iostream>

using namespace std;

int main() {
	
	int num;
	cin >> num;
	cout << knots_to_miles_per_minute(num) << endl;
    return 0;
}
