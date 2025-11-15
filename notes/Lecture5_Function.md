# 🧩 CS2310 Lecture 5 — Function

------

## 1️⃣ What is a Function?

A **function** is a collection of statements that performs a specific task.
 Functions help break a program into smaller, manageable parts — each doing one clear task correctly.
 This follows the **KISS principle (Keep It Simple and Short)**.

**函数（Function）** 是执行特定任务的一组语句，用来把复杂问题拆分成可管理的部分。
 遵循 **KISS 原则（保持简洁和单一功能）**，每个函数只做一件事，并且做对。

✅ 优点：

- 避免重复代码（Avoid code repetition）
- 提高可读性（Improve readability）
- 方便调试与维护（Easier debugging & maintenance）
- 可多次调用（Can be invoked multiple times）

------

## 2️⃣ Function in C++

C++ provides a rich **Standard Library** of functions, such as:

- `<cmath>` — mathematical functions (`sqrt`, `pow`)
- `<cstring>` — string functions (`strlen`, `strcmp`)
- `<iostream>` — input/output (`cin`, `cout`)

------

## 3️⃣ Defining and Calling Your Own Function

Example:

```cpp
void printHello(int n) {
    for (int i = 0; i < n; i++)
        cout << "Hello\n";
}
```

Call:

```cpp
printHello(3);
```

Execution flow:
 `main()` → call `printHello()` → execute loop → return to `main()`.

------

## 4️⃣ Parameter Passing（参数传递方式）

| Type              | Explanation                                      | Example                  |      |
| ----------------- | ------------------------------------------------ | ------------------------ | ---- |
| Call by Value     | Copies the argument’s value 传值，不影响原变量   | `f(y)`                   |      |
| Call by Pointer   | Passes variable’s address 传地址，可修改原值     | `f(&y)`                  |      |
| Default Parameter | Uses default value if omitted 可给参数设置默认值 | `void f(int a, int b=0)` |      |

### Example – Call by Pointer

```cpp
void f(char *c1_ptr) {
    *c1_ptr = 'B';
}
int main() {
    char c1 = 'A';
    f(&c1);     // modifies c1 directly
    cout << c1; // prints 'B'
}
```

➡️ *Pointer passing can change the original variable value.*



### Default Parameters

A **default parameter** gives a function parameter a pre-defined value that will be used **if the caller does not provide an argument** for it.
 If the caller **does provide a value**, that value **overrides** the default one.

**默认参数（Default Parameter）** 是在函数定义中为某个形参（formal parameter）设置一个**默认值**。
 在调用函数时：

- 如果**没有传入该参数**，则使用默认值；
- 如果**传入了参数**，则使用传入的值（默认值被覆盖）。

#### Example — With and Without Default Parameter

```cpp
#include <iostream>
using namespace std;

void greet(string name = "Guest") {
    cout << "Hello, " << name << "!\n";
}

int main() {
    greet();          // uses default value → "Guest"
    greet("Jeremy");  // uses passed value → "Jeremy"
}
```

**Output:**

```
Hello, Guest!
Hello, Jeremy!
```

在 `greet()` 中，形参 `name` 被赋予默认值 `"Guest"`。
 调用时：

- `greet()` → 未传参，使用默认值；
- `greet("Jeremy")` → 传参，默认值被覆盖。

所以：**有默认值的形参可以不传入**，也可以传入值覆盖它。

#### Multiple Parameters with Defaults

```cpp
void f(int a, int b = 2, int c = 5) {
    cout << a << ", " << b << ", " << c << endl;
}

int main() {
    f(10);          // b=2, c=5  → 10, 2, 5
    f(10, 20);      // b=20, c=5 → 10, 20, 5
    f(10, 20, 30);  // b=20, c=30 → 10, 20, 30
}
```

**Rule:**
 Default parameters **must appear on the right** of all non-default parameters. 默认参数必须放在**普通参数的右侧**。
 Otherwise the compiler cannot tell which argument corresponds to which parameter. 否则会导致编译器无法匹配参数位置。

#### ❌ Invalid Example

