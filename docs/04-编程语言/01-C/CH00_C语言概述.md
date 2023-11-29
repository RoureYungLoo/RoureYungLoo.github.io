# 什么是C语言？

## 本章大纲

程序是什么？

1. 程序又叫软件，最常见的就是手机APP和电脑软件，不常见的有服务器软件、嵌入式软件、穿戴设备软件。

2. 程序可以看作是数据和逻辑的组合
3. 为了让计算机执行某些操作或解决某个问题而编写的一系列有序指令的集合

C语言之父、UNIX之父——丹尼斯·里奇（`Dennis Ritchie`），`1941-2011`

![Dennis Ritchie](./img/ch00-dennis.png)

C语言的诞生与UNIX操作系统密不可分。

`ANSI`，[American National Standards Institute](https://www.ansi.org/)，美国国家标准学会

`ISO`，[International Organization for Standardization](https://www.iso.org/)，国际化标准组织

**C语言发展历程**

1. `1972.11`  `C`语言诞生
2. `1978.11`  贝尔实验室正式发布`C`语言
3. `1983`  `ANSI`开始制定`C`语言标准
4. `1989.12`  `ANSI`完成标准的制定
5. `1990.9`  `ANSI`被`ISO`采纳为国际标准
6. `1999.8`  `ISO`发布`C99`标准

**C语言的特点**

1. 代码级别的跨平台
2. 允许直接访问物理地址，对硬件进行操作。（操作系统、数据库、杀毒软件、防火墙、驱动程序、服务器程序）
3. 面向过程
4. 传参方式：按值传递、传递指针
5. 没有对象
6. 预编译处理，代码质量高，执行效率高

**开发工具**

- `Visual Studio Code & Visual Studio Community`
- `Code::Blocks`
- `DEV C++`
- `Visual C++2010 Express`
- `JetBrains CLion`
- `Source Insight 4`
- `Eclipse`

**C程序运行机制简述**

1. **编辑**：源代码，`.c`文件
2. **编译**：`.c`　-->　`.obj`
3. **链接**：（`.obj`＋`libxxx.so/a`）--> 可执行文件
4. **运行**：运行可执行文件