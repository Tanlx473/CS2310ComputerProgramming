# CS2310 Lec07 – Pointer I & Inheritance

> Scope: **Pointers & operations** (`*`/`&`, const pointer vs pointer-to-const, pointer arrays), **call by pointer / reference**, **`main(int argc, char\* argv[])`**, **function returning pointer & dynamic allocation**, **memory layout (text/data/stack/heap)**, and **C++ inheritance** (modes, access outcomes, ctor/dtor order, name hiding, multiple inheritance, diamond problem & virtual inheritance). English first, concise Chinese glosses in parentheses.

------

## 0) Big Picture & Quick Sheet

- **Pointers, references, and C++ inheritance** form today’s core: how pointers take/modify addresses; how references give aliases; how inheritance reuses and organises OOP code (access modes, ctor/dtor order, name hiding, diamond problem).
   **指针、引用与 C++ 继承** 是本讲核心：指针如何保存/修改地址；引用如何提供别名；继承如何复用与组织面向对象代码（访问模式、构造/析构顺序、同名隐藏、菱形继承问题）。
- `*p` **dereference** → value at address（解引用）；`&x` **address-of** → address of `x`（取地址）。
- `int * const p` = **const pointer** (address fixed)；`const int * p`/**`int const \*p`** = **pointer-to-const** (value read‑only)（常量指针 vs 指向常量）。
- `void f(int* p); f(&x);` modifies caller; `void f(int& r); f(x);` reference style（指针/引用传参）。
- `argc` counts parameters (includes program path); `argv` is array of `char*`（命令行参数）。
- **Memory layout**: text/data(BSS+init)/stack/heap（内存布局）。
- **Inheritance**: `class D : public B {}`; access mode affects members’ visibility（继承模式影响可见性）。

------

## 1) Pointers Basic

- **Declare / 取地址 / 解引用**:

  - `int *p;` (pointer to int 指向 int 的指针)
  - `p = &x;` (`&` = address-of 取地址)
  - `*p = 10;` (`*` = dereference 解引用，间接修改 x)
     课件强调 `*p` 等价于“所指对象本身”。CS2310-Lec07-PionterI-Inheritan…

- **Reference vs. Dereference | 引用符与解引用**: `&` 在**声明处**表示“引用/取地址语义”，`*` 在**表达式**里表示“解引用”。
   记忆：**read `*p` as “value at p”**；**把 `&x` 想成 “x 的地址”**。

  | 表达式 | 含义                                            |
  | ------ | ----------------------------------------------- |
  | `p`    | address of x  变量 x 的地址                     |
  | `*p`   | value at address p  指针所指向的值（即 x 本身） |
  | `&x`   | address of x  变量 x 的地址（与 p 相同）        |
  | `&p`   | address of pointer p  指针变量 p 的地址         |

- **Const forms | const 形态**：

  - `int * const p = &x;` → **const pointer 常量指针**：*地址*不能改，值可改。
  - `const int * p` / `int const * p` → **pointer to const 指向常量的指针**：地址可改，*值*不可改。

- **Pointer array | 指针数组**：`int *n[5];` 可批量指向 `a[i]` 并通过 `*n[i]` 改写数组值。

> ⚠️ Pitfalls（易错点）
>
> - 混淆 `int * const p` 与 `const int * p`（谁 const？地址还是值）。
> - 忘记初始化“常量指针”（必须在声明时绑定地址）。CS2310-Lec07-PionterI-Inheritan…

**Declare/assign｜声明/赋值**

```cpp
int x=0; int *p = &x; // p holds address of x
*p = 10;              // x becomes 10
int y = *p;           // y == 10
```

**Meaning of `*`｜星号的两义**

- In declaration: `int *p;` → type is “pointer to int”（类型修饰）。
- In expression: `*p` → dereference to the **pointed value**（解引用为值）。

**Const forms｜const 形式**

```cpp
int v=1, w=2;
int * const cptr = &v;  // const pointer (地址不变)
*cptr = 5;              // OK 修改 v
// cptr = &w;           // ❌ 不允许改指向

const int * p1 = &v;    // pointer to const (只读视图)
// *p1 = 7;             // ❌ 不可改值（通过该指针）
p1 = &w;                // OK 可改指向
```

**Pointer array｜指针数组**

```cpp
 int a[5] = {0};
int *n[5];
for(int i=0;i<5;++i){ n[i]=&a[i]; *n[i]=i; } // a -> 0,1,2,3,4
```

------

## 2) Call by Pointer & Reference｜指针/引用传参

**Why**: 

- **Call by value** cannot be used to update arguments to function but **Call by Pointer** can.

- Call-by-value 只能返回一个值；指针/引用可**原地修改**多个变量，实现“多返回”。

  > **In call by pointer, the argument(s) can be a pointer which may reference or point to the variable(s) in the caller function.**
  >  在“通过指针传参（call by pointer）”的方式中，函数参数可以是一个**指针**，这个指针**引用或指向调用函数（caller function）中的变量**。

  > **More than one variables can be updated, achieving the effect of returning multiple values.**
  >  使用这种方式，可以在函数内部**修改多个变量的值**，从而实现“**返回多个结果**”的效果。

### **Call by value vs pointer｜值传递 vs 指针**

```cpp
void f_val(char c){ c='B'; } //Call by Value

void f_ptr(char* pc){ *pc='B'; } //Call by Pointer
char c='A'; f_val(c);   // c 仍为 'A'
f_ptr(&c);              // c -> 'B'
```

向函数传**地址**，在函数内对 `*cPtr` 的写入影响实参

### **Call By reference（引用传参）**:

```cpp
void swap(int &x, int &y){ int t=x; x=y; y=t; }
```

**Reference = constant pointer 本质等价“常量指针”**：必须初始化，不能再指向别处。可读性更好。

- **Const reference（常量引用）**：函数形参常用 `const T&` 以避免拷贝且保护被引对象不可改。字面值可绑定到 `const T&`。CS2310-Lec07-PionterI-Inheritan…

> ⚠️ Pitfalls（易错点）
>
> - `cPtr='B'` 是**错的**：`cPtr` 存放地址，不能写字符；应写 `*cPtr='B'`。
> - 引用未初始化：`int &r;` **非法**。

```cpp
int n=100; int &ref = n; // must init（必须初始化）
ref = 200;               // n->200；引用不能重新绑定到别处

void swap_ref(int &a,int &b){ int t=a; a=b; b=t; }
```

**Const reference（常量引用）**

```c++
void g(const int& r){ /* r 只读 */ }
const int &r1 = 100;     // 右值延长（常量引用允许）
// int &r2 = 100;        // ❌ 非 const 左值引用不可绑定右值
```

Example: swapping values

```c++
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int a = 3, b = 7;
    swap(&a, &b);  // 把 a 和 b 的地址传进去
    cout << a << " " << b << endl; // 输出：7 3
}
```

Call by Pointer

- 这里 `p` 和 `q` 分别指向 `a`、`b`；
- 在函数内用 `*p`, `*q` 解引用访问变量值——在函数内部通过 `*p`、`*q` 直接修改了主函数中的变量；
- `swap` 没有 `return`，但外部变量已被改变——等价于“返回了两个值”。

``` c++
void swap(int &p, int &q) {
  int tmp;
 	tmp = p; /* tmp = 3 */
 	p = q; /* *p = 7 */
 	q = tmp; /* *q = 3 */
}
int main() 
{
 	int a = 3, b = 7;
 	swap(a, b);  // 直接传变量
 	cout << a <<“ “<< b <<endl; 
/* 7 3 is printed */
return 0;
}
```

Call by Reference

- 语法上看起来像“值传递”，但**实际上传的是引用（alias）**。
- `p` 与 `a` 绑定在一起、`q` 与 `b` 绑定在一起。
- 在函数内部修改 `p`、`q`，就相当于修改 `a`、`b` 本身。



| 项目               | Call by Value（值传递） | Call by Pointer（指针传递） |
| ------------------ | ----------------------- | --------------------------- |
| 传入内容           | 变量的副本              | 变量的地址                  |
| 是否能修改外部变量 | ❌ 不能                  | ✅ 可以                      |
| 能否修改多个变量   | ❌ 只能返回一个值        | ✅ 可同时修改多个变量        |
| 示例               | `void f(int x)`         | `void f(int *x)`            |

Pass by Value/Reference/Pointer

✅ 一、总体规律总结

| 传参方式                         | 定义函数时写法   | 调用函数时写法 | 函数内部操作          | 修改效果       |
| -------------------------------- | ---------------- | -------------- | --------------------- | -------------- |
| **值传递 (Pass by Value)**       | `void f(int x)`  | `f(a)`         | 直接操作 `x`（副本）  | ❌ 不影响原变量 |
| **引用传参 (Pass by Reference)** | `void f(int &x)` | `f(a)`         | 操作 `x` 就是操作 `a` | ✅ 改变原变量   |
| **指针传参 (Pass by Pointer)**   | `void f(int *x)` | `f(&a)`        | 操作 `*x` 才是原变量  | ✅ 改变原变量   |

🧠 二、记忆口诀

> 💡 **“值传副本，指针取址，引用别名”**

- **值传递**：函数得到一份**副本**（copy）
- **引用传递**：函数得到**原变量的别名（alias）**
- **指针传递**：函数得到**原变量的地址（address）**

🧪 三、实例对比

```cpp
#include <iostream>
using namespace std;

