
Problems Titles :
1.Turbo Sort
2.Maximum Length even Subarray
3.Racing Horses
4.Puppy and Sum 
5.Farmer And His Plot
6.Balls and Boxes
7.Fill The Grid
8.The Begining Era Of Cyberverse
9.Alternate Additions
10.Tom And Jerry 
11.Distinct Pair sum
12.Turn It
13.Andrew and the Meatballs
14.Chef and easy problem
15.Facebook
16.Passing Marks
17.400M Race
18.ChefWatson uses Social Network
19.WA Test Cases
20.Simple Statistics
21.Existence
22.Cutting Recipes
23.Chef and Interview
24.Little elephant and divisors
25.Number of Factors
26.Little Elephant and Divisors
27.Chef and String
28.Evacuate to Moon
29.Maximize Disjoint Pair sum
30.Maximum Weight difference
31.Watson asks Does permutation Exist
32.Snakes, Mongooses and the Ultimate Election
33.K-flip
34.Zonal Computing Olympaid 2015 ,29 Nov 2014
35.Coins and Triangle
36. The Wave
37.Shoekand and Number
38.Minion Chef and Banana
39.Snake Eating
40.Forest Gathering
41.Squirrel and chestnut
42.Minimize the Maximum
43.Circular intervals
44.Flu Shot Lineup
45.Binary Substitution
46.Magic Rankings
47.Count Palindromes
48.Barcelona Gamplay Tactics
49.Alternating subarray prefix
50.Count Subarrays
51.Event Organizer
52.SUPW Zonal Computing Olympiad 2014, 30 Nov 2013
53.IPL Zonal Computing Olympiad 2014, 30 Nov 2013
54.Maximal crosses


54.Maximal crosses
----------------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {

		int k;
	cin>>k;
	while(k--) {
	    ll n;
	    cin>>n;
	    double t;
	    cin>>t;
	    double dist[n];
	    double ans=0.0;
	    
	    for(int i=0;i<n;i++) {
	        cin>>dist[i];
	    }
	    
	    double l=0.0,r=n*t;
	    
	    while(l<=r) {
	        double mid= (l+r)/2;
	        double lastele=max(0.0,dist[0]-mid);
	        double curr=0.0;
	        bool found=1;
	        for(int i=1;i<n;i++) {
	            curr=max(lastele+t,dist[i]-mid);
	            lastele=curr;
	            if(curr>dist[i]+mid) {
	                found=0;
	                break;
	            }
	        }
	        if(found) {
	            ans=mid;
	            r=mid-0.00001;
	        }
	        else l=mid+0.00001;
	    }
	    cout<<fixed<<setprecision(4)<<ans<<endl;
	}
	return 0;
}
53.IPL Zonal Computing Olympiad 2014, 30 Nov 2013
-------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <cfloat>
#include <ctime> 
#include <climits>
using namespace std; 
 
typedef long long int64; 
typedef unsigned long long uint64;
 
template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, const T& y) { if (!(y < x)) return false; x = y; return true; }
template<typename T> bool remax(T& x, const T& y) { if (!(x < y)) return false; x = y; return true; }
 
#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n) - 1); i >= 0; --i)

int m;
vector<int> T, P;

int64 solve(int64 time, int n) {
	static vector<int64> am;
	am.resize(m);
	REP(i, m) {
		if (time < T[i]) am[i] = 0;
		else am[i] = (time-T[i]+P[i])/P[i];
	}
	sort(am.begin(), am.end());
	int64 res = 0;
	REPD(i, m) {
		if (n == 0) break;
		res += am[i];
		--n;
	}
	return res;
}

int main() {
#ifdef REM_HOME
	freopen("input.txt", "r", stdin);
#endif
 
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;
		scanf("%d%d%d", &m, &n, &k);
		T.resize(m);
		REP(i, m) scanf("%d", &T[i]);
		P.resize(m);
		REP(i, m) scanf("%d", &P[i]);
		int64 L = 0, R = 1;
		while (solve(R, n) < k) {
			L = R;
			R *= 2;
		}
		while (R-L > 1) {
			int64 M = (L+R)/2;
			if (solve(M, n) >= k) R = M;
			else L = M;
		}

		printf("%lld\n", R);
	}
}

52.SUPW Zonal Computing Olympiad 2014, 30 Nov 2013
--------------------------------------------------
#include<iostream>
#include<algorithm>
#include<climits>
#include<inttypes.h>
using namespace std;
typedef long long int ll;

uint64_t w,sum,l,ratio,min1=UINT64_MAX;
int n;
uint64_t *arr,*arr1;
int calc(uint64_t j){
	sum = 0;
	for (int k = 0; k < n; k++)
		{
				if((arr[k]+j*arr1[k])>=l){
					sum+=arr[k]+j*arr1[k];
					if(sum>=w){
						return 1;
					}
				}

		}
		return 0;
}

