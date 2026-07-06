class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(), ans=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=intervals[i-1][0] && intervals[i][1]<=intervals[i-1][1]){
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                continue;
            } else{
                if(intervals[i][0]==intervals[i-1][0] && intervals[i][1]>=intervals[i-1][1]){
                   cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                    continue;
                }
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;              
                ans++;
            }
        }
        return ans;
    }
};