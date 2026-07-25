class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MIN, b = INT_MAX;
        for(int i:nums){
            if(a<i){
                a = i;
            }
            if(i<b){
                b = i;
            }
        }
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
};