int main(int argc, char const *argv[])
{
	
	cin>>n>>w>>l;
	arr= new uint64_t [n];
	arr1= new uint64_t [n];
	for (int i = 0; i <n; i++)
	{
		cin>>arr[i]>>arr1[i];

	}
	uint64_t lower=0,upper=1000000000000000000,mid,flag2,flag=calc(lower);
	while(lower<upper){
		mid=lower+(upper-lower)/2;
		flag2=calc(mid);
		if(flag2==1){
			upper=mid;
		}
		else if(flag2==0){
			lower=mid+1;

		}
	}
	if(calc(lower)){
		cout<<lower<<"\n";
		return 0;
	}
}


51.Event Organizer
--------------------
import bisect as bs

T = int(input())
while T:
    T -= 1
    N, Q = map(int, input().split())
    L = list(map(int, input().split()))
    L.sort()
    sum=[0] * N
    for j in range(1, N):
        sum[j] = sum[j - 1] + L[j]
    for i in range(Q):
        K = int(input())
        pos = bs.bisect_left(L, K)
        l = 0 
        r = pos
        while l < r:
            m = (l + r) // 2
            need = K * (pos -m ) - (sum[pos - 1] - sum[m - 1])
            if(need <= m):
                r = m
            else:
                l = m + 1
        print(N - r)


50.Count Subarrays
------------------
import java.io.*;
import java.util.*;

public class Main {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		long m=in.nextLong();
		int n=in.nextInt();
		long[] l = new long[n], r = new long[n];
		for(int i=0; i<n; ++i) {
			l[i]=in.nextLong();
			r[i]=in.nextLong();
		}
		long lb=1, rb=m/n;
		while(lb<=rb) {
			long mb=(lb+rb)/2;
			long a=0;
			for(int i=0; i<n; ++i)
				a=Math.max(l[i]-i*mb, a);
			boolean ok=true;
			long lp=n*mb+a;
			for(int i=n-1; i>=0&&ok; --i) {
				lp=Math.min(r[i], lp-mb);
				ok=l[i]<=lp;
			}

			ok&=lp+m-((n-1)*mb+a)>=mb;
			if(ok)
				lb=mb+1;
			else
				rb=mb-1;
		}
		out.println(rb);
		out.close();
	}
	
	static class StdIn {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public StdIn(InputStream in) {
			try{
				din = new DataInputStream(in);
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}
		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
		}
		public int nextInt() {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public int[] readIntArray(int n, int os) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt()+os;
			return ar;
		}
		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long[] readLongArray(int n, long os) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong()+os;
			return ar;
		}
		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() {
			try{
				if (bufferPointer == bytesRead)
					fillBuffer();
				return buffer[bufferPointer++];
			} catch(IOException e) {
				throw new RuntimeException();
			}
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}


49.Alternating subarray prefix
----------------------------------
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;
 
#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
int mod = 1000000007;
const int inf = 1034567891;
const ll LL_INF = 1234567890123456789ll;
#define PI 3.14159265
#define endl '\n'
#define F first
#define S second
#define debug(x) cout << #x << " = " << x << endl;
#define TRACE
 
#ifdef TRACE
#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define out(container) for (auto it : container) cout << it << " "; cout << endl;
 
 
template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
  int x = 1 % mod;
  while(b){
    if(b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    
    long long sum = 0;
    int v;
    vector<int> vec;
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> v;
        vec.push_back(v);
        sum += v;
        ans = max(ans, (sum + i) / (i + 1));
    }
    
    cout << ans << endl;
  }

  return 0;
}


48.Barcelona Gamplay Tactics
----------------------------
#include <stdio.h>
#include <math.h>

int can_finish_bananas(int piles[], int N, int K, int H) {
    int hours = 0;
    for (int i = 0; i < N; i++) {
        hours += ceil((double)piles[i] / K);
    }
    return hours <= H;
}

int find_min_eating_speed(int piles[], int N, int H) {
    int left = 1, right = piles[0];
    for (int i = 1; i < N; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }

    while (left < right) {
        int mid = (left + right) / 2;
        if (can_finish_bananas(piles, N, mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, H;
        scanf("%d %d", &N, &H);

        int piles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &piles[i]);
        }

        int min_speed = find_min_eating_speed(piles, N, H);
        printf("%d\n", min_speed);
    }

    return 0;
}


47.Count Palindromes
---------------------
#include <iostream>
#include<bits/stdc++.h>
#define d long long int
#define g 1000000001
using namespace std;

