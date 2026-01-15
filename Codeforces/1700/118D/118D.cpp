#include <iostream>

using namespace std;

// dp[num_of_1][num_of_2][num_of_last_1][num_of_last_2]
int dp[101][101][11][11];

const int MOD = 100000000;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    dp[0][0][0][0] = 1;

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int h = 0; h <= k1; h++) {
                for (int z = 0; z <= k2; z++) {
                    if (dp[i][j][h][z] == 0) continue;
                    // insert 1
                    if (i + 1 <= n1 && h + 1 <= k1) {
                        dp[i + 1][j][h + 1][0] = (dp[i + 1][j][h + 1][0] + dp[i][j][h][z]) % MOD;
                    }
                    // insert 2
                    if (j + 1 <= n2 && z + 1 <= k2) {
                        dp[i][j + 1][0][z + 1] = (dp[i][j + 1][0][z + 1] + dp[i][j][h][z]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int h = 0; h <= k1; ++h) {
        for (int z = 0; z <= k2; ++z) {
            ans = (ans + dp[n1][n2][h][z]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}