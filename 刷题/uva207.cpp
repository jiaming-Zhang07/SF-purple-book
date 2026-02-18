#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>
#include<sstream>
using namespace std;
struct cptor {
	int score[5] = {0}, ran = 0, isam = 0, isch1 = 0, isch2 = 0, total = 0, total2 = 0, hav = 0;
	double money;
	string name;
} ;
bool cmp2(cptor a, cptor b) {
	if (b.isch2 && !a.isch2)return true;
	 if (a.isch2 && !b.isch2)return false;
	if (a.isch2 && b.isch2)for (int i = 0; i < 4; i++) {
			if (a.score[i] != 0 && b.score[i] == 0)return true;
			if (a.score[i] == 0 && b.score[i] != 0)return false;
		}  if (a.isch2 && b.isch2) {
		int aa = 0, bb = 0;
		for (int i = 0; a.score[i] != 0; i++) {
			aa += a.score[i];
			bb += b.score[i];
		}
		if (aa == bb);
		else return aa < bb;
	}  if (!a.isch2 && !b.isch2) {
		if (a.total != b.total)
			return a.total < b.total;
	}
	return a.name < b.name;
}
bool cmp1(cptor a, cptor b) {
	if (b.isch1 && !a.isch1)return true;
	if (a.isch1 && !b.isch1)return false;
	if (b.total2 != a.total2)return a.total2 < b.total2;
	return a.name < b.name;
}

int main() {
	freopen("z.txt", "r", stdin);
	freopen("zjm.txt", "w", stdout);
	int T;
	int kase = 0;
	scanf("%d", &T);
	while (T--) {
		if (kase++)printf("\n");
		printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
		printf("-----------------------------------------------------------------------\n");
		map<int, int>r;
		cptor c[150];
		double sum, dist[80];
		scanf( "%lf", &sum);
		for (int i = 0; i < 70; i++)scanf("%lf", &dist[i]);
		int tor;
		scanf("%d", &tor);
		char ch;
		while (( ch = getchar()) != '\n' && ch != '\r');
		for (int i = 0; i < tor; i++) {
			string s;
			getline(cin, s);
			c[i].name = s.substr(0, 20);
			stringstream ss(s.substr(20));
			for (int k = 0; k < 20; k++)if (c[i].name[k] == '*')c[i].isam = 1;
			int j = 0;
			while (ss >> c[i].score[j++]);
			if (j == 5 ){for (int k = 0; k < 4; k++)c[i].total += c[i].score[k];for (int k = 0; k < 2; k++)c[i].total2 += c[i].score[k];}
			else if (c[i].score[1] != 0) {
				for (int k = 0; k < 2; k++)c[i].total2 += c[i].score[k];
				c[i].isch2 = 1;
			} else c[i].isch1 = 1;

		}
		sort(c, c + tor, cmp1);

		int v;
		c[0].ran = 1;int cnt1=1;
		for ( v = 1; v < tor; v++) {
			if (c[v].isch1)break;
			if (c[v].total2 != c[v - 1].total2){c[v].ran = c[v - 1].ran + cnt1;cnt1=1;}
			else {c[v].ran = c[v - 1].ran;cnt1++;}
			if (c[v].ran >= 71)break;
		}
		sort(c, c + v, cmp2);
		c[0].ran = 1;
		if (!c[0].isam) {
			c[0].hav = 1;
			c[0].money = sum * dist[0] * 0.01;
		}
		int i, cn = 1, flag = 1;
		for ( i = 1; i < v; i++) {
			if (c[i].isch2)break;
			
			if (c[i].total != c[i - 1].total) {if(flag>1)cn+=flag-1;
				c[i].ran = c[i - 1].ran + flag;
				flag = 1;
				if (cn < 71 && !c[i].isam) {
					c[i].hav = 1;
					r[c[i].ran] = 0;
					cn++;
				}

			} else {
				flag++;
				c[i].ran = c[i - 1].ran;
				if (!c[i].isam && cn < 71) {
					c[i].hav = 1;
					if (r.count(c[i].ran))
						r[c[i].ran]++;
					else 	r[c[i].ran] = 0;
					
				}
			}
		}
	
		int flag1 = 0;
			int cnt = 1;
		if(c[0].isam)cnt=0;
		for (int j = 1; j < i; j++) {
			
			if (flag1 == 1&&c[j].ran!=c[j-1].ran) {int h;
				for(h=j;c[h].ran==c[j].ran;h--);
				cnt += (r[c[h].ran] + 1);
				flag1 = 0;
			}if (cnt >= 70)break;
			if (c[j].isam)continue;
			
			if (r[c[j].ran] > 0) {
				flag1 = 1;
				double su = 0;
				for (int k = 0; k < r[c[j].ran] + 1; k++) {
					su += dist[cnt + k];
				}
				c[j].money = sum * su * 0.01 / (r[c[j].ran] + 1);

			} else {
				
				c[j].money = sum*dist[cnt] * 0.01;
				cnt++;
			}
		}
		for (int j = 0; j < v; j++) {
			printf("%-21s", c[j].name.c_str());
			if (c[j].isch2)printf("          ");
			else if (r[c[j].ran] > 0&&!c[j].isam) {
				string s = to_string(c[j].ran ) + "T";
				printf("%-10s",s.c_str());
			} else printf("%-10d", c[j].ran);
			int k;
			for ( k = 0; k < 4 && c[j].score[k] != 0; k++)printf("%-5d", c[j].score[k]);
			if (k != 4)for (int m = 0; m < 4 - k; m++)printf("%-5s", "");
			if (c[j].isch2)printf( "DQ\n");
			else if(c[j].hav)printf("%-10d", c[j].total);
			else printf("%d\n",c[j].total);
			if (c[j].hav)printf("$%9.2f\n", c[j].money+1e-8);
			
		}

	}
}

