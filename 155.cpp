#include <iostream>
#include <vector>
#include <string>


using namespace std;

class MinStack {
public:
    vector<int> normal_st;
    vector<int> mini_st;
    MinStack() {}
    
    void push(int val) {
        
        if(normal_st.empty()){
             mini_st.push_back(val);
        }else if(val <= mini_st.back()){
            mini_st.push_back(val);
        }
        normal_st.push_back(val);
    }
    
    void pop() {
        if(normal_st.empty())
            return;
        if(normal_st.back() == mini_st.back() ){
             mini_st.pop_back();
        }
        normal_st.pop_back();
    }
    
    int top() {
        return normal_st.back();
    }
    
    int getMin() {
        return mini_st.back();
    }
};

int main()
{
    MinStack mst;
    mst.push(2147483646);
    mst.push(2147483646);
    mst.push(2147483647);
    cout << mst.top() << endl;
    mst.pop();
    cout << mst.getMin() << endl;
    mst.pop();
    cout << mst.getMin() << endl;
    mst.pop();
    mst.push(2147483647);
    cout << mst.top() << endl;
    cout << mst.getMin() << endl;
    mst.push(-2147483646);
    cout << mst.top() << endl;
    cout << mst.getMin() << endl;
    mst.pop();
    cout << mst.getMin() << endl;
/*   mst.push(1);
    cout << mst.getMin() << endl;
    mst.pop();
    cout << mst.getMin() << endl;*/
}

