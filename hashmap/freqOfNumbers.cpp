#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}

	unordered_map<int,int>m;
	for(int i =0 ;i<n;i++){
		if(m.end()!= m.find(arr[i])){
			m[arr[i]] += 1;
		}else{
			m[arr[i]] = 1;
		}
	}
	int val,freq = INT_MIN;

	for(auto num : m){
		if(freq < num.second){
			val = num.first;
			freq = num.second;
		}
	}

	cout << val;

	return 0;

}
