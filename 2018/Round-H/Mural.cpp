#include <bits/stdc++.h>
/**
@Description: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ee2/000000000005118a
*/
using namespace std;
long long solutionToProblem(string s, int n){
	int window = (n+1)/2;
	long long ans = 0;
	for(int i = 0; i < window; i++){
		ans += (s[i] - '0');
	}
	long long tempAns = ans;
	for(int i = window; i < n; i++){
		tempAns = tempAns + (s[i] - s[i-window]);
		ans = max(ans, tempAns);  
	}
	return ans;
}

int main(){
    int testcases;
    cin >> testcases;
    for(int testcase = 1; testcase <= testcases; testcase++){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << testcase << ": " <<  solutionToProblem(s,n) << endl;        
        
    }
    return 0;
}
