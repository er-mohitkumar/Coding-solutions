class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        int n = arr.size(), right = 0, left = 0, maxStringLength = 0;
        unordered_map<char,int> characters;
        for(int right=0; right<n; right++) {
            if(characters.find(arr[right])!=characters.end()){
                while(true){
                    char leaving = arr[left];
                    left++;
                    characters[leaving]--;
                    if(characters[leaving]==0) characters.erase(leaving);
                    if(leaving ==arr[right]){
                        break;
                    }
                }
            } 
            characters[arr[right]]++;
            maxStringLength = max(maxStringLength, right-left+1);
        }
        return maxStringLength;
    }
};