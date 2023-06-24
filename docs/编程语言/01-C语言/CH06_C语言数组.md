# C语言数组

## 本章大纲

 * 用数组结构来表示一维和二维数据表
 * 数组的定义、初始化和访问
 * 数组的排序、数组元素的查询
 * 多维数组简介

#### 数组

一组具有相同数据类型的数据的有序集合。

 * 数组是由相同数据类型的相关联的数据组成的一种数据结构
 * 其它的数据结构 ：结构体，链表，队列，堆栈和树等


 数组是一组相关联的存储单元。所谓“相关联”就是指它们具有相同的名字和相同的数据类型。若要访问数组中某个特定的存储单元或数组元素，需要指定数组的名称及该元素在数组中的位置号。

运算符[ ]的优先级：最高，与( )相同

#### 数组的定义

指定数据类型和元素个数

```cpp
int c[12];
double score[40];
char str[20];
```

##### 一维数组的定义格式

```c
// 数据类型  数组名[常量表达式];
int a[10];//定义了一个整型数组，数组名为a，此数组有10个元素。
```

1、数组名定名规则和变量名相同，遵循标识符定名规则。
2、在定义数组时，需要指定数组中元素的个数，方括弧中的常量表达式用来表示元素的个数，即数组长度。
3、常量表达式中可以包括常量和符号常量，但不能包含变量。也就是说，C语言不允许对数组的大小作动态定义，即数组的大小不依赖于程序运行过程中变量的值。

```c
int n,m;
scanf("%d %d"，&n,&m); /*在程序中临时输入数组的大小 */
int a[n][m];
```

##### 数组说明中其他常见的错误

1、float a[0];   数组大小为0没有意义
2、int b(2)(3);  不能使用圆括号 
3、int k, a[k];   不能用变量说明数组大小

##### 一维数组在内存中的存放

`float mark[100];`

![img](./img/ch06-01.png)

每个数据元素占用的字节数，是基本类型的字节数，一个元素占4个字节。

##### 一维数组元素的引用

`数组名[下标]`
定义数组时用到的`数组名[常量表达式]” `和引用数组元素时用到的`数组名[下标]”` 是有区别的

##### 定义一个数组并初始化

1、使用for循环

```c
#include <stdio.h>
int main() {
  int m[10];
  int i;
  for (i = 0; i < 10; i++) {
    m[i] = 0;
  }
  printf("%s%13s", "Element", "Value\n");
  for (i = 0; i < 10; i++) {
    printf("%7d%13d\n", i, m[i]);
  }
  return 0;
}
```

2、使用初始化列表

```c
#include <stdio.h>
int main() {
  int m[10]={32,43,12,54,15,17,43,21,18,29};
  int i;
  printf("%s%13s", "Element", "Value\n");
  for (i = 0; i < 10; i++) {
    printf("%7d%13d\n", i, m[i]);
  }
  return 0;
}

//int a［10］={0,1,2,3,4,5,6,7,8,9};
int a［10］={0，1，2，3，4};   
int a［10］={0,0,0,0,0,0,0,0,0,0};
int a［10］={0};
int a［5］={1，2，3，4，5};
int a［］={1，2，3，4，5};  
int a［10］={1，2，3，4，5}; // 只初始化前5个元素，后5个元素为0
```

##### 已知数组长度

* 
  初始化为0

  - 全部: `int a[10]={0,0,0,0,0,0,0,0,0,0};`或者`int a[10]={0};`	

    * 部分: `int a［10］={1，2，3，4，5};`

* 初始化为具体值

  - 全部：`int a［10］={0,1,2,3,4,5,6,7,8,9};`
  - 
    部分：`int a［10］={0，1，2，3，4};   //剩余元素为0`

##### 未指定数组长度：对全部数组元素赋初值

* `int a［5］={1，2，3，4，5};`
* `int a［］={1，2，3，4，5};  `

#### 用符号常量来定义数组的大小并通过计算来初始化数组元素

```c
#include <stdio.h>
#define SIZE 10
int main() {
  int arr[SIZE];
  int i;
  printf("%s%13s", "Element", "Value\n");
  for (i = 0; i < SIZE; i++) {
    arr[i] = 2 + 2 * i;
  }
  printf("%s%13s", "Element", "Value\n");
  for (i = 0; i < 10; i++) {
    printf("%7d%13d\n", i, arr[i]);
  }
  return 0;
}
```

