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
        int odd = 1, even = 2, i = 0;
        while(i<n){
            odd = (odd + (i*2)+ 1);
            even = (even+(i*2));
            i++;
        }
        cout<<odd<<" "<<even<<endl;
        return gcd(odd,even);
    }
};