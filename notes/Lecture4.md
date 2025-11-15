# CS2310 Lec04 – Character, String & Structure

> Scope: **char basics & ASCII**, keyboard input buffering, printing, **C‑style strings (cstring)**: declaration/initialization, `cin >>`, `cin.get`, `cin.getline`, null terminator `\0`, common `<cstring>` APIs; **structures (struct)**: declaration, member access, arrays, pointers (`->`), nested structs, pass‑by‑value/pointer/`const` pointer. English first with concise Chinese glosses in parentheses.

------

## 0) Quick Sheet｜速查

- `char` is an **integer type** in C++ (字符在 C++ 中本质为整数) → `'a'+1=='b'`.
- `cin >> c` reads **one** non‑whitespace char; extra input stays in **buffer**（缓冲区）.
- **cstring** is `char[]` ending with **`'\0'`**（以空字符结尾）; capacity `n` ⇒ max content `n-1`.
- Use `cin.get(c)` or `cin.getline(arr, N)` to include **spaces**（读取含空格的行）.
- `<cstring>` 常用：`strcpy`/`strcat`/`strcmp`/`strlen`（注意目标缓冲区大小）.
- `struct` groups **heterogeneous** members（异质成员）; access with `.`; pointer uses `->`.
- Prefer `const T*` when a function **won’t modify** the struct（不修改时用常量指针）.

------

## 1) Character & ASCII｜字符与 ASCII

**Facts｜要点**

- Literals: `'A'`, `'b'`, `'*'`（字符字面量）
- Comparisons map to codes: `'a'<=ch && ch<='z'` same as `97<=ch && ch<=122`（字符比较即整数比较）
- Case map: `ch - 'a' + 'A'` converts lower→upper（小写转大写）

**I/O & Buffering｜输入与缓冲**

```cpp
char c1, c2, c3;      // input: CS2310↵
cin >> c1;            // 'C'
cin >> c2;            // 'S' (from buffer)
cin >> c3;            // '2'
```

（多余字符会留在缓冲区供后续读取）

**Printing a char｜打印字符**

```cpp
char c='A';
cout << c;        // stream output
cout.put(c);      // put one char
```

**Char classifier demo｜字符分类示例**

```cpp
char c; cin >> c;
if ('A'<=c && c<='Z') cout << "Upper\n";
else if ('a'<=c && c<='z') cout << "Lower\n";
else if ('0'<=c && c<='9') cout << "Digit\n";
else cout << "Special\n";
```

------

## 2) C‑String (char[])｜C 风格字符串

**Decl & Init｜声明与初始化**

```cpp
char s1[12];                 // up to 11 chars + '\0'
char s2[] = "John";         // compiler adds '\0'
// char name[10]; name = "john"; // ❌ 不能在声明后再用赋值整体初始化
```

**Reading & Printing｜读取与输出**

```cpp
char word[20];
cin >> word;          // stops at whitespace（遇空白停止）
cout << word;
```

**Read a line (with spaces)｜整行读取（含空格）**

```cpp
char line[20];
cin.getline(line, 20); // reads up to 19 chars + '\0'
if (!cin) {            // 长度溢出/到达源结尾/错误 → 状态位被置位
    cin.clear();       // 清除状态位后可继续
}
```

**Single‑char get｜读取单个字符**

```cpp
char c; do { cin.get(c); cout << c; } while(c!='\n');
```

**Why `\0` matters｜为何需要 `\0`**

- `cout` prints bytes **until** it meets `\0`（输出遇到 `\0` 终止）
- If you overwrite the terminator, printing may **run past** intended end（改写终止符会越界输出）

**Count frequency example｜频次统计函数**

```cpp
int count_char(const char s[], char target){
    int f=0; for (int i=0; s[i] != '\0'; ++i) if (s[i]==target) ++f; return f;
}
```

------

## 3) `<cstring>` Common APIs｜常用库函数

```cpp
#include <cstring>
char a[40], b[40] = "This is CS2310";
strcpy(a, b);                 // 复制（确保 a 足够大）
strcat(a, " Lecture.");      // 追加（同样注意容量）
int cmp = strcmp("AB", "AC"); // 逐字典序比较（<0/0/>0）
size_t n = strlen(a);         // 长度（不含'\0'）
```

> 注意：部分编译器/IDE 推荐 `strcpy_s/strcat_s`（更安全，带入参检查）。

**Implement `strlen` idea｜手写长度函数**

```cpp
int length_of_string(const char s[]){ int i=0; while(s[i] != '\0') ++i; return i; }
```

**Merge two sorted strings｜合并两个已排序字符串**

- Step 1: 先分别排序两个 `char[]`（可用简单冒泡/选择）
- Step 2: 双指针线性归并到目标数组（稳定，O(n+m)）

------

## 4) `struct` Basics｜结构体基础

**Declare & Use｜声明与使用**

```cpp
struct Book{
    char id;           // e.g., 'A'
    char subject[32];  // cstring subject
    int  price;        // 整型价格
    int  month, day;   // 出版月/日
};

Book b; b.id='A';
strcpy(b.subject, "Math");
b.price=80; b.month=9; b.day=1;
cout << b.id << " (" << b.price << ")\n";
```

**Struct arrays｜结构体数组**

```cpp
Book shelf[10];
shelf[0] = b; // 逐个成员或整体赋值（POD）
```

**Pointer & `->`｜指针访问**

```cpp
Book *p = &b;
p->price = 90;           // 等价于 (*p).price = 90;
```

**Nested structs｜嵌套结构体**

```cpp
struct TA   { int stuID; };
struct Course{ int courseID; double score; TA myTA; };
Course c; c.courseID=1111; c.myTA.stuID=123456;
```

**Passing to functions｜传参方式**

```cpp
void print1(Book x){ cout<< x.id <<"\n"; /* 传值：副本，可改副本 */ }
void print2(Book* p){ cout<< p->id<<"\n"; /* 指针：可原地修改 */ }
void print3(const Book* p){ cout<< p->id<<"\n"; /* const 指针：禁止修改 */ }
```

> 建议：若函数不修改对象，用 `const T*`（或 `const T&`）表明意图，避免拷贝成本。

------

## 5) Typical Pitfalls｜常见坑点

- **忘记 `\0`**：手动构造/拼接后未写入终止符（导致越界打印）
- **缓冲区不足**：`strcpy/strcat` 目标数组过小（缓冲区溢出）
- **`cin >>` vs `getline`**：`>>` 读到空白截止，`getline` 才能读整行
- **混用 `string` 与 cstring**：`std::string` 与 `char[]` API 不同（本讲聚焦 cstring）
- **结构体指针解引用**：误写 `p.price` 而非 `p->price`
- **函数参数选择**：需要修改时传指针/引用；只读时传 `const` 引用/指针

------

## 6) Quick Drills｜随练

1. 写函数：将小写字母转大写（若非字母则原样返回）。
2. 用 `cin.getline` 读入最多 30 字符的一行，并输出其长度与最后一个非空白字符。
3. 写 `count_char(s, 'a')` 与 `count_char(s, 'A')` 的累计统计（忽略大小写）。
4. 写 `mergeStrings`：对两个输入的 cstring（各自先排序）做归并输出。
5. 定义 `struct Student{int id; char name[20]; int score;}`，读入 N 个学生并按 `score` 升序输出（冒泡/选择，双数组不再需要，用结构体数组即可）。

> Master the **three pillars** of this lecture: char as int, cstring with `\0`, and struct with pointer/const semantics. 掌握三大支柱：字符即整数、以 `\0` 结尾的 cstring、以及带指针/常量语义的结构体。