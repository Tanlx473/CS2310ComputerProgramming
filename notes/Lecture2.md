# CS2310 Lec02 – Operators, I/O, Conditionals 

> Scope: **Operators, precedence/associativity, assignment vs equality, logical/relational ops, short‑circuit, conditional `?:`, `if/else` (including nested & pitfalls), `switch`, and basic I/O (`cin`/`cout` with `<iomanip>` manipulators).** English first, then concise Chinese glosses in parentheses.

------

## 0) Quick Sheet｜速查

- Headers: `#include <iostream>` and optionally `#include <iomanip>`（头文件）。
- Namespaces: `using namespace std;` or qualify `std::cin`, `std::cout`（命名空间）。
- Output newline: prefer `"\n"` for speed; `endl` also flushes buffer（换行与刷新）。
- Only **integer types** (`int/char/short/long`) allowed in `switch` expression（switch 表达式需整数类型）。
- Common pitfalls: `=` vs `==`, stray semicolon after `if`, dangling `else` binds to **nearest** `if`（易错点）。

------

## 1) Arithmetic & Update Operators｜算术与自增自减

- `+ - * / %` act on integers; `/` yields **quotient** (e.g., `5/2==2`), `%` yields **remainder** (`5%2==1`)（整数除法与取余）。
- `k++` / `k--` **postfix**: use old value, then modify（后缀先用后改）。
- `++k` / `--k` **prefix**: modify first, then use（前缀先改后用）。

**Trace**

```cpp
int k=0; int i;
i = 1 + (k++); // i=1, k=1
k=0; i = 1 + (++k); // i=2, k=1
```

（先后次序不同，结果不同）

**Digit‑sum idea｜三位数的数位和**

```cpp
int n=456;
int a = n/100;   // 4
int b = (n%100)/10; // 5
int c = n%10;    // 6
int s = a+b+c;   // 15
```

（用 `/` 与 `%` 分离百十个位）

------

## 2) Precedence & Associativity｜优先级与结合性

- Precedence（优先级）决定不同运算符的先后（如 `+` vs `/`）。
- Associativity（结合性）决定同级运算符的方向（如 `+` 左结合）。

**Common bands（常见分组自高到低）**

1. Unary `+ - ++ --`（一元，右结合）
2. `* / %`（左结合）
3. `+ -`（左结合）
4. `< <= > >=`（左结合）
5. `== !=`（左结合）
6. `&&`（左结合）
7. `||`（左结合）
8. `?:`（右结合）
9. `= += -= *= /=`（右结合）

**Ambiguity example｜歧义示例**

```cpp
int a, b=2, c=1;
a = b+++c; // parses as (b++) + c, 不是 b + (++c)
```

（`++` 优先级与右结合性导致解析为后缀自增）

------

## 3) Assignment vs Equality｜赋值与相等

- `=` is **assignment** (赋值)，`==` is **equality test** (相等比较)。
- In C++, assignments **have a value**（赋值表达式有值）：`a = (b=2) + (c=3); // a=5`
- Non‑zero is **true**, zero is **false**（非零为真，零为假）。

**Bug pattern｜常见错误**

```cpp
int x=0,y=1;
if (x = y) { /* always true because x becomes 1 */ }
```

（误把 `=` 当作 `==`）

------

## 4) Relational & Logical｜关系与逻辑

- Relational: `< <= > >=`（关系运算）。
- Equality: `== !=`（相等/不等）。
- Logical: `! && ||`（非/与/或）。
- **Short‑circuit**（短路求值）：`&&` 左侧为假则右侧不求值；`||` 左侧为真则右侧不求值。

**Short‑circuit traces｜短路示例**

```cpp
int i=2,j=2,k;
k = (i=2) && (j=2);  // i=2,j=2
k = (i=0) && (j=3);  // i=0,j仍为2（右侧未执行）
k = i || (j=4);      // i=0 -> 执行右侧，j=4
k = (i=2) || (j=5);  // i=2为真，右侧不执行，j保持4
```

（`&&`/`||` 短路带来副作用差异）

**Math vs C++｜数学式与 C++**

```cpp
if (mark>=70 && mark<=100) { }
// 不可写成: if (70<=mark<=100) { } // 错误
```

------

