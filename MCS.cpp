#include <iostream>
#include <vector>
#include <climits>

int matrixChainOrder(const std::vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    
    // dp[i][j] will store the minimum multiplications needed to compute the matrix M[i]...M[j]
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    // L is chain length.
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    // Matrix dimensions: 
    // A: 10x30, B: 30x5, C: 5x60

    std::vector<int> p = {10, 30, 5, 60};
    
    std::cout << "Minimum number of multiplications is " 
              << matrixChainOrder(p) << std::endl;

    return 0;
}
