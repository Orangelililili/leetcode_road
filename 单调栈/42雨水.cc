class Solution {
    public:
        int trap(vector<int>& height) {
            // 主要有暴力遍历就是一列列去求，
            // 公式就是宽*高，要是一列列求，宽就是1，高=min（lHIGHEST，rHIGESRT）-selfHIGH
    
            // 还有就是像接下来一样，一行行去求
            if (height.size() <= 2)
                return 0; // 就俩柱子，肯定接不了水
    
            stack<int> st; // 栈中存放下标，计算柱子的高度
            st.push(0);    // 放进去里面，后面有的比
    
            int sum = 0; // 计算结果
            for(int i = 1; i < height.size(); i++){
                if(height[i]<height[st.top()]){
                    st.push(i);
                }else if(height[i]==height[st.top()]){
                    st.push(i);
                }else{//找到变大的了
                    while(!st.empty()&& height[i]>height[st.top()]){
                        int mid =st.top();
                        st.pop();
    
                        if(!st.empty()){
                            int h=min(height[st.top()],height[i])-height[mid];
                            int w=i-st.top()-1;
                            sum+=h*w;
                        }
    
                        
                    }
                    st.push(i);
                }
            }
    
            return sum;
        }
    };