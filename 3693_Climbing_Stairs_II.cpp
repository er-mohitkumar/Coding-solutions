class Solution {
public:
    int minCost(int n, int i, vector<int>& costs, vector<int>& dp){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=INT_MAX){
            return dp[i];
        }
        int ans = INT_MAX, j=i+1;
        ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+1,costs,dp));
        j=i+1;
        if(i+1<n){
            ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+2,costs,dp));
        }
        j=i+2;
        if(i+2<n){
            ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+3,costs,dp));
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        return minCost(n,0, costs, dp);
    }
};