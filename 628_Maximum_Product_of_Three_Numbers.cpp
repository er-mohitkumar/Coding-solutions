class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>a){
                c = b;
                b = a;
                a = nums[i];
            } else if(nums[i]>b && nums[i]<=a){
                c=b;
                b=nums[i];
            } else if(nums[i]>c && nums[i]<=a && nums[i]<=b){
                c = nums[i];
            }
        }
        return a*b*c;
    }
};