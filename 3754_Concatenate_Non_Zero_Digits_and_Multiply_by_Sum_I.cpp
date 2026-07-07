class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sumX = 0, newX = 0, place = 1;
        while(n){
            if(n%10 != 0){
                x = ((n%10) * place) + x;
                sumX = sumX+(n%10);
                place*=10;
            }
            n = n/10;
        }
        return newX*sumX;
    }
};