// 1️⃣ 值传递：不会改变原变量
void byValue(int x) {
    x += 10;
}

// 2️⃣ 引用传参：会改变原变量
void byReference(int &x) {
    x += 10;
}

// 3️⃣ 指针传参：会改变原变量，但要解引用
void byPointer(int *x) {
    *x += 10;
}

int main() {
    int a = 5;

    byValue(a);       // 不变
    cout << "After byValue: " << a << endl;   // 输出 5

    byReference(a);   // 改变
    cout << "After byReference: " << a << endl; // 输出 15

    byPointer(&a);    // 继续改变
    cout << "After byPointer: " << a << endl;   // 输出 25

    return 0;
}
```

🔍 四、形象理解

| 类型     | 调用时  | 函数内访问谁            | 说明                 |
| -------- | ------- | ----------------------- | -------------------- |
| 值传递   | `f(a)`  | `x` 是 `a` 的**复制品** | 修改 `x` 不影响 `a`  |
| 引用传参 | `f(a)`  | `x` 是 `a` 的**别名**   | 修改 `x` = 修改 `a`  |
| 指针传参 | `f(&a)` | `x` 是 `a` 的**地址**   | 修改 `*x` = 修改 `a` |

📘 五、重点补充

| 项目               | 引用 (Reference)     | 指针 (Pointer)     |
| ------------------ | -------------------- | ------------------ |
| 是否可为 `null`    | ❌ 不行，必须绑定对象 | ✅ 可以是 `nullptr` |
| 是否可重新指向别处 | ❌ 一旦绑定就不能改   | ✅ 可以修改指向     |
| 使用语法           | 直接用变量名         | 需要 `*` 或 `->`   |
| 与 C 语言兼容性    | C 不支持引用         | C 支持指针         |

------

✅ **总结一句话：**

> - 普通参数 → 改副本
> - 引用参数 → 改原件（自动传地址）
> - 指针参数 → 改原件（手动传地址）

------

是否希望我帮你画一张**内存指向图**，直观显示三种传参方式在内存中的关系（变量 → 地址 → 副本/原件）？

## 3) `main(argc, argv)`｜**`main()` function with parameters**  命令行参数

```cpp
int main(int argc, char* argv[]){
    cout << "argc=" << argc << "\n";
    for(int i=0;i<argc;++i) cout << argv[i] << "\n";
}
```

- `argc`≥1；`argv[0]` 通常是可执行文件路径（含程序名）。（参数计数与内容）

一、Syntax

```c++
int main(int argc, char *argv[]) {
    cout << "The parameters are:" << endl;
    for (int i = 0; i < argc; i++) {
        cout << *(++argv) << endl;
    }
    return 0;
}
```

- `int argc`
   → argument count，表示参数的数量。
   包括程序本身的路径名；因此若没有额外参数，`argc == 1`
- `char *argv[]`
   → argument vector，表示参数数组。
   每个元素是一个 C 字符串（`char*`），指向命令行输入的文本CS2310-Lec07-PionterI-Inheritan…。

二、运行机制

在 Windows 或命令行运行时，可以像这样执行：

```
myProgram.exe apple banana orange
```

此时：

- `argc = 4`
- `argv[0] = "myProgram.exe"`
- `argv[1] = "apple"`
- `argv[2] = "banana"`
- `argv[3] = "orange"`

循环语句会逐一输出参数。

 三、典型输出示例

```
The parameters are:
apple
banana
orange
```

四、用途总结

| 功能                           | 说明                           |
| ------------------------------ | ------------------------------ |
| 读取命令行输入                 | 用于 CLI 程序、脚本式工具      |
| 支持多参数处理                 | 可同时解析多个字符串或数值输入 |
| 结合 `atoi()`、`stof()` 等函数 | 将字符串参数转换为数值类型     |

**一句话总结：**

> `main(int argc, char *argv[])` 允许程序从命令行接收外部输入参数，
>  通过 `argc` 得知参数个数，通过 `argv[]` 访问每个参数的内容。

------

## 4) Returning a Pointer & `new`｜返回指针与动态分配

典型：**动态内存**创建对象并返回指针：

```c++
int* f(int n){ int *p = new int(n); return p; }
```

责任：记得 `delete`，或改用 **`std::unique_ptr<int>`** / **值返回**（RVO/NRVO）。

> Heap:
>
> 堆区是程序运行时可自由使用的**动态内存区域**。
>
> - 当你使用 `new` 或 `malloc()` 时，程序会在堆上申请一块空间；
> - 当你使用 `delete` 或 `free()` 时，才会真正释放这块空间；
> - 堆中的内存不会随函数结束而自动销毁。
>
> ```c++
> int* p = new int(10);  // 在堆区分配内存并初始化为10
> cout << *p;            // 输出 10
> delete p;              // 释放堆内存
> ```
>
> 堆区的工作机制
>
> 1. 程序请求内存 → 操作系统在堆区分配一块空间；
> 2. 返回一个指向这块空间的**指针（pointer）**；
> 3. 程序员通过指针访问、修改该内存内容；
> 4. 使用完毕后调用 `delete` / `free` 释放，否则会造成**内存泄漏（memory leak）**。
>
> Common Errors and Traps:
>
> | 错误类型                     | 例子              | 说明                               |
> | ---------------------------- | ----------------- | ---------------------------------- |
> | 悬空指针（dangling pointer） | 返回局部变量地址  | 局部变量在栈上，函数结束后地址无效 |
> | 内存泄漏（memory leak）      | 忘记 `delete`     | 堆区空间无法回收，导致资源浪费     |
> | 重复释放（double free）      | 调用两次 `delete` | 会引发程序崩溃                     |

Memory Layout｜内存布局

- **Text/Code 段**：可执行指令（只读/共享）。
- **Data 段**：全局/静态、常量字符串；BSS（未初始化）与已初始化区。
- **Stack 栈**：局部变量、参数、返回地址（后进先出）。
- **Heap 堆**：动态分配（`new`/`delete`）。

| 区域             |        | 主要内容                        | 生命周期                           |
| ---------------- | ------ | ------------------------------- | ---------------------------------- |
| **Text Segment** | 代码段 | 可执行指令（程序代码）          | 程序整个运行期间                   |
| **Data Segment** | 数据段 | 全局变量、静态变量              | 程序整个运行期间                   |
| **Stack**        | 栈区   | 局部变量、函数参数              | 函数结束时自动释放                 |
| **Heap**         | 堆区   | 动态分配的内存 (`new`/`malloc`) | 由程序员手动管理 (`delete`/`free`) |

Examples:

```c++
// 函数定义：在堆区创建一个整数并返回其地址
int* make_int(int v){
    int *p = new int(v);  // 在堆上分配内存并初始化为 v
    return p;             // 返回该内存的地址
}

