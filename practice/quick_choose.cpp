#include <bits/stdc++.h>
using namespace std;
int a[100];
int quick_choose(int l, int r, int k) {
  if (l == r)
    return a[l];
  int x = a[(l + r) >> 1];
  int i = l - 1;
  int j = r + 1;
  while (i < j) {
    do
      i++;
    while (a[i] < x);
    do
      j--;
    while (a[j] > x);
    if (i < j)
      swap(a[i], a[j]);
  }
  if (k > j - l + 1)
    return quick_choose(j + 1, r, k - (j - l + 1));
  else
    return quick_choose(l, j, k);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int k;
  cin >> k;
  cout << quick_choose(0, n - 1, k);
  return 0;
}