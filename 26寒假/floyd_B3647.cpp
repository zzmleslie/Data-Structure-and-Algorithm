#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

// 带权有向图 用邻接矩阵记录
// G u,v = { x (if x < ∞ ,there exists an edge connecting u and vwith weight x,
//          ∞ （if there are not any edges connecting u and v directly.)}
// G u,u = 0;

// 具体算法
// step 1:
//f (k,u,v)表示当只考虑编号不大于 k 的顶点和 u,v 自身时，u 到 v 的最短路，即要求 u 到 v 的路径上的顶点（不包括 u,v 自身）编号不大于 k，考察此时的最短路。
//初始：f(0,u,v) = G(u,v)
//f (k,u,v) = min{f(k-1,u,v) , (f(k-1,u,k) + f(k-1,k,v))}

//step2:
//  f（k）的值只与 f（k−1）有关，和再之前的状态无关，
//且我们最终关心 f（n），所以 k−2 及以前的状态可以无需记录。
//所以用滚动数组记录即可
// cur(u,v) = min{prev(u,v) , prev(u,k) + prev(k,v)}
// 更新：prev = cur

//step3:
//因为：f(k-1,u,k)=f(k,u,k) , f(k-1,k,v) = f(k,k,v)
//所以：f(k,u,v) = min{f(k/k-1,k,v)+f(k/k-1,u,k), f(k-1,u,v)}
//所以每次更新，f(k,k,v) and f(k,u,k)的更新不会影响结果
//所以每次只有f(k-1,u,v)更新，所以只需一个数组
//f(u,v) = min{f(u,v) , f(u,k)+f(k,v)}

//非负权图上的 Floyd 算法可以直接推广到无负圈的负权图上。
#define N 105
#define M 4505
#define W 1005
int g[N][N];
int main(void){
    int n , m ,u , v , w;
    scanf("%d %d" , &n , &m);
    for(u = 1 ; u <= n ; u++){
        for(v = 1 ; v <= n; v++){
            if(u != v) g[u][v] = INT_MAX / 2;
        }
    }
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d" , &u , &v , &w);
        if(u == v) continue; // 自环！！
        //重边！！
        if(g[u][v] > w) g[u][v] = g[v][u] = w;
    }
    for(int k = 1 ; k <= n ; k++){
        for(u = 1 ; u <= n ; u ++){
            for(v = 1 ; v <= n ; v ++){
                g[u][v] = min(g[u][v] , g[u][k]+g[k][v]);
            }
        }
    }
    for(u = 1 ; u <= n ; u++){
        for(v = 1 ; v <= n ; v++ ){
            printf("%d " , g[u][v]);
        }
        printf("\n");
    }
    return 0;
}