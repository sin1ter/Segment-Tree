#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int arr[N];
int t[N * 4]; // used for tree index

void build(int node, int b, int e) {
	if(b == e) {
		t[node] = arr[b];
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[node] = t[l] + t[r];
}

int query(int node, int b, int e, int i, int j) {
	if(b > j or e < i) {
		return 0;
	}
	if(b >= i and e <= j) {
		return t[node];
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;
	
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void update(int node, int b, int e, int i, int x) {
	if(b > i or e < i) {
		return;
	}
	if(b == e and b == i) {
		t[node] = x;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;
	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);
	t[node] = t[l] + t[r];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n = 5;
		
	for(int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	
	build(1,1,n);
	
	cout << t[1] << endl;
	cout << query(1, 1, n, 2, 4) << endl;
	update(1, 1, n, 3, 10);
	cout << query(1, 1, n, 2, 4) << endl;
	
		return 0;
}
