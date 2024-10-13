## hash的使用
1. 包含在头文件 functional
```
#include <functional>
```
2. hash是模板, 类似STL, 需要实例化
```
// 创建哈希对象(用于哈希计算)
hash<string> hasher;
// 使用哈希对象, 计算传入对象的哈希值
size_t hashVal = hash(obj);
```
3. 可以创建临时对象
```
// hash<string>()创建临时哈希对象
// ()是默认构造函数调用 生成一个实例
// (obj)是对临时哈希对象的调用
size_t hashVal = hash<string>()(obj);
```