class Solution {
public:
    int get_level(int label){
        int level = 0;
        while(label){
            label = label / 2;
            level ++;
        }
        return level;
    }
    int get_tag_or_label(int level, int label){
        if(level % 2) return label;
        return (1 << (level - 1)) + (1 << level) - 1 - label;
    }
    vector<int> pathInZigZagTree(int label) {
        int level = get_level(label);
        vector<int> ans; ans.resize(level);
        
        int tag = get_tag_or_label(level, label);
        ans[level - 1] = tag;
        for(int i = level - 1; i >= 1; i --){
            int tmp = ans[i];
            ans[i - 1] = tmp / 2;
            ans[i] = get_tag_or_label(i + 1, tmp);
        }
        ans[0] = 1;
        return ans;
    }
};