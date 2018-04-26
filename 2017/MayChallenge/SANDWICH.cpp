#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n,k,m,ans=0;

// Partition generation code from GeeksForGeeks

void printArray(ll p[], ll d)
{
    ll x = ceil(float (n)/ k);
    ll ans = fact(n);
	if(d == x){
        ll siz = p[0];
        for(int i=0; i<d; i++){
            if(p[i] > k){
                return;
            }
        }
        ll temp=1;
        for(int i=0; i<d; i++){
            if(p[i]==p[i-1]){
                temp++;
            }
            else{
                ans = ans
            }
            cout<<p[i]<<" ";
        }
        cout<<"\n";
        ans+=x;
	}
}

ll fact(ll x){
    ll res=1;
    for(ll k=1; k<=x; k++){
        res = (res * k)%m;
    }
    return res;
}


void printAllUniqueParts()
{
	ll p[n]; // An array to store a partition
	ll k = 0; // Index of last element in a partition
	p[k] = n; // Initialize first partition as number itself

	// This loop first prints current partition, then generates next
	// partition. The loop stops when the current partition has all 1s
	while (true)
	{
		// print current partition
		printArray(p, k+1);
		// Generate next partition
		// Find the rightmost non-one value in p[]. Also, update the
		// rem_val so that we know how much value can be accommodated
		int rem_val = 0;
		while (k >= 0 && p[k] == 1)
		{
			rem_val += p[k];
			k--;
		}
		// if k < 0, all the values are 1 so there are no more partitions
		if (k < 0) return;
		// Decrease the p[k] found above and adjust the rem_val
		p[k]--;
		rem_val++;
		// If rem_val is more, then the sorted order is violeted. Divide
		// rem_val in differnt values of size p[k] and copy these values at
		// different positions after p[k]
		while (rem_val > p[k])
		{
			p[k+1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}
		// Copy rem_val to next position and increment position
		p[k+1] = rem_val;
		k++;
	}
}





ll solve(){
    ll original=0;
    ll numS = ceil(n/k);

}


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>m;
        ans=0;
        ll minSandwiches = (ll)((ceil(((float)n)/(float)k)))%m;
        printAllUniqueParts();
        cout<<minSandwiches<<"  Ans- "<<ans<<"--\n";
    }
	return 0;
}
