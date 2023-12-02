# C语言数组

## 本章大纲

 * 用数组结构来表示一维和二维数据表
 * 数组的定义、初始化和访问
 * 数组的排序、数组元素的查询
 * 多维数组简介

## 数组

一组具有相同数据类型的数据的有序集合。

 * 数组是由相同数据类型的相关联的数据组成的一种数据结构
 * 其它的数据结构 ：结构体，链表，队列，堆栈和树等


 数组是一组相关联的存储单元。所谓“相关联”就是指它们具有相同的名字和相同的数据类型。若要访问数组中某个特定的存储单元或数组元素，需要指定数组的名称及该元素在数组中的位置号。

运算符[ ]的优先级：最高，与( )相同

## 数组的定义

指定数据类型和元素个数

```cpp
int c[12];
double score[40];
char str[20];
```

### 一维数组的定义格式

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

### 数组说明中其他常见的错误

1、float a[0];   数组大小为0没有意义
2、int b(2)(3);  不能使用圆括号 
3、int k, a[k];   不能用变量说明数组大小

### 一维数组在内存中的存放

`float mark[100];`

![img](./img/ch06-01.png)

每个数据元素占用的字节数，是基本类型的字节数，一个元素占4个字节。

### 一维数组元素的引用

`数组名[下标]`
定义数组时用到的`数组名[常量表达式]” `和引用数组元素时用到的`数组名[下标]”` 是有区别的

### 定义一个数组并初始化

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

### 已知数组长度

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

### 用符号常量来定义数组的大小并通过计算来初始化数组元素

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

### 计算数组元素的总和

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

### 用数组统计掷骰子结果

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

### 静态和自动局部数组

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

### 数组和函数

传参数两种情况：

- 某个数组元素作函数实参
- 整个数组作函数实参

#### 1、某个数组元素作函数实参

单项传递，即“值传递”

```c
void aa(int a,int b);
int f[2]={5,6};
aa(f[0],f[1]);
```

#### 2、整个数组作函数实参：

传递地址 ：出于性能方面考虑，减少数据传递量。

```c
int  hourly [ 24 ];
int  modifyArray( int b[], int size);
modifyArray(hourly, 24)；
```

用数组名作函数参数时，此时实参应当用**数组名**或用**指针变量** 。

#### 3、数组传递和值传递的不同：

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

#### 4、禁止修改实参数组元素值

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

## 数组元素查找

线性查找: 用查找键值逐个与数组元素的值相比较以实现查找

```c
#include <stdio.h>
#define SIZE 100
int linearSearch(const int array[], int key, int size);
int main(void) {
  int a[SIZE];
  int x;         /* 0-99 */
  int searchKey; /* key */
  int element;   /* location */
  for (x = 0; x < SIZE; x++) {
    a[x] = 2 * x;
  } /* end for */
  printf("Enter integer searchkey:\n");
  scanf("% d", &searchKey);
  element = linearSearch(a, searchKey, SIZE);
  if (element != -1) {
    printf("Found value in element % d\n", element);
  } /* end if */
  else {
    printf("Value not found\n");
  } /* end else */
  return 0;
} /* end main */

int linearSearch(const int array[], int key, int size) {
  int n;
  /* loop through array */
  for (n = 0; n < size; ++n) {
    if (array[n] == key) {
      return n;
    } /* end if */
  }   /* end for */
}
```

二分查找

- 先对数组排序，再进行查找

- 算法首先选取位于数组中间的元素，将其与查找键进行比较。如果它们相等，则查找键被找到，返回该中间元素的下标。否则，将查找的范围缩小为在一半的子数组元素中查找

- 假设数组为升序排列，如果查找键的值小于数组的中间元素，则在前一半数组元素中继续查找，否则在后一半数组元素中继续查找

- 重复上述过程，直到查找键等于某个子数组的中间元素的值（找到查找键），或者子数组只包含一个不等于查找键的元素（即没有找到查找键）为止


