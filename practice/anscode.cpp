#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Course {
  string name;
  int s, d, c;
};
int main() {
  // 关流同步，应对 2e5 的巨大 IO 量
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  if (!(cin >> m >> n))
    return 0;
  // 课程下标从 1 到 n
  vector<Course> courses(n + 1);
  // exam_day[i] 记录第 i 天是哪门课的考试（存储课程 ID，0 表示无考试）
  vector<int> exam_day(m + 1, 0);
  // release[i] 记录在第 i 天公布的所有课程 ID
  vector<vector<int>> release(m + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> courses[i].name >> courses[i].s >> courses[i].d >> courses[i].c;
    exam_day[courses[i].d] = i;
    release[courses[i].s].push_back(i);
  }
  // 优先队列（小根堆）：存储 pair<考试日 d_i, 课程 ID>
  // 这样默认就会按照 d_i 从小到大排序（死线最近的优先）
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  // ans 数组预设为全 REST，方便直接覆盖
  vector<string> ans(m + 1, "REST");
  bool die = false;
  // 扫描线：时间 t 从 1 流逝到 m
  for (int t = 1; t <= m; ++t) {
    // 1. 将今天刚刚公布的课程加入候选池
    for (int id : release[t]) {
      pq.push({courses[id].d, id});
    }
    // 2. 优先级最高：检查今天是不是某个科目的考试日
    if (exam_day[t] != 0) {
      int id = exam_day[t];
      // 考试到了，但没复习完，直接寄
      if (courses[id].c > 0) {
        die = true;
        break;
      }
      ans[t] = "EXAM";
    }
    // 3. 今天没有考试，可以复习或者休息
    else {
      if (!pq.empty()) {
        int id = pq.top().second;
        pq.pop();
        ans[t] = courses[id].name;
        courses[id].c--; // 复习了一天
        // 如果还需要复习，重新塞回堆里
        if (courses[id].c > 0) {
          pq.push({courses[id].d, id});
        }
      }
    }
  }
  if (die) {
    cout << "DIE\n";
  } else {
    for (int t = 1; t <= m; ++t) {
      cout << ans[t] << "\n";
    }
  }
  return 0;
}