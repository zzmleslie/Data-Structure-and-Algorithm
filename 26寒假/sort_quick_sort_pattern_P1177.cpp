// 归并排序：
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[600000], b[600000], ans;
void mergee(ll l, ll r) {
	if (l >= r) {  //不能再分了，直接返回。
		return ;
	}
	ll mid = (l + r) / 2;//取一个中间值
	ll i = l, j = mid + 1, tot = l;  // i是第一个序列的开头，j是第二个序列的开头，tot是整个的大序列。
	while (i <= mid && j <= r) {  //合并
		if (a[i] <= a[j]) {  //谁小就把谁放到前面。
			b[tot++] = a[i]; 
			i++;
		} else {
			b[tot++] = a[j];
			j++;
		}
	}
	while (i <= mid) {  //可能还没有放完，就把剩下的放进来。
		b[tot++] = a[i];
		i++;
	}
	while (j <= r) {  // 同上
		b[tot++] = a[j];
		j++;
	}
	for (int i = l; i <= r; i++) {  // 给最终的答案数组赋值。
		a[i] = b[i];
	}
	return;
}
void mergesort(ll l, ll r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(l, mid);  //  先给左子序列排序。
		mergesort(mid + 1, r); //再给右子序列排序。
		mergee(l, r);  // 最后把两个子序列合并。
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	mergesort(1, n);
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}



//标准快排
int randint(int l, int r){ // 生成在 [l, r] 之间的随机数
	return rand() % (r - l + 1) + l;
}
void qsort(int l, int r){ // l 为左端点，r 为右端点
	if(l >= r){ // 如果长度为 0 或 1 就返回
		return;
	}
	int num = randint(l, r), ind1 = 0, ind2 = 0, ind3 = 0; // 随机选择一个数，并定义三个作为下标的变量来记录长度、存放数据
	for(int i = l;i <= r;i++){ // 将 a 中的数分别分到 b, c, d（如上所述）
		if(a[i] < a[num]){
			b[ind1++] = a[i];
		}
		else if(a[i] == a[num]){
			c[ind2++] = a[i];
		}
		else{
			d[ind3++] = a[i];
		}
	}
	for(int i = 0;i < ind1;i++){ // 将 b, c, d 中的数重新放回 a
		a[i + l] = b[i];
	}
	for(int i = 0;i < ind2;i++){
		a[i + ind1 + l] = c[i];
	}
	for(int i = 0;i < ind3;i++){
		a[i + ind1 + ind2 + l] = d[i];
	}
	qsort(l, l + ind1 - 1); // 继续递归，排序原来的 b 和 d
	qsort(l + ind1 + ind2, r);
}

//堆排序 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
int read(){
    int x = 0 ,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if( ch == '-' ) 
            f = -1;
        ch = getchar();
    }
    while( ch > = '0' && ch <= '9'){
        x = x * 10 + ch - '0' ;
        ch = getchar();
    }
    return x * f;
}
void Write(int x){
    if( x < 0 ){
        putchar( '-' );
        Write( -x );
        return;
    }
    if( x < 10 ){
        putchar( x + '0' );
        return;
    }
    Write( x / 10 ) ;
    putchar( x % 10 + '0' );
}
void write(int x , char *s){
    Write( x );
    printf("%s", s);
}
int n , a[N];
priority_queue<int , vector<int>, greater<int> >q;
void solve()
{
	n = read();
	while( n-- )  
        q.push(read());
	while( q.size() ) 
        write(q.top()," "),q.pop();
}
signed main()
{
	int T = 1;
	while(T--) solve();
}

#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
int n ;int a[N];
int main(void){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	sort(a , a + n);
	for(int i = 0 ; i < n ; i++){
		cout << a[i] << " ";
	}
	return 0;	
}


