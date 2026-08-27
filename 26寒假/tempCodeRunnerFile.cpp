#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 5005
#define maxm (2 * 100005)

struct node{
    int id;
    int val;
    int last;
}a[maxm * 2];//每条路是记录两遍的
int n , m;
int x , y , z;
int k ;
long long sum ;
int pre[maxm * 2];
int dis[maxn];
int flag[maxn];
void add(int x , int y , int z){
    a[++k].id = y;
    a[k].val = z;
    a[k].last = pre[x];
    pre[x] = k;
}
int cmp(struct node * pa , struct node* pb){
    return pa->val > pb->val;
}
int main(void){
    scanf("%d %d" , &n, &m);
    for(int i = 1 ; i <= m ; m++){
        scanf("%d %d %d" , &x ,&y , &z);
        add(x ,y ,z); add(y , x , z);
    }
    memset(dis , 0x3f , sizeof(dis));
    dis[1] = 0; //第一次一定去1 所以这样设置
    for(int i = 1 ; i < n ; i++){
        int mk = 0;
        for(int j = 1 ; j <= n ; j++){
            if(!flag[j] && dis[j] < dis[mk]){
                mk = j;
            }
        }
        if(dis[mk] == 0x3f3f3f3f){
            printf("orz\n");
            return 0;
        }
        sum += dis[mk];
        flag[mk] = 1;
        for(int j = a[mk].last ; j ; j = a[j].last){
            int nei = a[j].id;
            int w = a[j].val;
            if(!flag[nei] && w < dis[nei]) { //注意这里要未被记录
                dis[nei] = w;
            }
        }
    }
    printf("%lld" , sum);
    return 0;
}