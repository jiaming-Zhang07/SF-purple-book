#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
int main() {
	priority_queue<LL, vector<LL>, greater<LL> >pq;
	set<LL>s;
	int co[3] = {2, 3, 5};
	s.insert(1);
	pq.push(1);
	for (int i = 1;; i++) {
		LL t = pq.top();
		pq.pop();
		if (i == 1500) {
			cout << "The 1500'th ugly number is "<<t<<"."<<endl;
			break;
		}
		for (int j = 0; j < 3; j++) {
			LL m = t*co[j];//一个丑数可能被不同的数生成，要找到第1500个丑数，所有要先判断是否已被生成，由于队列没有count成员函数，
			if (!s.count(m)) {//但本题又想用到优先队列的性质，所以要借助另外一个容器。
				s.insert(t*co[j]);
				pq.push(m);
			}
		}
	}
}
