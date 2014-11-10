class MinStack {
private:
    deque<int> st;
    deque<int> mi;
public:
    void push(int x) {
        st.push_back(x);
        if (mi.empty() || x <= mi.back()) mi.push_back(x);
    }

    void pop() {
        if (st.empty()) return;
        if (st.back() == mi.back()) mi.pop_back();
        st.pop_back();
    }

    int top() {
        if (st.empty()) return -1;
        return st.back();
    }

    int getMin() {
        if (mi.empty()) return -1;
        return mi.back();
    }
};