# CS2310 Midterm – Bilingual Exam Notes

> Scope: Based on **Lec 01** (Intro to C++) and the **Mid‑Term Mock Test**. English first, followed by concise Chinese glosses for key terms (in parentheses). Only `<iostream>` and `<iomanip>` are permitted in the mock (只能使用 iostream 与 iomanip)。

------

## 0) Quick Exam Checklist｜考试速查

- **Headers**: `#include <iostream>`, optionally `<iomanip>` for formatting（头文件）。
- **Namespace**: either `using namespace std;` or qualify with `std::`（命名空间）。
- **`main` signature**: prefer `int main(){ ... return 0; }`（main 函数签名）。
- **I/O**: `cout << ... << '\n';` or `<< endl;`（输出）。
- **No extra libs**: Do **not** include `<vector>`, `<string>`, etc. unless allowed（禁止额外库）。
- **Initialization**: initialize counters/accumulators before use（初始化计数/求和变量）。
- **Loops**: watch bounds (`i < n` vs `i <= n`)（循环边界）。
- **Types**: `int`, `double`, `char`, `bool` basics; casting when needed（基本类型与类型转换）。
- **Pre/Post ++**: `x++` returns old value; `++x` returns new value（自增运算顺序）。
- **Switch**: `break` each case to avoid fall‑through（switch 需 break 防穿透）。

------

## 1) Language & Build Basics｜语言与构建基础

- **Build pipeline**: Preprocess → Compile → Link → Execute（预处理→编译→链接→运行）。
- **Tokens**: keywords, identifiers, literals, operators, punctuators（词法单元：关键字/标识符/常量/运算符/分隔符）。
- **Keywords** (subset): `int`, `double`, `char`, `if`, `else`, `switch`, `for`, `while`, `break`, `continue`, `return`, `const`, `class`, `public`, `private`（常见关键字）。
- **Identifiers**: start with letter/underscore; case‑sensitive; meaningful names（标识符规则）。
- **cout/endl/"\n"**: `endl` flushes stream; `"\n"` just newline（endl 会刷新，\n 仅换行）。

**Minimal template｜最小模板**

```cpp
#include <iostream>
using namespace std;
int main(){
    cout << "Hello\n"; // or std::cout
    return 0;
}
```

------

## 2) Types, Literals, and Conversions｜类型与转换

- **Integer (`int`)**: typically 4 bytes; beware overflow（整数与溢出）。
- **`char` ↔ int**: chars are small integers (ASCII). `'a'+1 == 'b'`（字符与整数可互转）。
- **Floating (`double`)**: 8 bytes, ~15 digits precision; prefer over `float`（双精度）。
- **`sizeof(T)`**: returns byte size of type/object（字节大小）。
- **Implicit conversions**: in `x + y`, narrower promotes; in assignment, RHS converts to LHS type（隐式提升/降级）。
- **Explicit cast**: `(int)`, `static_cast<int>(...)`（显式类型转换）。

**Common pitfalls｜易错点**

- Assigning double to int truncates（double 赋值给 int 截断）。
- Printing `char` arithmetic prints characters unless cast（字符算术输出）。

------

## 3) Operators & Control Flow｜运算与控制流

- **Pre/Post increment**: `a = x++;` (use old x, then x=x+1); `b = ++a;` (a=a+1, then use new a)（前/后缀 ++）。
- **`if/else`**: braces `{}` prevent dangling else/one‑line bugs（花括号避免歧义）。
- **`switch(char)`**: remember `break;` in each case; `default` as fallback（switch 用 break）。
- **Loops**: `for(init; cond; step){}` iterates while `cond` true; `continue` skips to next; `break` exits loop（循环控制）。

------

## 4) Arrays & Strings (C‑style)｜数组与 C 风格字符串

- **Array decl**: `int a[10];` index 0..9（数组下标）。
- **Traverse backward**: `for(int i=4;i>0;--i){...}` check conditions carefully（逆序遍历条件）。
- **Compare chars**: `'d' > 'c'` using ASCII codes（字符比较基于 ASCII）。

------

## 5) Functions & Scope｜函数与作用域

- **Prototype & return**: define return type; `return` value matches type（返回类型匹配）。
- **Local vs Global**: inner scope hides outer variable of same name（内层可遮蔽外层）。
- **Namespace**: `std::cout`, or `using namespace std;`（命名空间解析）。

------

## 6) Pointers (Intro awareness)｜指针入门意识

- **Address-of `&`** and **dereference `\*`**（取地址与解引用）。
- Type of pointer matches pointee type（指针类型匹配）。
- **Common mistake**: `char* p; p=&x;` where `x` is `int` → type mismatch（类型不匹配错误）。

