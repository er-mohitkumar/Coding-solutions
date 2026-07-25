class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0, x = n;
        while(x--){
            cout<<x%10<<endl;
            if(x==n){
                a = x%10;
            } else {
                if(a<x%10){
                    b = a;
                    a = x%10;
                } else if(b<x%10){
                    b = x%10;
                }
            }
            x = x/10;
            cout<<a<<" "<<b<<endl;
        }
        return a*b;
    }
};