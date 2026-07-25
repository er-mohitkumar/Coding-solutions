class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0, x = n;
        while(x--){
            if(x==n){
                a = x%10;
            } else {
                if(a<x%10){
                    b = a;
                    a = x%10;
                }
            }
            x = x/10;
            
        }
        return a*b;
    }
};