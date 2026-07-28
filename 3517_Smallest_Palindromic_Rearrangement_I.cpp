class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        sort(s.begin(),s.end());
        int i=0,od=0;
        char center;
        string ans = "";
        if(n%2!=0){
            od = 1;
        }
        while(i<n){
            if(s[i]!=s[i+1] && od == 1){
                center = s[i];
                od = 0;
                i++;
                continue;
            } else if(s[i]!=s[i+1]) {
                break;
            }
            ans += s[i];
            i += 2;
        }
        string Ans = ans;
        if(n%2!=0) Ans = Ans + center;
        reverse(ans.begin(),ans.end());
        ans = Ans + ans;
        return ans;
    }
};