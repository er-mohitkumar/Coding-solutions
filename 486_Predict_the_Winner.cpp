class Solution {
public:
    int aliceWins(vector<int>&piles, int i, int j, vector<vector<int>>&dp){
        if(i == j)
            return piles[i];

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int takeLeft = piles[i] - aliceWins(piles, i+1, j, dp);
        int takeRight = piles[j] - aliceWins(piles, i, j-1, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return aliceWins(nums, 0, n-1, dp)>=0?true:false;
    }
};