#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int ans[15][405];
int dp[405][1024];

// 判断一个二进制数的后 len 位是否为回文串
bool is_palin(int mask, int len) {
    for (int i = 0; i < len / 2; ++i) {
        int left_bit = (mask >> (len - 1 - i)) & 1;
        int right_bit = (mask >> i) & 1;
        if (left_bit != right_bit) return false;
    }
    return true;
}

// 离线预处理所有 (K, N) 的答案
void init() {
    for (int k = 1; k <= 10; ++k) {
        for (int i = 1; i <= 400; ++i) {
            if (i < k) {
                // 长度小于 K，不可能包含长度 >= K 的回文串
                ans[k][i] = (1 << i) % MOD;
            } else if (i == k) {
                // 长度等于 K，初始化 DP 边界
                for (int s = 0; s < (1 << k); ++s) {
                    if (!is_palin(s, k)) {
                        dp[k][s] = 1;
                        ans[k][i] = (ans[k][i] + 1) % MOD;
                    } else {
                        dp[k][s] = 0;
                    }
                }
            } else {
                // 长度大于 K，状态转移
                for (int s = 0; s < (1 << k); ++s) {
                    dp[i][s] = 0; // 滚动清空当前层的状态
                }
                
                for (int s = 0; s < (1 << k); ++s) {
                    if (!dp[i - 1][s]) continue;
                    
                    for (int c = 0; c <= 1; ++c) {
                        int mask = (s << 1) | c;
                        
                        // 检查新生成的 K+1 长度后缀是否回文
                        if (is_palin(mask, k + 1)) continue;
                        
                        // 截取后 K 位，检查新生成的 K 长度后缀是否回文
                        int next_s = mask & ((1 << k) - 1);
                        if (is_palin(next_s, k)) continue;
                        
                        // 转移累加
                        dp[i][next_s] = (dp[i][next_s] + dp[i - 1][s]) % MOD;
                    }
                }
                
                // 统计当前长度 i 的总合法方案数
                for (int s = 0; s < (1 << k); ++s) {
                    ans[k][i] = (ans[k][i] + dp[i][s]) % MOD;
                }
            }
        }
    }
}

int main() {
    // 竞赛标配 I/O 优化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init(); // 赛前打表
    
    int t;
    if (cin >> t) {
        while (t--) {
            int n, k;
            cin >> n >> k;
            cout << ans[k][n] << "\n";
        }
    }
    return 0;
}