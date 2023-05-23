---
comments: true
---

# C++多态性

## 本章大纲

- 复制兼容
- 多态概念
- 虚函数
- 虚析构函数
- 抽象类和纯虚函数
- 强制转换

## 赋值兼容

赋值兼容规则：可以将<strong style="color:red">公有</strong>派生类对象赋值给基类对象，反之是不允许的。

![图1.赋值兼容](../../assets/images/ch21/01.png)

结果：将派生类对象中从基类继承来的成员赋给基类对象。

```cpp
#include <iostream>
using namespace std;
class Point {
 protected:
  int x, y;  // 保护成员
 public:
  Point(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
  void Show() { cout << "point(" << x << "," << y << ")\n"; }
};
class Line : public Point  // 公有继承
{
 protected:
  int x1, y1;

 public:
  Line(int a, int b, int c, int d)
      : Point(a, b)  // 调用基类构造函数
  {
    x1 = c;
    y1 = d;
  }
};
int main() {
  Line line(2, 2, 6, 6);
  Point p;
  p = line;  // A
  p.Show();
  return 0;
}
//输出：
point(2,2)
```

赋值兼容要点：

1. 派生类对象可以赋值给基类对象，系统将派生类对象中从基类继承来的成员赋给基类对象
2. 不能将基类对象赋值给派生类对象
3. **私有或保护继承**的派生类对象，不可以赋值给基类对象。
4. 可将派生类对象的地址赋给基类指针变量。例 `Point *ptr = &line;`

5. **派生类对象可初始化基类的引用**。例如 `Point &refp = line;`
6. 在后两种情况下，使用基类指针或引用时，只能访问<strong style="color:red">从相应基类中继承</strong>来的成员，而不允许访问<strong style="color:red">其他基类成员或派生类中增加</strong>的成员。

## 多态概念

多态性是指发出<strong style="color:red">同样的消息</strong>被<strong style="color:red">不同</strong>类型的<strong style="color:red">对象</strong>接收时有可能导致完全<strong style="color:red">不同的行为</strong>。

### 多态的实现

在C++程序设计中， 多态的实现

- **函数重载**
- **运算符重载**
- **虚函数**

### 多态分类

#### 编译时多态

在程序编译时系统就能决定调用的是哪个函数。

- 函数重载

- 运算符重载

#### 运行时多态

- **通过继承关系和虚函数来实现。**

- 在程序执行前，无法根据函数名和参数来确定该调用哪一个函数，必须在程序执行过程中，根据执行的具体情况来动态地确定。

### 类继承层次中指针和对象之间的关系

基类指针、派生类指针、基类对象、派生类对象 之间的4种关系：

- 直接用基类指针指向基类对象
- 直接用派生类指针指向派生类对象
- 派生类对象给基类指针赋值（基指针指向派对象）
- 基类对象给派生类指针赋值。(编译会出错）

![图2.类继承关系](../../assets/images/ch21/02.png)