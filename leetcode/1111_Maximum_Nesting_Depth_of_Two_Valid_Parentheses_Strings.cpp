class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ret; ret.resize(seq.length());
        int left = 0;
        for(int i = 0; i < seq.length(); i ++){
            char c = seq[i];
            if(c == '('){
                left ++;
                ret[i] = left;
            }
            else if (c == ')'){
                ret[i] = left;
                left --;
            }
        }
        for(int i = 0; i < ret.size(); i ++){
            ret[i] = ret[i] % 2;
        }
        return ret;
    }
};