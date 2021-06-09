#include <bits/stdc++.h>
using namespace std;

template<class T, class U, class V>
class triplet {

public:
	T first;
	U second;
	V third;

	triplet(T first, U second, V third): first(first), second(second), third(third) {

	}

};

int main() {

	int numfriends, numTransactions;
	cin >> numfriends >> numTransactions;


	map<string, int> net;

	while (numTransactions--) {
		// x has to give y Rs. amount
		string x, y;
		int amount;
		cin >> x >> y >> amount;
		net[x] -= amount;
		net[y] += amount;
	}

	multiset<pair<int, string>> m;

	vector <triplet<string, string, int>> v;


	// Init a list and sort it => Multiset
	for (auto x : net) {
		if (x.second != 0) {
			m.insert({x.second, x.first});
			cout << x.second << " " << x.first << endl;
		}
	}


	// Person A with the highest debt will give money to the person B with the highest credit //

	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		auto debit = *low;
		auto credit = *high;

		m.erase(low);
		m.erase(high);

		int mn = min(credit.first, abs(debit.first));
		cout << mn << endl;
		debit.first += mn;
		credit.first -= mn;
		// One of them will be zero
		if (debit.first != 0) {
			m.insert(debit);
		}
		if (credit.first != 0) {
			m.insert(credit);
		}
		v.push_back({debit.second, credit.second, mn});
	}
	for (auto x : v) {
		cout << x.first << " pay " << x.third << " to " << x.second << endl;
	}
}

/*
Input : 
3 3
Kalyan Krishnendu 100
Krishnendu Rishav 50
Rishav Kalyan 40

Output: 
-60 Kalyan
50 Krishnendu
10 Rishav
50
10
Kalyan pay 50 to Krishnendu
Kalyan pay 10 to Rishav
*/
