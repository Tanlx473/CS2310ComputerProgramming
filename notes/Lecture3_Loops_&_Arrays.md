# Lec03 – Loops & Arrays

> Scope: **while / do–while / for**, loop pitfalls, nested loops & patterns, `break/continue`, input validation, **1D arrays** (definition/initialization/indexing), common mistakes (out-of-bound, uninitialized array), **bubble sort**, **2D arrays** (row‑major, sizes, initialization), and small practice tasks. English first, concise Chinese glosses in parentheses.

------

## 0) Quick Sheet｜速查

- Choose a loop:
  - **while**: when you need to check first（先判断）
  - **do–while**: must run at least once（至少执行一次）
  - **for**: known counter / range iteration（计数/范围迭代）
- Use **relational** bounds (e.g., `i<4`) rather than equality sentinels（优先关系表达式）。
- Avoid floating‑point as loop control（避免浮点控制循环）。
- Arrays are **0‑indexed**, length **N ⇒ 0..N-1**（数组从0开始）。
- Always **initialize arrays** (e.g., `{0}`) before counting（初始化）。
- 2D arrays are contiguous in **row‑major** order（行优先存储）。

------

## 1) `while` – check first｜先判断再执行

**Idea**: Repeat while condition is true（条件为真则重复）。

```cpp
int n;
cout << "How many? ";
cin >> n;
while (n <= 0) {                // input validation（输入校验）
    cout << "ERROR: positive required. Re-enter: ";
    cin >> n;
}
```

**Max-so-far pattern｜滚动最大值**

```cpp
int cnt = 0; int n; double x, mx;
cin >> n;                        // assume validated
cin >> x; mx = x;                // seed（种子赋值）
while (++cnt < n) {              // read remaining n-1 values
    cin >> x;
    if (mx < x) mx = x;         // update（更新）
}
cout << mx << "\n";
```

------

## 2) `do–while` – run once｜先执行后判断

**Idea**: Body executes ≥1 time; condition at the end（末尾判断）。

```cpp
int n, error;                    // use int as boolean（用int充当布尔）
do {
    cout << "Input a positive integer: ";
    cin >> n;
    error = (n <= 0);
    if (error) cout << "Error: non‑positive!\n";
} while (error);
```

**When to use｜适用场景**: menu loops / re‑prompting input（菜单/重复输入）。

------

## 3) `for` – count & step｜计数与步进

**Form**: `for(init; cond; step) { body }`（初始化；条件；步进）。

```cpp
for (int i=0; i<10; ++i) {       // 0..9
    if (i%2==0) cout << i << '\n';
}
// multiple init/step with comma（逗号分隔多个表达式）
for (int i=0, j=0; i<10; ++i, ++j) { /*...*/ }
```

**Common errors｜易错**

- `=` vs `==`（赋值/比较混淆）
- Extra semicolon after `for`（多写分号导致空循环）

```cpp
for (int j=1; j<=10; ++j);  // ← WRONG（错误）
sum += j;                   // 不在循环体内
```

- Range test `70<=mark && mark<=100` ✔, NOT `70<=mark<=100` ✘（数学习惯误用）。

------

## 4) `break` & `continue`｜跳出与跳过

- **break**: exit current loop immediately（立即跳出当前循环）。
- **continue**: skip to next iteration（跳过本轮，进入下一轮）。
- Prefer range‑based termination (e.g., `i<limit`) over `while(i!=target)`（推荐范围边界）。

------

## 5) Nested loops｜嵌套循环

**Multiplication table｜乘法表**

```cpp
int n, m; cin >> n >> m;        // assume n>1, m<=9
for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
        cout << i*j << "\t";
    }
    cout << '\n';
}
```

**Diagonal pattern｜对角线图案**

```cpp
int L; cin >> L;
for (int row=1; row<=L; ++row) {
    for (int col=1; col<row; ++col) cout << ' '; // row-1 spaces（空格）
    cout << 'x' << '\n';
}
```

------

## 6) 1D Arrays – define/index/init｜一维数组

**Define**: `int a[10];` ⇒ indices `0..9`（索引范围）。
 **Store/Read**:

