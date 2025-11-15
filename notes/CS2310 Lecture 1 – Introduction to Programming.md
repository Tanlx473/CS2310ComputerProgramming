## CS2310 Lecture 1 – Introduction to Programming

## 1 Programming Languages 编程语言

**Three Levels of Languages 三种语言层次：**

| 语言类型                                    | 特点                                  | 示例                 |
| ------------------------------------------- | ------------------------------------- | -------------------- |
| Machine Language（机器语言）                | 二进制代码，计算机直接理解            | 01010110...          |
| Symbolic/Assembly Language（符号/汇编语言） | 英文缩写符号（mnemonics）代表机器指令 | MOV, ADD, JMP        |
| High-Level Language（高级语言）             | 接近人类语言，可读性高                | C, C++, Java, Python |

**Syntax（语法） & Libraries（库）**

- 不同语言在语法与标准库上不同
   例：

  ```java
  if (a > b) { System.out.println("a > b"); }
  ```

  ```pascal
  if a > b then writeln('a > b');
  ```

- 基本语法结构：

  - Variable / function declaration（声明）
  - Condition（条件）
  - Loop（循环）
  - Built-in functions（内置函数）

## 2 Building a C++ Program 构建C++程序

**Steps 构建步骤：**

1. **Write** 源代码（.cpp）
2. **Preprocess** 预处理（处理 #include 等）
3. **Compile** 编译（语法检查 → 生成对象文件 .obj）
4. **Link** 链接（整合库与对象 → 可执行文件 .exe）

**Example 示例：**

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!\n";
    return 0;
}
```

------

### 4️⃣ Function: `main()` 主函数

- 程序入口点（execution starts here）
- `int main()` 返回值类型为int（标准写法）
- 花括号 `{}` 包裹函数体
- 区分大小写（case-sensitive）

------

### 5️⃣ `cout` 与输出流

- `cout` = Console Output（标准输出对象）

- 来自 `<iostream>` 库

- `<<` 称为**插入运算符 (insertion operator)**

- 示例：

  ```cpp
  cout << "Hello, world!\n";
  cout << "Age: " << 18 << endl;
  ```

**转义字符 (Escape sequences)：**

| 符号   | 含义         |
| ------ | ------------ |
| `\n`   | 换行 newline |
| `\\`   | 输出反斜杠   |
| `\"`   | 输出双引号   |
| `endl` | 等价于 `\n`  |

------

### 6️⃣ Syntax 语法规则与词法元素

**Token（词法单元）分类：**

- Keywords（保留字）→ 如 `int`, `return`
- Identifiers（标识符）→ 用户定义名（变量、函数）
- Constants（常量）→ `"Hello"`, `3.14`
- Operators（运算符）→ `+`, `-`, `=`
- Punctuators（标点符号）→ `;`, `,`, `{}`

**命名规则：**

- 只能使用字母、数字、下划线
- 不能以数字开头
- 区分大小写
- 不可使用保留字

------

### 7️⃣ Variables & Constants 变量与常量

**四个属性：**

- **Name**（名称）
- **Type**（类型）
- **Address**（地址）
- **Scope**（作用域）

**声明格式：**

```cpp
data_type variable_name;
data_type variable_name = value;
```

**C++内置数据类型：**

| 类型类别 | 关键字                             | 示例         |
| -------- | ---------------------------------- | ------------ |
| 整数型   | `int`, `short`, `long`, `unsigned` | 3, -5, 1024  |
| 浮点型   | `float`, `double`                  | 3.14, 1.23e2 |
| 字符型   | `char`                             | 'A', '\n'    |
| 逻辑型   | `bool`                             | true, false  |

**常量定义：**

```cpp
const float PI = 3.14159;
const char NAME[] = "Andy";
```

------

### 8️⃣ Memory, Address & Pointers 内存与指针

**Memory & Address**

- 变量存储在内存中，地址通常为十六进制（如 `0x00023AF0`）
- 连续声明的变量常分配在相邻内存

**Pointer（指针）定义：**

- 指针是存储变量地址的变量

```cpp
int x = 10;
int *p = &x;
cout << *p; // 输出x的值
```

| 操作符 | 含义                   |
| ------ | ---------------------- |
| `&`    | 取地址                 |
| `*`    | 解引用（访问指向的值） |

------

### 9️⃣ Variable Scope 变量作用域

| 类型                        | 定义位置            | 可见性           |
| --------------------------- | ------------------- | ---------------- |
| Local Variable（局部变量）  | 函数或代码块内 `{}` | 仅在该范围内有效 |
| Global Variable（全局变量） | 所有函数外定义      | 可被所有函数访问 |

**命名遮蔽 (Name hiding)：**
 局部变量会覆盖同名全局变量。

**Namespace（命名空间）**

- 用于避免命名冲突

```cpp
namespace level1 {
    int a = 1;
    namespace level2 { int a = 2; }
}
cout << ::a; // 全局a
cout << level1::a;
cout << level1::level2::a;
```

------

### 🧩 Exam Focus 考试重点总结

✅ Programming language levels
 ✅ Basic program structure (main, cout, iostream)
 ✅ Syntax rules, keywords, identifiers
 ✅ Data types (int, char, float, double, bool)
 ✅ Constants & variable declaration
 ✅ Pointers & memory address
 ✅ Scope (local/global/namespace)
 ✅ Escape characters & endl
 ✅ Type conversion (promotion/demotion)
 ✅ sizeof operator

------

是否希望我接下来把这些内容整理成更适合考试记忆的 **章节速查表 + 中英文术语表格版**（例如打印型笔记风格）？