```cpp
// ❌ Error: default parameter on the left side
void f(int a = 1, int b, int c = 2);
```

🛑 Compile Error：

```
error: default argument missing for parameter 'b'
```

⚠️ 解释：
 默认参数 `a` 在最左边，而中间的 `b` 没有默认值，会导致调用时歧义。

正确写法：

```cpp
void f(int a, int b = 1, int c = 2);
```

####  Default Parameters in Prototype

You can specify default values **either** in the function declaration **or** in the definition — **but not both**.

默认参数可以写在**函数声明**或**函数定义**中，但不能两处都写。
 否则会产生重复定义错误。

Example:

```cpp
// ✅ Write default in declaration
void f(int a, int b = 3);
void f(int a, int b) { cout << a + b; }

// ❌ Wrong: repeated default
// void f(int a, int b = 3) { ... }
```

#### Summary Table

| 场景             | 行为       | 示例                   | 结果 |
| ---------------- | ---------- | ---------------------- | ---- |
| 未传入参数       | 使用默认值 | `f(3)` → `b=0`         | ✅    |
| 传入参数         | 覆盖默认值 | `f(3, 4)`              | ✅    |
| 默认参数在左边   | 语法错误   | `f(int a=0, int b)`    | ❌    |
| 默认参数定义重复 | 语法错误   | 在声明和定义都写默认值 | ❌    |

#### Key Takeaways（要点）

| 英文                                                 | 中文                             |
| ---------------------------------------------------- | -------------------------------- |
| Default parameters simplify function calls           | 默认参数让函数调用更灵活         |
| Can omit arguments at the end of parameter list      | 可以省略最后几个参数             |
| Provided value overrides the default one             | 传入的值会覆盖默认值             |
| Defaults must be rightmost                           | 默认参数必须放在右侧             |
| Specify defaults once (in declaration or definition) | 默认值只能定义一次（声明或定义） |

------

## 5️⃣ Returning Values（返回值）

```cpp
int f(int x) {
    x = 4;
    return x;
}
int main() {
    int y = 3;
    y = f(y);
    cout << y;  // Output: 4
}
```

In C++, the **type of the expression in `return` must match the function’s declared return type**.
 If it does **not** match, **the compiler will try to perform an implicit type conversion** (if possible).
 However, if the conversion is not allowed or causes data loss, you’ll get a **compiler warning or error**.

在 C++ 中，函数的 **`return` 返回值类型必须与函数声明中指定的类型一致**。
 如果类型不同，编译器会尝试**自动类型转换（implicit conversion）**。
 若无法安全转换或会导致精度丢失，编译器会发出**警告（warning）或错误（error）**。

------

## 6️⃣ Passing Arrays（数组参数）

### 📘 Example – 1D Array

```cpp
void f(int a[]) {
    a[0] = 10;
}
int main() {
    int a[3] = {1, 2, 5};
    f(a);
    cout << a[0];  // Output: 10
}
```

➡️ Array names act as pointers — modifications persist after function ends.

### 📘 Example – 2D Array

```cpp
void sort2D(int x[][4]) {
    // Sort each row
}
```

⚠️ The **first dimension** size is optional, but the **second** must be specified.

非常棒 ✅！你这个问题正好触及了 C++ 数组传参机制的“**编译器识别边界问题**”，也是 Lecture 5（slides 27–31）中提到但没详细展开的重点。
 我们下面系统讲解这个问题——含英文说明、中文解释、代码示例和编译规则总结。

### Size Specification

#### 🧩1D Array Parameters

When passing a **one-dimensional array** to a function, you **do not need to specify its size** inside the parameter declaration.
 That’s because the array name decays (转化) to a **pointer** to its first element, and the compiler doesn’t need to know its full length at compile time.

当函数接收**一维数组**参数时，形参中**不需要指定数组大小**。
 因为在函数调用时，数组名会“退化”为一个**指向首元素的指针**，
 编译器只需知道元素类型（`int`、`double`等），不需知道数组总长度。

✅ Example: 1D Array without Size

```cpp
void printArray(int arr[]) {
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    printArray(a);  // size is not needed in parameter
}
```

