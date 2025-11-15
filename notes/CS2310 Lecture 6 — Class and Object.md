# 🧭 CS2310 Lecture 6 — Class and Object

------

## 1️⃣ Introduction to Class and Object

类与对象的引入

A **class** is a user-defined data type that groups variables and functions together.
 **类（Class）** 是一种用户自定义的数据类型，用于把**变量**和**函数**组织在一起。

A class represents an abstract concept or object from the real world (e.g., Circle, Car, Student).
 类代表现实世界中的一个抽象概念或对象（例如圆、汽车、学生）。

An **object** is an instance of a class.
 **对象（Object）** 是类的一个实例。

Classes and objects are core features of **Object-Oriented Programming (OOP)**.
 类与对象是**面向对象编程（OOP）**的核心特征。

Using classes makes code more organised, reusable, and modular.
 使用类可以让代码结构清晰、可复用、模块化。

------

## 2. Defining a Class

类的定义

A class consists of **member variables** (data) and **member functions** (methods).
 一个类由**成员变量**（数据）和**成员函数**（方法）组成。

Basic syntax:
 基本语法：

```cpp
class ClassName {
public:
    int var;
    void func();
};
```

Functions can also be defined outside the class using the scope resolution operator `::`.
 函数也可以在类外通过**作用域解析运算符 `::`**来定义。

Example of a member function definition:
 成员函数定义示例：

```cpp
double Circle::getArea() { return 3.14 * radius * radius; }
```

### 3. Class Size and Memory Alignment

类的大小与内存对齐

##### What determines a class’s size 类的大小由什么决定

The **size of a class** in C++ depends mainly on its **data members**, not on its functions.
 在 C++ 中，类的**大小（size）**主要由其**成员变量（data members）**决定，而与成员函数的数量或内容无关。

All objects of a class share the same copies of the functions, but each object has its own set of data members.
 类的所有对象共享同一份函数代码，但每个对象都有属于自己的数据成员。

Therefore, `sizeof(ClassName)` only measures the memory used by data members (plus possible padding).
 因此，`sizeof(ClassName)` 只计算数据成员占用的内存空间（以及可能存在的填充字节）。

Example

```
class Circle {
public:
    int radius;
    double getArea() { return 3.14 * radius * radius; }
};
```

Here, only `radius` occupies memory. 这里只有 `radius` 占用内存空间。

If `int` is 4 bytes, then `sizeof(Circle)` = **4 bytes**.
 如果 `int` 是 4 字节，那么 `sizeof(Circle)` = **4 字节**。

Member functions do **not** increase the object’s size.
 成员函数不会增加对象的大小。

#####  Empty class 空类

Even an **empty class** (no members at all) still has a nonzero size.
 即使一个类完全没有成员，它的大小也不是 0。

```
class Empty {};
cout << sizeof(Empty);  // 1
```

It is **1 byte**, so that each object can have a unique memory address.
 其大小为 **1 字节**，以保证每个对象在内存中都有唯一的地址。

#####  Memory alignment 内存对齐

C++ compilers usually align data members in memory for efficient CPU access.
 C++ 编译器通常会为了提高 CPU 访问效率而进行**内存对齐（memory alignment）**。

Each member starts at an address that is a multiple of its type’s alignment size (e.g., 4 for `int`, 8 for `double`).
 每个成员的起始地址通常是其类型对齐单位的整数倍（例如 `int` 对齐到 4，`double` 对齐到 8）。

If a member would start at a non-aligned address, the compiler inserts **padding bytes** to realign it.
 如果某个成员的起始位置不满足对齐要求，编译器会自动插入**填充字节（padding）**以重新对齐。

Example of alignment

```
class Example {
    char a;     // 1 byte
    double b;   // 8 bytes
    char c;     // 1 byte
};
```

Visually:
 内存分布如下：

```
| a(1) | padding(7) | b(8) | c(1) | padding(7) |
```

- `a` starts at address 0.
   `a` 从地址 0 开始。
- `b` must start at an address multiple of 8, so 7 bytes are padded after `a`.
   `b` 必须从 8 的倍数地址开始，因此在 `a` 后填充 7 个字节。
- `c` is 1 byte, but total size must be a multiple of 8, so 7 more bytes are padded at the end.
   `c` 占 1 字节，但整个类的大小必须是 8 的倍数，因此末尾又补了 7 字节。

✅ `sizeof(Example)` = 24 bytes

#####  General rule

一般规律

1. Each member is aligned according to its type.
    每个成员变量根据其类型进行对齐。
2. Padding may be added between or after members.
    编译器可能在成员之间或结尾添加填充字节。
3. The **total class size** is rounded up to a multiple of the **largest alignment unit** (the largest member’s size).
    **类的总大小** 会补齐为 **最大成员类型对齐单位** 的整数倍。

Thus:
 因此：

> The size of a class = “sum of all members + padding”,
>  then rounded up to the nearest multiple of the largest member size.

> 类的大小 = “所有成员大小之和 + 填充字节”，
>  然后再补齐到最大成员类型大小的倍数。

