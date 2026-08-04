class Solution {
public:

    int aliceWins(vector<int>&piles, int i, int j, vector<vector<int>>&dp){
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        int temp = piles[i];
        int first = temp - aliceWins(piles, i+1, j, dp);
        temp += piles[i+1];
        int second = temp - aliceWins(piles, i+1, j, dp);
        if(i+2<=j){
            temp+=piles[i+2];
            int third = temp - aliceWins(piles, i+1, j, dp);
            return dp[i][j] = max(max(first, second), third);
        }
        return dp[i][j] = max(first, second);
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n<=3) return "Alice";
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