int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n+1, 0), curr(n+1, 0);

	for(int N = 0; N <= n; N++){
		prev[N] = N * price[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int N=0; N <= n; N++){
			int notTake = prev[N];
			int take = INT_MIN;
			int rodlength = ind+1;
			if(rodlength <= N){
				take = price[ind] + curr[N - rodlength];
			}
			curr[N] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[n];
}
