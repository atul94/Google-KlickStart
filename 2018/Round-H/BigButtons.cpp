
#include <bits/stdc++.h>

using namespace std;

int compare(string a, string b){
    return a.size() < b.size();
}

bool isASubSet(string &a, string &b){
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}
long long powerOf2(int n){
	long long ans = 1;
	long long c = 2;
	for(int i = 0; i < n; i++){
		ans *= c;
	}
	return ans;
}
long long solutionToProblem(long long  n, vector<string> &a, int p){
	sort(a.begin(), a.end(), compare);
	long long ans = powerOf2(n);
	map<string,int> finalStrings;
	map<string,int> duplicateStrings;
	for(int i = 0; i < p-1; i++){
		for(int j = i+1; j < p; j++){
			if(a[i].size() != a[j].size() && isASubSet(a[i],a[j])){
				duplicateStrings[a[j]] = 1;
			}
		}
	}
	for(int i = 0; i < a.size(); i++){
		if(duplicateStrings.find(a[i]) == duplicateStrings.end()){
			finalStrings[a[i]] = 1;
		}
	}
	for(map<string,int> :: iterator it = finalStrings.begin(); it != finalStrings.end(); it++){
		long long temp = powerOf2(n - it->first.size());
		ans = ans - temp;
	}
	return ans;
}
int main(){
    int testcases;
    cin >> testcases;
    for(int testcase = 1; testcase < testcases; testcase++){
        long long n,p;
        cin >> n >> p;
        vector<string> f(p);
        for(int i = 0; i < p; i++){
            
            cin >> f[i];
        }
       
        cout << "Case #" << testcase << ": " <<  solutionToProblem(n,f,p) << endl;        
        
    }
    return 0;
}
