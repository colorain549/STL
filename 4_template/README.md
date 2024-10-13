## 练习模版

1. vector(适用随机访问)
* 基于数组 维护三个信息 数组T *_elements 大小_size 容量_capacity 

2. list(适用插入删除)
* 基于双向链表

3. deque(适用随机访问, 双端插入删除)
* 基于循环数组, 即一个一维数组(连续存储区域)
* 基于一个或多个一维数组(连续存储区域)

4. HashTable(适用无序关联容器)
* 

5. RedBlackTree(适用有序关联容器)
* 

6. set(唯一, 有序)
* 基于红黑树

7. unordered_set(唯一, 无序)
* 基于哈希表

8. multiset(不唯一, 有序)
* 基于红黑树

9. map(键唯一, 自动排序)
* 基于红黑树

10. unordered_map(键唯一, 无序)
* 基于哈希表

11. multimap(键不唯一, 自动排序)
* 基于红黑树

12. stack(FILO)
* 基于双端队列deque, list
* 基于双端队列deque

13. queue(FIFO)
* 基于双端队列deque, list 和 vector
* 基于双端队列deque

14. priorit_queue
* 底层是堆, 基于vector 