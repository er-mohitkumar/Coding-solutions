class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int minNum = INT_MAX, maxNum = INT_MIN, n = nums.size();
        for(int i=0;i<n;i++){
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i=minNum; i<=maxNum; i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};