🟢 Works fine!
 Because inside the function, `arr` is treated as a pointer (`int *arr`).

🟡 Optional Style Variants

C++ allows several equivalent notations for 1D array parameters:

| Declaration form    | Equivalent meaning |
| ------------------- | ------------------ |
| `void f(int a[])`   | `void f(int *a)`   |
| `void f(int a[10])` | `void f(int *a)`   |
| `void f(int *a)`    | Same as above      |

⚠️ 即使你写 `int a[10]`，编译器仍然会忽略这个大小信息，因为函数参数中它只是语法提示（不影响行为）。

#### 🧩  2D or Higher Dimension Array Parameters 

For **multi-dimensional arrays**,
 you **can omit the first dimension**,
 but **must specify the size of all remaining dimensions** (e.g. the second one).
 This is because the compiler must know how to compute memory offsets.

对于**多维数组**，

- 第一维（行数）可以不写，
- 但**第二维（列数）和更高维度必须写明**。
   因为编译器需要知道每一行的长度，以便正确计算内存偏移量。

✅ Example: Omit First Dimension

```cpp
void print2D(int arr[][3]) {  // second dimension size required
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };
    print2D(matrix);
}
```

✅ Works fine — compiler knows each row has 3 columns.

❌ Example: Missing All Dimensions

```cpp
void print2D(int arr[][]) {  // ❌ Error
    ...
}
```

🛑 Compiler Error:

```
error: array type has incomplete element type 'int []'
```

📗 Explanation (说明):
 编译器不知道每行的长度（即第二维的大小），所以无法计算 `arr[i][j]` 在内存中的偏移地址。

> Why the Second Dimension Is Required
>
> Let’s recall the memory layout:
>  A 2D array `int arr[2][3]` is stored **contiguously** as:
>
> ```
> arr[0][0] arr[0][1] arr[0][2] arr[1][0] arr[1][1] arr[1][2]
> ```
>
> To access `arr[i][j]`, compiler calculates:
>
> ```
> Address = base_address + (i * number_of_columns + j) * sizeof(int)
> ```
>
> Hence, without knowing `number_of_columns`, the compiler **cannot** compute where each row begins.
>
> ---
>
> #### 💡 Alternative — Pointer or `std::vector`
>
> 在现代 C++ 中，二维或动态数组通常不会用固定大小数组，而使用以下替代方式：
>
> ### (1) Pointer to Pointer
>
> ```cpp
> void print2D(int **arr, int rows, int cols);
> ```
>
> ### (2) `std::vector`
>
> ```cpp
> void print2D(const vector<vector<int>> &arr);
> ```
>
> 这种方式更安全且支持动态大小（Dynamic size）。

#### ✅  Summary Table（总结表）

| 类型               | 大小是否必须指定 | 示例                    | 是否合法 | 说明           |
| ------------------ | ---------------- | ----------------------- | -------- | -------------- |
| 一维数组           | ❌ 可省略         | `void f(int a[])`       | ✅        | 视作指针       |
| 一维数组（带大小） | ✅ 可写可不写     | `void f(int a[10])`     | ✅        | 大小信息被忽略 |
| 二维数组           | ✅ 必须写第二维   | `void f(int a[][4])`    | ✅        | 必须写明列数   |
| 二维数组（全省略） | ❌                | `void f(int a[][])`     | ❌        | 编译错误       |
| 三维数组           | ✅ 需写后两维     | `void f(int a[][3][4])` | ✅        | 需写明列与深度 |

#### Key Takeaways（重点总结）

| 英文                                                      | 中文                              |
| --------------------------------------------------------- | --------------------------------- |
| 1D arrays can omit size                                   | 一维数组参数可省略大小            |
| Multi-dimensional arrays require later sizes              | 多维数组必须写明后续维度大小      |
| Compiler needs inner dimension to calculate memory offset | 编译器需知道列宽以计算内存偏移    |
| Array name decays to pointer                              | 数组名会退化为指针                |
| Use `std::vector` for flexible dynamic arrays             | 建议用 `std::vector` 管理动态数组 |

------

