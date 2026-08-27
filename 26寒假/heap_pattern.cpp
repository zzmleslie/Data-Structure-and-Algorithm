//二叉堆
//因为堆是一棵完全二叉树，所以对于一个节点数为n的堆，它的高度不会超过log2n
//所以对于插入，删除操作复杂度为O(log2n)
//查询堆顶操作的复杂度为O(1)
#include<iostream>
//STL优先队列
#include<queue>
using namespace std;
priority_queue<int> q;//这是一个大根堆q
priority_queue<int,vector<int>,greater<int> >p;//这是一个小根堆p
//注意某些编译器在定义一个小根堆的时候greater<int>和后面的>要隔一个空格，不然会被编译器识别成位运算符号>>





//手写heap ，数组模拟二叉堆(小根堆)
#define N 10000
int heap[N];
int siz;

void swap(int *x , int * y)
{
    int t = *x; *x = *y; *y = t;
}

//插入
void push(int x)
{
    heap[++siz] = x;
    int cur = siz;
    while(siz){
        int nxt = siz << 1;
        if(nxt && heap[nxt] > heap[cur]){
            swap(&heap[nxt] , &heap[cur]);
        }
        else break;
        cur = nxt;
    }
}

//删除 （根节点）
void pop()
{
    swap(&heap[siz] , &heap[1]);
    siz--;
    int cur = 1;
    while(cur){
        int nxt = cur << 1;
        if(nxt > siz) break;
        if(nxt + 1 < siz && heap[nxt + 1] < heap[nxt]){
            nxt ++;
        }
        if(heap[cur] > heap[nxt]){
            swap(&heap[cur] , &heap[nxt]);
        }else break;
        cur = nxt;
    }
}

int main(void){
    q.top(); // 取得堆顶的元素 ，不弹出
    q.pop();// 弹出堆顶的元素
    //STL只支持删除堆顶，而不支持删除其他元素
    // 可以开一个del数组记录
    q.push();// 往堆里插入元素
    q.empty();// 查询堆是否为空，为空则返回 1 
    q.size(); //查询堆内元素个数
    return 0;
}
