class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(expression[i] < '0')
            {
                vector<int> v1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> v2 = diffWaysToCompute(expression.substr(i + 1));

                for(auto i1 : v1){
                    for(auto i2 : v2){
                        switch (expression[i]){
                            case '+':
                                res.push_back(i1+i2);
                                break;
                            
                            case '-':
                                res.push_back(i1-i2);
                                break;
                            
                            case '*':
                                res.push_back(i1*i2);
                        }
                    }
                }
            }
        }
        if (res.empty()){
            res.push_back(stoi(expression));
        }

        return res;
    }
};