##### 定义符号常量

* `#define  SIZE  10`
* 
  在编译前的预处理时将标识符“SIZE”用文本“10”替换掉
* 
  优点 ：使用符号常量可使程序更易于扩展。
* 
  若符号常量包含多个单词，应使用下划线加以分割。
  - `#define STUDENT_AMOUNT 20`

#### 计算数组元素的总和

```c
#include <stdio.h>
#define SIZE 12
int main() {
  int arr[SIZE] = {1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45};
  int i, total = 0;
  for (i = 0; i < SIZE; i++) {
    total += arr[i];
  }
  printf("Total of array element values is %d\n", total);
  return 0;
}
```

##### 问题举例：

40名学生被邀请来给学生食堂中饭菜的质量打分，分数的范围是1到10分（1分表示非常糟糕，10分表示非常满意）。这些学生打出的分数存储在一个整型数组中，请统计这次调查的结果。

```c
#include <stdio.h>
#define RESPONSE_SIZE 40
#define FREQUENCY_SIZE 11
int main() {
  int answer;
  int rating;
  int j;
  int frequency[FREQUENCY_SIZE] = {0};
  int responses[RESPONSE_SIZE] = {
    1, 2,  6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8,
    6, 10, 3, 8, 2, 7, 6, 5, 7, 6,  8, 6, 7, 5,
    6, 6,  5, 6, 7, 5, 6, 4, 8, 6,  8, 10};
  for (answer = 0; answer < RESPONSE_SIZE; answer++) {
     frequency[responses[answer]]=frequency[responses[answer]]+1;
  }
  printf("%s%17s\n", "Rating", "Frequency");
  for (rating = 1; rating < FREQUENCY_SIZE; rating++) {
    printf("%6d%17d\n", rating, frequency[rating]);
  }
  return 0;
}
```

##### 使用直方图

```c
#include <stdio.h>
#define SIZE 10

int main() {
  int n[SIZE] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
  int i;
  int j;
  printf("%s%13s%17s\n", "Element", "Value", "Histogram");
  for (i = 0; i < SIZE; i++) {
    printf("%7d%13d    ", i, n[i]);
    for (j = 1; j <= n[i]; j++) {
      printf("%s", "■");
    }
    printf("\n");
  }
  return 0;
}
```

#### 用数组统计掷骰子结果

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7