int main(){
    int* q = make_int(10);    // 调用函数并接收返回的指针
    cout << *q << "\n";       // 输出 10（解引用访问堆中整数）
    delete q;                 // 释放堆内存（手动回收）
    return 0;
}
```

> 切勿返回局部栈变量的地址（悬垂指针）。

```c++
#include <iostream>
using namespace std;

int* f(int n){
    int *ptr1 = new int(n);  // 在堆上创建一个整数，值为 n
    return ptr1;             // 返回该整数的地址
}

int main(){
    int *ptr = f(10);        // ptr 接收返回的地址
    cout << *ptr << endl;    // 输出 10
    *ptr = 20;               // 通过指针修改值
    cout << *ptr << endl;    // 输出 20
    delete ptr;              // 释放动态内存
    return 0;
}
```

Output:

```
10
20
```



------

## 5) C++ Inheritance Basics｜继承基础

#### Object-Oriented Programming (OOP)

Three important features of OOP

- **Data encapsulation** 数据封装

  - Wrap data and functions into a unit called, a class

  - One related concept – **Data abstraction**
    - Displaying only essential information and hiding the details, 
    - e.g., using class is a typical way of data abstraction

- **Inheritance** 继承
  - Get (derive) properties and characteristics from another class

- **Polymorphism** 多形态
  - Have multiple functions with the same name, with different 

operations

**Why｜动机**：抽取共性到基类（`Device`），子类（`Phone/Watch/Tablet`）复用与扩展（去重复）。

A new class is created (or inherited) from an existing class

- Child / derived class: the new class created

-  Parent / base class: the existing class

**Syntax｜语法**

```c++
class <derived_class> : <access-specifier> <base_class>
{
//body
};
```

Example

```cpp
class Device{ 
  public: 
  void unlock();
  void update();
  private:int power; 
};
class Tablet : public Device { 
  public: void splitView();
};
class Watch  : public Device {
  public: void changeWatchFace(); 
};
```

**Modes｜继承模式**

- `public`：基类 `public→public`，`protected→protected`（最常用）。

  - Public members of the base class will be public members in the derived class

    基类的公共成员将成为派生类的公共成员

  - Protected members of the base class will become protected members in the 
    derived class

    基类的保护成员将变为派生类的保护成员

- `protected`：基类 `public/protected→protected`（对外变窄）。

  - Both public and protected members of the base class will be protected in the  derived class

    基类中的公有成员和受保护成员在派生类中都将被设为受保护类型。

- `private`：基类 `public/protected→private`（对子类再派生不友好）。

  - Both public and protected members of the **base class** become private in the 

    **derived class**

    基类中的公有成员和保护成员在派生类中都会变为私有成员。


Example: How are `x`, `y` and ` z` inherited in a child class

```c++
class Base {
public:
 int x;
protected:
 int y;
private:
 int z;
};

