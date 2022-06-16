//https://www.codingninjas.com/codestudio/problems/795104
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<int> st;
    for(char ch : expression){
           if( ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if(ch == ')' and (st.empty() or st.top() != '('))
                return false;
            else if(ch == ']' and (st.empty() or st.top() != '['))
                return false;
            else if(ch == '}' and (st.empty() or st.top() != '{'))
                return false;
            else
                st.pop(); 
    }
    return st.empty();
    
}