Verification example

```
class Point {
    int x;
    int y;
    double z;
};
```

- `int` → 4 bytes, `double` → 8 bytes
- All members are naturally aligned (no extra padding inside)
- Largest type = `double` (8 bytes)

✅ `sizeof(Point)` = 16 bytes

#####  Why alignment matters

为什么要对齐

- It improves CPU memory access speed.
   对齐能提高 CPU 访问内存的速度。
- Prevents hardware exceptions on some architectures.
   在某些硬件架构上可防止访问错误。
- You can change alignment manually using `#pragma pack`, but this is usually not recommended.
   可以用 `#pragma pack` 修改对齐方式，但一般不建议这样做。

##### Summary

- Class size depends only on **data members**.
   类的大小只取决于数据成员。
- Empty class still has **1 byte**.
   空类也占 1 字节。
- The compiler may insert **padding** for alignment.
   编译器会插入填充字节以对齐。
- Final size = smallest multiple of the largest member’s alignment greater than the total data size.
   最终大小 = 大于数据成员总和的、**最大成员类型大小的最小整数倍**。

-----

### 4. Class Pointer

类指针

#### What is a class pointer?

什么是类指针

A **class pointer** is a pointer that stores the memory address of an object of a class.
 **类指针（class pointer）** 是一个保存类对象地址的指针变量。

Just like `int*` stores the address of an integer,
 `Circle*` stores the address of a `Circle` object.
 就像 `int*` 保存整数变量的地址一样，`Circle*` 保存 `Circle` 对象的地址。

Example:
 示例：

```cpp
class Circle {
public:
    int radius;
    double getArea() { return 3.14 * radius * radius; }
};

int main() {
    Circle c;       // object
    Circle *p;      // pointer to Circle
    p = &c;         // store address of c
}
```

#### Accessing members through a pointer

通过指针访问成员

When you have a pointer to an object,
 you use the **arrow operator (`->`)** to access its members.
 当你有一个指向对象的指针时，使用 **箭头运算符 (`->`)** 访问成员。

```cpp
p->radius = 5;            // same as c.radius = 5
cout << p->getArea();     // same as c.getArea()
```

In other words:
 换句话说：

- `obj.member` → when you have the object itself
- `ptr->member` → when you have a pointer to the object

即：

- `obj.member` 用于直接对象
- `ptr->member` 用于对象指针

Example with both 对象与指针的对比示例

```cpp
Circle c;
c.radius = 3;
cout << c.getArea() << endl;   // direct access

Circle *p = &c;
p->radius = 4;
cout << p->getArea() << endl;  // access through pointer
```

Both work the same way — the arrow operator `->` is just syntactic sugar for `(*p).member`.
 两种方式功能完全一样，`->` 实际上等价于 `(*p).member`。

例如：

```cpp
(*p).radius = 4;   // equivalent to p->radius
```

#### Pointer to dynamically allocated object

指向动态分配对象的指针

We can create objects dynamically using `new`, and access them through pointers.
 可以使用 `new` 运算符动态创建对象，并通过指针访问。

```cpp
Circle *ptr = new Circle;
ptr->radius = 10;
cout << ptr->getArea() << endl;
delete ptr;   // must free memory
```

Here, `new` allocates memory from the heap, and `delete` releases it.
 这里的 `new` 从堆（heap）上分配内存，而 `delete` 释放该内存。

> ⚠️ If you forget to use `delete`, the memory will not be reclaimed — this is called a **memory leak**.
>  ⚠️ 如果忘记 `delete`，该内存不会被回收，这称为 **内存泄漏（memory leak）**。

#### Array of objects using pointer

使用指针访问对象数组

You can also use a pointer to access an array of class objects.
 还可以使用指针访问类对象的数组。

```cpp
Circle *arr = new Circle[3];   // 3 Circle objects
arr[0].radius = 1;
arr[1].radius = 2;
arr[2].radius = 3;

for (int i = 0; i < 3; i++)
    cout << arr[i].getArea() << endl;

delete[] arr;   // release the whole array
```

Each element of the array is a separate `Circle` object in memory.
 数组中的每个元素都是一个独立的 `Circle` 对象。

#### Pointer to class and member functions

类指针与成员函数的关系

Class pointers can also be used with function calls, especially when passing objects to functions.
 类指针可以用于调用函数或在函数间传递对象。

Example:
 示例：

```cpp
void printArea(Circle *cptr) {
    cout << cptr->getArea() << endl;
}

int main() {
    Circle c;
    c.radius = 6;
    printArea(&c);  // pass pointer
}
```

This allows efficient parameter passing without copying the whole object.
 这样做能高效地传递对象，而不用复制整个对象。

#### Summary

- A **class pointer** stores the address of an object.
   类指针保存对象的内存地址。
- Use `->` to access members through a pointer.
   通过 `->` 访问对象成员。
- Use `(*ptr).member` as an alternative form.
   也可以使用 `(*ptr).member`。
