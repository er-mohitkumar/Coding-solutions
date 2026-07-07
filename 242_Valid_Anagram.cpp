class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        unordered_map<char,int>xp;
        for(char i:t){
            mp[i]++;
        }
        for(char i:s){
            xp[i]++;
        }
        for(char i:s){
            if(mp.find(i)!=mp.end()){
                mp[i]--;
                xp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
                if(xp[i]==0){
                    xp.erase(i);
                }
            }
        }
        return mp.size()==0 && xp.size()==0?true:false;
    }
};