## 5) Conditional Operator `?:`｜条件运算符

- Form: `expr1 ? expr2 : expr3`（条件为真执行 `expr2`，否则 `expr3`）。
- Expression returns the selected branch’s value（整个表达式有值）。

**Max of two｜两数取大**

```cpp
int m = (x>y) ? x : y;
```

------

## 6) `if/else` & Nesting｜选择语句与嵌套

- One‑way `if (cond) stmt;`（单分支）。
- Two‑way `if/else`（双分支）。多分支可用 `else if` 链（多分支）。
- **Empty statement pitfall**（空语句陷阱）：`if(x!=5);` 导致条件被忽略。
- **Dangling else** binds to the **nearest** unmatched `if`（else 总是和最近的 if 绑定）。

**Safer style｜更安全风格**

```cpp
if (a==1) {
    if (b==2) {
        cout<<"***\n";
    } else {
        cout<<"###\n"; // 明确地与内层 if 绑定
    }
}
```

**Leap year sketch｜闰年判定**

```cpp
bool leap = (year%4==0 && year%100!=0) || (year%400==0);
```

------

## 7) `switch` Statement｜多分支选择

- Works with integral types (e.g., `int/char`)（整数类型）。
- `case` labels must be **constant expressions**（常量表达式）。
- `break;` to prevent **fall‑through**（无 break 会穿透至下一 case）。
- `default:` optional fallback（默认分支）。

**Template**

```cpp
switch (x) {
  case 0: cout<<"Zero"; break;
  case 1: cout<<"One";  break;
  default: cout<<"Greater than one";
}
```

（注意何时省略 `break` 才是有意为之）

------

## 8) Basic I/O with iostream｜基础输入输出

- `cin >> x >> y;` uses **whitespace** as delimiters（以空白分隔）。
- `cout << value;` supports all fundamental types（输出基本类型）。
- Escape: `\n` newline, `\t` tab, `\"` quote（转义序列）。

**Formatting (iomanip)｜格式化**

- Width（宽度一次性生效）：`setw(w)` or `cout.width(w)`；短则补空格，长不截断。
- Precision（精度）：默认是**有效位数**；配合 `fixed` 则是**小数位数**（持久生效，需 `<iomanip>`）。
- Fill（填充）：`setfill('*')`；Alignment（对齐）：`setiosflags(ios::left)`（左对齐）。
- Radix（进制）：`oct/hex/dec` 切换输出进制。

**Examples｜示例**

```cpp
#include <iomanip>
cout << setw(5) << 123 << "\n";         // __123
cout << fixed << setprecision(2) << 3.1;  // 3.10
cout << setfill('*') << setw(8) << 5.6;   // *****5.6
cout << hex << 11 << " " << dec << 11;   // b 11
```

**Input table tips｜输入行为**

- `cin >> charArr;` 读到空白处结束；要读含空格的字符串使用 `getline`（此课暂聚焦基本 `>>`）。

**Output 输出行为**

`cout` — Output Stream Object（输出流对象）

1️⃣ Basic Concept 基本概念

- `cout` 是 C++ 中的**标准输出对象（standard output object）**，定义在头文件 `<iostream>` 中。
- 它通过**输出运算符（output operator）`<<`** 将数据发送到输出流（output stream）。
- 输出通常显示在屏幕上。

```cpp
#include <iostream>
using namespace std;

cout << "Hello, World!" << endl;
```

**Explanation 解释：**

- `<<` 把右边的内容送入左边的输出流（这里是 `cout`）。
- `endl` 表示换行，相当于 `\n`，但还会**刷新缓冲区（flush buffer）**。

2️⃣ Output Types 输出类型示例

| 数据类型 (Type) | 示例 (Example)                | 输出结果 (Output) | 说明 (Explanation)        |
| --------------- | ----------------------------- | ----------------- | ------------------------- |
| Integer 整数    | `cout << 21;`                 | `21`              | 输出整数值                |
| Float 浮点数    | `cout << 14.5;`               | `14.5`            | 默认 6 位有效数字         |
| Char 字符       | `cout << 'A';`                | `A`               | 单个字符                  |
| String 字符串   | `cout << "Hi";`               | `Hi`              | 双引号字符串              |
| Bool 布尔值     | `cout << true;`               | `1`               | true 输出 1，false 输出 0 |
| New line 换行   | `cout << 'a' << endl << 'b';` | `a`↵`b`           | 使用 `endl` 换行          |
| Tab 制表符      | `cout << 'a' << '\t' << 'b';` | `a b`             | 用 `\t` 添加水平制表      |

