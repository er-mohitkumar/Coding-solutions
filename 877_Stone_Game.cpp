class Solution {
public:
    bool aliceWins(vector<int>&piles, int i, int j, int a, int b, bool aliceTurn, vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            if(dp[i][j]==1){
                return true;
            } else {
                return false;
            }
        }
        if(i==j-1){
            if(piles[i]>=piles[j]){
                if(aliceTurn){
                    a+=piles[i];
                } else {
                    b+=piles[j];
                }
            } else{
                if(aliceTurn){
                    a+=piles[j];
                } else {
                    b+=piles[i];
                }
            }
            return a>b?dp[i][j]=1:dp[i][j]=0;
        }
        aliceTurn = !aliceTurn;
        dp[i+1][j] = aliceWins(piles, i, j-1, a += piles[i], b, aliceTurn, dp);
        dp[i][j-1] = aliceWins(piles, i+1, j, a, b += piles[j], aliceTurn, dp);
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return aliceWins(piles, 0, n-1, 0, 0, true, dp);
    }
};