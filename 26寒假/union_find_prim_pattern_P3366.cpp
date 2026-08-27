//prim -> 从点出发，逐步扩展树 
//时间复杂度：O(n²)
/*
第1步：准备工作
选定一个起点（通常是点1）
标记起点已加入树
记录所有点到树的距离：
起点：距离为0
邻居：距离为边权
其他人：距离为无穷大
第2步：核心循环（重复n-1次）
找最近：在所有未加入的点中，找到离当前树最近的点X
加进来：将X加入树，累加它的距离到总权值
更新距离：用X更新它所有邻居到树的距离（取更小值）
第3步：收尾检查
如果成功加入n个点：输出总权值
如果中途找不到可加入的点：输出"不连通"
*/
#include<iostream>
#include<cstdio>
#include<cstring>      // 使用memset函数
using namespace std;

// 常量定义
const int N = 5100;     // 最大顶点数
const int M = 2e5 + 100;// 最大边数
const int INF = 0x3f3f3f3f; // 无穷大值

// 全局变量
int n, m;               // n:顶点数，m:边数
int k;                  // 邻接表边计数器
int t[N];               // 邻接表头指针，t[u]存储顶点u的第一条边在a数组中的索引
int u, v, w;            // 临时变量，用于输入边的端点u,v和权值w
int dis[N];             // dis[i]:顶点i到MST集合的最短距离
int mk;                 // 每次找到的离MST集合最近的顶点
int sum;                // MST总权值
bool flag[N];           // flag[i]:标记顶点i是否已加入MST集合

// 邻接表结构体
struct node {
    int id;            // 边的终点
    int last;          // 上一条同起点的边在a数组中的索引
    int val;           // 边的权值
} a[M * 2];            // 无向图需要存双向边，所以是M*2
// 添加边的函数（邻接表建图）
void add(int a1, int a2, int a3) {
    a[++k].id = a2;     // 新边的终点是a2
    a[k].last = t[a1];  // 新边的上一条边是原来t[a1]指向的边
    a[k].val = a3;      // 边的权值
    t[a1] = k;          // 更新顶点a1的第一条边为新加的边
}
int main() {
    scanf("%d%d", &n, &m);  // 输入顶点数和边数
    
    // 读取所有边并构建无向图
    while(m--) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);  // 无向图需要添加双向边
    }
    
    // 初始化距离数组为无穷大
    memset(dis, 0x3f, sizeof dis);
    // 0x3f3f3f3f是一个很大的数，常用于表示无穷大
    // 优点：两个0x3f3f3f3f相加不会溢出
    
    dis[1] = 0;  // 从顶点1开始，将其到MST集合的距离设为0
        // 循环n次，每次将一个顶点加入MST
    for(int i = 1; i <= n; i++) {
        mk = 0;  // 初始化为0，因为dis[0]是INF（dis数组从1开始）
        
        // 步骤2.1：从未加入MST的顶点中找到dis最小的顶点
        for(int j = 1; j <= n; j++) {
            if(!flag[j] && dis[j] < dis[mk]) {
                mk = j;  // 更新最小距离顶点
            }
        }
        
        // 步骤2.2：检查图是否连通
        // 如果找不到未加入且dis不是无穷大的顶点，说明图不连通
        if(dis[mk] == INF) {
            printf("orz");  // 输出"orz"表示不连通
            return 0;
        }
                // 步骤2.3：将顶点mk加入MST集合
        sum += dis[mk];     // 累加MST总权值
        flag[mk] = true;    // 标记顶点mk已加入MST
        
        // 步骤2.4：更新与mk相邻的顶点到MST集合的距离
        // 遍历顶点mk的所有邻边
        for(int j = t[mk]; j; j = a[j].last) {
            int neighbor = a[j].id;     // 相邻顶点
            int weight = a[j].val;      // 边的权值
            
            // 如果邻居未加入MST，且通过mk到MST的距离更小
            if(!flag[neighbor] && weight < dis[neighbor]) {
                dis[neighbor] = weight;  // 更新距离
            }
        }
    }
        printf("%d", sum);  // 输出最小生成树的总权值
    return 0;
}