是否希望我帮你接着整理下一页「Function Prototype（函数原型）」的中英文对照笔记？

## Function Prototype（函数原型）

A **function prototype** tells the compiler the function name, parameters, and return type before implementation.
 You can define it in a header file (`.h`).

**函数原型** 是函数的声明，用于提前告诉编译器函数的输入输出类型。
 可以放在头文件 `.h` 中，在 `.cpp` 中实现。

```cpp
// mylib.h
int calMin(int, int);

// mylib.cpp
int calMin(int a, int b) {
    return (a > b) ? b : a;
}
```

------

## 8️⃣ Function Overloading（函数重载）

C++ allows functions with the same name but different parameter lists.

```cpp
void print(int n);
void print(char a);
void print(char a, char b);
```

**函数重载**：同名函数，只要参数**类型**或**数量**不同即可。
 ⚠️ 不能仅靠返回类型区分。

------

## 9️⃣ Recursive Functions（递归函数）

### Example – Factorial

```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

###  Example – Count Zeros

```cpp
int zeros(int num) {
    if (num == 0) return 1;
    else if (num < 10 && num > -10) return 0;
    else return zeros(num / 10) + zeros(num % 10);
}
```

**递归函数**是函数自身调用自身（直接或间接）。
 需有**终止条件 (base case)** 防止无限递归。
 例如：

- 阶乘函数 (`factorial`)
- 幂函数 (`exp(n, p)`)
- 统计数字中 0 的个数 (`zeros`)
- 打印字符串 n 次 (`nPrintln`)

------

## 🔟 Static Variable（静态变量）

A **static** variable retains its value between function calls.

```cpp
int factorial(int n) {
    static int count = 0;
    count++;
    ...
}
```

`static` 变量在函数结束后不会被销毁，可在递归中记录调用次数。
 例如统计递归次数或累计求和。

 `count` is initialised to 0. When the function is called next time, `count` will not be assigned to 0.

`static` 变量的初始化语句在程序运行过程中只会执行一次；之后的所有函数调用都使用同一个内存地址的值；因此不会重新被赋值为 0。

```cpp
static int count;
count = 0;
```

注意是这样写，`count` 会被重新赋值为0。因为这不是初始化，而是普通的赋值语句。



------

## Extra Supplement： Returning Multiple Values（Optional: 多返回值函数）

虽然讲义未涉及，但在实际编程中常需要返回多个结果。
 以下是四种常用方法：

| 方法            | 示例                        | 说明                 |
| --------------- | --------------------------- | -------------------- |
| 指针传参        | `void cal(int *x, int *y)`  | 通过修改地址间接返回 |
| 结构体 `struct` | `Result compute()`          | 打包多个字段返回     |
| `std::pair`     | `return {sum, avg};`        | 返回两个值           |
| `std::tuple`    | `return make_tuple(a,b,c);` | 返回任意数量的值     |

Example:

```cpp
#include <tuple>
using namespace std;

tuple<int, double> compute(int a, int b) {
    return make_tuple(a + b, (a + b) / 2.0);
}

int main() {
    auto [sum, avg] = compute(3, 5);
    cout << sum << ", " << avg;
}
```

------

## ✅ Summary Table（总结表）

| 主题               | 关键词                  | 示例代码                     |
| ------------------ | ----------------------- | ---------------------------- |
| Function Basics    | Definition, KISS        | `void printHello()`          |
| Parameter Passing  | call by value/pointer   | `f(&x, y)`                   |
| Default Parameter  | default values          | `f(int a, int b=0)`          |
| Array Parameter    | array name as pointer   | `void f(int a[])`            |
| Function Prototype | declaration before use  | `int f(int, int);`           |
| Overloading        | same name, diff. params | `print(int)` / `print(char)` |
| Recursion          | base case + recursion   | `factorial(n)`               |
| Static Variable    | persist across calls    | `static int count;`          |
| Multiple Returns   | struct / tuple          | `make_tuple(a,b,c)`          |

------

是否希望我帮你把这份笔记导出为 **Markdown 文件（.md）** 或 **Word 版本（.docx）**，方便你直接放入复习资料？