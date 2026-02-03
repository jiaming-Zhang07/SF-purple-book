#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
string a[10000][10];
map<string, int>bin;
int main() {
	freopen("z.txt", "r", stdin);
	freopen("zjm.txt", "w", stdout);
	int r, c;
	while (cin >> r >> c) {char ch;
		while ((ch = getchar()) != '\n' && ch != '\r');
		for (int i = 0; i < r; i++) {
			int m = 0;
			string s;
			getline(cin, s);
			size_t last=0, next = s.find(",");
			while (next != string::npos) {
				a[i][m++] = s.substr(last, next - last);
				last = next + 1;
				next = s.find(",", last);
			}
			a[i][m] = s.substr(last);
		}
		for (int i = 0; i < c - 1; i++)
			for (int j = i + 1; j < c; j++)
				{bin.clear();
				for (int k = 0; k < r; k++) {
					if (bin.count(a[k][i] + "\0" + a[k][j])) {
						cout << "NO" << endl << bin[a[k][i] + "\0" + a[k][j]]+1 << " " << k+1 << endl << i+1 << " " << j+1 << endl;
						goto jump;
					}
					bin[a[k][i] + "\0" + a[k][j]] = k;
				}
			}
		cout << "YES" << endl;
jump:
		;

	}
}
