class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if(abs(nums[0])>abs(nums[1]) && abs(nums[0])> abs(nums[2])){
            a = nums[0];
            if(abs(nums[1])>abs(nums[2])){
                b = nums[1];
                c = nums[2];
            } else {
                b = nums[2];
                c = nums[1];
            }
        } else if(abs(nums[1])>abs(nums[0]) && abs(nums[1])>abs(nums[2])){
            a = nums[1];
            if(abs(nums[0])>abs(nums[2])){
                b = nums[0];
                c = nums[2];
            } else {
                b = nums[2];
                c = nums[0];
            }
        } else {
            a = nums[2];
            if(abs(nums[0])>abs(nums[1])){
                b = nums[0];
                c = nums[1];
            } else {
                b = nums[1];
                c = nums[0];
            }
        }
        for(int i=3;i<nums.size();i++){
            if(abs(nums[i])>abs(a)){
                c = b;
                b = a;
                a = nums[i];
            } else if(abs(nums[i])>abs(b)){
                c=b;
                b=nums[i];
            } else if(abs(nums[i])>abs(c)){
                c = nums[i];
            }
        }
        return a*b*c;
    }
};