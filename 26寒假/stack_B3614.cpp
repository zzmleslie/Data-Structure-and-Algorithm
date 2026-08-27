#include <stack>
#include <string>
#include <iostream>

int main() {
    std::cin.tie(0);
    //默认行为：cin和cout是"tie"在一起的，这意味着在执行cin之前，cout的缓冲区会自动刷新（flush）
    //作用：cin.tie(0)解除了cin和cout的关联
    //好处：减少不必要的缓冲区刷新，提高输入效率
    std::ios::sync_with_stdio(false);
    //默认行为：C++的iostream和C的stdio是同步的，以便可以混合使用cin/cout和scanf/printf
    //作用：关闭这种同步 显著提高cin/cout的速度
    int T, n;
    for (std::cin >> T; T; --T) {
        std::stack<unsigned long long int> s;
        for (std::cin >> n; n; --n) {
            std::string t;
            std::cin >> t;
            if (t == "push") {
                unsigned long long x;
                std::cin >> x;
                 s.push(x);
            } 
            else if (t == "pop") {
                if (s.empty())
                    std::cout << "Empty\n";
                else s.pop();
            } 
            else if (t == "query") {
                if (s.empty()) 
                    std::cout << "Anguei!\n";
                else std::cout << s.top() << '\n';
            } 
            else {
                std::cout << s.size() << '\n';
            }
		}
	}
  return 0;
}
