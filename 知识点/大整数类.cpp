#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct BigInt {
	static const int base = 100000000;
	static const int wid = 8;
	vector<int>s;
	BigInt operator=(long long num) {
		s.clear();
		do {
			s.push_back(num % base);
			num /= base;
		} while (num > 0);
		return *this;
	}
	BigInt(long long num = 0) {
		*this = num;
	}
	BigInt operator=(string&str) {
		s.clear();
		int len = (str.size() - 1 + wid) / wid;
		int x;
		for (int i = 0; i < len; i++) {
			int end = str.size() - i*wid;
			int start = max(0, end - wid);
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}

		return *this;
	}
	BigInt operator+(const BigInt&b) {
		BigInt c;
		c.s.clear();
		for (int i = 0, g = 0;; i++) {
			if (g == 0 && i >= (int)s.size() && i >= (int) b.s.size())break;
			int x = g;
			if (i < (int)s.size()) {
				x += s[i];
			}
			if (i < (int)b.s.size())x += b.s[i];
			c.s.push_back(x % base);
			g = x / base;
		}
		return c;

	}
	BigInt operator+=(const BigInt&b) {
		*this = *this + b;
		return*this;
	}
	bool operator<(const BigInt&b) const {
		if (s.size() != b.s.size())return s.size() < b.s.size();
		for (int i = s.size() - 1; i >= 0; i--)if (s[i] != b.s[i]) {
				return s[i] < b.s[i];
			}
		return false;
	}
	bool operator<=(const BigInt&b) {
		return !(b < *this);
	}
	bool operator>(const BigInt&b) {
		return b < *this;
	}
};
ostream& operator<<(ostream&out, const BigInt&b) {
	out << b.s.back();
	for (int i = b.s.size() - 2; i >= 0; i--) {
		char buf[20];
		sprintf(buf, "%08d", b.s[i]);
		out << buf;
	}
	return out;
}
istream& operator>>(istream&in, BigInt&b) {
	string str;
	if (!(in >> str))return in;
	b = str;
	return in;
}
int main() {
	BigInt a, b;
	b.s.clear();
	cin >> b>>a;
	cout << b << endl;
	
	cout << a + b << endl;
	if (b > a)cout << "b>a" << endl;
}
