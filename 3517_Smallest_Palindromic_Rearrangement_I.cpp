class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;

        sort(s.begin(), s.end());
        string ans = "";

        int n=s.size(), j=n-1;
        if(n%2==0){
            if(s[j]!=s[j-1]){
                return ans+=s[j];
            } else {
                j -= 2;
            }
        } else {
            j--;
        }

        while(j>0){
            if(s[j]!=s[j-1]){
                break;
            } 
            j -= 2;
        }

        if(j<0) j=0;
        while(j<n-1){
            ans+=s[j];
            j+=2;
        }
        
        string Ans = ans;
        if(n%2!=0){
            Ans += s[n-1];
        }
        reverse(ans.begin(),ans.end());
        ans = Ans + ans;
        return ans;
    }
};