#include <bits/stdc++.h>
using namespace std;
int a[3005], temp[3005];
long long ans = 0;
void merge_sort(int l, int r) {
  if (l >= r)
    return;
  int mid = l + (r - l) / 2;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);
  int p = l, q = mid + 1, k = l;
  while (p <= mid && q <= r) {
    if (a[p] >= a[q])
      temp[k++] = a[p++];
    else {
      ans += mid - p + 1;
      temp[k++] = a[q++];
    }
  }
  while (p <= mid)
    temp[k++] = a[p++];
  while (q <= r)
    temp[k++] = a[q++];
  for (int i = l; i <= r; i++)
    a[i] = temp[i];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  merge_sort(0, n - 1);
  cout << ans;
  return 0;
}