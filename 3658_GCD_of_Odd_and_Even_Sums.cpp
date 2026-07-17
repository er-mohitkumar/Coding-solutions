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
        int odd = 1, even = 2;
        while(n--){
            odd = (odd+2);
            even = (even+2);
        }
        cout<<odd<<" "<<even<<endl;
        return gcd(odd,even);
    }
};