int main() {

 d t;
	cin>>t;
	while(t--){
	    d n,ans,x=g;
	    cin>>n;
	 d  a[31];
	for(int i=0;i<31;i++){
	        a[i]=pow(2,i);}
	        for(int i=0;i<31;i++){
	           for(int j=i+1;j<31;j++){
	               ans=a[i]+a[j];
	               x=min(x,abs(ans-n));
	           }
	               
	    }
	   cout<<x<<endl;   
	}
	return 0;
}

46.Magic Rankings
-------------------
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
int f(vector<int>& a,int d){
    int l=0;
    int h=a.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l +(h-l)/2;
        if(d-a[mid]==0){
          ans=a.size()+1;
          break;
        }
        if(d-a[mid]<0){
            h=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

signed main() {
    int n,q;
    cin>>n>>q;
	vector<int>a;
	for(int i=0;i<n;i++){
	    int d;
	    cin>>d;
	    a.push_back(d);
	}
	sort(a.begin(),a.end());
	   for(int i=0;i<q;i++){
	       int d;
	       cin>>d;
	       
	      
	       int ans= f(a,d);
	       if(ans==a.size()+1){
	           cout<<0<<endl;
	           continue;
	       }
	       if(ans!=-1){
	           int count=n-ans;
	           if(count%2==0)cout<<"POSITIVE\n";
	           else  cout<<"NEGATIVE\n";
	       }else{
	           cout<<"POSITIVE\n";
	       }
	       
	   }
	return 0;
}


45.Binary Substitution
-------------------------
#include <stdio.h>
int findMaxHeight(int n) {
    int height = 0;
    int coinsUsed = 0;

    while (coinsUsed <= n) {
        height++;
        coinsUsed += height;
    }

    return height - 1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int maxHeight = findMaxHeight(N);

        printf("%d\n", maxHeight);
    }

    return 0;
}


44.Flu shot Lineup
-------------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	// your code goes here
		int k;
	cin>>k;
	while(k--) {
	    ll n;
	    cin>>n;
	    double t;
	    cin>>t;
	    double dist[n];
	    double ans=0.0;
	    
	    for(int i=0;i<n;i++) {
	        cin>>dist[i];
	    }
	    
	    double l=0.0,r=n*t;
	    
	    while(l<=r) {
	        double mid= (l+r)/2;
	        double lastele=max(0.0,dist[0]-mid);
	        double curr=0.0;
	        bool found=1;
	        for(int i=1;i<n;i++) {
	            curr=max(lastele+t,dist[i]-mid);
	            lastele=curr;
	            if(curr>dist[i]+mid) {
	                found=0;
	                break;
	            }
	        }
	        if(found) {
	            ans=mid;
	            r=mid-0.00001;
	        }
	        else l=mid+0.00001;
	    }
	    cout<<fixed<<setprecision(4)<<ans<<endl;
	}
	return 0;
}



43.Circular intervals
---------------------
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m, n;
ll s[1000000], e[1000000];

bool check(ll d) {
ll curr = s[0], first = s[0];
for (int i = 1; i < n; i++) {
if (curr+d < s[i])
curr = s[i];
else if (curr+d >= s[i] && curr+d <= e[i])
curr = curr+d;
else
return false;

}
if (curr+d < m) return true;
ll n_curr = (curr+d) % m;
if (n_curr > e[0]) return false;
for (int i = 1; i < n; i++) {
if (n_curr+d < s[i])
n_curr = s[i];
else if (n_curr+d >= s[i] && n_curr+d <= e[i])
n_curr = n_curr+d;
else
return false;
}
if (n_curr <= curr) return true;
return false;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.in", "r", stdin);
freopen("output.out", "w", stdout);
#endif
scanf("%lld %lld", &m, &n);
for (int i = 0; i < n; i++) scanf("%lld %lld", &s[i], &e[i]);
ll hi = 1e18, lo = 1, mid, ans;
while (lo <= hi) {
mid = (lo+hi)/2;
if (check(mid)) {
ans = mid;
lo = mid+1;
} else hi = mid-1;
}
printf("%lld", ans);
}


42.Minimize the Maximum
------------------------
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;
 
#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
int mod = 1000000007;
const int inf = 1034567891;
const ll LL_INF = 1234567890123456789ll;
#define PI 3.14159265
#define endl '\n'
#define F first
#define S second
#define debug(x) cout << #x << " = " << x << endl;
#define TRACE
 
#ifdef TRACE
#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define out(container) for (auto it : container) cout << it << " "; cout << endl;

