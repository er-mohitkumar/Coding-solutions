class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        while(k--){
            vector<int>lastCol;
            for(int i=0;i<r;i++){
                lastCol.push_back(grid[i][c-1]);
            }

            for(int i=0;i<r;i++){
                for(int j=c-1;j>0;j--){
                    grid[i][j]=grid[i][j-1];
                }
            }
            grid[0][0] = lastCol[lastCol.size()-1];
            for(int i=1;i<r;i++){
                for(int j=0;j<1;j++){
                    grid[i][j] = lastCol[i-1];
                }
            }
        }
        return grid;
    }
};