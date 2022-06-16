//https://www.codingninjas.com/codestudio/problems/2099908
vector<int> nums; 
public:
    Queue() {
        // Implement the default Constructor 
    }
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return nums.size()==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        nums.push_back(data);     
    }

    int dequeue() {
        // Implement the dequeue() function
        int val;
        if(isEmpty()) return -1;
        else{
           val = nums[0];
           nums.erase(nums.begin()); 
          return val; 
        }         
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return nums[0];
    }
};