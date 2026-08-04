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

        int l = aliceWins(piles, i+1, j, aliceTurn?a+=piles[i]:a, aliceTurn?b:b+=piles[i], aliceTurn=!aliceTurn, dp);
        int r = aliceWins(piles, i, j-1, aliceTurn?a+=piles[j]:a, aliceTurn?b:b+=piles[j], aliceTurn=!aliceTurn, dp);
        return l-r<0?dp[i][j]=r:dp[i][j]=l;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return aliceWins(nums, 0, n-1, 0, 0, true, dp)>=0?true:false;
    }
};