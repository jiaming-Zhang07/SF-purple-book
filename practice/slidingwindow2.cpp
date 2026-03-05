#include <bits/stdc++.h>
using namespace std;
int q[100005];
vector<int> window(vector<int> &A, int k) {
  int n = A.size();
  if (n == 0 || k == 0)
    return {};
  vector<int> ans;
  int head = 1, tail = 0;
  for (int i = 0; i < n; i++) {
    while (head <= tail && A[q[tail]] >= A[i])
      tail--;
    q[++tail] = i;
    if (q[head] <= i - k)
      head++;
    if (q[tail] >= k - 1)
      ans.push_back(A[q[head]]);
  }
  return ans;
}