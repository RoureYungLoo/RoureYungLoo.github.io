# C字符和字符串

## 本章大纲

- 字符和字符串基础
- 字符处理
- 字符串转换
- 标准输入输出函数
- 字符串处理
- 字符比较
- 字符查找
- 内存处理函数
- 其他字符处理

## 字符和字符串基础

### 字符

在C语言程序中，用一对单引号括起来的**一个**字符是一个字符常量，即一个字符。字符常量实际上是一个整数，它的数值等于它在ASCII码表中对应的值。

### 字符串

在C语言程序中，用一对双引号括起来的**一串**字符是一个字符串常量，即一个字符串。字符串是通过**字符数组**来实现的；所有表示字符串的字符数组的最后一个元素都是空字符串（`'\0'`）.

访问字符串即访问表示它的字符数组的第一个字符的地址。

C语言中的字符串就是指向字符数组首个元素的的指针，即指向一个字符数组的指针，或者说一个字符数组就是一个字符串。

字符数组或char*类型的变量可以用字符串来初始化。

声明并初始化一个字符串：

```c++
#include<stdio.h>

int main (){
    char color[] = "blue";
    char* ptr_color = "red";
    char yell[] = {'y','e','l','l','o','w','\0','a','b','c'};
    char* yellptr = {'y','e','l','l','o','w','\0'};
    
    for (size_t i = 0; i < 5; i++){
        printf("%c %d\n",color[i],color[i]);
    }

    for (size_t i = 0; i < 4; i++){
        printf("%c %d\n",ptr_color[i],ptr_color[i]);
    }

    printf("%s\n",yell); // yellow
    // printf("%c",*yellptr); //Segmentation fault      (core dumped)
    // printf("%c",yellptr); //Segmentation fault      (core dumped)
    
    char word[20];
    scanf("%19s",word);
    printf("%s\n",word);
    return 0;
}
```

## 字符处理函数库

```c
#include<ctype.h>
int isblank(int c);
int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int islower(int c);
int isupper(int c);
int tolower(int c);
int toupper(int c);
int isspace(int c);
int iscntrl(int c);
int ispunct(int c);
int isprint(int c);
int isgraph(int c);
```

## 字符串转换函数

```c
#include<stdlib.h>
double strtod(const char* n_ptr,char ** end_ptr);
long strtol(const char * n_ptr,char ** end_ptr,int base);
unsinged long strtoul(const char * n_ptr,char ** end_ptr,int base);
```

## 标准输入输出函数

```c
#include<stdio.h>
int getchar(void);
char * fgets(char* s,int n, FILE* stream);
int putchar(int c);
int puts(const char *s);
int sprintf(cahr* s,const char * format,...);
int sscanf(char * s,const char* format,...)
```

## 字符串处理函数



## 本章小结

- 字符和字符串基础
- 字符处理
- 字符串转换
- 标准输入输出函数
- 字符串处理
- 字符比较
- 字符查找
- 内存处理函数
- 其他字符处理