3️⃣ Formatted Output（格式化输出）

C++ 提供许多格式控制工具（称为 **manipulators 操纵符**），需要引入：

```cpp
#include <iomanip>
```

✅ (1) 设置输出宽度 `setw()`

```cpp
#include <iomanip>
cout << setw(5) << 123 << endl;
cout << setw(5) << 1234567 << endl;
```

输出：

```
  123
1234567
```

👉 `setw(5)` 表示该字段宽度为 5，不足时用空格填充（仅影响一次输出）。

✅ (2) 设置填充字符 `setfill()`

```cpp
cout << setfill('*') << setw(8) << 56 << endl;
```

输出：

```
******56
```

👉 用 `*` 填充空白部分。

✅ (3) 设置对齐方式 `setiosflags()`

```cpp
cout << setiosflags(ios::left) << setw(10) << 5.6 << endl;
```

输出：

```
5.6       
```

👉 `ios::left` 表示左对齐（默认是右对齐）。

✅ (4) 设置浮点数精度 `setprecision()` & `fixed`

```cpp
cout << 3.14159 << endl;
cout << setprecision(2) << 3.14159 << endl;
cout << fixed << setprecision(2) << 3.14159 << endl;
```

输出：

```
3.14159      ← 默认 6 位有效数字
3.1          ← 2 位有效数字
3.14         ← 固定小数点后 2 位
```

📘 注意：

- `setprecision(n)` 默认表示“**n 位有效数字**”；
- 但加上 `fixed` 后，表示“**保留小数点后 n 位**”。

------

#### ✅ (5) 设置进制（radix）

```cpp
cout << dec << 11 << endl; // 十进制
cout << oct << 11 << endl; // 八进制
cout << hex << 11 << endl; // 十六进制
```

输出：

```
11
13
b
```

------

### 4️⃣ Example 综合示例

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price = 12.5, tax = 0.08;
    cout << "Price: " << setw(8) << setfill(' ') << fixed << setprecision(2) << price << endl;
    cout << "Tax:   " << setw(8) << setfill(' ') << price * tax << endl;
    cout << "Total: " << setw(8) << price * (1 + tax) << endl;
    return 0;
}
```

输出：

```
Price:    12.50
Tax:       1.00
Total:    13.50
```

------

### 5️⃣ 小结 Summary

| 操纵符（Manipulator）          | 功能（Function）           |
| ------------------------------ | -------------------------- |
| `setw(n)`                      | 设置字段宽度（仅一次有效） |
| `setfill(ch)`                  | 设置填充字符               |
| `setprecision(n)`              | 设置数字精度               |
| `fixed`                        | 固定小数点格式             |
| `setiosflags(ios::left/right)` | 设置对齐方式               |
| `dec/oct/hex`                  | 设置进制格式               |
| `endl`                         | 输出换行并刷新缓冲区       |

------

## 9) Swap Correctly｜正确交换

**Wrong｜错误**

```cpp
int a=3,b=4; a=b; b=a; // both end as 4
```

**Right｜正确**

```cpp
int a=3,b=4,c;
c=a; a=b; b=c;
```

（临时变量保存再交换）

------

## 10) Style Guide｜编程风格

- Meaningful names & concise comments（有意义命名与简明注释）。
- Consistent indentation（统一缩进）。
- Comment purpose/arguments/returns for functions（函数头注释）。

------

## 11) Quick Drills｜随练

1. Evaluate: `int a=1; cout << (a++ + ++a);`（追踪前后缀）。
2. Write a `switch` printing weekday names for `1..7`（switch 实操）。
3. Format `3.1415926` as `3.14` then `3.142`（精度与 fixed）。
4. Write a leap‑year checker using short‑circuit（短路结合闰年）。
5. Parse a three‑digit number and print its digits sum（/ 与 % 分离位值）。

> Focus on **correct semantics first**, then formatting and style. 先保证语义正确，再处理输出格式与风格。