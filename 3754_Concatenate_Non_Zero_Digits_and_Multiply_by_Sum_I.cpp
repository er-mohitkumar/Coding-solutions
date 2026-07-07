class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sumX = 0, newX=0;
        while(n){
            if(n%10 != 0){
                x = (x*10) + (n%10);
                sumX = sumX+(n%10);
            }
            n = n/10;
        }
        while(x){
            newX = (newX*10) + (x%10);
            x = x/10;
        }
        return newX*sumX;
    }
};