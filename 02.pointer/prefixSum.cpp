#include <iostream>
using namespace std;

int main() {
	string s;
	
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			s[i] = '1';
		}
	}
	
	int prefixSum[s.length()];
	
	fill(prefixSum,prefixSum + s.length(), 0);
	
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			prefixSum[i] = (s[i] - '0');
		} else {
			prefixSum[i] = prefixSum[i-1] + (s[i] - '0');
		}
	}
	
	for (int d = 0; d <= 80; d++) {
		for (int i  = 0; i < s.length(); i++) {
			int tong1 = prefixSum[i];
			int tong2 = prefixSum[s.length()-1] - tong1;
			
			int doLech = abs(tong1 - tong2);
			if (doLech == d) {
				int result = max(tong1, tong2);
				cout << result;
				return 0;
			}
		}
	}
	
} 
