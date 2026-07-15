class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int n = low, place = 1, zeroth = 0;
        while(n){
            zeroth = n%10;
            n = n/10;
            if(n==0){
                continue;
            }
            place = place * 10;
        }
        int first_no = zeroth, next=1, digits = place;
        while(place!=1){
            place = place/10;
            ++zeroth;
            first_no = (first_no * 10) + zeroth;
            next = (next * 10) + 1;
        }
        while(first_no<high){
            if (first_no >= low)
            ans.push_back(first_no);
            first_no += next;
            if(first_no%10 ==9){
                if(first_no >= low && first_no <= high)
                    ans.push_back(first_no);
                first_no = 1;
                digits *= 10;
                cout<<digits<<endl;
                if(digits == 100000000){
                    break;
                }
                place = digits;
                next = 1;
                zeroth = 1;
                while(place!=1){
                    place = place/10;
                    ++zeroth;
                    first_no = (first_no * 10) + zeroth;
                    // cout<<first_no<<endl;
                    next = (next * 10) + 1;
                }
            }
        }
        return ans;
    }
};