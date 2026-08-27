//SPFA（Shortest Path Faster Algorithm），便是求单源最短路的一种算法
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f; 
int dis[10005]; 
struct node {
    int v, w;
}; 
vector<node> adj[10005];
bool in_q[10005]; 

void spfa(int s) { 
    memset(dis, INF, sizeof(dis)); 
    queue<int> q;
    dis[s] = 0, in_q[s] = 1, q.push(s); 
    while(!q.empty()) {
        int h = q.front();
        in_q[h] = 0, q.pop(); 
        for(node x : adj[h]) {
            if(dis[x.v] > dis[h] + x.w) {
                dis[x.v] = dis[h] + x.w; 
                if(!in_q[x.v]) {
                    in_q[x.v] = 1, q.push(x.v); 
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "请输入点数和边数: ";
    cin >> n >> m;

    cout << "请输入每条边的 起点 终点 权重:" << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 核心：把输入的数据存入 vector 数组
        adj[u].push_back({v, w}); 
    }

    int start;
    cout << "请输入起点: ";
    cin >> start;

    spfa(start); // 调用你提供的函数

    cout << "从起点 " << start << " 到各点的最短距离为:" << endl;
    for(int i = 1; i <= n; i++) {
        if(dis[i] == INF) cout << "点 " << i << ": 无法到达" << endl;
        else cout << "点 " << i << ": " << dis[i] << endl;
    }

    return 0;
}

//negative ring 
//实现方法 1 ：我们可以想到在 SPFA 算法中，
//如果从一个起点能到达一个负环，由于结点会一直被松弛，
//我们就无法求出最短路，而是会重复地更新最短路长度。

// 实现方法 2 ：我们统计每两个点间的最短路包含多少条边，
//如果在一条最短路上包含超过了 (n−1) 条边，
//说明有边被重复使用，则判断有负环。

//实际上是相通的
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f; // 极大值
int T,n,m,q,dis[2005],cnt[2005]; // cnt 记录最短路径经过边数
bool in_q[2005];
struct node{
	long long v,w;
}; vector <node> adj[2005];

bool spfa(int s){
	memset(cnt,0,sizeof(cnt)); // 初始化计数数组
	queue <int> q;
	q.push(s),in_q[s] = 1,dis[s] = 0; // 初始化起点
	while(!q.empty()){
		int h = q.front();
		q.pop(),in_q[h] = 0;
		if(cnt[h] > n) // 判断最短路边数是否大于 n，通常会因为添加超级源点写为 > 而并非 >=
            return 1; // 有负环
		for(node x : adj[h])
			if(dis[x.v] > dis[h] + x.w){ // 可以松弛
				dis[x.v] = dis[h] + x.w; // 进行松弛
				cnt[x.v] = cnt[h]+1; // 边数为对它松弛的点的边数+1
                if(!in_q[x.v]) // 不在队中
                    in_q[x.v] = 1,q.push(x.v); // 入队
			}
	}
	return 0; // 成功计算出最短路，故没有负环
}

int main(){
	cin >> T;
	while(T--){
		memset(adj,0,sizeof(adj));
		memset(in_q,0,sizeof(in_q));
		memset(dis,INF,sizeof(dis));
    // 多测时包括图也要初始化！！！
		cin >> n >> m;
		while(m--){  // 建图
			int u,v,w;
			cin >> u >> v >> w;
			if(w >= 0)
				adj[u].push_back({v,w}),adj[v].push_back({u,w});
			else
				adj[u].push_back({v,w});
		}
		cout << (spfa(1)?"YES\n":"NO\n");
	}
	return 0;
}
