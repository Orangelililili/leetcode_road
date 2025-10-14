class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            // 初始化栈
            stack<int> st;
            // 初始化结果集合,
            // 大小就是输入集合大小，由于存在右边没有比当前温度更大的可能性，所以直接赋值为0
            vector<int> result(temperatures.size(), 0);
    
            // 温度是30到100，为了将数组中元素和栈中元素比较，所以要初始化栈中元素，
            // 这里初始化为0,即温度数组的第一个元素
            st.push(0);
    
            // 开始遍历
            for (int i = 1; i < temperatures.size(); i++) {
                // case1
                if (temperatures[i] < temperatures[st.top()]) {
                    // 满足条件:温度数组第i个温度比之前放到栈里面的温度要小，不符合条件
                    // 入栈
                    st.push(i); // 存放的是数组
                }
    
                // case2
                else if (temperatures[i] == temperatures[st.top()]) {
                    // 满足条件，和上述小于的情况一样
                    st.push(i);
                }
                // 上述这两种情况就会使得栈从栈口到栈底里面下表对应的温度元素是递增的
    
                // case3
                // 满足条件的栈中元素可能不止一个
                else {
                    while (!st.empty() && temperatures[i] > temperatures[st.top()])     
                    {
                        // 满足条件：找到了温度数组中第i个元素比之前的存放到栈里面的元素温度要大
                        // 他们这两个元素之间下标差距就是result结果
                        result[st.top()] = i - st.top();
    
                        // 清除掉栈中这个位置的元素下表
                        st.pop();
                    }
                     //接着找当前位置这个元素的下一个最大值
                    st.push(i);
                }
    
            }
    
            return result;
        }
    };