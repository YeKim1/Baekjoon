#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	
	int day = 0;
	int cur = 0;

	while (cur < V) {
		day++;

		cur += A;
		if (cur >= V) break;
		
		cur -= B;
	}

	cout << day;
}