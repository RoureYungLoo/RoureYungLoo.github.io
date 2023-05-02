#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Status int
#define ElemType int

// 头结点，在首元结点之前附设的一个结点，头结点的指针域指向首元结点
// 头指针，指向链表中第一个结点（头结点/首元结点）的指针
// 首元结点，链表中存储第一个数据元素的结点

typedef struct LNode {
  int data;            // 数据域
  struct LNode* next;  // 指针域
} LNode, *LinkList;

// 初始化一个空的单链表
Status InitList(LinkList& L) {
  L = new LNode;   // L为头指针，指向头结点
  L->next = NULL;  // 头结点指针域置空
  return OK;
}

// 销毁单链表L

// 置空单链表L

// 判空

// 查询元素个数

// 返回前驱

// 返回后继

// 遍历

// 按序号查找
Status GetElem(LinkList L, int i, ElemType& e) {
  struct LNode* p = L->next;
  int j = 1;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) return ERROR;
  e = p->data;
  return OK;
}

// 按值查找
LNode* LocateElem(LinkList L, ElemType e) {
  struct LNode* p = L->next;
  while (p && p->data != e) p = p->next;
  return p;
}

/**
 * @description: description
 * @param {LinkList&} L
 * @param {int} i
 * @param {ElemType} e
 * @return {*}
 * @author: luruoyang
 */
Status ListInsert(LinkList& L, int i, ElemType e) {
  struct LNode* p = L;
  int j = 0;
  while (p && (j < i - 1)) {
    p = p->next;
    j++;
  }
  if (!p || j > i - 1) return ERROR;
  struct LNode* s = new LNode;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

// 按序号删除
Status ListDelete(LinkList& L, int i) {
  struct LNode* p = L;
  int j = 0;
  while ((p->next) && (j < i - 1)) {
    p = p->next;
    j++;
  }
  if (!(p->next) || (j > i - 1)) return ERROR;
  struct LNode* q = p->next;
  p->next = q->next;
  delete q;
  return OK;
}

// 按值删除值为e的第一个结点

// 按值删除值为e的所有结点

// 删除单链表中所有值重复的结点（重复的结点保留一个）

// 头插法
void CreateList_H(LinkList& L, int n) {
  L = new LNode;
  L->next = NULL;
  for (size_t i = 0; i < n; i++) {
    struct LNode* p = new LNode;
    cin >> p->data;
    p->next = L->next;
    L->next = p;
  }
}
// 尾插法
void CreateList_R(LinkList& L, int n) {
  L = new LNode;
  L->next = NULL;
  struct LNode* r = L;
  for (size_t i = 0; i < n; i++) {
    struct LNode* p = new LNode;
    cin >> p->data;
    p->next = NULL;
    r->next = p;
    r = p;
  }
}
int main() {}