template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
  int x = 1 % mod;
  while(b){
    if(b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    
    long long sum = 0;
    int v;
    vector<int> vec;
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> v;
        vec.push_back(v);
        sum += v;
        ans = max(ans, (sum + i) / (i + 1));
    }
    
    cout << ans << endl;
  }

  return 0;
}



41.Squirrel and chestnut
-------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool check(ll mid, const vector<ll>& a, const vector<ll>& b, int n, int m, int k) {
    vector<ll> c(m);
    for (int i = 0; i < m; ++i) {
        if (mid < a[i]) {
            c[i] = 0;
        } else {
            c[i] = max(0LL, (mid - a[i] + b[i]) / b[i]);
        }
    }
    sort(c.begin(), c.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < min(n, m); ++i) {
        ans += c[i];
        if (ans >= k) {
            return true;
        }
    }
    return false;
}
ll minimizeMax(ll low, ll high, const vector<ll>& a, const vector<ll>& b, int n, int m, int k) {
    ll result = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, a, b, n, m, k)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<ll> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        ll low = 1, high = 1e18;
        ll result = minimizeMax(low, high, a, b, n, m, k);
        cout << result << endl;
    }
    return 0;
}

40.Forest Gathering
----------------
#include <stdio.h>

struct data {
    long long time;
    long long initial;
    long long inc;
} d[100001], temp[100001];

void merge(long i, long j, long mid) {
    long l = mid + 1, k = i, i2 = i;
    while (i <= mid && l <= j) {
        if (d[i].time <= d[l].time) {
            temp[k].time = d[i].time;
            temp[k].initial = d[i].initial;
            temp[k].inc = d[i].inc;
            i++;
        } else {
            temp[k].time = d[l].time;
            temp[k].initial = d[l].initial;
            temp[k].inc = d[l].inc;
            l++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k].time = d[i].time;
        temp[k].initial = d[i].initial;
        temp[k].inc = d[i].inc;
        i++;
        k++;
    }
    while (l <= j) {
        temp[k].time = d[l].time;
        temp[k].initial = d[l].initial;
        temp[k].inc = d[l].inc;
        l++;
        k++;
    }
    for (; i2 < k; i2++) {
        d[i2].time = temp[i2].time;
        d[i2].initial = temp[i2].initial;
        d[i2].inc = temp[i2].inc;
    }
}

void split(long i, long j) {
    long mid = (i + j) / 2;
    if (i < j) {
        split(i, mid);
        split(mid + 1, j);
        merge(i, j, mid);
    }
}

int main() {
    long a, i;
    int j = 0;
    long long b, c, wood = 0, tt = 0, incre = 0, ss;
    scanf("%ld %lld %lld", &a, &b, &c);
    for (i = 0; i < a; i++) {
        scanf("%lld %lld", &d[i].initial, &d[i].inc);
        if (d[i].initial >= c)
            d[i].time = 0;
        else {
            d[i].time = (c - d[i].initial) / d[i].inc;
            if ((c - d[i].initial) % d[i].inc)
                d[i].time++;
        }
    }
    split(0, a - 1);
    i = 0;
    while (i < a) {
        if ((b - wood) % incre)
            ss = 1;
        if (incre != 0 && (tt + ((b - wood) / incre) + ss) <= d[i].time) {
            printf("%lld", tt + ((b - wood) / incre) + ss);
            j = 1;
            break;
        } else {
            wood += d[i].initial + d[i].inc * d[i].time + incre * (d[i].time - tt);
            incre += d[i].inc;
            tt = d[i].time;
            if (wood >= b) {
                printf("%lld", tt);
                j = 1;
                break;
            }
        }
        i++;
    }
    if (j == 0) {
        tt += (b - wood) / incre;
        if ((b - wood) % incre)
            tt++;
        printf("%lld", tt);
    }
    return 0;
}


39.Snake Eating
------------------

#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MP make_pair
#define INF mod

