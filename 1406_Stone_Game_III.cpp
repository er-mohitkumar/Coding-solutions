class Solution {
public:

    int aliceWins(vector<int>&piles, int i, int j, vector<vector<int>>&dp){
        if (i > j)
            return 0;

        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        int first = INT_MIN;
        int temp = piles[i];
        first = max(first, temp - aliceWins(piles, i+1, j, dp));
        if(i+1<=j){
            temp += piles[i+1];
            first = max(first, temp - aliceWins(piles, i+2, j, dp));
        }
        if(i+2<=j){
            temp+=piles[i+2];
            first = max(first, temp - aliceWins(piles, i+3, j, dp));
        }
        return dp[i][j] = first;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int ans = aliceWins(stoneValue, 0, n-1, dp);
        if(ans>0){
            return "Alice";
        } else if(ans<0){
            return "Bob";
        } 
        return "Tie";
    }
};