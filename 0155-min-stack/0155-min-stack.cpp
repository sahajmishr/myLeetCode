class MinStack {
public:
stack<int> s1,s2 ;
int min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
      if(value <= min){
        s1.push(value);
        s2.push(value);
        min = value ;
      }  
      else s1.push(value);
    }
    
    void pop() {
      if(s1.top()==s2.top()){
        s1.pop();
        s2.pop();
        min = s2.empty() ? INT_MAX : s2.top();
      }  
      else s1.pop();
    }
    
    int top() {
      return s1.top(); 
    }
    
    int getMin() {
     return  s2.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */