class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n = low, place = 1, zeroth = 0;
        while(n){
            place = place * 10;
            zeroth = n%10;
            n = n/10;
        }

        cout<<zeroth<<endl;
        cout<<place<<endl;
        return {0};
    }
};