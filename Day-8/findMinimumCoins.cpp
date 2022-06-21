vector<int> val = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int findMinimumCoins(int amount) 
{
    // Write your code here
   int coins =0; 
   for(int i=8;i>=0;i--){
       if(val[i] <= amount){
           coins += amount/val[i];
           amount = amount%val[i];
       }
       if(amount == 0) break;
   }   
  return coins;   
}