//Public mode:
class A :public Base{
public:
 int x;
protected:
 int y;
//cannot access:
 //int z;
};

class B :protected Base{
protected:
 int x;
 int y;
//cannot access:
 //int z;
};

class C :private Base{
private:
 int x;
 int y;
//cannot access:
 //int z;
};
```



**Access table（访问结果示意）**

- Private members in the base class

  - They are still inherited, but hidden in the **child class** (not 

  accessible in the child class)

  基类 `private` 成员：**被继承但不可访问**（隐藏，仅占空间/布局影响）。

  Example: 

  ```c++
  class Base {
  public:
      int x;       // 公有成员
  protected:
      int y;       // 受保护成员
  private:
      int z;       // 私有成员
  };
  class A : public Base {
  public:
      int w;
  };
  
  A a;
  cout << sizeof(a) << endl;   // 包含 x, y, z, w 四个成员的总大小
  
  ```

  即使 `z` 无法访问，它仍然占据空间，因为它属于对象的内存布局（object layout）。

  虽然 Base::z 在逻辑上被继承，但：

  子类对象中仍然包含这块内存空间；

  只是子类代码不能直接访问它；

  所以 z 是“被继承但被隐藏（hidden）”的。

  | 类别           | 是否被继承 | 子类是否能访问     | 是否占内存 |
  | -------------- | ---------- | ------------------ | ---------- |
  | public 成员    | ✅ 是       | ✅ 可访问           | ✅ 是       |
  | protected 成员 | ✅ 是       | ✅ 可访问（仅子类） | ✅ 是       |
  | private 成员   | ✅ 是       | ❌ 不可访问         | ✅ 是       |

- 在派生类**内部**：能访问基类的 `public/protected`（取决于继承模式）。

- 在**类外**：只能经由接口（`public` 成员函数）。

  Example:

```c++
class Base {
private:
    int z;
public:
    void setZ(int v) { z = v; }
    int getZ() { return z; }
};

