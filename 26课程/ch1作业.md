# ch1 homework

---

### 第 1 章（Chapter 1）

#### 练习题（Exercises:）

1. **编写一个递归方法，返回整数 $N$ 的二进制表示中 $1$ 的个数。可以利用这样一个事实：该数值等于 $N/2$ 的二进制表示中 $1$ 的个数，如果 $N$ 是奇数，则再加 $1$。**
*(Write a recursive method that returns the number of 1’s in the binary representation of N. Use the fact that is equal to the number of 1’s in the representation of N/2, plus 1, if N is odd.)*
2. **根据以下声明编写相应的例程（routine）：**
*(Write the routines wise the following declarations:)*
```java
public void permute( String str );
private void permute( char [ ] str, int low, int high )

```


**第一个例程是一个驱动程序，用于调用第二个例程并打印字符串 `str` 中字符的所有排列。如果 `str` 是 `"abc"`，那么输出的字符串为 `abc`, `acb`, `bac`, `bca`, `cab` 和 `cba`。第二个例程要使用递归。**
*(The first routine is a driver that calls the second and prints all the permutations of the characters in String str. If str is “abc”, then the strings that are output are abc, acb, bac, bca, cab,and cba. Use recursion for the second routine.)*
3. **已知a[n]为整型数组，试写出实现下列运算的递归算法。**
1）**求数组a中的最大整数。**
2）**求n个整数的平均值。**
4. **编写一个递归方法，计算并返回链表的长度。**
*(Write a recursive method that calculates and returns the length of a linked list.)*
5. **递归地检查以下对象是否为回文：**
*(Check recursively if the following objects are palindromes:)*
**a. 一个单词** *(a. A word)*
**b. 一个句子（忽略空格、大小写差异以及标点符号，从而使 `"Madam, I'm Adam"` 被接受为回文）** *(b. a sentence ( ignoring blanks, lower- and uppercase differences, and punctuation marks so that “Madam, I’m Adam” is accepted as a palindrome))*




---





# 主要考核知识点：递归(rec)
# 主要考核模型：4种递归模型：

### ① 缩小一个元素

链表：

f(node)=1+f(node.next)

---

### ② 从两端向中间缩

回文：

$$f(l,r)\rightarrow f(l+1,r-1)$$

---

### ③ 分治

最大值、平均值：

$$f(l,r)\rightarrow f(l,mid),f(mid+1,r)$$

---

### ④ 做选择 → 递归 → 撤销选择

全排列：

```text
选择一个字符放当前位置
        ↓
递归处理剩余位置
        ↓
撤销选择
        ↓
选择下一个字符
```



我的解答
### 1.
```c++
int HammingWeightRec(int n){
    if(n == 0){
        return 0;
    }

    return HammingWeightRec(n >> 1) + (n & 1);
}
```

### 2.
```java
//全排列：确定第 low 个位置放谁 → 把候选字符换到 low → 递归确定 low+1 → 递归回来后换回来。
public void permute(String str){
    permute(str.toCharArray() , 0 , str.length() - 1);
}

public void permute(char[] str , int low, int high){
    if(low == high) {
        System.out.println(str);
        return;
    }

    for(int i = low ; i <= high ; i++){
        int tmp = str[low];
        str[low] = str[i];
        str[i] = tmp;
        permute(str , low + 1 , high);
        str[i] = str[low];
        str[low] = tmp;
    }
}
```

### 3. 1
```java
public int MaxRec(int[] a, int left, int right){
    if(left == right) return a[left];

    int mid = left + (right - left) / 2;
    return Math.max(MaxRec(a , left , mid) , MaxRec(a , mid+1 , right));
}
```

### 3. 2

写法一：有点多余
```java
public double AverageRec(int[] a , int left ,int right){
    if(left == right) return (double)a[left];

    int mid = left + (right - left) / 2;
    return ((mid - left + 1) * AverageRec(a , left , mid) + (right - mid) * AverageRec(a , mid + 1 , right)) / (right - left + 1);
}
```

写法二：简单一些,但需要在递归外操作一次，不知道符不符合要求
```java
public int SumRec(int[] a , int left ,int right){
    if(left == right) return a[left];

    int mid = left + (right - left) / 2;
    return (SumRec(a , left , mid) + SumRec(a , mid + 1 , right));
}

public double AverageRec(int[] a , int left , int right){
    return (double)SumRec( a , left , right) / (right - left);
}
```
### 4.
```java
public int LinkedListLenRec(Node<E> node ){
    if(node == null) return 0; //注意null是小写的，在java中

    return LinkedListLenRec(node.next) + 1; //node.next也可能是node.next()，看具体类型
}
```

### 5. 1
```java
boolean PalindromesTestRec( char[]str , int left , int right ){
    if(left >= right) return true;

    if(str[left] != str[right]) return false;

    return PalindromesTestRec(str , left + 1 , right - 1);
}
```
### 5. 2
```java
boolean PalindromesTestRec(char[] str , int left ,int right){
    if(left >= right) return true;

    while(left < right && !Character.isLetterOrDigit(str[left])){ //注意isDigit()不是字符和数字都包括的，数字和字符要写成isLetterOrDigit
        left ++;
    }
    while(left < right && !Character.isLetterOrDigit(str[right])){
        right--;
    }

    if(Character.toLowerCase(str[left]) != Character.toLowerCase(str[right])){
        return false;
    }
    return PalindromesTestRec(str , left + 1 , right - 1);
}
```








#### 实习题：

1. **找出从自然数 $1, 2, \dots, n$ 中任取 $r$ 个数的顺序所有组合，编一个递归算法。**
**例子：$n = 5$**
**$r = 3$**
```text
1 2 3 4 5
5 4 3
5 4 2
5 4 1
5 3 2
5 3 1
5 2 1
4 3 2
4 3 1
4 2 1
3 2 1

```


思路：不是全排列的截断，而是组合，是不一样的

```java

调用
Combine(n - 1 , r , new ArrayList<Integer>());
void Combine(int cur ,  int r , ArrayList<Integer> array){
    if(array.size() == r){
        for(int x: array){
            System.out.print(x + " ");
        }
        System.out.println(" ");
    }

    for(int i = cur ; i >= 1 ; i--){
        array.add(i);
        Combine(cur - 1 , r , array);
        array.remove(array.size() - 1); //当前array种最后一位而不是cur
    }
}
```


2. **实现Hanoi塔**
```java
int HanoiRec(int n){
    if(n == 1) return 1;

    return HanoiRec(n - 1) * 2  + 1;
}
```
