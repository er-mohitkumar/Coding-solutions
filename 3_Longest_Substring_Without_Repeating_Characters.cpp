class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        int n = arr.size(), right = 0, left = 0, maxStringLength = INT_MIN, stringLength = 0;
        unordered_map<char,int> characters;
        while(right<n){
            if(characters.find(arr[right])!=characters.end()){
                stringLength = characters.size();
                maxStringLength = max(maxStringLength, stringLength);
                do {
                    characters[arr[left]]--;
                    if(characters[arr[left]]==0) characters.erase(arr[left]);
                    left++;
                } while(arr[left]!=arr[right] && left<right);
            } 
            characters[arr[right]]++;
            right++;
        }
        stringLength = characters.size();
        maxStringLength = max(maxStringLength, stringLength);

        return maxStringLength;
    }
};