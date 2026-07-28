class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;
        sort(s.begin(), s.end());
        string ans = "";
        int j=s.size()-1;
        if(s.size()%2==0){
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
        while(j<s.size()){
            ans+=s[j];
            j+=2;
        }

        string Ans = ans;
        reverse(ans.begin(),ans.end());
        ans = Ans + ans;
        return ans;
    }
};