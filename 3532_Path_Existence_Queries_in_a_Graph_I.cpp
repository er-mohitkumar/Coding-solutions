class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                mp[nums[i-1]] = nums[i];
            }
        }

        vector<bool> ans(queries.size(), true);

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            while(a<=queries[i][1]){
                if(mp.find(nums[a])==mp.end()){
                    ans[i] = false;
                }
                a++;
            }
        }
        return ans;
    }
};