```cpp
for (int i=0; i<10; ++i) cin >> a[i];
for (int i=0; i<10; ++i) { cout << a[i] << ' '; sum += a[i]; }
```

**Initialization options｜初始化**

```cpp
int count[10] = {0};             // all zeros（全部置零）
int mark[2]  = {100, 90};
int mark2[10]= {100, 90};        // others auto‑zero（其余自动为0）
```

**`#define` macro for size｜宏定义数组大小**

```cpp
#define N 10
int mark[N];
```

**Common bug – uninitialized counts｜计数未初始化**

```cpp
int cnt[10];              // ← 未初始化
// cnt[digit]++ 将产生垃圾结果（随机值）
```

**Correct counting with sentinel −1｜以 −1 结束的统计**

```cpp
int cnt[10] = {0}, d;
do {
    cin >> d;
    if (0<=d && d<=9) cnt[d]++;  // guard bounds（越界保护）
} while (d != -1);
for (int i=0; i<10; ++i)
    cout << "Frequency of " << i << " is " << cnt[i] << '\n';
```

------

## 7) Bubble Sort – stable adjacent swap｜冒泡排序

**Idea**: Adjacent swap from tail to head; after pass `j`, first `j` elements are settled（相邻交换，逐趟冒泡）。

```cpp
const int n = 10; int a[n];
for (int j=0; j<n; ++j) cin >> a[j];
for (int j=0; j<n-1; ++j)              // passes（趟数）
    for (int k=n-1; k>j; --k)          // bubble up（冒泡）
        if (a[k] < a[k-1])
            swap(a[k], a[k-1]);
for (int j=0; j<n; ++j) cout << a[j] << ' ';
```

**Notes｜要点**

- Compare `a[k]` with `a[k-1]` to move smaller forward（与前一位比较）。
- Complexity **O(n²)**; good for teaching/small inputs（教学/小规模）。
- For paired arrays, swap both arrays in sync（双数组同步交换）。

------

## 8) 2D Arrays – row‑major｜二维数组（行优先）

**Define & access｜定义与访问**

```cpp
int page[2][3];            // [row][col]
page[0][0] = 1; page[1][2] = 6;
cin >> page[i][j];
```

**Initialization｜初始化**

```cpp
int A[2][3] = {{1,2,3},{4,5,6}}; // by rows（按行）
int B[2][3] = {1,2,3,4,5,6};     // flat order（顺序填充）
int C[][3]  = {1,2,3,4,5,6};     // omit first dim（省略第一维）
int D[2][3] = {{1},{4,5}};       // partial init（部分初始化）
```

**Row‑major memory｜内存布局**: 第一行块在前，随后是第二行块（行连续存储）。
 **Sizes｜行列数**

```cpp
int arr[3][4];
size_t rows = sizeof(arr)/sizeof(arr[0]);
size_t cols = sizeof(arr[0])/sizeof(arr[0][0]);
```

**Transpose 2×3 example｜2×3 转置输出**

```cpp
double M[2][3]; // read M
// print transposed with 1 decimal（1位小数）
for (int c=0; c<3; ++c){
    for (int r=0; r<2; ++r){
        cout << fixed << setprecision(1) << M[r][c] << '\t';
    }
    cout << '\n';
}
```

------

## 9) Style & Safety｜风格与安全

- **Indentation** mirrors control flow（缩进反映结构）。
- **Avoid infinite loops**: ensure loop condition becomes false（确保终止）。
- Prefer `i<limit` over `i!=limit`（更稳健的边界）。
- Keep counters/invariants near the loop they govern（变量就近原则）。

------

## 10) Quick Drills｜随练

1. 输入 `n`，打印 `1..n` 的所有偶数之和（while / for 两种写法）。
2. 读入 10 个数，输出 **最大值** 与 **其出现次数**（一次扫描）。
3. 读入若干数字（以 −1 结束），统计各数字频次（数组计数）。
4. 用 **冒泡** 将数组升序，并保持 **伴随数组** 同步（双数组冒泡）。
5. 读入 2×3 矩阵并按 **列** 输出（转置打印，保留 1 位小数）。

> Think in **patterns**: validation loop, max‑so‑far, counting array, nested table, bubble swap. 用“模式”思考，写出稳定可读的程序。