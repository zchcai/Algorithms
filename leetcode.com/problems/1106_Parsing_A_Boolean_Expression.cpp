class Solution {
public:
    bool parseBoolExpr(string e) {
        bool ret;
        if((e[0] == '|') || (e[0] == '&') || (e[0] == '!')){
            string s = e.substr(2, e.length() - 3);
            if(e[0] == '!') ret = !parseBoolExpr(s);
            else ret = work_recur(s, e[0]);
        }
        else{
            if(e[0] == 't') ret = true;
            else if(e[0] == 'f') ret = false;
        }
        return ret;
    }
    
    bool work_recur(string s, char op){
        int left = 0;
        string w = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ',') {
                w += s[i];
                if(s[i] == '('){
                    left ++;
                }
                if(s[i] == ')'){
                    left --;
                }
            }
            else{
                if(left == 0){
                    if(parseBoolExpr(w)){
                        if(op == '|') return true;
                    }
                    else {
                        if(op == '&') return false;
                    }
                    w = "";
                }
                else{
                    w += s[i];
                }
            } 
        }
        if(parseBoolExpr(w)){
            if(op == '|') return true;
        }
        else {
            if(op == '&') return false;
        }
        return (op == '&');
    }
};