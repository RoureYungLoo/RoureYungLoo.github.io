# C语言指针

## 本章大纲

## 函数指针

- 数组名  != &数组名：`arr!=&arr;`
- 函数名 = &函数名：`func=&func;`

### 声明

```cpp
返回值类型 ( * 指针变量名) ( 形参列表 ); 
int func(int a,double b);//声明函数
int (*ptr) (int a,double b);//声明函数指针
```

#### 声明简化

```cpp
typedef int (*type_ptr) (int a,double b);
//声明函数指针数据类型，类型名为type_ptr
type_ptr ptr1,ptr2,ptrn;
ptr1=func;
ptr2=func
```

### 赋值

```cpp
ptr=func;//函数指针赋值方式1
ptr=&func;//函数指针赋值方式2
```

### 调用

```cpp
ptr(10,10.5);//函数指针调用
(*ptr)(10,10.5);//函数指针调用
```

### 应用场景

1. 回调函数
2. 线程