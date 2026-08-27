#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
using namespace std;
#define N 205
int g[N][N];
int a[N][3];
int main(void){
    int n , x, y, p;
    cin>>n;
    for(int i = 1 ; i <= n ;i++){
        cin >>x>>y>>p;
        a[i][0] = x;a[i][1] = y; a[i][2] = p;
    } 

    for(int u = 1 ; u<= n ; u++){
        for(int v = u ; v<= n ; v++){
            if(u == v){ 
                g[u][v] = 1;
                continue;
            }
            float t = hypot(a[u][0] - a[v][0] , a[u][1] - a[v][1]);
            //printf("dis = %f \n" , t);
            int p1 = a[u][2] , p2 = a[v][2];
            if(t > p1){
                g[u][v] = 0;
            }else{
                g[u][v] = 1;
            }
            if(t > p2){
                g[v][u] = 0;
            }else{
                g[v][u] = 1;
            }
        }
    }

    for(int k = 1 ; k <= n ; k++){
        for(int u = 1 ; u <= n ; u++){
            for(int v = 1 ; v <= n ; v++){
                g[u][v] = ((g[u][v] + g[u][k] * g[k][v]) > 0) ? 1 : 0; 
            }
        }
    }
    int max  = 0;
    for(int u = 1 ; u <= n ; u++){
        int sum = 0;
        for(int v = 1 ; v <= n ; v++){
            if(g[u][v] > 0) sum++;
            //printf("%d " , g[u][v]);
        }
        if(sum > max){
            max = sum;
        }
    }
    printf("%d" , max);
    return 0;
}