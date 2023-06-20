# Lua编程语言

[TOC]

# 安装

```bash
curl -R -O http://www.lua.org/ftp/lua-5.3.0.tar.gz
tar -zxvf lua-5.3.0.tar.gz
cd lua-5.3.0/
sudo apt install gcc make libreadline-dev
sudo make linux test
sudo make install
```

# 语法

交互式编程

脚本式编程

## 注释

## 标识符

- 由字母(A...Za...z)、数字(0...9)、下划线(_)组成，不能以数字开头。
- 不能出现`@`、`$`、`%`，大小写敏感。

## 保留字

由下划线+大写字母组成。

一般约定，以下划线开头连接一串大写字母的名字（比如 _VERSION）被保留用于 Lua 内部全局变量。

## 关键字

```bash
and			break	do		else
elseif		end		false	for
function	if		in		local
nil			not		or		repeat
return		then	true	until
while		goto
```

## 全局变量

默认，变量是全局变量。

### 删除全局变量

赋值为`nil`即可。

当一个变量不等于`nil`时，这个变量即存在。

## 数据类型

- Lua 是动态类型语言，变量不要类型定义,只需要为变量赋值。 
- 值可以存储在变量中，作为参数传递或结果返回。

Lua 中有 8 个基本类型分别为：nil、boolean、number、string、userdata、function、thread 和 table。

- nil：无效值，在条件表达式中相当于false
- boolean：true、false
- number：双精度类型的实浮点数
- string：字符串，由一对双引号或单引号来表示
- function：由C或lua编写的函数
- userdata：表示任意存储在变量中的C数据结构
- thread：表示执行的独立线路，用于执行协同程序
- table：表，其实是“关联数组”，数组的索引可以是**数字**、**字符串**或**表类型**。在 Lua 里，table 的创建是通过"构造表达式"来完成，最简单构造表达式是{}，用来创建一个空表。

### nil

- “删除“作用
- 比较时用`=="nil"`

### boolean

- true：其余的
- false：false、nil

### number

### string

- 使用双引号、单引号、[[ ]]表示字符串
- 对字符串进行算术操作，字符串会被转为数字
- 字符串连接使用`..`
- 计算字符串长度使用`#`

### table

- Lua 中的表（table）其实是一个"关联数组"（associative arrays），数组的索引可以是**数字**或者是**字符串**。
- 在 Lua 里表的默认初始索引一般以 1 开始。
- table 不会固定长度大小，有新数据添加时 table 长度会自动增长，没初始的 table 都是 nil。

### function

- 在 Lua 中，函数是被看作是"第一类值（First-Class Value）"，函数可以存在变量里。
- function 可以以匿名函数（anonymous function）的方式通过参数传递

### thread

- 在 Lua 里，最主要的线程是协同程序（coroutine）。它跟线程（thread）差不多，拥有自己独立的栈、局部变量和指令指针，可以跟其他协同程序共享全局变量和其他大部分东西。
- 线程跟协程的区别：**线程可以同时多个运行，而协程任意时刻只能运行一个**，并且**处于运行状态的协程只有被挂起（suspend）时才会暂停。**

### userdata

自定义类型。用于表示一种由应用程序或 C/C++ 语言库所创建的类型，可以将任意 C/C++ 的任意数据类型的数据（通常是 struct 和 指针）存储到 Lua 变量中调用。