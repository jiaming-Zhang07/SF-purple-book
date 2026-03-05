#include <bits/stdc++.h>
using namespace std;
vector<int> window(vector<int> &A, int k) {
  int n = A.size();
  if (n == 0 || k == 0)
    return {};
  deque<int> dq;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && A[dq.back()] > A[i])
      dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k)
      dq.pop_front();
    if (i >= k - 1)
      ans.push_back(A[dq.front()]);
  }
  return ans;
}