#include <bits/stdc++.h>
using namespace std;
vector<int> window(vector<int> &A, int k) {
  int n = A.size();
  multiset<int> s;
  vector<int> ans;
  for (int i = 0; i < k; i++)
    s.insert(A[i]);
  ans.push_back(*s.begin());
  for (int i = k; i < n; i++) {
    s.insert(A[i]);
    s.erase(s.find(A[i - k]));
    ans.push_back(*s.begin());
  }
  return ans;
}