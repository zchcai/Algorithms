class Solution {
public:
    /* dp[i]: i length answer
     * dp[i] = max(dp[i - j] + j * max(A[i - 1],..., A[i - j])) for j = 1 to K, i - j >= 0
     * */
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp; dp.resize(n + 1, 0);
        dp[0] = 0; dp[1] = A[0];
        for(int i = 2; i < n + 1; i ++){
            int top = 0;
            for(int j = 1; (i - j > -1) && (j < K + 1); j ++){
                top = max(top, A[i - j]);
                dp[i] = max(dp[i], dp[i - j] + top * j);
            }
        }
        return dp[n];
    }
};