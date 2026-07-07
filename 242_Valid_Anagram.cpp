class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
        for(char i:t){
            if(mp.find(i)!=mp.end()){
                mp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
            }
        }
        return mp.size()==0?true:false;
    }
};