class Solution {
public:
    int find(int c){
        int can = (int)sqrt(c + c);
        can --;
        while((can * (can + 1)) < (2 * c)){
            can ++;
        }
        return can;
    }
    vector<int> distributeCandies(int c, int n) {
        int count = find(c);
        int last_index = (count + n - 1) % n;
        int last_remain = c - (count - 1) * count / 2;
        int round = (count - 1) / n;
        vector<int> ret; ret.resize(n);
        for(int i = 0; i < n; i ++){
            if(i < last_index){
                ret[i] = (i + 1) * (round + 1) + n * ((round    ) * (round + 1) / 2);
            }
            else {
                ret[i] = (i + 1) * (round    ) + n * ((round - 1) * (round + 0) / 2);
                if(i == last_index){
                    ret[i] += last_remain;
                }
            }
        }
        return ret;
    }
};