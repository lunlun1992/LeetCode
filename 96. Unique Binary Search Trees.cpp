class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {      //当节点总数量为i的时候
            for (int j = 1; j <= i; j++) {  //以j为根节点的时候
                dp[i] += dp[j - 1] * dp[i - j]; //左边子树的节点数量*右边节点的节点数量
            }
        }
        return dp[n];
    }
};