typedef vector<int> VI;
typedef long long LL;
typedef list<int> LI;
LL N, Q;
LL BS( LL arr[] , LL X )
{
	LL lo = 0, hi = N-1, mid;
	while( lo < hi ){
 
		mid = lo + (hi-lo+1)/2;
 
		if( arr[mid] < X )
			lo = mid+1;
 
		else
			hi = mid;
	}
	return lo ;
} 
LL BS_extra( LL arr[], LL X , LL idx ) 
{
	LL lo = 0, hi = idx, mid;
	LL found = 0;
	while( lo <= hi ){ 
		mid =( lo + hi)/2;
		if( X*(idx-mid+1) - (arr[mid] - arr[idx+1]) > mid )
			lo = mid+1;
		else{
			if( found == 1 && hi==lo)break;
			hi = mid;
			found = 1;
		}
	}
	if( found == 1 )return idx-lo+1;
	else return 0;
}
int main()
{
	LL TC;
	scanf("%lld",&TC);
	while( TC-- ){ 
		scanf("%lld %lld",&N,&Q);
		LL arr[N];
		REP(i,N)
		scanf("%lld",&arr[i]); 
		sort(arr, arr+N);
		LL sum[N+1];
		sum[N] = 0;
		sum[N-1] = arr[N-1];
		for( int i=N-2; i>=0; i-- )
			sum[i] = sum[i+1] + arr[i];
		while( Q-- ){
			LL K; LL ans = 0;
			scanf("%lld",&K);
 
			if( K <= arr[0] )
				ans = N;
			else{
				 int index= lower_bound(arr,arr+N,K)-arr;
				ans += N-index;
				ans += BS_extra(sum,K,index-1);
			}
			printf("%lld\n",ans);
	}
}
 

38.Minion Chef and Banana
-----------------------
#include <stdio.h>

int can_finish_all_bananas(int N, int H, int piles[]) {
    int max_bananas = 0;
    for (int i = 0; i < N; i++) {
        if (piles[i] > max_bananas) {
            max_bananas = piles[i];
        }
    }
    
    int left = 1, right = max_bananas;
    while (left < right) {
        int mid = (left + right) / 2;
        int hours = 0;
        for (int i = 0; i < N; i++) {
            hours += (piles[i] + mid - 1) / mid;
        }
        if (hours <= H) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N, H;
        scanf("%d %d", &N, &H);
        int piles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &piles[i]);
        }
        int result = can_finish_all_bananas(N, H, piles);
        printf("%d\n", result);
    }
    return 0;
}


37.Shoekand and number
--------------------
#include <stdio.h>
#include <math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int n1=n;
	    int ct=0;
	    while(n!=0){
	        n=n/2;
	        ct++;
	    }
	    int a= pow(2,0) + pow(2,ct-1);
	    int min = abs(a-n1);
	    for(int i=1;i<ct-1;i++){
	        
	        int x = pow(2,i) + pow(2,ct-1);
	        int y = abs(n1-x);
	        if(min>y){
	            min=y;
	        }
	    }
	    int a1 = pow(2,0) + pow(2,ct);
	    int min1 = abs(a1-n1);
	    if(n1==1){
	        printf("2\n");
	    }
	    else if(min1>min){
	        printf("%d\n",min);
	    }
	    else if(n1==1){
	        printf("2\n");
	    }
	    else {
	        printf("%d\n",min1);
	    }
	}

}

36.The Wave
-------------------
#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int pos = binary_search(arr, n, x);
        if (pos != -1) {
            cout << "0" << endl;
        } else {
            int greater_count = upper_bound(arr, arr + n, x) - arr;
            if (greater_count % 2 == 0) {
                cout << "POSITIVE" << endl;
            } else {
                cout << "NEGATIVE" << endl;
            }
        }
    }
    return 0;
}

35.Coins and Triangle
--------------------
#include <stdio.h>

int main() {
    int t, c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &c);
        int count = 0;
        int j = 1;
        while (c > 0) {
            c -= j;
            if(c<0)
            break;
            else
            {
            count++;
            j++;
            }
        }
        printf("%d\n", count);
    }
    return 0;}

34.Zonal Computing Olympiad 2015, 29 Nov 2014
---------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int smallestSetSize(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    int setSize = 0;
    int currentEnd = -1;

    for (const auto& interval : intervals) {
        if (interval.start > currentEnd) {
            setSize++;
            currentEnd = interval.end;
        }
    }

    return setSize;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Interval> intervals(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    int result = smallestSetSize(intervals);

    std::cout << result << std::endl;

    return 0;
}



33.K-flip
----------------
#include <stdio.h>
#include <string.h>
char setd[100001];
long long int arr[200001], N, K, don;
void dip_1() {
    scanf("%lld %lld", &N, &K);
    don = 0;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &setd[i]); 
    memset(arr, 0, sizeof(arr));

    for (int i = 1; i <= N - K + 1; i++) {
        if ((setd[i] + don) % 2 == 1) {
            don++;
            arr[i + K - 1] = 1;
        }
        don -= arr[i];
        setd[i] = '0'; 
    }

    for (int i = N - K + 2; i <= N; i++) {
        setd[i] = '0' + (setd[i] + don) % 2;
        don -= arr[i];
    }
    for (int i = 1; i <= N; i++) {
        printf("%c", setd[i]);
    }

    printf("\n");
}

int main() {
    int za;
    scanf("%d", &za);

    while (za--) {
        dip_1();
    }

    return 0;
}