class A : public Base {};
int main() {
    A a;
    a.setZ(5);         // 间接访问
    cout << a.getZ();  // 输出 5
}
```


这里 z 虽然是 private，但仍存在于 A 的对象结构中，只是必须通过 Base 提供的接口访问。

#### Order of Constructor/Destructor | 构造/析构顺序

- 对象创建：**base‑ctor → derived‑ctor**（先基后派）。
- 对象销毁：**derived‑dtor → base‑dtor**（先派后基）。

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base()  { cout << "base-constructor" << endl; }
    ~Base() { cout << "base-destructor" << endl; }
};

class Child : public Base {
public:
    Child()  { cout << "child-constructor" << endl; }
    ~Child() { cout << "child-destructor" << endl; }
};

int main() {
    Child c;  // 创建对象
    cout<<"Constructed, now destruct it.\n";
    return 0;
}
```

Output:

```
base-constructor
child-constructor
Constructed, now destruct it.
child-destructor
base-destructor
```



#### Name Hiding & Scope｜同名隐藏与作用域

Same Name in Child & Parent Class

- The name in the child class will hide it in the parent class. 

  子类同名成员会**隐藏**基类同名成员

- To access this name in parent class, use the scope operator :

  用 `Base::name` 访问基类版本。

```cpp
struct Base{ 
  int x=1;
  void f(){cout<<"base";} 
  void f(int){} 
};
struct A: Base{ 
  int x=2; 
  void f(){cout<<"child";}
};
void f () {
 A a; 
 cout << a.x << endl; // 2
 cout << a.Base::x << endl; // 1
 a.f(); // child-1
 a.Base::f(); // base-1
 a.Base::f(10); // base-2
};
```

#### Types of Inheritance: 

- **Single** inheritance

  - a child class inherits from only one base class

    ```c++
    class Base {
    public:
        void show() { cout << "Base class" << endl; }
    };
    
    class Derived : public Base {   // 单继承
    public:
        void display() { cout << "Derived class" << endl; }
    };
    
    ```

    理解：Derived 继承了 Base 的成员和函数。→ “一个孩子有一个父亲。”

- **Multiple** inheritance 多重继承

  - a class can inherit from more than one class

  - 多个基类并列继承；成员名冲突需**限定作用域**解决（`B1::x` vs `B2::x`）。

  ```cpp
    struct B1{ int x=1; }; struct B2{ int x=2; };
    struct A: public B1, public B2{ int y; };
    A a; cout<< a.B1::x <<","<< a.B2::x;
  ```

   ```c++
    class A {
    public:
        void showA() { cout << "Class A" << endl; }
    };
    
    class B {
    public:
        void showB() { cout << "Class B" << endl; }
    };
    
    class C : public A, public B {   // 多继承
    public:
        void showC() { cout << "Class C" << endl; }
    };
    
   ```
  
   理解： `C` 同时继承了 `A` 和 `B`。 → “一个孩子有两个父母。”
     ⚠️ 注意：如果 `A` 和 `B` 都有同名函数，可能出现 **命名冲突（ambiguity）**，需要通过作用域解析符 `A::function()` 来区分。
  
