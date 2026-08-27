#include<iostream>
#include<queue>
using namespace std;
#define N (2 * 100005)
priority_queue<int>p;
priority_queue<int, vector<int> , greater<int> > q;
int a[N];
int u[N];
int main(void){
    int m , n;
    scanf("%d %d" , &m , &n);
    for(int i = 1 ; i <= m ; i++ ){
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i <= n ;i++){
        scanf("%d" , &u[i]);        
    }
    // 大根堆先到 i 再把其他ui - i 个放入小根堆 
    /*不行
    p.push(a[1]);
    for(int i = 2 ; i <= u[1] ; i++){
        q.push(a[i]);
    }
    printf("%d\n" , p.top());
    for(int i = 2 ; i <= n ; i++){
        int siz = q.size();
        int cnt = p.size();
        while(siz > 0 && cnt < i){
            p.push(q.top());
            q.pop();
            siz--;cnt ++;
        }
        while(cnt < i){
            cnt++;
            p.push(a[cnt]);
        }
        int tot = p.size() + q.size();
        while(tot < u[i]){
            tot++;
            if(a[tot] < p.top()){
                q.push(p.top());
                p.pop();
                p.push(a[tot]);
            }else{
                q.push(a[tot]);
            }
        }
        printf("%d\n" , p.top());

    }*/
    //standard

    // 因为 大根堆每次是（i- 1）个元素 ，
    // 所以可以做到有序的每次在查询结束之后，
    //将小根堆的top push进大根堆中 
    //使得每次压入新的元素时，大根堆始终是（i- 1） 个元素，
    //从而只需push pop即可
    //q.top() is res 
    int t = 0;
    for(int i = 1 ; i <= n ; i++){
        while(t < u[i]){
            p.push(a[t]);
            q.push(p.top());
            p.pop();
        }
        printf("%d\n" , q.top());
        p.push(q.top());
        q.pop();
    }
    return 0;
}