#include <bits/stdc++.h>
using namespace std;
#define sz 1000005
#define ll long long
#define mod 1000000007


struct node{
	int val;
	bool isQuery;
	int ansIndex,indexL,indexH;
	// ansIndex = index of element in original array when unsorted
	// if a query the ansIndex = index of the query
    bool operator < (const node &n2) const{
        if(val == n2.val){
            if(isQuery==true){
                return false;
            }
            return true;
        }
        return val < n2.val;
	}
};

//struct query_node{
//    int primeL,primeH,indexL,indexH,ansIndex;
//};

struct answer_node{
    int aboveLowerPrime=-1,aboveUpperPrime=-1;
};

struct original_node{
    int val;
    int startIndex,endIndex;
};
// variables declarations
original_node numbers[sz];
answer_node ans[sz];
int f_tree[sz],N;

bool prime[sz];
int nextPrime[sz];
int SPF[sz];

vector<node> combined;

// function declarations
void updateTree(int index){
    // update in the tree that there is one more element now at index
    while(index < N){
        f_tree[index]+=1;
        index = index + (index & (-index));
    }
}

int readTree(int index){
    // return count of elements from range 1 to index
    // so the count from range l to r will be read(r)- read(l-1)
    int s=0;
    while(index>0){
        s+=f_tree[index];
        index = index - (index & (-index));
        //cout<<index<<"\n";
    }
    return s;
}


void precompute(){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	prime[2]=true;
	for(int i=2; i<sz; i++){
		if(prime[i]==true){
            SPF[i]=i;
			for(int k=2*i; k<sz;k+=i){
                if(prime[k]==true){
                    prime[k]=false;
                    SPF[k]=i;
                }
			}
		}
	}
	int lastPrime = -1;
	for(int i=sz-1; i>=1; i--){
		nextPrime[i] = lastPrime;
		if(prime[i]==true){
			lastPrime = i;
		}
	}
}

void factorize(int num){
//        ll pF = 2;
//		while(pF * pF <= num){
//			while(num%pF==0){
//				num/=pF;
//				node x;
//				x.val = pF;
//				x.ansIndex = combined.size();
//				x.isQuery = false;
//				combined.push_back(x);
//			}
//			pF = nextPrime[pF];
//		}
//		if(num!=1){
//            node x;
//            x.val = num;
//            x.ansIndex = combined.size();
//            x.isQuery = false;
//            combined.push_back(x);
//		}
    while(num!=1){
        node x;
		x.val = SPF[num];
		x.ansIndex = combined.size();
		x.isQuery = false;
		combined.push_back(x);
		num = num/x.val;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	memset(f_tree,0,sizeof(f_tree));
	node dummy;
	dummy.val = -1;
	combined.push_back(dummy); // just to occupy the zeroth index
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>numbers[i].val;
        numbers[i].startIndex = combined.size();
        factorize(numbers[i].val);
        numbers[i].endIndex = combined.size()-1;
        //cout<<numbers[i].startIndex<<" " <<numbers[i].endIndex<<"\n";
    }
    int q;
    N = combined.size()+10;
    cin>>q;
    for(int i=0; i<q; i++){
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        node leftQuery, rightQuery;
        leftQuery.val = x-1;
        leftQuery.indexL = numbers[l].startIndex;
        leftQuery.indexH = numbers[r].endIndex;
        leftQuery.ansIndex = i;
        leftQuery.isQuery = true;

        rightQuery.val = y;
        rightQuery.indexL = numbers[l].startIndex;
        rightQuery.indexH = numbers[r].endIndex;
        rightQuery.ansIndex = i;
        rightQuery.isQuery = true;

        combined.push_back(leftQuery);
        combined.push_back(rightQuery);
    }

    sort(combined.begin()+1,combined.end());

    for(int k=combined.size()-1; k>=1; k--){
        node x = combined[k];
        if(x.isQuery){
            //cout<<" "<<readTree(x.indexL-1)<<" "<<readTree(x.indexH)<<"\n";
            int an = (readTree(x.indexH) - readTree((x.indexL)-1));
            //cout<<"Query for "<<x.val <<" Query Number " <<x.ansIndex << " Query Result "<<an<< "\n";
            //cout<<"Query from "<<x.indexL<<" "<<x.indexH<<"\n";
            if(ans[x.ansIndex].aboveUpperPrime !=-1){
                ans[x.ansIndex].aboveLowerPrime = an;
            }
            else{
                ans[x.ansIndex].aboveUpperPrime = an;
            }
        }
        else{
            updateTree(x.ansIndex);
            //cout<<"Number "<<x.val<<"\n";
        }
    }

    for(int i=0; i<q; i++){
        cout<<(ans[i].aboveLowerPrime -  ans[i].aboveUpperPrime) <<"\n";
    }
	return 0;
}
