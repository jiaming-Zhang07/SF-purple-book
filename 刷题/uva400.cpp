#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<string>str(n);
		int max = 0;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			if (str[i].size() > str[max].size())
				max = i;
		}
		int M = str[max].size();
		int col = (60 - M) / (M + 2) + 1;
		int r;
		for ( r = 1; !(r * col >= n); r++);
		col = n / r;
		if (n % r != 0)col++;
		sort(str.begin(), str.end());

		for (int i = 0; i < 60; i++)cout << "-";
		cout << endl;
		for (int i = 0; i < n - (col - 1) * r; i++) {
			int wid = M + 2;
			for (int j = 0; j < col; j++) {

				if (j == col - 1)wid -= 2;
				cout << left << setw(wid) << str[j*r + i];
				if (j == col - 1)cout << endl;

			}

		}
		for (int i = n - (col - 1) * r; i < r; i++) {
			int wid = M + 2;
			for (int j = 0; j < col - 1; j++) {
				if (j == col - 2)wid -= 2;
				cout << left << setw(wid) << str[j*r + i];
				if (j == col - 2)cout << endl;
			}
		}

	}
}
