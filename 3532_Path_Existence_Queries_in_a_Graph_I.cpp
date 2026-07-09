class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                mp[i-1] = i;
            }
        }
        vector<bool> ans(queries.size(), true);

        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==queries[i][1]){
                ans[i]=true;
                continue;
            }
            int a = queries[i][0];
            while(a<queries[i][1]){
                if(mp.find(a)!=mp.end()){
                    if(mp[a]>queries[i][1]){
                        ans[i]=false;
                        break;
                    }
                } else {
                    ans[i]=false;
                    break;
                }
                a++;
            }
        }
        return ans;
    }
};