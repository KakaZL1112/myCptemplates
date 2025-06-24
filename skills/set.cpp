#include <iostream>
#include <set>

//set 中查找距离
int main() {
    std::set<int> s = {10, 20, 30, 40, 50};
    
    // 查找元素30的位置
    auto it = s.find(30);
    if (it != s.end()) {
        size_t position = std::distance(s.begin(), it);
        std::cout << "元素30的位置索引是: " << position << std::endl;  // 输出: 2
    }
    
    return 0;
}