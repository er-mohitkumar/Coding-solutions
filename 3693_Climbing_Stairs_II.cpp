class Solution {
public:
    int minCost(int n, int i, int j, vector<int>& costs, vector<int>& dp){
        if(j>=n-1){
            return 0;
        }
        if(dp[i]!=INT_MAX){
            return dp[i];
        }
        int ans = INT_MAX;
        ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+1,j+1,costs,dp));
        if(j+1<=n){
            i+=1;
            j+=1;
            ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+1,j+1,costs,dp));
        }
        if(j+2<=n){
            i+=1;
            j+=1;
            ans = min(ans, costs[j]+((j-i)*(j-i)) + minCost(n,i+1,j+1,costs,dp));
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        return minCost(n,0,1, costs, dp);
    }
};