32.Snakes, Mongooses and the Ultimate Election
-----------------------------------------------
#include<bits/stdc++.h>
#define pi                  acos(-1)
#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)
#define INF                 1000000000000000000
#define dist(ax,ay,bx,by)   sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define M                   1000000
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define m_p(a,b)            make_pair(a,b)
#define pb                  push_back
#define pf                  printf
#define sf                  scanf

using namespace std;
typedef unsigned long long llu;
typedef long long lli;
typedef long double ld;

using namespace std;
int main()
{
    string a;
    stack<char>s;
    stack<char>s1;
    lli p,i;
    cin>>p;
    bool mark=true;
    while(p--)
    {
cin>>a;
        mark=true;
        for(i=0; i<a.size(); i++)
        {
            if(a[i]=='m'&&a[i+1]=='s'&&mark)
            {
                mark=false;
                swap(a[i],a[i+1]);
            }
            if(a[i]=='s')
            {
           s.push('s');
            }
            else
            {
                mark=true;

                if(!s.empty()&&a[i-1]=='s') s.pop();
                s1.push('m');
            }
        }
        if(s.size()>s1.size()) cout<<"snakes";
        else  if(s.size()<s1.size()) cout<<"mongooses";
        else cout<<"tie";
        cout<<endl;
        while(!s.empty())
            s.pop();
        while(!s1.empty())
            s1.pop();
}

}

31.watson asks Does permutation Exist
-------------------------------------
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main()
{
 int t,flag;
 ll n,*arr,i;
 cin>>t;
 while(t--) }
}
 {
 cin>>n;
 arr=(ll *)malloc(sizeof(ll)*n);
 for(i=0;i<n;i++)
 {
 cin>>arr[i];
 }
 sort(arr,arr+n);
 flag=0;
 for(i=1;i<n;i++)
 {
 if(arr[i]-arr[i-1]>1)
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"YES\n";
 }
 else
 {
 cout<<"NO\n";
 }
 }
}


30.Maximum Weight difference
-----------------------------
for _ in range(int(input())):
    N,K=map(int,input().split())
    w=list(map(int,input().split()))
    w.sort()
    son=sum(w[:K])
    dad=sum(w[K:])
    first=dad-son
    w.reverse()
    min=sum(w[:K])
    max=sum(w[K:])
    sec=min-max
    if first<sec:
        print(sec)
    else:
        print(first)


29.Maximize Disjoint pair sum
-----------------------------
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long ans = 0;
		for (int i = n - 1; i - 1 >= 0; ) {
			if (a[i] - a[i - 1] < d) {
				ans += (a[i] + a[i - 1]);
				i -= 2;
			} else {
				i--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

28.Evacuate to Moon
---------------------
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
   long long n,m,h;
   cin>>n>>m>>h;
   long long int A[n],B[m];
   int c1=0,c2=0,co=0,c3=0;
   for(int i=0;i<n;i++)
   cin>>A[i];
   for(int i=0;i<m;i++)
   cin>>B[i];
   sort(A,A+n,greater<long long>());
   sort(B,B+m,greater<long long>());
   long long ans=0;
   for(int i=0;i<min(m,n);i++)
   {
      ans+=min(A[i],B[i]*h);
   }
   cout<<ans<<endl;
    }}
chef and String
------------------
#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans1 = 0;
        char s[100000];
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans1++;
                i++;
            }
        }
        printf("%d\n", ans1);
    }
    return 0;
}

26.Little Elephant and Divisors
---------------------------------
#include <stdio.h>
#include <math.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int getFactor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(a[i], g);
        }
        int factor = getFactor(g);
        printf("%d\n", factor > 1 ? factor : -1);
    }
    return 0;
}


25.Number of factors
---------------------------
const MAX = 1000001;
function countFactors(n) {
    let factors = new Array(MAX).fill(0);
    
    for (let i = 2; i * i <= n; ++i) {
        while (n % i === 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    if (n > 1) {
        factors[n]++;
    }
    
    let count = 1;
    for (let i = 2; i < MAX; ++i) {
        if (factors[i] > 0) {
            count *= (factors[i] + 1);
        }
    }
    
    return count;
}
function main() {
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Enter the number of test cases: ", function(t) {
        t = parseInt(t);
        let testCase = 0;
        rl.question("Enter the values for each test case separated by space: ", function(input) {
            let values = input.split(' ').map(Number);
            for (let i = 0; i < t; ++i) {
                let n = values[testCase++];
                let product = 1;
                for (let j = 0; j < n; ++j) {
                    let a = values[testCase++];
                    product *= a;
                }
                console.log(countFactors(product));
            }
            rl.close();
        });
    });
}
main();


