## 拷贝、赋值与销毁

## 拷贝构造函数(Page 440)
* 构造函数的第一个参数是'自身类'类型的引用...则此构造函数是拷贝构造函数
```
class Vector {
public:
    // 构造函数
    Vector(){}
    // 拷贝构造函数
    Vector(const Vector& other){}
}
```

## 拷贝初始化(Page 441)
* 直接初始化
使用函数匹配(参考函数重载)
```
string dots(10, '.');
```

* 拷贝初始化
将右侧运算对象拷贝到正在创建的对象中
```
string s2 = dots;
```

* 拷贝初始化依靠
1. 拷贝构造函数
2. 或移动构造函数(Page 473)

## 拷贝构造函数发生时机(Page 441)
1. 用=定义变量时
2. 将一个对象作为实参传递给一个非引用类型的形参
```
class Person{
public:
    void display(){ cout<<name<<" "<<age<<endl; }
private:
    string name;
    int age;
};

void printMsg(Person p){
    p.display();
}

Person person("Amy", 10);
person.printMsg(person);
```
3. 从一个返回类型为非引用类型的函数返回一个对象
```
class Person{
public:
    void display(){ cout<<name<<" "<<age<<endl; }
private:
    string name;
    int age;
};

Person createPerson(){
    Person tempObj("Amy", 10);
    return tempObj;
}

Person person = createPerson();
person.display();
```
4. 用{}列表初始化一个数组中的元素或一个聚合类中的成员
```
class Data {
public:
    int val;
    string s;
};
Data data1 = {1, "Anna"};
```
## 拷贝赋值运算符(Page 443)
* 名为operator=的函数
```
class Vector {
public:
    Vector operator=(const Vector& other){
        if(this != other){}
    }
}
```

## 析构函数(Page 445)
* 构造函数初始化非static数据成员
* 析构函数销毁对象的非static数据成员
* 析构函数不接受参数, 因此它不能被重载(!!!)
* 析构函数释放对象在生存期分配的所有资源

## 析构函数发生时机
* 对象被销毁时自动调用

## 标准库move函数(Page 469)
* 定义在utility头文件中
* 通常不为move提供一个using声明
* 使用move时, 直接调用std::move而不是move

## 对象移动(Page 470)
* 从旧内存将元素拷贝到新内存是不必要的, 更好的方式是移动元素
* 如果对象较大, 或者是对象本身要求分配内存空间

## 右值引用(Page 471)
* 左值(!!!记住!!!)
1. 赋值( int i = 42, 42是左值 )
2. 下标( string s("hi"); s[0]是左值 )
3. 解引用 ( *(&i) 是左值 )
4. 前置递增递减( ++i和 --i 是左值)

* 右值
1. 算数( i * 42 是右值 )
2. 关系( a && b 是右值 )
3. 位运算( int i2 = 1024; i2 >> 2是右值 )
4. 后置递增递减( i++和 i-- 是左值)

## 标准库move函数(Page 572)
* 将左值转换为右值引用类型

## 移动构造函数和移动赋值函数


