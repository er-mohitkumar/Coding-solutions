class Solution {
public:

    int gcd(int a, int b)
    {
        if(a==0 || b==0) return max(a, b);
        
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result;
    }

    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0, i = 1;
        while(i<=n){
            even += (i*2);
            odd += (i*2) + 1;
            i++;
        }
        return gcd(odd,even);
    }
};