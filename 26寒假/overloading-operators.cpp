 /** 重载运算符
  */


//part1 : 普通重载

返回值 operator<具体的operator符号>(需要的参数类型) {  /* 具体实现*/  }


//part2 :自增自减重载

/**
    踩坑的地方 c++的指针和java的引用还是不一样的，在this这里除了差错
    java类中的this是当前对象的引用，不存在解引用等
    c++中的this是指向当前对象的指针，通过this访问当前对象的成员变量需要this -> x;得到当前变量需要 *this
    c++中的this存放的是当前对象的地址，*this可通过访问当前对象地址得到当前的对象


    首先，需要明确一个符号 & 
    在c++中，该符号被用在两个完全不相关的领域：
    1）取地址符号：&variable 表示获取该var的内存地址
    2）标记别名：MyInt& b = a ,b只是a的一个别名，b和a在任何意义上都等价，修改b.x相当于修改a.x

    下面的重载运算符中， ++a 为什么使用的是MyInt&呢？
    *this 返回的是对象本身，是MyInt类型的俄，返回值规定的是MyInt&是引用类型的，不会做副本拷贝，直接传递，
    如果用MyInt&接受，直接得到的就是实际的对象本身
    如果用MyInt接受，因为参数传递实际上是值拷贝传递，所以得到的不是对象本身，只是一个值一样的副本

    而a++则需要的只是副本，因为实际这句表达式之后，拥有旧值的副本本身就失去了作用，所以直接值拷贝就可以
    

 */


struct MyInt {
    int x;
    //自增
    //++a;

    MyInt& operator++() {
        x++;
        return *this;
    }
    //a++;
    /**这里a++传入一个int参数，是为了区分两种重载的不同，实际上的int是在编译的过程中自动填入的，一般为0值
     */
    MyInt operator++(int) {
        MyInt tmp;
        tmp.x=x;
        x++;
        return tmp;
    }

    //practice :自减
    //a--;
    MyInt operator--(int) {
        MyInt tmp = *this; //旧值拷贝？
        x--;
        return tmp;
    }
    //--a
    MyInt& operator--() {
        x--;
        return *this;
    }

}

//part3 : 函数调用符重载
/**
就是将符号（）重载，但这种重载只能作为成员函数，重载后，该类的对象可以像函数一样被调用。
最常见的应用是，在结构体中重载函数调用符，重载的函数体中主要比较两个成员的优先级，将该结构体作为comparator使用
> oi.wiki的原话是：将重载了 () 运算符的结构体作为自定义比较函数传入优先队列等 STL 容器中．
*/

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
}

priority_queue<int, vector<int>, cmp> pq;


//part4 : 比较运算符重载 >/<