------

## 7) Mock Q1 Patterns – Reasoning Templates｜样题 Q1 推导模板

> Write console output of small programs（写出程序输出）。

**A) Pre/Post ++ trace｜前/后缀自增跟踪**

```cpp
int x=5; int a,b; a=x++; // a=5, x=6
b=++a; // a=6, b=6
cout<<b<<","<<x; // 6,6
```

**Key idea｜要点**: left‑to‑right evaluation of assignments; pre/post semantics（自增语义）。

**B) `char` arithmetic｜字符算术**

```cpp
char x='b', y='d'; char z=++y; // y->'e', z='e'
cout << (z - x); // 'e'(101)-'b'(98)=3
```

**C) Integer division in `if`｜整除判断**

```cpp
for(int i=0;i<a;i++){ if(i/2==0) res+=b; }
// i=0 -> 0/2=0 true; i=1 -> 1/2=0 true; i=2 -> 2/2=1 false; i=3 -> 3/2=1 false
// with a=4,b=1 → res=2
```

**D) `switch(char)` with breaks｜switch 案例**
 `func('b')=2`, `func('c')=1` → sum 3.

**E) Backward loop + continue/break｜逆序+跳过/中断**
 `a[4..1]= e d c b`：

- i=4:'e' > 'c' → `continue` (skip)
- i=3:'d' > 'c' → `continue`
- i=2:'c' NOT > 'c' and NOT 'b' → print 'c'
- i=1:'b' → `break` stop → **Output: c**

**F) Post++ compare｜后缀++ 比较**
 `int x=3; int y=x++;` ⇒ `y=3, x=4`; `x>y` true → print `x+1` = **5**.

------

## 8) Mock Q2 – Debugging Template｜样题 Q2 语法纠错模板

**Goal｜目标**: count odd numbers & their average（统计奇数个数与平均值）。

**Typical fixes｜常见修正**

- Header: `#include <iostream>`（修正 including）。
- `int main()` with braces and `return 0;`（main 结构）。
- Loop bound: if `int a[]={1..8};` then last index is 7 → use `i<8`（下标上界）。
- Logic: odd test should **add** odd (`%2 != 0`) not `continue`（奇数逻辑）。
- Initialize `sum=0`, `count=0` before loop（初始化）。
- `count++;` not `count+;`（自增）。
- Assignment: `average = sum / count;` **(beware integer division)**（赋值与整除）。
- Output uses `<<`, not `>>`; and `endl` or `\n`（输出运算符）。

**Robust version｜稳健版本** (keep `average` as `double` to avoid truncation)：

```cpp
#include <iostream>
using namespace std;
int main(){
    int i, count=0, sum=0;
    double average=0.0;
    int a[] = {1,2,3,4,5,6,7,8};
    for(i=0;i<8;i++){
        if(a[i]%2!=0){ // odd
            sum += a[i];
            count++;
        }
    }
    if(count>0) average = static_cast<double>(sum)/count;
    cout << "count = " << count << endl
         << "average = " << average << endl;
    return 0;
}
```

------

## 9) Mock Q3 – Series f(x,n)｜样题 Q3 幂级数求和

**Spec**: input `x` with `0.1 ≤ x ≤ 1` and odd positive `n`；compute
 (f = x^2 + x^3 + x^5 + … + x^n)（x 范围与 n 为正奇数，求特定幂之和）。

**Key patterns｜关键模式**

- Validate `x` via loop: `while(x<0.1 || x>1) { prompt; cin>>x; }`（输入校验）。
- Validate `n`: `while(n<=0 || n%2==0){...}`（正奇数）。
- No `pow` → iteratively build power（禁止 pow，迭代幂）。
- Format to 2 decimals: `cout<< fixed << setprecision(2)`（两位小数输出）。

**Power build idea｜幂迭代思路**

```cpp
// accumulate odd exponents except 1, starting from 2
// we can maintain a running power

double term = x; // x^1
double sum = 0.0;
for(int k=2;k<=n;k++){
    term *= x; // now term = x^k
    if(k==2 || (k%2==1 && k>=3)) sum += term; // 2,3,5,...,n
}
```

