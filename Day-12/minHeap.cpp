void addnum(int num, vector<int> &heap){
    heap.push_back(num);
    int i = heap.size()-2;
    while(i >= 0){
        if(heap[i] < heap[i+1]) break;
        else{
            swap(heap[i],heap[i+1]); i--;
        }
    }
}

int deletenum(vector<int> &heap){
    int temp = heap[0];
    heap.erase(heap.begin());
    return temp;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i].size() == 1){ 
           int val = deletenum(heap);
           ans.push_back(val);}
        else
           addnum(q[i][1],heap); 
    }
    return ans;
}
