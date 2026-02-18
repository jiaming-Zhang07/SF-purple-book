//难点：位运算的知识点，dfs的构建
#include<bits/stdc++.h>
using namespace std;
double r;
const int maxn = 6;
double sum[1 << maxn];
struct Tree {
	double lef, righ;
};
vector<Tree>tree[1 << maxn];
void dfs(int subset) {
	if(tree[subset].size())return;
	bool have_child = false;
	for (int lef = subset & (subset - 1); lef; lef = (lef - 1)&subset) {
		have_child=true;
		int righ = subset^lef;
		dfs(lef);
		dfs(righ);
		for (int i = 0; i < (int)tree[lef].size(); i++)
			for (int j = 0; j < (int)tree[righ].size(); j++) {
				Tree t;
				double d1 = sum[righ] / sum[subset],d2=sum[lef]/sum[subset];
				t.lef = max(tree[lef][i].lef + d1, tree[righ][j].lef - d2);
				t.righ=max(tree[righ][j].righ+d2,tree[lef][i].righ-d1);
				if(t.lef+t.righ<r)tree[subset].push_back(t);
			}
		
	}if(!have_child)tree[subset].push_back(Tree{});
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		double w[maxn];
		scanf("%lf%d", &r, &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", &w[i]);
		for (int i = 0; i < 1 << n; i++) {
			tree[i].clear();
			sum[i] = 0;
			for (int j = 0; j < n; j++)
				if (i & 1 << j)
					sum[i] += w[j];
		}
		int root = (1 << n)-1;
		dfs(root);
		double ans=-1;
		for(int i=0;i<(int)tree[root].size();i++)
			ans=max(ans,tree[root][i].lef+tree[root][i].righ);
		printf("%.16f\n",ans);
	}
}
