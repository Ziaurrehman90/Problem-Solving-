 int countTriplets(vector<int>& arr) {
		unordered_map<int,vector<int>>m;
		int x=0,ans=0;
		m[0].push_back(-1);
		for(int i=0;i<arr.size();i++){
			x^=arr[i];
			if(m.find(x)!=m.end()){
				for(auto a:m[x]){
					ans+=(i-a)-1;
				}
			}
			m[x].push_back(i);
		}
		return ans;
	}