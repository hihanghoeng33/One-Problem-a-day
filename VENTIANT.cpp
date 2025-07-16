#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX / 2;
const int N_MAX = 39;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int allowed_moves[3][3];
        for (int i = 0; i < 3; ++i) {
            string row_str;
            cin >> row_str;
            for (int j = 0; j < 3; ++j) {
                allowed_moves[i][j] = row_str[j] - '0';
            }
        }

        int n;
        cin >> n;

        long long dp[N_MAX + 1][3][3];

        for (int k = 0; k <= n; ++k) {
            for (int src = 0; src < 3; ++src) {
                for (int dest = 0; dest < 3; ++dest) {
                    dp[k][src][dest] = INF;
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[0][i][j] = 0;
            }
        }

        for (int k = 1; k <= n; ++k) {
            for (int src_peg = 0; src_peg < 3; ++src_peg) {
                for (int dest_peg = 0; dest_peg < 3; ++dest_peg) {
                    if (src_peg == dest_peg) {
                        dp[k][src_peg][dest_peg] = 0;
                        continue;
                    }

                    int other_peg = 3 - src_peg - dest_peg;

                    if (allowed_moves[src_peg][dest_peg]) {
                        if (dp[k-1][src_peg][other_peg] != INF && dp[k-1][other_peg][dest_peg] != INF) {
                            long long current_cost = dp[k-1][src_peg][other_peg] + 1 + dp[k-1][other_peg][dest_peg];
                            dp[k][src_peg][dest_peg] = min(dp[k][src_peg][dest_peg], current_cost);
                        }
                    }

                    if (allowed_moves[src_peg][other_peg] && allowed_moves[other_peg][dest_peg]) {
                        if (dp[k-1][src_peg][dest_peg] != INF && dp[k-1][dest_peg][src_peg] != INF) {
                            long long current_cost = dp[k-1][src_peg][dest_peg] + 1 + dp[k-1][dest_peg][src_peg] + 1 + dp[k-1][src_peg][dest_peg];
                            dp[k][src_peg][dest_peg] = min(dp[k][src_peg][dest_peg], current_cost);
                        }
                    }
                }
            }
        }

        long long result = dp[n][0][2];

        if (result >= INF) {
            cout << "Epic Fail...\n";
        } else {
            cout << result << "\n";
        }
    }

    return 0;
}
