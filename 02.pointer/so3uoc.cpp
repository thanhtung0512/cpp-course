#include <iostream>
#include <math.h>
using namespace std;

int prime[10000001]; // N = 10^7

void sang(){
        //Bu?c 1 : Coi t?t c? các s? t? 0 t?i N là s? nguyên t?
	for(int i = 0; i <= 10000000; i++){
		prime[i] = 1;
	}
        //Bu?c 2 : Sàng
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= sqrt(10000000); i++){
		if(prime[i]){
			for(int j = i * i; j <= 10000000; j += i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	sang();
	long long N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		if ( ((long long) sqrt(x) * (long long) sqrt(x)) == x ) {
			if (prime[(int)sqrt(x)] == 1 )  {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {	
			cout << "NO" << endl;
		}
	}
	return 0;
}
