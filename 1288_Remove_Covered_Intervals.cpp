class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(), ans=1, first = intervals[0][0], second = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=first && intervals[i][1]<=second){
                continue;
            } else{
                if(intervals[i][0]==first && intervals[i][1]>=second){
                    first = intervals[i][0];
                    second = intervals[i][1];
                    continue;
                }
                first = intervals[i][0];
                second = intervals[i][1];      
                ans++;
            }
        }
        return ans;
    }
};