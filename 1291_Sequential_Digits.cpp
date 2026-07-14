class Solution {
public:

    int n = 0, place = 1, zeroth = 0, first_no = 0, next = 0;

    void find_next(int x, int plac, int zero){
        while(x){
            zero = x%10;
            x = x/10;
            if(x){
                plac = plac * 10;
            }
        }
        place = plac;
        zeroth = zero;
    }

    void find_first(int plac, int first_n, int &nxt, int &zero){
        while(plac!=1){
            plac = plac/10;
            ++zero;
            first_n = (first_n * 10) + zero;
            nxt = (nxt * 10) + 1;
        }
        place = plac;
        first_no = first_n;
        next = nxt;
        zeroth = zero;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        place = 1, zeroth = 0;
        find_next(low,place,zeroth);
        first_no = zeroth, next=1;
        find_first(place, first_no, next, zeroth);
        while(first_no<high){
            ans.push_back(first_no);
            first_no += next;
            if(first_no%10 == 9){
                first_no+=next;
                place = 1;
                zeroth = 0;
                find_next(first_no, 1, 0);
                first_no = zeroth;
                next=1;
                find_first(place, first_no, next, zeroth);
            }
        }
        return ans;
    }
};