24.Little Elephant and Divisors 
------------------------------
#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getFactor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
      
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(a[i], g);
        }
        int factor = getFactor(g);
        printf("%d\n", factor > 1 ? factor : -1);
    }
    return 0;
}



23.Chef and Interview(java)
-------------------
import java.io.*;
import java.util.*;

public class Main {
	
	private static FastReader in;
	
	public static void main(String[] args) {
		in = new FastReader();
		int tc = 1;
		tc = in.nextInt();
		for(int t = 0; t < tc; t++) {
			new Solver();
		}
	}
	static class Solver { 
		Solver() {
			int n = in.nextInt();
			ArrayList<Integer> divisors = new ArrayList<Integer>();
			for(int i = 1; i <= (int) Math.sqrt(n); i++) {
				if(n % i == 0) {
					divisors.add(i);
					int otherDivisor = n / i;
					if(otherDivisor != i) {
						divisors.add(otherDivisor);
					}
				}
			}
			
	
			long sum = 0;
			for(Integer x : divisors) {
				sum += x;
			}
			

			System.out.println(sum);
		}
	}
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
		
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
		
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}
			return str;
}
}
}
22.Cutting Recipes
----------------
#include <stdio.h>
int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int T, N, i, gcd_all, min_factor;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int A[N];
        for (i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        gcd_all = A[0];
        for (i = 1; i < N; i++) {
            gcd_all = gcd(gcd_all, A[i]);
        }
        min_factor = gcd_all;
        for (i = 0; i < N; i++) {
            A[i] /= min_factor;
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    return 0;
}

21.Existence
------------
#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long X, Y;
        scanf("%lld %lld", &X, &Y);

        if (X * X == 2 * Y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

20.Simple Statistics
-----------------------
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int measurements[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &measurements[i]);
        }
        qsort(measurements, n, sizeof(int), compare);
        double sum = 0;
        for (int i = k; i < n - k; i++) {
            sum += measurements[i];
        }
        double average = sum / (n - 2 * k);
        printf("%.6lf\n", average);
    }
    return 0;
}

19.WA Test Cases
---------------------
#include <stdio.h>
#include <limits.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int sizes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sizes[i]);
        }
        char verdict[n + 1];
        scanf("%s", verdict);
        int minSize = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (verdict[i] == '0') {
                if (sizes[i] < minSize) {
                    minSize = sizes[i];
                }
            }
        }
        printf("%d\n", minSize);
    }
    return 0;
}

18.ChefWatson uses Social Network
----------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct post {
    int id;
    int popularity;
    char content[101];
    int is_special;
} Post;
int compare_posts(const void* a, const void* b) {
    const Post* post_a = (const Post*)a;
    const Post* post_b = (const Post*)b;
    if (post_a->is_special != post_b->is_special) {
        return post_a->is_special > post_b->is_special ? -1 : 1;
    } else if (post_a->popularity != post_b->popularity) {
        return post_a->popularity > post_b->popularity ? -1 : 1;
    } else {
        return strcmp(post_a->content, post_b->content);
    }
}
int main() {
    int n, m; 
    scanf("%d %d", &n, &m);
    int special_friends[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &special_friends[i]);
    }
    Post posts[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %s", &posts[i].id, &posts[i].popularity, posts[i].content);
        posts[i].is_special = 0;
        for (int j = 0; j < n; j++) {
            if (posts[i].id == special_friends[j]) {
                posts[i].is_special = 1;
                break;
            }
        }
    }
    qsort(posts, m, sizeof(Post), compare_posts);
    for (int i = 0; i < m; i++) {
        printf("%s\n", posts[i].content);
    }
    return 0;
}

17.400M Race
--------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        double speedAlice = 400.0 / a;
        double speedBob = 400.0 / b;
        double speedCharlie = 400.0 / c;
        if (speedAlice > speedBob && speedAlice > speedCharlie) {
            printf("ALICE\n");
        } else if (speedBob > speedAlice && speedBob > speedCharlie) {
            printf("BOB\n");
        } else {
            printf("CHARLIE\n");
        }
    }
    return 0;
}

16.Passing Marks
------------------
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, X;
        scanf("%d %d", &N, &X);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        qsort(A, N, sizeof(int), cmp);
        int passingMark = A[N - X];
        printf("%d\n", passingMark-1);
    }
    return 0;
}

15.Facebook
-----------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        int mostPopularIndex = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[mostPopularIndex] || (a[i] == a[mostPopularIndex] && b[i] > b[mostPopularIndex])) {
                mostPopularIndex = i;
            }
        }
        printf("%d\n", mostPopularIndex + 1);
    }
    return 0;
}


14.Chef and easy problem
-----------------------------
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];

    
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), compare);
        long long maxStones = 0;
        for (int i = 0; i < n; i += 2) {
            maxStones += a[i];
        }
        printf("%lld\n", maxStones);
    }

    return 0;
}