- When creating objects dynamically with `new`, remember to `delete` them.
   动态分配对象后必须使用 `delete` 释放。
- Class pointers are the foundation for later topics like **dynamic binding** and **polymorphism**.
   类指针是后续学习**动态绑定（dynamic binding）**和**多态（polymorphism）**的基础。

------

要不要我接下来带你学习“对象数组和对象指针的内存布局”，
 也就是 `Circle c[3];` 与 `Circle *p = new Circle[3];` 在内存上的差异？

## 3️⃣ Public and Private Members

公有与私有成员

**Public members** can be accessed from anywhere in the program.
 **公有成员（public）** 可以在程序的任何地方访问。

**Private members** can only be accessed inside the class.
 **私有成员（private）** 只能在类的内部访问。

By default, all class members are private.
 默认情况下，类成员是私有的。

We usually use **get()** and **set()** functions to control access to private variables.
 通常使用 **get()** 和 **set()** 函数来访问和修改私有变量。

Advantages: data protection and information hiding.
 优点：保护数据完整性、隐藏内部实现细节。

Example:

```cpp
class DayOfYear {
private:
    int month;
    int day;
public:
    void set(int m, int d) { month = m; day = d; }
    int get_month() { return month; }
    int get_day() { return day; }
};
```

------

## 4️⃣ Friend Function

友元函数

Sometimes we want a function outside the class to access private data.
 有时我们希望类外的函数也能访问类的私有成员。

We can declare it as a **friend function** using the keyword `friend`.
 可以使用关键字 `friend` 将函数声明为**友元函数**。

Friend functions are not member functions but can access private members.
 友元函数并非类的成员函数，但可以直接访问其私有数据。

Example:
 示例：

```cpp
class DayOfYear {
    friend void printDate(DayOfYear d);
private:
    int month, day;
};
void printDate(DayOfYear d) {
    cout << d.month << "/" << d.day << endl;
}
```

------

## 5️⃣ Constructors and Destructors

构造函数与析构函数

A **constructor** initializes an object when it is created.
 **构造函数（constructor）** 在对象创建时自动调用，用于初始化成员变量。

A **destructor** is called automatically when the object is destroyed.
 **析构函数（destructor）** 在对象销毁时自动调用，用于释放资源。

A constructor has the same name as the class and no return type.
 构造函数与类同名且没有返回类型。

A destructor has the same name preceded by `~`.
 析构函数在名称前加 `~` 符号。

Example:
 示例：

```cpp
class Circle {
private:
    int radius;
public:
    Circle() { radius = 0; }             // Default constructor  
    Circle(int r) { radius = r; }       // Parameterized constructor  
    ~Circle() { cout << "Deleted"; }     // Destructor  
};
```

**Initializer list** is a preferred way to initialize members: `Circle(int r): radius(r) {}`
 **初始化列表** 是推荐的成员初始化方式，例如 `Circle(int r): radius(r) {}`。

We can **overload** constructors to create objects in multiple ways.
 可以**重载**构造函数以多种方式创建对象。

If a class contains another object as a member, that member’s constructor is called first.
 如果类中包含另一个类的对象成员，该对象的构造函数会先被调用。

------

## 6️⃣ Static Members

静态成员

A **static member variable** is shared by all objects of the class.
 **静态成员变量（static member variable）** 被所有对象共享。

It is declared inside the class and defined outside.
 在类中声明、类外定义。

A **static member function** can only access static variables.
 **静态成员函数** 只能访问静态成员变量。

Example:
 示例：

```cpp
class Circle {
public:
    static int count;
    Circle() { count++; }
};
int Circle::count = 0;
```

------

## 7️⃣ The C++ String Class

C++ 标准字符串类

The C++ `string` class (in `#include <string>`) provides many useful functions and operators.
 C++ 中的 `string` 类（需 `#include <string>`）提供了丰富的函数与运算符。

Examples of constructors:
 构造方式示例：

```cpp
string s1;
string s2("cs2310");
string s3(s2);
string s4(5, 'a'); // "aaaaa"
```

Main operations:
 主要操作：

- `=` or `assign()` → assignment 赋值
- `+=` or `append()` → concatenation 拼接
- `at()` or `[]` → access characters 访问字符
- `find()`, `rfind()` → find substring 查找子串
- `replace()`, `insert()`, `erase()` → modify string 修改内容
- `substr(pos, n)` → extract substring 提取子串
- `compare()` → compare two strings 比较字符串（返回 0、<0 或 >0）

Example:
 示例：

```cpp
string email = "abc@cityu-dg.edu.cn";
int pos = email.find('@');
string username = email.substr(0, pos); // Extract "abc"
```

------

## 🧾 Summary

总结

- **Class = Data + Functions** → 模板
- **Object = Instance of Class** → 实例
- **Access Control** → 使用 public/private 保护数据
- **Constructor/Destructor** → 对象的初始化与清理
- **Friend Function** → 外部函数访问私有数据的方式
- **Static Member** → 类级共享变量
- **String Class** → C++ 内置字符串工具