- **Multilevel** inheritance 多层继承
  
  - a child (derived) class is created from another derived class
  
    子类再派生出新的子类（层层继承）。
  
    ```c++
    class GrandParent {
    public:
        void showG() { cout << "GrandParent" << endl; }
    };
    
    class Parent : public GrandParent {
    public:
        void showP() { cout << "Parent" << endl; }
    };
    
    class Child : public Parent {   // 多层继承
    public:
        void showC() { cout << "Child" << endl; }
    };
    
    ```
  
    理解 ：`Child` 继承自 `Parent`，而 `Parent` 又继承自 `GrandParent`。
     → “爷爷 → 爸爸 → 孩子” 的三代传承关系。
  
    

####  Diamond Problem

Problem: When a class inherits from two or more classes that have a common base class, the members of that common base 

class may cause ambiguity in the program

**问题**：`Mother` 和 `Father` 均继承自 `Person`，`Child` 再继承两者 → `Person` 成员**二义性**。

```cpp
struct Person{ int age; };
struct Mother: public Person{ /* age=50 */ };
struct Father: public Person{ /* age=51 */ };
struct Child: public Mother, public Father{ /* Person 有两份，age 二义 */ };
```

What happened? 

- `Child` 同时继承了 `Mother` 和 `Father`；
- 而 `Mother` 和 `Father` 都继承自同一个基类 `Person`；
- 因此 `Child` 里实际上存在两份 `Person` 副本：
  - 一份来自 `Mother`
  - 一份来自 `Father`

这样在访问 `age` 时，编译器无法判断指的是哪一个 → **歧义（ambiguity）**。

**解法 1**：用作用域指明 `Mother::age` 或 `Father::age`（显式选择）。

**解法 2（推荐）**：**Virtual Inheritance 虚拟继承**确保 `Person` 仅一份：

```cpp
struct Mother: virtual public Person{};
struct Father: virtual public Person{};
struct Child : public Mother, public Father{
    Child(){ age = 20; } // OK, 单一 Person 基类
};
```

> 虚拟继承引入**虚基指针/表**（实现层面），但对接口透明。

Virtual Inheritance will modify the order of Construction/ Destruction

虚拟继承改变了基类的构造顺序。

``` c++
#include<iostream>
using namespace std;
class Person {
public:
    Person() { cout << "Person()" << endl; }
    ~Person() { cout << "~Person()" << endl; }

};

class Mother : virtual public Person {
public:
    Mother() { cout << "Mother()" << endl; }
    ~Mother() { cout << "~Mother()" << endl; }
};

class Father : virtual public Person {
public:
    Father() { cout << "Father()" << endl; }
    ~Father() { cout << "~Father()" << endl; }
};

class Child : public Mother, public Father {
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }
};

int main() {
    Child c;
    cout<<"Constructed, now destruct it.\n";
    return 0;
}
```

Output:

```
Person()
Mother()
Father()
Child()
Constructed, now destruct it.
~Child()
~Father()
~Mother()
~Person()

```

Explanonation:

- 虚基类（`Person`）由**最下层的派生类（`Child`）**统一构造；
- `Mother`、`Father` 不再重复构造 `Person`；
- 析构顺序则相反（Child → Father → Mother → Person）。

编译器底层机制（Implementation Mechanism）

C++ 编译器使用两个特殊结构来支持虚拟继承：

| 名称                             | 含义       | 作用                                           |
| -------------------------------- | ---------- | ---------------------------------------------- |
| **vbptr (virtual base pointer)** | 虚基类指针 | 每个虚拟继承的类都有一个隐藏指针，指向虚基类表 |
| **vbtable (virtual base table)** | 虚基类表   | 存储从当前类到虚基类的偏移量（offset）信息     |

🧩 内存结构（示意）：

```
Child 对象：
 ├── Mother (含 vbptr → vbtable)
 ├── Father (含 vbptr → vbtable)
 └── [共享的 Person 实例]
```

运行时，`vbptr` 会告诉程序“虚基类（Person）在内存中的唯一位置”，从而确保无论通过 `Mother` 还是 `Father` 访问，得到的都是同一个 `Person`。



------

## 11) Patterns & Pitfalls｜模式与陷阱

