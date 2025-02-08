class Solution {
public:
    int largestRectangleArea(vector<int>& histo) 
    {
        stack <int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};



// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) 
//     {
//         int area;
// 		int maxArea = 0;
// 		int i = 0;
// 		stack<int> s;
// 		while(i < heights.size())
//         {
// 			if(s.empty() or heights[s.top()] <= heights[i])
//             {
// 				s.push(i);
// 				i++;
// 			}
// 			else
//             {
// 				int temp = s.top();
// 				s.pop();
// 				if(s.empty())
//                 {
// 					area = heights[temp] * i;
// 				}
// 				else
//                 {
// 					area = heights[temp] * (i - s.top() - 1);
// 				}
// 				if(area > maxArea)
//                 {
// 					maxArea = area;
// 				}
// 			}
// 		}
// 		while(!s.empty())
//         {
// 			int temp = s.top();
// 			s.pop();
// 			if(s.empty())
//             {
// 				area = heights[temp] * i;
// 			}
// 			else
//             {
// 				area = heights[temp] * (i - s.top() - 1);
// 			}
// 			if(area > maxArea)
//             {
// 				maxArea = area;
// 			}
// 		}
// 		return maxArea;
//     }
// };