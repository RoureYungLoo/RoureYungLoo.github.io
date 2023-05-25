/*
 * @Description: Description
 * @Version: 1.0
 * @Author: luruoyang
 * @Date: 2023-05-25 21:37:56
 * @LastEditors: luruoyang
 * @LastEditTime: 2023-05-25 21:51:14
 */
#include <iostream>

#include "demo.h"
using std::cin;
using std::cout;
using std::endl;
class A {
 private:
  int id;

 public:
  A();
  ~A();
};

A::A() : id(0) { cout << "default ctor.this=" << this << "id=" << id << endl; }

A::~A() { cout << "dtor.this=" << this << "id" }

int main(int argc, char const *argv[]) {
  /* code */
  int *pi = new int[10];
  delete pi;  // 对int而言，加不加[]都可以

  int ia[10];          // from stack but not heap
  cout << sizeof(ia);  // 40

  Demo *p = new Demo[3] return 0;
}
