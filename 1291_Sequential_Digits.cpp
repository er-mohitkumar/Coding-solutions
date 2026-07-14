class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n = low, place = 1, zeroth = 0;
        while(n){
            zeroth = n%10;
            n = n/10;
            if(n){
                place = place * 10;
            }
        }
        cout<<zeroth<<endl;
        cout<<place<<endl;
        int first_no = zeroth, next=1;
        while(place){
            place = place%10;
            ++zeroth;
            first_no = (first_no * 10) + zeroth;
            next = (next * 10) + 1;
        }
        cout<<first_no<<" "<<next<<endl;
        return {0};
    }
};