int main() {
  int face; /* 1-6  */
  int roll; /* 1-6000 */
  int frequency[SIZE] = {0};
  srand(time(NULL));
  for (roll = 1; roll <= 6000; roll++) {
    face = 1 + rand() % 6;
    ++frequency[face];
  }
  printf("%s%17s\n", "Face", "Frequency");
  for (face = 1; face < SIZE; face++) {
    printf("%4d%17d\n", face, frequency[face]);
  }
  return 0;
}
```

##### 用字符数组来实现字符串处理

- 定义及初始化 ：`char string1[] = { 'f', 'i', 'r', 's', 't', '\0' };`
- 字符数组可以用一个字符串来初始化: `char string1[] = "first";`
  实际存储：first\0
  该字符数组大小为 5 + 1 = 6     

- 通过字符数组输入、输出字符串 ：

- ```c
  char string2[20];
  scanf( "%s", string2 );
  // 接收一个字符序列，直到遇到空格键、Tab键、换行符或文件结束符EOF为止。
  printf( "%s", string2 );
  ```

  

#### 用字符数组处理字符串

```c
#include <stdio.h>
int main() {
  char string1[20];
  char string2[] = "string literal";
  int i;
  printf("Enter a string: ");
  scanf("%s", string1);
  printf(
      "string1 is \"%s\"\nstring2 is \"%s\"\n"
      "string1 with spaces between characters is:\n",
      string1, string2);
  printf("\"");
  for (i = 0; string1[i] != '\0'; i++) {
    printf("%c ", string1[i]);
  }
  printf("\"");
  printf("\n");
  return 0;
}
```

#### 静态和自动局部数组

```c
#include <stdio.h>
void staticArrayInit(void);
void automaticArrayInit(void);
int main() {
  printf("First call to each function:\n");
  staticArrayInit();
  automaticArrayInit();
  printf("\n\nSecond call to each function :\n");
  staticArrayInit();
  automaticArrayInit();
  return 0;
}
void staticArrayInit(void) {
  static int array1[3];
  int i;
  printf("\nValue on entering staticArrayInit:\n");
  for (i = 0; i <= 2; i++) {
    printf("array1[ %d ] = %d, ", i, array1[i]);
  }
  printf("\nValue on exiting staticArrayInit:\n");
  for (i = 0; i <= 2; i++) {
    printf("array1[ %d ] = %d, ", i, array1[i] += 5);
  }
}
void automaticArrayInit(void) {
  int array2[3] = {1, 2, 3};
  int i;
  printf("\n\nValue on entering automaticArrayInit:\n");
  for (i = 0; i <= 2; i++) {
    printf("array2[ %d ] =%d, ", i, array2[i]);
  }
  printf("\nValue on exiting automaticArrayInit:\n");
  for (i = 0; i <= 2; i++) {
    printf("array2[ %d ] = %d, ", i, array2[i] += 5);
  }
}
```

#### 数组和函数

传参数两种情况：

- 某个数组元素作函数实参
- 整个数组作函数实参

##### 1、某个数组元素作函数实参

单项传递，即“值传递”

```c
void aa(int a,int b);
int f[2]={5,6};
aa(f[0],f[1]);
```

##### 2、整个数组作函数实参：

传递地址 ：出于性能方面考虑，减少数据传递量。

```c
int  hourly [ 24 ];
int  modifyArray( int b[], int size);
modifyArray(hourly, 24)；
```

用数组名作函数参数时，此时实参应当用**数组名**或用**指针变量** 。

##### 3、数组传递和值传递的不同：

```c
#include <stdio.h>
#define SIZE 5
void modifyArray(int b[], int size);
void modifyElement(int e);
int main() {
  int a[SIZE] = {0, 1, 2, 3, 4};
  int i;
  printf(
      "Effects of passing entire array by reference \n\nThe"
      "values of the original array  are:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%3d", a[i]);
  }
  printf("\n");
  modifyArray(a, SIZE);
  printf("The Values of the modified array are:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%3d ", a[i]);
  }
  printf(
      "\n\n\nEffects of passing array element "
      "by value:\n\nThe value of a[3] is %d\n",
      a[3]);
  modifyElement(a[3]);
  printf("The value of  a[ 3 ] is %d\n", a[3]);
  return 0;
}
void modifyArray(int b[], int size) {
  int j;
  for (j = 0; j < size; j++) {
    b[j] *= 2;
  }
}
void modifyElement(int e) { printf("Value in modifyElement is %d\n", e *= 2); }
```

##### 4、禁止修改实参数组元素值

```c
#include <stdio.h>

void tryToModifyArray(const int b[]);

int main() {
  int a[] = {10, 20, 30};
  tryToModifyArray(a);
  printf("%d %d %d\n", a[0], a[1], a[2]);
  return 0;
}
void tryToModifyArray(const int b[]) {
  b[0] /= 2; /*error */
  b[1] /= 2; /*error */
  b[2] /= 2; /*error */
}
```

#### 数组元素的排序

- 排序 ：将数据按照特定的顺序排列，如升序或降序。
  - 通常需要对大量的数据进行排序
  - 排序方法 ：选择法，冒泡法（起泡、沉降法）等，

##### 用起泡排序法对数组元素进行升序排序

```c

int b[8]={38,49,65,97,76,13,27,52};
```

对N个数排序
*    共比较 (N-1)轮次
*    第 j 轮次两两比较 (N-j) 次（这是轮次从1开始，从0开始N-1-j）

```c
#include <stdio.h>
int main() {
  const int N = 8;
  int a[N], j, i;
  //逐个输入数组a元素
  for (j = 0; j < N - 1; j++)        // N个元素共比较(N-1)轮
    for (i = 0; i < N - 1 - j; i++)  //第j轮比较(N-1-j)次
      if (a[i] > a[i + 1]) {         //交换
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
  //输出排序后的数组a
  return 0;
}
```

