class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(), ans=1;
        for(int i=1;i<n;i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(intervals[i][0]>=intervals[i-1][0] && intervals[i][1]<=intervals[i-1][1]){
                continue;
            } else{
                if(intervals[i][0]==intervals[i-1][0] && intervals[i][1]>=intervals[i-1][1]){
                    continue;
                }
                
                ans++;
            }
        }
        return ans;
    }
};