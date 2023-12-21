class Solution {
public:
    
    int calc(int a,int b,string op){
        if(op=="+"){
            return a+b;
        }
        if(op=="-"){
            return a-b;
        }
        if(op=="*"){
            return a*b;
        }
        if(op=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans;
        for(string c : tokens){
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                int temp=calc(stoi(b),stoi(a),c);
                st.push(to_string(temp));
            }else{
                st.push(c);
            }
        }
        ans=stoi(st.top());
        return ans; 
    }
};