13.Andrew and the Meatballs
---------------------------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long p[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (p[j] < p[j + 1]) {
       
                    long long temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        long long totalMeatballs = 0;
        int plates = 0;
        for (int i = 0; i < n; i++) {
            totalMeatballs += p[i];
            plates++;
            if (totalMeatballs >= m) {
                break;
            }
        }
        if (totalMeatballs >= m) {
            printf("%d\n", plates);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}


12.Turn It
---------
#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long U, V, A, S;
        scanf("%lld %lld %lld %lld", &U, &V, &A, &S);
        long long min_distance = (U * U) - (V * V);
               if (min_distance <= 2 * A * S) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

11.Distinct Pair Sums
------------------
#include <stdio.h>
int count_reachable(int L, int R) {
    return (2 * R - 2 * L) + 1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        int result = count_reachable(L, R);
        printf("%d\n", result);
    }

    return 0;
}

10.Tom And Jerry 
----------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* can_reach_in_k_moves(int a, int b, int c, int d, int k) {
    int distance = abs(a - c) + abs(b - d);
    if (distance > k || (k - distance) % 2 != 0) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        char* result = can_reach_in_k_moves(a, b, c, d, k);
        printf("%s\n", result);
    }

    return 0;
}

9.Alternate Additions
-------------------
#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int A,B;
        scanf("%d %d", &A, &B);
        int diff = B - A;
        if ((B - A) % 3 == 0)
        {
            printf("Yes\n");
        }
        else if ((B - A)%3 == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

8.The Begining Era Of Cyberverse
-------------------------------

#include <stdio.h>

int solve(int N, int K) {
    return K / N;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; ++tc) {
        int N, K;
        scanf("%d %d", &N, &K);

        printf("%d\n", solve(N, K));
    }

    return 0;
}

7.Fill The Grid
-------------
#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        if(n % 2 != 0 && m % 2 != 0)
        {
            printf("%d\n", n+m-1);
        }
        else if(n % 2 != 0 && m % 2 == 0)
        {
            printf("%d\n", m);
        }
        else if(n % 2 == 0 && m % 2 != 0)
        {
            printf("%d\n", n);
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    
    return 0;
}

6.Balls and Boxes
---------------

#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,k,s;
	    scanf(" %d %d",&n,&k);
	    s=(k*(k+1)/2);
	    if(s<=n){
	        printf("Yes \n");
	    }
	    else{
	        printf("No \n");
	    }
	}
	return 0;
}

5.Farmer And His Plot
--------------------

#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int find_min_square_plots(int length, int breadth) {
    int common_divisor = gcd(length, breadth);
    int min_plots = (length / common_divisor) * (breadth / common_divisor);
    return min_plots;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
         int N, M;
        scanf("%d %d", &N, &M);
        int result = find_min_square_plots(N, M);
        printf("%d\n", result);
    }

    return 0;
}

4.Puppy and Sum (python)
--------------
def sum_function(D, N):
    if D == 1:
        return sum(range(1, N+1))
    else:
        return sum_function(D-1, sum(range(1, N+1)))

# Input reading
T = int(input())
for _ in range(T):{
    D, N = map(int, input().split())
    result = sum_function(D, N)
    print(result)
}

3.Racing Horses
---------------------
#include <stdio.h>
#include <stdlib.h> 
int compare(const void *a, const void *b) {
    return *(long *)a - *(long *)b;
}
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        long s[n];
        for (int i = 0; i < n; i++) {
            scanf("%ld", &s[i]);
        }

        qsort(s, n, sizeof(long), (int (*)(const void *, const void *))compare);

        long min_diff = s[n - 1];  
        for (int i = 1; i < n; i++) {
            long diff = s[i] - s[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        printf("%ld\n", min_diff);
    }

    return 0;
}

2.Maximum Length Even Subarray 
----------------------------
#include <stdio.h>
int max_even_subsequence_length(int N) {
    int sequence_sum = N * (N + 1) / 2;
    if (sequence_sum % 2 == 0) {
        return N;
    }
        return N - 1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        int result = max_even_subsequence_length(N);
        printf("%d\n", result);
    }
    return 0;
}

1.Turbo Sort
-----------------
Given a list of numbers, you have to sort them in non decreasing order.
#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int sizes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sizes[i]);
        }

        char verdict[n + 1];
        scanf("%s", verdict);
        int minSize = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (verdict[i] == '0') {
                if (sizes[i] < minSize) {
                    minSize = sizes[i];
                }
            }
        }
        printf("%d\n", minSize);
    }

    return 0;
}

