class MinStack {
public:
    MinStack() {
        
    }
    
    vector<pair<int,int>>st;
    void push(int val) {
        if(st.size()==0)st.push_back({val,val});
        else {
            int prev=st.back().second;
            st.push_back({val,min(val,prev)});
        
        }
    }
    
    void pop() {st.pop_back();}
    
    int top() {
        return st.back().first;
        
    }
    
    int getMin() {
        return st.back().second;
        
    }
};

