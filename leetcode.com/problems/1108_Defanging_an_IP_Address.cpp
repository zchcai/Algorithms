class Solution {
public:
    string defangIPaddr(string address) {
        string ret;
        for(int i = 0; i < address.length(); i ++){
            char c = address[i];
            if(c == '.'){
                ret += "[.]";
            }
            else ret.push_back(c);
        }
        return ret;
    }
};