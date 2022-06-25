int findCelebrity(int n) {
 	// Write your code here.
    int l = 0, r = n-1;
    while(l!=r){
        if(knows(l,r)) l++;
        else r--;
    }
    
    for(int i=0;i<n;i++){
        if(i==l) continue;
        else if(knows(l,i)) return -1;
        else if(!knows(i,l)) return -1;
    } 
    return l;
}