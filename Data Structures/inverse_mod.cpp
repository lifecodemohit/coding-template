/*
author : lifecodemohit
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (ll i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
    
    ll denominator = 1; // k!
    for (ll i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
    
    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

ll calculate(ll n, ll r) {
    return (ll)( modBinomial(n,r, MOD) );
}
int main() 
{
    cout<<calculate(6,3)<<endl;
    return 0;  
}