- 传参修改：需用 `T*` 或 `T&`；只读用 `const T*` / `const T&`（意图明确）。
- **不要写** `*p = 'B';` 为 `p = 'B';`（后者错误：给指针变量赋‘字符’）。
- 绝不返回局部栈对象地址（悬垂）；`new` 后记得 `delete`（避免泄漏）。
- 继承模式影响**对外可见性**；对外 API 需要保持 `public` 继承。
- 同名隐藏常致困惑：必要时用 `Base::` 限定；或 `using Base::f;` 引入基类重载。

------

## 12) Quick Drills｜随练

1. 写 `void swap(int* p,int* q)` 与 `void swap(int& a,int& b)` 两个版本并测试。
2. 写 `int* make_array(int n)`：用 `new` 分配并返回，调用者释放。
3. 打印 `argc/argv`；手工从 `argv` 解析第一个整数参数并输出其平方。
4. 定义 `class Device` 与 `class Phone: public Device`，验证 `public` 继承下基类方法可直接被调用。
5. 构造 `Person→Mother/Father→Child` 的菱形结构，改为**虚拟继承**使 `Child` 仅有一份 `age`。



Supplement:

`*` 什么时候表示取值？

## 🧩 一、在**声明（declaration）或定义（definition）**里

`*` 👉 **只是告诉编译器“这是一个指针变量”**，不是取值。

```cpp
int *p;        // p 是一个指向 int 的指针（类型说明符的一部分）
double *q;     // q 是一个指向 double 的指针
char *s;       // s 是一个指向 char 的指针
```

此时 `*` 是**类型说明符的一部分**，告诉编译器 “我要一个可以保存地址的变量”。
 编译器不会对内存取值，它只是**建立类型关联**。

------

## 🧠 二、在**表达式（expression）**中

`*` 👉 变成了“**解引用（dereference）**”运算符，也就是取出指针指向的内容。

```cpp
int a = 10;
int *p = &a;

cout << *p;    // *p 表示“访问 p 指向的内存内容” → 输出 10
*p = 20;       // *p 表示“修改 p 指向的内存内容” → a 变成 20
```

在表达式中，`*` 会让程序**顺着地址访问那块内存的值**。
 此时 CPU 会真的去那个地址读取或写入数据。

------

## ⚙️ 三、在**声明 vs 表达式**中的不同作用对比表

| 用法场景 | 示例           | 含义                                | 编译阶段    |
| -------- | -------------- | ----------------------------------- | ----------- |
| 声明     | `int *p;`      | 声明 `p` 是一个指针变量（类型信息） | 编译时      |
| 初始化   | `int *p = &a;` | 令 `p` 存储 `a` 的地址              | 编译+运行时 |
| 表达式   | `*p = 10;`     | 访问 p 指向的值并修改               | 运行时      |
| 表达式   | `cout << *p;`  | 访问 p 指向的值并读取               | 运行时      |

------

## 📘 四、一个图像化理解 🧩

假设：

```cpp
int a = 10;
int *p = &a;
```

| 名称 | 地址（示意） | 内容                 |
| ---- | ------------ | -------------------- |
| `a`  | `0x1000`     | `10`                 |
| `p`  | `0x2000`     | `0x1000`（a 的地址） |

当你写：

- `p` → 表示变量本身的值 = `0x1000`
- `*p` → 访问地址 `0x1000` 的内容 = `10`

------

## 🧩 五、总结成一句经典口诀：

> **定义时的 `\*` 表示“指针类型”**，
>  **使用时的 `\*` 表示“取指向的值”**。

换句话说：

> “在定义里它告诉编译器，
>  在表达式里它告诉 CPU。”

------

如果你愿意，我可以帮你画一张“指针定义 vs 解引用”对照图（变量、地址、指针箭头、内存格子全画出来），
 让你**一眼看懂**为什么“定义时不是取值”。要我帮你画出来吗？

Dangling Pointer  悬空指针:

🧩 一、什么是悬空指针（Dangling Pointer）

悬空指针指的是：**指针仍然保存着一个内存地址，但该地址指向的对象已被释放或失效**。
 换句话说，**指针还在，但它所指的内容已经不存在**。

⚠️ 二、常见场景与示例

🔹 示例 1：返回局部变量的地址（最常见错误）

```cpp
#include <iostream>
using namespace std;

int* make_int_wrong(int v){
    int x = v;   // 局部变量，在栈区
    return &x;   // ❌ 返回局部变量地址
}

int main(){
    int* p = make_int_wrong(10);
    cout << *p << endl;   // ⚠️ 未定义行为（Undefined Behavior）
    return 0;
}
```

**解释：**

- `x` 是栈上的局部变量；
- 函数执行完后，栈区的 `x` 被销毁；
- `p` 仍然保存着 `x` 原来的地址（比如 0x7ffee3...）；
- 这时 `p` 就成了 **悬空指针**。

🔹 示例 2：释放内存后继续使用指针