**I/O skeleton｜完整骨架**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double x; int n;
    cout<<"Input x: ";
    cin>>x; while(x<0.1 || x>1){ cout<<"Input x: "; cin>>x; }
    cout<<"Input n: ";
    cin>>n; while(n<=0 || n%2==0){ cout<<"Input n: "; cin>>n; }
    double term=x, sum=0.0;
    for(int k=2;k<=n;k++){ term*=x; if(k==2 || (k%2==1 && k>=3)) sum+=term; }
    cout<<"\nValue is: "<< fixed << setprecision(2) << sum << "\n";
    return 0;
}
```

------

## 10) Mock Q4 – Digit Sum + Bubble Sort (paired arrays)｜样题 Q4 数位和+冒泡（双数组同步）

**Steps**

1. Read 10 ints into `arr[10]`（读入）。
2. For each number, compute digit‑sum into `out[10]`（数位和）。
3. Bubble sort `arr` ascending; when swapping `arr[i]↔arr[j]`, also swap `out[i]↔out[j]`（冒泡+同步交换）。
4. Print both arrays in sorted order（输出）。

**Digit sum helper｜数位和函数**

```cpp
int digit_sum(int x){ int s=0; if(x==0) return 0; if(x<0) x=-x;
    while(x){ s+= x%10; x/=10; } return s; }
```

**Bubble skeleton｜冒泡骨架**

```cpp
for(int pass=0; pass<10-1; ++pass){
    for(int i=0;i<10-1-pass;++i){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
            swap(out[i],out[i+1]);
        }
    }
}
```

**I/O layout｜输入输出格式**（按样例先打印 out，再打印 Sorted arrays）。

------

## 11) Mock Q5 – Class & Sort of Books｜样题 Q5 书籍类与排序

**Class spec｜类规格**

- Private members: `id (char)`, `subject (string)`, `price (int)`, `month (int)`, `day (int)`（私有成员）。
- Public getters: `getID()`, `getSub()`, `getPrice()`, `getMonth()`, `getDay()`（公有访问器）。
- `set(char i, string s, int p, int m, int d)` declared in‑class, defined outside（set 原型在类内、实现类外）。

**Minimal definition｜最小定义**

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Book{
private:
    char id; string subject; int price, month, day;
public:
    char getID() const { return id; }
    string getSub() const { return subject; }
    int getPrice() const { return price; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    void set(char i, string s, int p, int m, int d); // prototype only
};
void Book::set(char i, string s, int p, int m, int d){ id=i; subject=s; price=p; month=m; day=d; }
```

**Array init & print｜数组初始化与打印**

```cpp
void printBooks(Book b[], int n){
    cout << "The list of the books:\n";
    for(int i=0;i<n;++i){
        cout << "Book " << b[i].getID() << ": " << b[i].getSub() << ' '
             << b[i].getMonth() << '-' << b[i].getDay() << '\n';
    }
}
```

**Custom sort rule｜自定义排序**

- Primary: ascending by `price`（主键：价格升序）。
- Tiebreaker: **descending** by `subject` lexicographically（同价：学科名降序，使用 `string.compare`）。

```cpp
void sortBooks(Book a[], int n){
    for(int p=0;p<n-1;++p){
        for(int i=0;i<n-1-p;++i){
            bool worse = (a[i].getPrice() > a[i+1].getPrice());
            if(!worse && a[i].getPrice()==a[i+1].getPrice()){
                worse = (a[i].getSub().compare(a[i+1].getSub()) < 0); // ascending string? we want DESC
            }
            if(worse) swap(a[i], a[i+1]);
        }
    }
}
```

**Sorted output format｜排序后输出格式**

```
B(60, Computer Science)
A(80, Math)
...
```

------

## 12) Formatting & Common I/O｜格式化与常见 I/O

- `fixed << setprecision(2)` to keep 2 decimals（固定两位小数）。
- Print arrays in one line separated by space（数组一行空格分隔）。
- `\n` vs `endl`: prefer `\n` for speed unless you need flush（性能考虑）。

------

## 13) Typical Edge Cases｜典型边界

- Division by zero when `count==0`（除零）。
- Loop off‑by‑one (`i<=7` vs `i<8`)（越界）。
- Integer vs double average（整型除法导致截断）。
- Switch fall‑through without `break`（穿透）。
- Casting when mixing `char` and `int`（字符与整数混用）。

------

## 14) Practice Prompts｜快速自测

1. Predict output for mixed `++` and `--` with `char` math（预判输出）。
2. Rewrite Q2 so that average prints with 2 decimals（两位小数平均）。
3. Modify Q3 to include `x^4` term as well—what changes?（增加 x^4）。
4. Extend Q4 to stable‑sort by `out[]` first, then `arr[]`—how to tie‑break?（按数位和再按值稳定排序）。
5. Extend Q5: add method `string toLabel()` returning `A(80, Math)` style（格式化标签）。

------

> You’ve got this—focus on correctness first, then formatting. 先确保逻辑正确，再考虑输出格式。祝考试顺利！