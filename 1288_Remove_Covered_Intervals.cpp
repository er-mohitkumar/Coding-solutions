class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(), ans=1;
        for(int i=0;i<n-1;i++){
            if(intervals[i+1][0]>=intervals[i][0] && intervals[i+1][1]<=intervals[i][1]){
                continue;
            } else{
                if(intervals[i+1][0]==intervals[i][0] && intervals[i+1][1]>=intervals[i][1]){
                    continue;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};