```cpp
#include <iostream>
using namespace std;

int main(){
    int* p = new int(42);
    delete p;            // 释放堆区内存
    cout << *p << endl;  // ❌ 悬空指针：访问已释放内存
    return 0;
}
```

**解释：**

- `p` 原本指向堆区的一块内存；
- 调用 `delete p` 后，该内存已被回收；
- 但 `p` 本身仍然保存旧地址；
- 解引用 `*p` 将访问无效内存，结果不可预期。

 三、如何避免悬空指针

| 情况                  | 正确做法                                                 |
| --------------------- | -------------------------------------------------------- |
| 返回局部变量地址      | 改为使用 `new` 在堆区分配                                |
| delete 后忘记清空指针 | 立即置空：`p = nullptr;`                                 |
| 多指针指向同一块内存  | 注意释放顺序或使用智能指针（`unique_ptr`, `shared_ptr`） |

 安全写法示例

```cpp
#include <iostream>
using namespace std;

int* make_int_safe(int v){
    int* p = new int(v);  // 分配在堆区
    return p;             // 安全返回
}

int main(){
    int* q = make_int_safe(10);
    cout << *q << endl;   // 输出 10
    delete q;             // 释放堆内存
    q = nullptr;          // 防止悬空指针
    return 0;
}
```

总结

> “悬空指针” 就是一个指向无效内存的指针。
>  它常出现在：
>
> - 函数返回局部变量地址；
> - delete/free 后仍然访问；
> - 指针作用域外使用旧地址。
>
> 解决方法：使用 `new`/`delete` 配对、`nullptr` 清空，或使用智能指针管理内存。







Why Diamond Problem matter?

当 `Child` 类中出现 **两份相同基类（Person）的副本** 时，会带来以下三大问题👇：

## 🧩 一、内存浪费（Memory Duplication）

在普通多重继承中（非虚拟继承）：

```cpp
class Person { public: int age; };
class Mother : public Person {};
class Father : public Person {};
class Child : public Mother, public Father {};
```

`Child` 对象的结构大致如下：

```
Child:
 ├── Mother 部分
 │    └── Person(age=50)
 └── Father 部分
      └── Person(age=51)
```

➡️ **结果：**

- `Child` 有两份独立的 `Person` 数据；
- 每份都各自占用内存；
- 如果基类有多个成员（比如 name, id, address...），内存开销会成倍增加。

------

## ⚠️ 二、访问歧义（Ambiguity）

这才是最麻烦的问题。
 当你写：

```cpp
Child c;
c.age = 10;   // ❌ 错误：'age' is ambiguous
```

编译器会报错，因为：

- `c` 有两份 `age`（一份在 `Mother::Person`，一份在 `Father::Person`）；
- 编译器不知道你想访问哪一个。

💡 必须写成：

```cpp
c.Mother::age = 10;  // 明确指定来自 Mother 的那一份
```

这显然很麻烦，也容易出错。

------

## 💥 三、逻辑错误与数据不一致（Inconsistent State）

即使你强制区分开两份 `Person`，也可能出现逻辑混乱：

```cpp
c.Mother::age = 40;
c.Father::age = 41;

cout << c.Mother::age << " " << c.Father::age << endl;
```

输出：

```
40 41
```

➡️ 这意味着在同一个 `Child` 对象中：

- “同一个人”的年龄出现了两份不一致的版本；
- 在逻辑上是不合理的。

------

## 🧠 四、解决办法：**虚拟继承（virtual inheritance）**

通过虚拟继承，编译器会让 `Mother` 和 `Father` **共享一份共同的 `Person` 实例**：

```cpp
class Mother : virtual public Person {};
class Father : virtual public Person {};
class Child : public Mother, public Father {};
```

此时：

```
Child:
 ├── Mother
 ├── Father
 └── [共享的唯一 Person(age)]
```

✅ 优点：

- 内存只保留一份 `Person`；
- 不再出现歧义；
- 数据一致性得到保证；
- `Child` 直接访问 `age` 即可。

------

## 🧭 五、总结对比表

| 问题类型            | 普通继承（non-virtual）             | 虚拟继承（virtual） |
| ------------------- | ----------------------------------- | ------------------- |
| Person 副本数量     | 两份（Mother 和 Father 各自带一份） | 一份（共享）        |
| 访问 `age` 是否歧义 | ❌ 是（需要 `Mother::age`）          | ✅ 否（直接访问）    |
| 数据一致性          | ❌ 可能不一致                        | ✅ 始终一致          |
| 内存开销            | 大（重复副本）                      | 小（共享副本）      |

------

📘 **一句话总结：**

> 当 `Child` 同时继承两个拥有相同基类的父类时，
>  普通继承会导致 **多份副本、访问歧义、数据不一致**；
>
> 使用 **virtual inheritance（虚拟继承）** 可以让 `Child` 共享一份基类，彻底解决菱形继承问题。