```c
#include <stdio.h>
#define SIZE 15
/* function prototype */
int binarySearch(const int b[], int searchkey, int low, int high);
void printHeader(void);
void printRow(cousnt int b[], int low, int mid, int high);

/* function main begins program execution */
int main(void) {
  int a[SIZE];
  int i;      /* 0-14 */
  int Key;    /* key */
  int result; /* location */
  /* create data */
  for (i = 0; i < SIZE; i++) {
    a[i] = 2 * i;
  } /* end for */
  printf("Enter a number between 0 and 28:");
  scanf("%d", &Key);
  printHeader();
  /* search for key in array a */
  result = binarySearch(a, key, 0, SIZE - 1);
  /*display results */
  if (result != -1) {
    printf("\n%d found in array element %d\n ", key, result);
  } /* end if */
  else {
    printf("\n % dValue not found\n", key);
  } /* end else */

  return 0;
} /* end main */

/* function to perform binary search of an array */
int binarySearch(const int b[], int searchkey, int low, int high) {
  int middle;
  /* loop until low subscript is greater than high subscript */
  while (low <= high) {
    /* determine middle element of subscribe being searched */
    middle = (low + high) / 2;

    /* display subarray used in this loop iteraion */
    printfRow(b, low, middle, high);
    /* if searchKey matched middle element, return middle*/
    if (searchKey == b[middle]) {
      return middle;
    } /* end if */
    /* if searchKey less than middle, set new high */
    else if (searchKey < b[middle]) {
      high = middle - 1;
    } /* end else if */

    /* if searchKey greater than middle, set new low */
    else {
      low = middle + 1;
    } /* end else */
  }   /* end while */
  return -1;
} /* end binarySearch */

/* Print a header for the output */
void printHeader(void) {
  int i;
  printf("\nSubscripts :\n");

  /* output column head */
  for (i = 0; i < SIZE; i++) {
    printf("% 3d ", i);
  } /* end for */
  printf("\n");

  /* output line of - characters */
  for (i = 0; i <= 4 * SIZE; i++) {
    printf("-");
  } /* end for */
  printf("\n");
} /* end function printHeader */

/* Print one row of output showing the current part of the array being
 * processed. */
void printRow(const int b[], int low, int mid, int high) {
  int i;

  /* loop through array */
  for (i = 0; i < SIZE; i++) {
    /* display spaces if outside current subarray range */
    if (i<low ¦¦ i> high) {
      printf(" ");
    } /* end if */
    else if (i == mid) {
      printf("%3d*", b[i]);
    } /* end else if */
    else {
      printf("% 3d ", b[i]);
    } /* end else */
  }   /* end for */

  printf("\n");
} /* end printRow */
```

## 多维数组

数组可以有多个下标，称为多下标数组或多维数组

二维数组 ：具有两个下标，用来表示由按行、列组织起来的信息组成的表格

- 第一个下标确定行号
- 第二个下标确定列号
- m行n列 ：称作m乘n数组

二维数组定义

```c
//数据类型 数组名[常量表达式-行数][常量表达式-列数]
int arr[4][3];
int a[3][4];
/*
a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]
*/
int a[3][4] = {
    {-4,2,0,19}, 
    {16,-5,4,3}, 
    {8,-3,23,15} 
};
```

```c
#include <stdio.h>
void printArray(const int a[][3]);

int main(void) {
  /* initialize array1, array2, array3 */
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int array2[2][3] = {1, 2, 3, 4, 5};
  int array3[2][3] = {{1, 2}, {4}};
  printf("Values in array1 by row are :\n");
  printArray(array1);
  printf("Values in array2 by row are :\n");
  printArray(array2);
  printf("Values in array3 by row are :\n");
  printArray(array3);
  return 0;
} /* end main */

void printArray(const int a[][3]) {
  int i; /* row */
  int j; /* column */
         /* loop through rows */
  for (i = 0; i <= 1; i++) {
    /* output column values */
    for (j = 0; j <= 2; j++) {
      printf("%d ", a[i][j]);
    } /*end inner for */
    printf("\n");
  } /* end outer for */
} /* end printArray */
```

基于for循环的数组处理

