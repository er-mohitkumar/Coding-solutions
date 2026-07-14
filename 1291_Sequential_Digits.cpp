class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int n = low, place = 1, zeroth = 0;
        while(n){
            zeroth = n%10;
            n = n/10;
            if(n){
                place = place * 10;
            }
        }
        int first_no = zeroth, next=1;
        while(place!=1){
            place = place/10;
            ++zeroth;
            first_no = (first_no * 10) + zeroth;
            next = (next * 10) + 1;
        }
        while(first_no<high){
            ans.push_back(first_no);
            first_no += next;
        }
        return ans;
    }
};