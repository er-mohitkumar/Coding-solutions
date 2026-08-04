class Solution {
public:
    int aliceWins(vector<int>&piles, int i, int j, int a, int b, bool aliceTurn, vector<vector<int>>&dp){
        if(i==j){
            if(aliceTurn){
                a+=piles[i];
            } else {
                b+=piles[i];
            }
            return dp[i][j]=a-b;
        }

        if(dp[i][j]!=0){
            return dp[i][j];
        }

        if(aliceTurn){
            if(piles[i]>=piles[j]){
                a+=piles[i];
            } else {
                a+=piles[j];
            }
        } else {
            if(piles[i]>=piles[j]){
                b+=piles[i];
            } else {
                b+=piles[j];
            }
        }

        aliceTurn = !aliceTurn;
        int l = aliceWins(piles, i+1, j, a, b, aliceTurn, dp);
        int r = aliceWins(piles, i, j-1, a, b, aliceTurn, dp);
        return dp[i][j]=l-r;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return aliceWins(nums, 0, n-1, 0, 0, true, dp)>=0?true:false;
    }
};