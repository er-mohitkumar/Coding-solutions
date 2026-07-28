class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        string ans = "";
        int start = 0, st = 0, end = s.size()-1, ed = s.size()-1;
        while(start<=end){
            if(s[start]==s[end]){
                break;
            } else if(s[start]<s[end]){
                start++;
            } else{
                end--;
            }
        }
        while(start<=end){
            ans += s[start];
            start++;
        }
        return ans;
    }
};