/*
    AUTHOR:         BHUVNESH JAIN
    INSTITUITION:   BITS PILANI, PILANI
    [ ( [ ( [ ( [ ( ) ] ( ) [ ] ) ] ) ] ) ]
    20
    3 1 3 1 3 1 3 1 2 4 1 2 3 4 2 4 2 4 2 4
*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar
#define LL              long long
#define MAX             1000005
#define MOD             1000000007
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)
#define CREP2(i,n)      for(__typeof(n) i=n-1; i>=1; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define sz(a)           int((a).size())
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define reset(c)        (c).clear()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())

const double EPS = 1e-10;

template <typename T>
void inPos(T &x)
{
    register T c = inchar();
    while(((c<48) || (c>57)) && (c!='-')) c = inchar();
    x = 0;
    for(;c<48 || c>57; c = inchar());
    for(;c>47 && c<58; c = inchar())    x=(x<<3)+(x<<1)+(c-48);
}

template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return (!b)? a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}

int main()
{
    int n, x, ans1, ans2, ans3, count1, count3, t1, t2, t3, t4;
    inPos(n);
    ans1 = 0;
    ans2 = 0;
    ans3 = 0;
    count1 = 0;
    count3 = 0;
    t1 = 0;
    t2 = 0;
    t3 = 1;
    bool c1, c2;
    c1 = false;
    c2 = false;
    REP(i, n)
    {
        inPos(x);
        if (count1==0 && count3==0)
        {
            if (x==3)
                t4 = 1;
            else
                t4 = 3;
        }
        if (x==1)
        {
            count1++;
            c1 = true;
            if (count1>0 && count3>0 && t4==x)
            {
                t3++;
                t4 = 3;
            }
        }
        else if (x==3)
        {
            count3++;
            c2 = true;
            if (count1>0 && count3>0 && t4==x)
            {
                t3++;
                t4 = 1;
            }
        }
        else if (x==2)
            count1--;
        else if (x==4)
            count3--;

        // printf("%d %d-->", count1, count3);
        if (count1>0)
            t1++;
        else if (count1==0)
        {
            ans2 = max(ans2, t1);
            t1 = 0;
        }
        if (count3>0)
            t2++;
        else if (count3==0)
        {
            ans3 = max(ans3, t2);
            t2 = 0;
        }
        if (count1==0 && count3==0)
,�Rr���@61ٲ��/���0:�AR�����=�����GSE6�6����&���1�0d� ������wwmS:�F�W~�丈������:q��4�U#��3����_�(J ��d�7�@$CTX�CߢP��>��@�X�c	etZF�R��G<ʘ�ϐ�	a�c1c��x�`3�T�>dX�����y��O���h'��]���`[�.��wa(�s]�X�8�1�]urfdv������	�p(c�	n���X(`N�Ȕ,� ΢����Ɩ�� d������dG+_���HG'g