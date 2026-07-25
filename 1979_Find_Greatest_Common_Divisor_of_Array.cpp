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
        for(int i=2;i<=b;i++){
            if(a%i==0 && b%i==0){
                return i;
            }
        }
        return 1;
    }
};