```c
/* Double - subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4
/* function prototypes */
int minimum(const int grades[][EXAMS], int pupils, int tests);
int maximum(const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[][EXAMS], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);
/* function main begins program execution */
int main(void) {
  int student;
  /* initialize student grades for three students (rows) */
  const int studentGrades[STUDENTS][EXAMS] = {
      {77, 68, 86, 73}, {96, 87, 89, 78}, {70, 90, 86, 81}};
  /* output studentGrades */
  printf("The array is :\n");
  printArray(studentGrades, STUDENTS, EXAMS);

  /* determine smallest and largest grade values */
  printf("\n\nLowest grade: %d\nHighest grade : %d\n ",
         minimum(studentGrades, STUDENTS, EXAMS);
         maximum(studentGrades, STUDENTS, EXAMS));
  /* calculate average grade for each student */
  for (student = 0; student <= STUDENTS; student++) {
    printf(" The average grade for student %d is %.2f\n", student,
           average(studentGrades[student], EXAMS));
  } /* end for */
  return 0;
} /* end main */

/* Find the mimimum grade */
int minimum(const int grades[][EXAMS], int pupils, int tests) {
  int i; /* student */
  int j; /* exam */
  int lowGrade = 100;

  /* loop through rows of grades*/
  for (i = 0; i < pupils; i++) {
    /* loop through columns of grades */
    for (j = 0; j < tests; j++) {
      if (grades[i][j] < lowGrade) {
        lowGrade = grades[i][j];
      } /* end if */
    }   /* end inner for */
  }     /* end outer for */
  return lowGrade;
} /* end function minimum */

/* Find the maximum grade */
int maximum(const int grades[][EXAMS], int pupils, int tests) {
  int i; /* student */
  int j; /* exam */
  int highGrade = 0;

  /* loop through rows of grades*/
  for (i = 0; i < pupils; i++) {
    /* loop through columns of grades */
    for (j = 0; j < tests; j++) {
      if (grades[i][j] > highGrade) {
        highGrade = grades[i][j];
      } /* end if */
    }   /* end inner for */
  }     /* end outer for */
  return highGrade;
} /* end function maximum */

/* Determine the average grade for a particular student */
double average(const int setOfGrades[], int tests) {
  int i;
  int total = 0;
  /* total all grades for one student */
  for (i = 0; i < tests; i++) {
    total += setOfGrades[i];
  } /* end for */
  return (double)total / test;

} /* end function average */

/* Print the array */
void printArray(const int grades[][EXAMS], int pupiles, int tests) {
  int i;
  int j;
  /* output column heads */
  printf(" [0][1][2][3] ");

  /* output grades in tabular format */
  for (i = 0; i < pupils; i++) {
    /* output label for row */
    printf("\nstudentGrades[% d] ", i);
    for (j = 0; j < tests; j++) {
      printf("% -5d", grades[i][j]);
    } /* end inner for */
  }   /* end outer for */
} /* end function printArray */
```

多下标数组

下标地址的含义 ：`int a[3][4];`

- 整个数组的首地址 ：`a, a[ 0]`
- 第一行元素(相当于一个一维数组）的首地址: `a[ 0 ]`
  - 第一行第二个元素 ：`a[0][1] = (a[0])[1]`
  - 第一行第四个元素 ：`a[0][3]`
- 第二行元素的首地址: `a[1]`
- 第三行元素的首地址: `a[2]`

示例：**销售总额**

这样，每位推销员每天可能交上来0到5个卡片。假设上个月的所有卡片都保存好，可供使用。请编写一个程序来读入上个月所有卡片中的信息，然后按照不同推销员、不同产品统计出销售总额，并将其存储在一个双下标数组sales中。最后，将这些销售总额按照表格形式打印出来，一个推销员占一列，一个产品占一行。每一行的末尾统计出整行数据之和表示上个月该产品的销售总额，每一列的下方统计出整列数据之和表示上个月该推销员的销售总额

```c
#include <stdio.h>

int main() {
  int i;
  int j;
  float sum1, sum2;
  float sales[5][4] = {{10, 120, 5.6, 220},
                       {3, 45, 0.9, 2.24},
                       {40, 12, 35.2, 22},
                       {35, 46, 25.8, 26},
                       {100, 12, 506, 28}};

  printf("%-22s%-10s%-10s%-10s%-10s%-20s\n", "", "销售员1", "销售员2",
         "销售员3", "销售员4", "该产品销售总额");

  for (i = 0; i < 5; i++) {
    printf("产品%-18d", i + 1);
    sum1 = 0;
    for (j = 0; j < 4; j++) {
      printf("%-10.2f", sales[i][j]);
      sum1 += sales[i][j];
    }
    printf("%-20.2f\n", sum1);
  }
  printf("销售员的销售总额 ");
  for (j = 0; j < 4; j++) {
    sum2 = 0;
    for (i = 0; i < 5; i++) {
      sum2 += sales[i][j];
    }
    printf("%-10.2f", sum2);
  }
  printf("\n");

  return 0;
} /* end main */
```


## 本章小结

- **利用数组可以方便地处理表格数据**

- **数组元素的名称代表该数组的起始存储位置**

- **在C语言中，数组的元素序号从0开始**

- **若要将一个数组作为实参传递给函数，传递的是数值的地址，只需传递数组名即可**

- **数组元素的排序可采用易于编程实现的冒泡排序法，但速度较慢。**

- **有序数组元素的查找可采用速度较快的折半查找法**
