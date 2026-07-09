class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        mp[0] = 0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                cout<<abs(nums[i]-nums[i-1])<<" ";
                mp[i-1] = i;
            }
        }
        cout<<endl;
        vector<bool> ans(queries.size(), true);

        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            while(a<=queries[i][1]){
                if(mp.find(a)==mp.end()){
                    cout<<a<<" ";
                    ans[i] = false;
                }
                a++;
            }
        }
        return ans;
    }
};