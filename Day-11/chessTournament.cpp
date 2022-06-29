bool isPossible(vector<int> a, int n, int c, int minDist) {
      int cntC = 1;
      int lastPlacedC = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedC >= minDist) {
          cntC++;
          lastPlacedC = a[i];
        }
      }
      if (cntC >= c) return true;
      return false;
    }

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());

      int low = 1, high = positions[n - 1] - positions[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(positions, n, c, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    return high;
}