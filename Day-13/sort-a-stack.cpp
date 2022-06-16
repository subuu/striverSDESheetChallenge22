//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275
void sortInsert(stack<int> &stack , int n){
   // basecase
   if(stack.empty() || (!stack.empty() && stack.top() < n)){
      stack.push(n);
      return ;}

   int num = stack.top();
   stack.pop();
   // recursive call
   sortInsert(stack , n);
   stack.push(num);
}

void sortStack(stack<int> &stack)
{
    // Write your code here
   if(stack.empty()) return ;
   int num = stack.top();
   stack.pop();
   sortStack(stack);
   sortInsert(stack , num);   
}