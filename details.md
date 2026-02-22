1.﻿
```cpp

string s="a",s2="bc",s3,s4="ab",s5="c",s6;

s3=s+"\0"+s2;

s6=s4+"\0"+s5;

```
结果：s3==s6;原因：空字符放在双引号中，被视为c风格字符串即char数组，遇到空字符终止，长度为0，所以不会拼接进去。
2.定义在全局的结构体内部成员变量的默认值是0值，即int=0,char='\0';bool=false……；也可自己设置默认值：int a=1;
3.scanf不能读入string对象
4.sort函数的第三个参数可以传入自己定义的比较函数，注意是只传入函数名，即函数地址，函数定义的返回值应为bool型，或者自己重载小于号，即可不用传第三个参数。若对数组排序，前两个参数传起始和终止对应地址，注意终止是最后一个再加1.
理解自己传入的cmp的调用原理：
```cpp
if(!cmp(a,b))swap(a,b);//a的下标小于b,值交换，也就是你想要使在前面的元素和在后面的元素满足什么样的关系
```cpp
注意：若有不同优先级的依次遵循的排序标准，则cmp函数中应该连着用多个if语句，而非if-else if-else结构（只能走一条路，走完就跳出）。
getline(cin,s);//读入一整行，直到读到换行符为止，getline 会“读取”换行符，但它不会把换行符“存入”字符串中,会有自动的处理。
stringstream ss(s);//创建一个“字符串流”,stringstream在<sstream>中，但一般在其他头文件中也会间接包含它，但最好写上，因为你不知道比赛时的编译环境
ss>>n>>m;//像使用 cin 一样，从这个字符串流里提取出两个变量 n 和 m
```
5.cin>>读入失败时不会改变变量的值，但是读入失败的东西还会留在缓冲区。
6.string s1;
s1.back()='c';//back()返回s1的最后一个字符的引用；
7.stoi 是 C++11 标准引入的一个标准库函数，全称是 String TO Intger,定义在 <string> 头文件中。它的功能是将字符串 std::string 转换为整数 int
```cpp
string s = "123";
int num = stoi(s); // num 变成 123
```
8.去除末尾空格：
```cpp
string name = line.substr(0, 20); // 截取前20位
//string sub=s.substr(pos,len);pos是起始下标，len是要截取的个数,substr(pos, count) 中不写 count 时，它会默认取到字符串的末尾
// 只要字符串不为空，且最后一个字符是空格，就把它弹出
while (!name.empty() && name.back() == ' ') {
    name.pop_back();
}
```
9.for循环的语法糖（c++11后）
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 传统的写法
for (int i = 0; i < v.size(); i++) cout << v[i];

// 语法糖写法
for (int x : v) {
    cout << x << " "; // x 会依次代表 v 中的每一个元素
}
数组也可以用：
```cpp
ctor c[50];//ctor是我定义的结构体
for (auto& x : c) { // 使用 & 引用，不产生拷贝，且能修改原数组内容
    x.total = x.score[0] + x.score[1]; 
}
```
10.map的value如果是int或double，则初始化后（键的出现）默认为0.（全局map和局部map都是这样）
11.to_string是<string>头文件中定义的全局函数，它的作用非常纯粹：将数值类型转换为字符串类型。
语法：to_string(数值)，既可以转化整数，也可以转化小数
```cpp
	string s = to_string(12.1);
	cout << s;//结果：12.100000
```
12.sprintf：把格式化后的结果输出到一个字符数组中
示例：
```cpp
char buf[50];
int rank = 10;
sprintf(buf, "%dT", rank); //和printf一样，可以有多个%-，以及对应的多个变量。
// 现在 buf 里的内容就是 "10T\0"
```
13.cout<<left<<setw(5)<<a;left：开启左对齐模式，想切回右对齐模式要用right，setw:设置宽度，只对后面紧跟的一个输出起作用。均在头文件<iomanip>中
14.以字符串形式输出123和以整数形式输出123对于评测机来说是一样的。
15.c_str()（只读）:将string转为字符数组（printf不能输出string）,返回值是字符串首字符的地址。
```cpp
string s = "Hello";
printf("%s", s.c_str()); // 完美配合 printf
```
16.动态生成n个空格（其他字符也一样）：方法一：
```cpp
int n = 10;
cout << string(n, ' '); // 打印10个空格
```
原理：利用 std::string 的构造函数生成一个由n个相同字符组成的字符串
方法二：
```cpp
int n = 10;
printf("%*s", n, ""); // 打印 n 个空格
```
原理：%*s 表示输出一个字符串，其宽度由对应的整数参数决定。这里我们传入一个空字符串""，由于它长度为 0,printf就会为了填满n个宽度而全部打印空格。
打印固定数量空格：printf("%-10s", "");
17.不要混用printf和cout,他们有各自的缓冲区。在某些 OJ 上，混用会导致输出顺序混乱（比如名字还没打印，奖金先出来了）。
18.检查代码时一定要注意有没有把i写成j,毕竟这两个循环变量在一个程序中多次出现，很容易手误。
19.如果你在 if 的结束花括号 } 和 else 之间插入了任何语句，编译器就会认为 if 语句已经彻底结束了。所以不能插入语句。
20.复合赋值运算符的优先级是最低的，最后执行，所以不用给后面的表达式打括号。
21.消除浮点数存储方式造成的误差的方法是加一个很小的数EPS，对于 double 类型：常用1e-8或1e-9,对于long double，常用1e-12或更小，EPS 必须大于机器能表示的最小精度（double约为1e-16)
22.格式控制：观察行末：你可以尝试在样例输出中用鼠标选中文字。如果行末的蓝色高亮块一直延伸到很远，说明有行末空格；如果紧贴着最后一个字符就结束了，说明没有行末空格。（不知道是不是在比赛环境才可以用这个方法，反正在自己电脑上不行）
也可自己把光标跳到行尾：鼠标点击行末再往后一段距离的地方或者用end键。
23.ctrl+G：跳转到某一行
24.“行末无空格”是一个非常普遍且极其严格的默认要求，也有的题目需要末尾空格，这种题目一般是类似这样的：最后输出一个两位或三位数（如成绩），则可能需要用%3d或%-3d，在两位数的时候自然有末尾空格（这种情况也可能是直接用%d没有末尾空格，所以一般都要求末尾无空格，有末尾空格的情况了解即可，一般不会出）。处理行末多余空格的方法（尤其是当每一行的输出情况不同导致列宽不同时）：先定义一个固定长度的字符数组，再用memset(a,' ',sizeof(a))全部填充上空格，
再把数据往对应位置填（通过memcpy),最后从后往前执行裁剪：去除所有末尾空格并加上'\0'.但是其实有点麻烦，不如自己根据情况用if else进行不同的处理：一行数据全部输出完后接着输出换行。
25.memset:void* memset(void* ptr, int value, size_t num);ptr：要填充的内存起始地址。value：要设置的字符（ASCII 码）或字节值num：要填充的 字节数 (用sizeof),三个参数缺一不可，
如果你想用它把 int 数组全设为 1，你会得到一堆奇怪的巨型数字。因为它是把每个 int 的 4 个字节都变成了 01。除 0 和 -1 外，不要用 memset 初始化 int 数组的其他值。
memcpy:void* memcpy(void* destination, const void* source, size_t num);destination：目标内存地址,source：源内存地址,num：要复制的字节数。
二者位于头文件<cstring>中。
26.用命令行打开文件要用引号把路径括起来，如：cd "D:\c++\SF purple book"，cd后有空格。
27.PE 的定义：通常仅限于“非空字符序列完全一致，但空格或换行数量不对”。
WA 的判定：如果题目要求的是一种 “固定宽度格式” (Fixed-field format)，那么每一个位置上的字符（包括空格）都被视为“答案内容”的一部分。如果你漏掉了一个属于字段宽度的空格，判题机在进行逐字节对比（diff）时，会认为你的输出流在结构上就出错了。
趋势：现代的 UVA 判题系统越来越倾向于将所有的格式错误直接判定为 WA。
28.sscanf 的作用是从一个字符串中按照指定的格式提取数据，就像 scanf 是从键盘（stdin）读数据一样，int sscanf(const char *str, const char *format, ...);str: 目标源字符串。format: 格式控制字符串（与 scanf 完全一致，如 %d, %lf, %s 等）...: 变量地址列表。
高级用法 %n， 可以告诉你到目前为止已经读取了多少个字符，
```cpp
char buf[] = "123 456 789";
char *p = buf;
int val, offset;
while (sscanf(p, "%d%n", &val, &offset) == 1) {
    printf("读到了数字: %d\n", val);
    p += offset; // 移动指针，跳过已经读过的部分
}   
	int T;
	char s[40];
	gets(s);
	sscanf(s, "%d", &T);
```
29.绝大多数现代评测系统（尤其是使用 Testlib.h 库作为 Checker 的 Codeforces, AtCoder, 以及现在的 ICPC 区域赛）在对比答案时，默认会忽略行末空格和文末换行符。
30.algorithm中的max函数可用于找出固定个数相同类型元素的最大值：max({a,b,c,……})；max_element可以找到容器中的最大值，这个函数返回的是一个迭代器（指针），指向容器中的最大值。如果你需要获取数值，需要进行解引用（加 *）。
```cpp
vector<int> v = {3, 1, 9, 7, 5};
int maxVal = *max_element(v.begin(), v.end());
int a[] = {3, 1, 9, 7, 5};
int n = 5;
int maxVal = *max_element(a, a + n);
```
31.万能头文件：#include <bits/stdc++.h>几乎包含所有常用头文件
32.宏：在 C++ 编译过程中，有一个步骤叫 “预处理” (Preprocessing)。宏就在这个阶段生效。简单来说，它就像是在你正式编译代码前，先执行了一次全局的“查找与替换”。
其基本格式是： #define 标识符 替换内容。如：
```cpp
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
typedef long long ll;//和宏差不多
// 或者
#define int long long // 这种写法在某些题目下很方便，但要注意 main 函数必须返回 signed
//换完后main前面的int也变成了long long,main返回值必须是int(确切说是signed int)，所以更换后会报错，所以用这个宏时应该写成signed main(){}（signed和int都可以单独代表signed int类型）
```
33.数组长度一定要开大点，起码比要求的大一（有时它真的会输入一个大小等于上限的样例），因为你不知道自己是不是会改变最后一个元素的下一位，以保证循环可以进行到头（改变最后一位的下一位置的元素值，以保证最后一位和其他位情况相同）
34.求出数组来后如果后面会有多组不同下标范围的元素求和，不要用每次都重新循环一遍求和的方法，及其容易TLE,应该这样：
``cpp
for(int i=1;i<n;i++)a[i]+=a[i-1];//如果不能改变原数组，可以先int c[n];(动态创建数组)memcpy(c,a,sizeof(a));
for(int i=0;i<q;i++){cin>>l>>r;cout<<a[r-1]-a[l-2]<<endl;}//不用再挨个循环了
```
35.int型的上限为：2,147,483,647，约2*10^9。
36.在大多数OJ上，c++的运行速度约为10^8次运算/秒
37.| 函数 | 查找目标 | 数学表达式 |
| --- | --- | --- |
| lower_bound | 第一个不小于 x 的元素 | ≥x |
| upper_bound | 第一个大于 x 的元素 | >x |
使用二者的前提是先排序
以lower_bound为例：// 实例
```cpp
int a[5] = {1, 2, 4, 4, 6};
int* p = lower_bound(a, a + 5, 4);//若没有符合的，返回a+5
vector<int> v = {1, 2, 4, 4, 6};
auto it = lower_bound(v.begin(), v.end(), 4);//若没有符合的，返回v.end()
```
获取下标：数组：直接减去首地址。 int index = lower_bound(a, a + n, x) - a;
Vector：减去首个迭代器。 int index = lower_bound(v.begin(), v.end(), x) - v.begin();
38.当不同类型的算术类型（如 int 和 long long）进行运算时，会发生隐式类型转换（Implicit Conversion），基本原则是：向表达能力更强、取值范围更大的类型转换。
39.reverse(first, last);适用于数组，vector，字符串等等
```cpp
int a[] = {0, 1, 2, 3, 4, 5};
// 只反转下标 1 到 3 的元素 (即 {1, 2, 3})
reverse(a + 1, a + 4); 
// 结果: {0, 3, 2, 1, 4, 5}
```
想要实现降序排列，可以先sort，在reverse，也可一步到位：sort(a, a + n, greater<int>());
在 C++ 里，类名() 的语法是调用该类的构造函数来生成一个实例。 greater<int> 是一个结构体（或类），它内部重载了 () 运算符（这叫 仿函数 / Functor）。
greater<int>：这是类型名（像 int、vector 一样）。
greater<int>()：这产生了一个具体的“比较器对象”。
sort 函数需要一个实实在在的对象作为参数，用来执行类似 if (对象(a, b)) 的逻辑。
40.对于那种数据量特别多且需要往数组中储存这些数据（如200000个1）的测试用例，调试时不要用单步执行，不然到了输入数组的环节会造成调试器与控制台的大量交互，
由于读入量巨大，程序会在后台高速读取文件，调试器无法即时反馈当前的行号，看起来就像光标丢了。应该在输入位置后面设置断点直接跳到断点。
41.有时如果有大量重复元素，循环处理浪费时间，可用以下方法：
```cpp
sort(a.begin(), a.end()); // 必须先排序
a.erase(unique(a.begin(), a.end()), a.end()); // 典型的 Erase-Unique 组合
for (long long x : a) {
    // 现在的 x 每一个都是唯一的！
}
```
unique的逻辑：把所有**不重复的“领头羊”**依次挪到数组的最前面。//unique是相邻去重，它只检查当前元素是否与前一个选中的元素相等，因此必须先排序再用它。
返回值的真正含义：它返回的是去重后的“新边界”。这个位置指向的是第一个不再属于有效数据的槽位
假设你的数组 a 是 {1, 1, 2, 2, 3}执行完后数组变成：{1, 2, 3, ?, ?}（后面的 ? 是原来剩下的垃圾数据）unique 返回的迭代器 it：指向的是下标为 3 的位置（也就是第一个 ? 所在的地方）
42.for(int i=1;i<=n;i++)cout<<" \n"[i==n];这是利用数组下标访问字符串常量的方法，简单易懂，可用于控制格式输出。
43.两句用于加快运行速度的语句（防止TLE）ios_base::sync_with_stdio(false);默认情况下，C++ 的 cin 和 cout 会与 C 标准库的 stdio（scanf/printf）保持同步这种同步需要大量的开销，因为 cin 每次读取前都要去确认 stdio 的缓冲区状态
设置 false 之后，切断了同步。一旦写了这行，绝对不能在同一个程序里混用 cin/cout 和 scanf/printf，否则输出顺序会乱作一团。
cin.tie(nullptr);默认情况下，cin 是与 cout 绑定（tie） 的。这意味着每次你执行 cin 读取数据之前，程序会自动执行 flush() 清空 cout 的缓冲区，确保你在输入提示之前能看到输出。
在竞赛中，我们不需要这种实时交互。cin.tie(nullptr) 解开了这种绑定。这样 cin 就不必每次都等 cout 清空缓冲区，从而进一步加快读取速度。
Flush 的作用就是：不等缓冲区满，强行把当前缓冲区里的所有内容立刻“倒”向目的地（屏幕、文件等）默认情况下，执行 cin 会先 flush 掉 cout（除非你用了刚才学的 cin.tie(nullptr)）。
44.sort(a.begin(), a.end(), greater<>());//编译器会自己推导类型。
45.pair中重载了比较大小的运算符.规则是先比较first再比较second。pair定义格式：pair<type1,type2>p={a,b};
46.map中存储的实际上就是一个个pair,所以可以用.first访问它的key,.sencod访问它的value，遍历map中元素方法：for(auto i:mp){i.first……}每个i就是一个pair.遍历顺序：按照key的升序顺序。
47.istream& getline (istream& is, string& str);它返回的是输入流对象 is 的引用（即返回 cin 自身）。可用于循环条件判断，为什么一个流对象能放进 while 循环里？因为 istream 类重载了 bool 转换运算符（或 void*）。
当流处于“健康”状态时，它返回 true；当遇到 EOF (End of File)、读入失败或文件损坏时，它返回 false。
48.删除字符串字符的方法：s.erase(pos, len);参数 1 (pos)：开始删除的下标。参数 2 (len)：删除的字符个数。
```cpp
string s = "hello";
s.erase(0, 1); // 从下标 0 开始，删除 1 个字符
```
49.*格式控制中是赋值抑制符，在 scanf 或 sscanf 中，如果在 % 和格式字符（如 d, s, c）之间加上 *，它的意思是：读取这一部分数据，但不要把它存储到任何变量中。
```cpp
int num;
// 跳过 "ID: "，跳过一个字符串，最后读入数字
scanf("ID: %*s %d", &num);
//假设输入日期格式是 2026-02-06，你只需要年份和日期，不需要月份
int year, day;
scanf("%d-%*d-%d", &year, &day);
char buf[10];
scanf("%5s%*s", buf);//只要前 5 个字符，剩下的不管多长都扔掉，直到遇到空格
```
50.a是字符串首元素地址，可以printf("%s",a+1)这样输出从第二位往后的字符串。
51.%[^@]:读取字符串，直到遇到 @ 符号为止（但不包括 @）;
52. .find()如果找到返回下标，没找到返回string::npos.既可以找字符串（返回字符串首个字符在原串的下标），也可以找字符（用单引号）
```cpp
int k=s.find('@');
user=s.substr(0,k);
mta=s.substr(k+1);
```
53.map的key和value可以是任意有小于运算符的对象
如vector,set,string,甚至是另一map(vector的小于运算符是从第一个元素开始往后一一比对,map也有小于号，它会按照 Key 的顺序，依次比较每个单元的 pair<const Key, Value>)
```cpp
map<string, vector<int>> mp;
mp["class_A"].push_back(95);
```
54.数组和vector没有.count(),但可以用algorithm头文件中的count
```cpp
    int arr[] = {1, 2, 3, 2, 4, 2};
    int n = 6;
    int c1 = count(arr, arr + n, 2); // 统计 2 出现的次数
    vector<int> v = {1, 2, 3, 2, 4, 2};
    int c2 = count(v.begin(), v.end(), 2);
    cout << c1 << " " << c2 << endl; // 输出 3 3
```
他们也没有.find(),但同样可以用find(a,a+n,target);找到返回第一个找到的指针或迭代器，没有找到返回结束地址.
55.set.find()如果找到了： 返回指向该元素的迭代器。
如果没找到： 返回该容器的 .end() 迭代器
向set中插入一个原来已经存在的值，程序不会报错，但该次插入无效，这正是set的特性。
56.格式输出动态宽度设定：
```cpp
int width = 5;
int val = 42;
printf("%*d\n", width, val); // 等价于 printf("%5d\n", 42)
printf("%-*d", w, x);//左对齐写法
```
57.把数字改为字符串：(法一是用sprintf)
```cpp
int num = 123;
string s = to_string(num);
```
58.set和map都有find：(返回相应迭代器)
```cpp
auto it = s.find(target); // C++11 建议用 auto，省去写 set<int>::iterator 的麻烦
if (it != s.end()) {
    cout << "找到了：" << *it << endl;
} else {
    cout << "没找到" << endl;
}
map<string, int> scores;
scores["Alice"] = 95;
auto it = scores.find("Alice");
if (it != scores.end()) {
    // it->first 是 Key ("Alice")
    // it->second 是 Value (95)
    cout << "Found! Score: " << it->second << endl;
} else {
    cout << "Not Found" << endl;
}
```
59.删除set元素的方法：
```cpp
set<int> s = {1, 2, 3, 10};
s.erase(10); // 删除了 10
auto it = s.find(2);
if (it != s.end()) s.erase(it); // 务必先检查是否找到了
s.erase(s.begin(), s.find(3)); // 删除所有小于 3 的元素
```
60.对于类似vector的各种动态容器，及时定义时开的长度很大，也可以定义在局部。
61.可以通过下标访问string的每个字符，你可以把它看作一个特殊的 vector<char>。
62.结构化绑定：
```cpp
struct Point { double x, y, z; };
Point p = {1.0, 2.0, 3.0};
auto [px, py, pz] = p;
// 假设 map<int, string> mp;
for (auto& [key, value] : mp) {
    // 直接使用 key 和 value
    cout << key << " : " << value << endl;
}
```
63.判断vector是否为空：
```cpp
vector<int> v;
if (v.empty()) {
    // vector 为空时的逻辑
}
```
64.abs函数可以求整数和浮点数的绝对值
65.在 C++ 的 sort、set、map 以及 priority_queue 中，比较规则必须满足“严格弱序”。其中一条核心准则就是：不可反身性
对于任何元素a，comp(a, a) 必须返回 false。为什么必须是 false？ 因为在 STL 的逻辑里，它是这样判断“相等”（等价性）的:
如果 comp(a, b) 是 false，且 comp(b, a) 也是 false，那么系统就判定a等于b。
66.优先队列对于优先级相同的元素，谁先出来是不确定的。
67.vector的erase语法：
```cpp
iterator erase(iterator pos);//返回值：指向被删除元素之后位置的迭代器
iterator erase(iterator first, iterator last);//返回值：指向最后一个被删除元素之后位置的迭代器。
```
erase后vector长度相应减小。
68.用大括号初始化是内部也可以是变量：
```cpp
pair<int, int> p1 = {x, y};
```
69.多元组（三元及以上）尽量使用struct,用起来方便，除非你想用tuple的默认字典序排序特性
```cpp
tuple<string, string, int> book = {"Chaucer, G.", "The Canterbury Tales", 1387};
//访问元素方式：
string author = get<0>(book);
string title  = get<1>(book);
int year      = get<2>(book);
//结构化绑定：
auto [author, title, year] = book; 
// 这样你就直接得到了三个变量，用起来和普通变量一样快！
```
70.自己重载多元组的<：
```cpp
struct Node {
    int a, b, c;
    bool operator<(const Node& other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return c < other.c;
    }
};
//如果你不想写一堆 if 判断，C++ 提供了一个“偷懒”神器：std::tie。它能把变量临时捆绑成一个 tuple 并利用 tuple 的默认比较逻辑。
struct Node {
    int a, b, c;
    bool operator<(const Node& other) const {
        // 这行代码会自动按 a, b, c 的顺序进行字典序比较
        return tie(a, b, c) < tie(other.a, other.b, other.c);
    }
};
```
71.vector元素的默认值为其类型的0值，bool型默认为false。
单独定义bool型时，如果是全局，则默认为false，局部则随机。
72.auto 的核心作用是：让编译器根据变量的初始值，在编译阶段自动推导出变量的类型
73.迭代器可以通过自增到下一元素（即使内存不连续）,不能通过&获得指向某个对象的迭代器，迭代器是类中定义的一个对象，是类的一个内部类型；迭代器解引用时如果后面还有.函数一定要先打括号(*it).……
74.vector的迭代器可以进行加减运算，和指针相同，如+2，-2。但list,set,map不行（只能是自增自减）；
75.将字符串转为全为小写：
```cpp
transform(s.begin(), s.end(), s.begin(), ::tolower);//第三个参数是转完后的字符串的写入起始位置。这里的 ::tolower 前面加了 ::，是为了明确调用全局命名空间下的 C 语言版本的 tolower，防止与某些环境下的重载版本冲突。
for (auto &c : s) {
    c = tolower(c);
}
//转为大写是toupper
```
如果传入的已经是小写(大写)或非字母，它会原样返回。
76.find_last_of 的原型作用是：从字符串的末尾开始向前搜寻，找到第一个匹配给定字符集中任意一个字符的位置。
重点：它查的是“字符”，而不是整个“单词”。
语法：s.find_last_of("abc") 会找到最后一个出现的 'a' 或 'b' 或 'c' 的位置。
77.vector的assign和string的assign：
```cpp
//assign 的核心作用是：清除容器原有内容，并根据提供的新数据重新填充容器。
vector<bool> on_shelf;
on_shelf.assign(n, true); // 将容器大小设为 n，并把所有元素设为 true
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2;
v2.assign(v1.begin() + 1, v1.end()); // v2 现在是 {2, 3, 4, 5}
vector<int> v;
v.assign({10, 20, 30}); // v 现在变为 {10, 20, 30}
string s;
string long_str = "Hello, algorithm!";
// 从索引 7 开始，截取 9 个字符赋值给 s
s.assign(long_str, 7, 9); // s 变成 "algorithm"
```
78.普通队列，栈，优先队列都有size():
```cpp
priority_queue<int> pq;
// ...
cout << pq.size() << endl; // 返回当前队列中元素的个数
```
79.typedef set<int,Compare> _IntSet;//set<int, Compare>: 这是定义了一个 std::set 容器。
第一个参数 int：表示集合中存储的数据类型。
第二个参数 Compare：这是一个比较函数对象（Functor）。set 会根据这个对象定义的规则来决定元素的排列顺序和唯一性。
typedef ... _IntSet;: 这是 C 语言风格的类型别名定义。它把这一长串复杂的 set 类型起了一个短名字叫 _IntSet。之后你只需要写 _IntSet my_set; 就等同于写了带自定义排序的完整定义。
80.deque用法讲解：
```cpp
//声明和初始化：
deque<int> dq;              // 空队列
deque<int> dq2(5, 10);      // 包含5个元素，值都为10
deque<int> dq3 = {1, 2, 3}; // C++11 初始化列表
| 函数名 | 功能 | 复杂度 |
| --- | --- | --- |
| push_back(val) | 队尾添加元素 | O(1) |
| push_front(val) | 队头添加元素 | O(1) |
| pop_back() | 删除队尾元素 | O(1) |
| pop_front() | 删除队头元素 | O(1) |
| front() / back() | 访问队头/队尾元素 | O(1) |
| size() / empty() | 获取长度/判空 | O(1) |
| at(i) / dq[i] | 随机访问第 i 个元素 | O(1) |
| clear() | 清空容器 | O(N) |
81.
```cpp
struct matrix {
    int a, b;
    matrix(int x, int y) { a = x; b = y; } // 一旦你定义了带参数的构造函数，编译器就不再自动生成无参构造函数了。
};
matrix test; // 报错！因为编译器不知道不给参数时该怎么初始化
解决办法:括号中设置默认值(int x=0,int y=0 )
82.
```cpp
//我的写法（超时）
for (int i = 1; i <= (int)strlen(s + 1); i++)//把 strlen 写在了 for 循环的判断条件里。这意味着每一次循环（每处理一个字符），程序都要重新跑一遍 strlen。总复杂度：O(N^2)。
//正确写法
int n = strlen(s + 1); // 提前算好，O(N)
for (int i = 1; i <= n; i++) { // 循环 O(N)，总共 O(N)
}
```
83.long long型的格式符是%lld
84.调试时查看全局数组不像查看单变量那么直观。由于全局数组通常很大，编译器默认不会直接展开所有元素，否则会卡死。
查看前N个元素：输入 *数组名@长度,例如，想看 l 数组的前 10 个元素，输入：*l@10。注意最好在添加监视里输入，然后找到左栏的监视栏，这样就可以实时监视了。
85.一个数组，经过一系列操作（包括反转(用inv标记)），最后求奇数项的和：
```cpp
int sum=0,su=0;
for(int i=0;i<n;i++)if(i%2==0)sum+=a[i];
for(int i=0;i<n;i++)su+=a[i];
if(inv&&n%2==0)sum=su-sum;//只有这种情况需要改sum,inv&&n%2==1时反转后的奇数项和与反转前的相同。
cout<<sum;
```
86.左移运算符 x << n 的直观表现是将数字 x 的二进制表示向左移动 n 位，右侧空出的位置全部补 0，左侧移出的位则被丢弃
87.!0的结果是1
88.位移运算符的优先级很低，所以表示2^D-1时要加括号：(1<<D)-1
89.默认构造函数是指不需要提供任何参数就能调用的构造函数。可以自己定义一个，也可以用编译器送的，但初始化的变量的值可能是随机值。
如果你定义了任何带参数的构造函数，编译器就不会再送你默认构造函数了。
90.用new实例化类对象的方法:
```cpp
// 1. 调用默认构造函数（不带括号）
Node* p1 = new Node; 
// 2. 调用默认构造函数并进行值初始化（带括号，有时能保证成员清零）
Node* p2 = new Node(); 
// 3. 调用带参数的构造函数（最常用）
Node* p3 = new Node(10, nullptr); 
// 4. 申请对象数组（必须有默认构造函数）
Node* p4 = new Node[100];
```
91.new的返回值：成功时，它返回一个指向分配内存首地址的指针。失败时：在 C++ 标准中，如果堆内存耗尽，执行 new 表达式会抛出一个类型为 std::bad_alloc 的异常。
92.char* strchr(const char* str, int character);在字符串中查找第一个出现的指定字符，并返回其内存地址。
它会把字符串末尾的 \0 也视为字符串的一部分，所以可以用来查找结束符。没找到返回NULL。
93.* 始终是绑定在变量名上的，而不是绑定在类型名上。int*a,b;//a是指针，b是int;
int *a,*b;//两者都是指针
94.树的叶子（叶子节点）指没有子节点的节点。根到一个叶子的路径是指从根到叶子的那一条线
95.当你在 if 或 while 语句中使用 getline 时，它会触发 std::ios::operator bool() 的隐式转换。读取成功：返回的流对象状态为 good，转换为 true。读取失败：返回的流对象状态包含 failbit 或 badbit，转换为 false。
96.cin也能向字符数组中输入字符串：char s[90];cin>>s;
97.对vector使用resize时，如果缩小容量，则原先长出来的那一部分被删除，剩余部分不变，如果增大容量，则原先的不变，多出来的被初始化为0值
98.v.clear();v.resize(n);可以清空原来的元素；原理：v.resize(n)：将 size 改为 n。因为之前清空了，现在是从 0 增加到 n，这会触发 n 次初始化操作（变为0）
99.采用从字符到字符串的映射时，一般设定映射数组为char arr[256][maxn];因为asc码值有两种情况，一个是标准asc(最大为127),另一个是扩展asc(最大为255)；
注意char通常是signed,如果 char c 的 ASCII 值超过 127（变成扩展 ASCII），它会被解释为负数。这时访问arr[c]会RE，解决方案： 使用 unsigned char 或者在下标处强制转换：arr[(unsigned char)c]
100.dfs由于会进行递归调用，主要占用系统栈（内存很小，很容易超出），bfs由于是在queue中储存，主要依靠堆（内存很大，一般不会超出);所以有时候用dfs在本地运行时由于调用次数超出系统栈能存储的上限，会异常终止，这时候转为bfs就正常了。
101.想要给一个对象重新整体赋值时可以用大括号列表，也可以用创建临时对象的方法：
```cpp
Node u; // 定义时初始化为默认值 (0, 0, 0)
// ... 经过一些运算 ...
u = Node(1, 2, 3); // 创建一个临时 Node 对象，并赋值给 u
struct Point { int x, y; };
Point p = {10, 20}; // 定义时初始化
p = {30, 40};       // 定义后，利用列表生成临时对象并赋值
```
也可以用memset(p,-1,sizeof(p));p是结构体数组名，结果是数组中每个结构体元素的所有成员变量都变为-1（只适用于成员变量均为简单类型，不能有vector等）
也可以memset(&d,-1,sizeof(d));d是一个结构体对象。结果同上。
102.bool a[5];memset(a,0,sizeof(a));可以把a全设为false，因为memset本质上就是按字节填充，0填充进去后就是false,而且memset的第二个参数就要求是int,所以你写成false也会隐式转化为0。
memset(str, 0, sizeof(str)) 把字符数组填充成了 '\0'.
103.cin.getline() —— 专门用于字符数组 (这是istream类的成员函数)语法：cin.getline(char* s, streamsize n, char delim = '\n');//第二个参数是读入的最大长度（包括读入后自动添加的空字符）
第二个参数是终止符(默认是换行符)，当遇到这个字符时，停止读取。该字符会被从输入流（buffer）中提取并丢弃（不会出现在你的 s 数组里）。在 s 数组的末尾自动补上 \0。
```cpp
char buf[100];
cin.getline(buf, 100); // 最多读入 99 个字符，末尾自动补 '\0'
```
与fgets(buf, maxn, stdin)类似，但fgets会读入最后的换行符到字符数组中。
fgets:读取成功：返回存储字符串的指针（即你传入的第一个参数 str 的地址）。
读取失败 / 遇到 EOF：返回 NULL (在 C++ 中通常等于 0)。
```cpp
char buf[1024];
while (fgets(buf, sizeof(buf), stdin) != NULL) {
    // 只要返回值不是 NULL，说明读到了有效数据
    // 处理字符串...
}
//简洁写法：
while (fgets(buf, 1024, stdin)) {
    // 处理数据
}
```
104.越界访问时程序不会继续往下进行，后面的打印内容明显缺失。但可能也不会抛出异常，返回值为0，看到这种情况时就要想到越界访问了。
105.给字符数组设值：memset(a, 32, sizeof(a));char a[MAXN];memset(a, ' ', sizeof(a));//均可以实现设为空格。
106.y0, y1, jn, yn 都是数学库中用于计算 Bessel Functions（贝塞尔函数）的函数名.所以在全局定义变量名时不要用这些，定义在局部没事。
107.cin可以直接作为条件判断，因为它重载了bool运算符，如果读取正确，返回true，反之返回false
108.min和max函数后面用小括号，不是花括号。
109.bool a[3];memset(a,0,sizeof(a));结果：全变为false。
110.remove:把有效值放到前面覆盖要删除的值，末尾是垃圾，返回一个新的迭代器，指向处理后“新数组”的逻辑末尾。效率高，时间复杂度O（n)；erase可以删除单个元素（传一个参数），也可以删除区间元素（传两个）。
```cpp
vector<int> v = {1, 2, 3, 2, 4, 2, 5};
// 只调用 remove，size 没变，v 变成 {1, 3, 4, 5, 4, 2, 5} (末尾是残留垃圾)
auto it = remove(v.begin(), v.end(), 2); 
// 配合 erase 真正缩减大小
v.erase(it, v.end()); 
// 现在 v 是 {1, 3, 4, 5}，size 为 4
```
111.static定义的静态局部变量在函数调用结束后不会消失，下次进入函数时，它还记得上次的值。只初始化一次：static 变量在程序第一次执行到该声明行时初始化，之后的函数调用会跳过初始化语句。
112.stringstream ss(s);ss>>s1;ss>>s2;可以这样多语句使用，和一条语句ss>>s1>>s2;的效果一样
113.清空一个string数组的方法：std::string 是对象，不能使用 memset 清空！（重要：对 string 数组使用 memset 会导致程序直接崩溃，因为这会破坏 string 对象的内部指针结构）。
```cpp
//方法一：
for(int i = 0; i < N; i++) s[i].clear();
// 或者
for(int i = 0; i < N; i++) s[i] = "";
//方法二：
fill(s, s + N, "");
```
114.对于double型，scanf输入时用%lf,printf输出时用%f。对于float型，scanf用%f,printf用%f,对于long double型，输入输出都用%Lf
115.memset也可以把实数数组设为0；
116.left和right是输入输出流的函数，不要再用它们命名了，会冲突。
117.当你写一个很大的数字时,编译器默认它可能是 int。如果你想显式告诉编译器这是一个 long long 类型的常量，必须加后缀 LL：
```cpp
long long x = 2000000000000LL; // 这里的 LL 是系统自带的后缀，不是宏
int a = 1 << 10;          // 1024
long long b = 1LL << 40;  // 1099511627776
```
<<（左移）的优先级其实非常低，它排在加减法之后,关系运算符（<,==等)之前，1 << n + 1表示2的n+1次方。
118.为了防止用了正确算法但仍超时这种冤枉情况发生，我们在用cin和cout时要先加速（加速后就不能与scanf和printf混用了）
加速代码：
```cpp
///main函数开头
    // 1. 取消同步流（与c语言同步的流）
    ios::sync_with_stdio(false);//ios: 指 C++ 的输入输出流（Input/Output Stream）。sync (Synchronization): 指不同系统或模块之间保持数据一致的操作。with_stdio: 指的是 C 语言的标准输入输出库。false: 关闭这个状态
    // 2. 解绑 cin 和 cout
    cin.tie(nullptr);
    // 3. (可选) 解绑 cout 和 cerr//没有实际用处
    cout.tie(nullptr);
```
| 输入方式 | 单次耗时（常数 c） | 总耗时 | 结果 |
| --- | --- | --- | --- |
| 原生 cin | 1000ns | 1.0s | TLE (边缘徘徊) |
| scanf | 200ns | 0.2s | AC |
| 加速 cin | 100ns | 0.1s | AC (更稳) |
一旦执行了 ios::sync_with_stdio(false);，你就和 scanf、printf、getchar、putchar 以及 puts 这些 C 语言的标准输入输出函数彻底分手了。如果再混用，就会造成输出顺序错乱，读入数据丢失。
在 C++ 标准库里，如果流 A 绑定到了流 B，就意味着：
每当你要从 A 读取数据时，程序会自动强制刷新（flush） B 的缓冲区。绑定机制保证了：在读入之前，所有的输出提示一定会先显示在屏幕上。
所以交互题（评测机实时检测你的输出结果进行下一步的输入）不能解绑。
119.中序遍历加上另外任意一种遍历即可构造出唯一的二叉树，我们所说的构造是指储存不同节点的邻接关系，数组方式的构造（最常用）是指把数组lch和rch填满，分别对应一个节点的左邻节点和右邻节点。
存先序、中序、后序遍历的数组名可以分别取为preorder,inorder,postorder或者省略order。
120.用strlen测字符数组有效长度时，要注意不能把它放在for循环的判断条件中，要先提前赋值到一个变量中，否则复杂度直接变为O(N^2)(每次循环都要进行一次strlen),
但可以直接把.size()函数放在判断条件里，因为容器内部都有一个成员变量储存长度，这个函数只是把长度值取出来，并没有遍历。
121.结构体中自己定义的构造函数(初始化列表)要在括号内把参数设默认值后才能用stu()的方式创建一个默认对象，因为一旦自己定义构造函数系统就不会再给你默认的构造函数了。
122.自己定义的结构体也可以当作map的键，为了保证map的去重和排序正常实现，我们要根据需要重载结构体的<，map去重的判断方法是如果!(a < b) && !(b < a)为true，则这两个等价，即重复。
重载<运算符时一定要仔细考虑，下面是我的一个错误：
```cpp
struct status {
	int r = 0, c = 0, t = 0;
	bool operator<(const status& other)const {
		if (c + r != other.c + other.r)return r + c < other.c + other.r;//我想在两个结构体的三个成员完全相等时才为等价，但这里用到了和，则{1，2，0}和{2，1，0}也会被判为等价，出现错误。
		return t > other.t;
	} status(int r = 0, int c = 0, int t = 0): r(r), c(c), t(t) {}
};
//正确方法：
bool operator<(const status& other) const {
    return tie(r, c, t) < tie(other.r, other.c, other.t);//适用于2元及2元以上的任意组合，毕竟tuple就可以是二元及二元以上。
}
```
123.清空栈s的方法
```cpp
s = stack<int>(); // 重新构造一个空的栈并赋值给 s
```
124.用左移求2的次方值时只要n>=31就必须加LL后缀：1LL<<n;否则这个表达式的返回值就因溢出int范围而产生错误结果了。
125.
```cpp
//c++17结构化绑定：
for (auto& [key, value] : mp) {
    // 直接操作 key 和 value，不用写 it->first
}
```
126.map型可以用.size()直接获得键的数量
127.C++ 的隐式转换遵循 “向上提升” 的原则，即：为了保证精度不丢失，编译器会将范围小的类型转换为范围大的类型。
128.判断一个2的幂是2的几次方：
```cpp
int p = (int)(log2(n) + 1e-9);//log2 返回的是浮点数（double），在处理大整数时可能会有精度问题。通常需要加上一个微小的精度修正或者强制类型转换。
int k = __builtin_ctz(n); // 仅限 n > 0 且 n 是 2 的幂时使用
int power = 0;
while (!(n & 1)) { // 只要最后一位不是 1，就继续移
    n >>= 1;       // >>=:复合赋值运算符：n=n>>1;
    power++;
}
&:按位与：只有2个数都是1时才返回1，其余返回0；如：5&6=4；原因：二进制下：5=101，6=110；101&110=100=4（10进制）
n%2==1可以换为n&1,如果为真，则说明二进制最后一位是1，为奇数，为假则为偶数。
判断一个正整数是否为2的幂：
```cpp
if((n&(n-1))==0)//注意外层括号不能省去，==的优先级比&高。原理：如果n为2的幂，显然为真，如果不是2的幂，则该数的二进制至少有2个1，减1后会把从右往左数的第一个1变为0，但高位1不变，所以进行运算后不是0.
```
129.
```cpp
vector<pair<string,int>>v;
v.push_back({"acm",1});
```
130.
```cpp
// 删除下标为 idx 的元素
if (idx < v.size()) {
    v.erase(v.begin() + idx);
}
```
131.输出字符串和输出数字只要显示内容一样对评测机来说就是完全一样的。
132.对栈使用top()或pop()前先检查是否为空，不为空再执行，否则会产生未定义行为。
133.list:
```cpp
#include <list>
using namespace std;
list<int> l;
// 1. 增
l.push_back(10);    // 尾插
l.push_front(20);   // 头插 (vector 没有这个，或者很慢)
auto it = l.begin();
l.insert(it, 30);   // 在 it 指向的位置前插入 30, O(1)
// 2. 删
l.pop_back();       // 删尾
l.pop_front();      // 删头
it = l.erase(it);   // 删掉 it 指向的元素，并返回下一个元素的迭代器（重要！）
// 3. 查 (list 的弱项)
// int x = l[k];    // 错误！不能直接下标访问
auto it_find = l.begin();
advance(it_find, k); // 正确做法：手动向后挪 k 步，O(n),因为list不能跳跃，list的迭代器it只有it++;没有it+3;vector的迭代器可以+n是因为vector的内存是连续的，执行+n只是进行了地址更改的一次加法运算，所以是O（1）的，这是相比list的优势
// 4. 其他
l.size();           // 元素个数
l.clear();          // 清空
l.reverse();        // 原地反转链表
l.sort();           // 注意：list 有自己的 sort 成员函数，不能用 std::sort(l.begin(), l.end())
//在遍历删除时不要l.erase(it)；就不管了，这样后it成了野指针，应该把返回值（下一有效迭代器）再赋给it。
for (auto it = l.begin(); it != l.end(); ) {
    if (*it == target) {
        it = l.erase(it); // erase 会返回被删元素的下一个有效迭代器
    } else {
        it++; // 没删的时候才手动自增
    }
}
同样可以用语法糖：for(auto&s:l)cout<<s;
```
134.函数返回类型可以是auto（c++14及以后），会自动推导类型
```cpp
// c++20允许把函数形参设为auto
void check_and_move(auto it, auto& container) {
    if (it == container.end()) return;
    // ... 逻辑
}
//20之前的只能老老实实写模板
template <typename Iter>
void check_and_move(Iter it, list<stack<string>>& s) {
    if (it == s.end()) return;
    // ...
}
template <typename T>
T my_max(T a, T b) {
    return a > b ? a : b;
}
int a = 5;
double b = 6.6;
// cout << my_max(a, b); // 报错！编译器不知道 T 应该是 int 还是 double
cout << my_max<double>(a, b); // 正确：强制指定 T 为 double，a 会被自动转换
//两个不同类型的模板：
template <typename T1, typename T2>
void print_pair(T1 a, T2 b) {
    cout << a << " " << b << endl;
}
int main() {
    print_pair(10, "Gold Medal"); // 编译器自动推导 T1=int, T2=const char*
}
```
135.auto a;//非法，使用auto定义变量必须立即初始化：auto a=it;
136.if中定义的变量也是只能作用在if内。
137.用迭代器时和指针是类似的，it->成员函数等价于(*it).成员函数:
```cpp
list<stack<string>>l;
auto it=l.begin();
if(it->top()=="acm")cout<<endl;
```
138.for循环的判断条件中不要用逗号，逗号表达式只返回后面的值:for(;i<3,j<3;)等价于for(;j<3;)
139.vector有pop_back:删除向量最后一个元素。v.pop_back()；
140.
```cpp
// 1. 传统写法（带等号）
pair<int, int> p1 = {10, 20};
// 2. 统一初始化（不带等号，推荐）
pair<int, int> p2{10, 20};
// 3. 构造函数写法
pair<int, int> p3(10, 20);
tuple<int,int,int>t{1,2,3};
struct State {
    deque<int> hand;
    vector<deque<int>> piles;
    int cur;
    // 这一行代码就搞定了所有复杂的比较逻辑
	//tie使得三个变量从左往右依次比较，而这些容器自己都重载了<(也是从左往右依次比较)，所以这个方式是可以的
    bool operator<(const State& rhs) const {
        return std::tie(hand, piles, cur) < std::tie(rhs.hand, rhs.piles, rhs.cur);
    }
};
```
141.结构体有系统默认的聚合初始化，即不需要自己在定义初始化列表的构造函数。只要没有自己定义构造函数，结构体就有这个默认的初始化方式。
```cpp
struct Point {
    int x;
    int y;
    string label;
};
// 聚合初始化（按定义顺序依次填充）：10 赋给 x，20 赋给 y，"Start" 赋给 label
Point p{10, 20, "Start"};
Point p{10}; //没有给出的就用默认值
// x = 10
// y = 0 (int 的默认值)
// label = "" (string 的默认构造函数)
struct State {
    deque<int> hand;
    deque<int> backup; // 相同类型
    int cur;
};
// 正确：第一个 deque 给 hand，第二个给 backup
State s{{1, 2, 3}, {4, 5, 6}, 0};
struct State {
    deque<int> hand;
    vector<deque<int>> piles;
    int cur;
};
deque<int> current_hand;
vector<deque<int>> current_piles;
int current_cur;
// 可以直接在花括号内使用已有变量
State s{current_hand, current_piles, current_cur};
```
142.vector<deque<int>>piles(7);vector 的这个构造函数会调用元素的默认构造函数。
因为 std::deque<int> 的默认构造函数会创建一个不包含任何元素的空双端队列，所以 piles[0] 到 piles[6] 初始状态都是空的 deque。
143.自己重载的<必须要按格式来，不然后续操作可能会引起报错。
```cpp
    bool operator<(const State& rhs) const { ... }//&能省，但会造成多余开销，所以以后养成习惯，就照着这个板子写
```
如：std::set 和 std::map 是基于红黑树实现的有序容器。为了保证容器内元素的顺序不被破坏，容器在调用 operator< 进行比较时，禁止修改被比较的对象。
如果你定义的形参不是 const，但 set 传入的是 const 对象，编译器会因为“丢弃常量限定符（discards qualifiers）”而直接报错。
144.在结构体中不能使用小括号 () 进行构造初始化。编译器会把 piles(7) 误认为是定义了一个函数：
```cpp
vector<deque<int>>piles(7);//报错
//解决方法
// 方案 A：使用大括号初始化
vector<deque<int>> piles{vector<deque<int>>(7)}; 
// 方案 B：只声明，不指定长度，在构造函数或外部初始化（推荐）
vector<deque<int>> piles;
sta.insert(state{hand,piles,0});以后这种创建临时对象的方法也统一用花括号（更推荐）
```
145.完全可以用vector代替stack（且vector更有优势，可以随机访问）：
| 栈操作 (stack) | 对应的 vector 操作 | 复杂度 |
| --- | --- | --- |
| s.push(x) | v.push_back(x) | 均摊 O(1) |
| s.pop() | v.pop_back() | O(1) |
| s.top() | v.back() | O(1) |
| s.empty() | v.empty() | O(1) |
| s.size() | v.size() | O(1) |
queue完全可以用deque代替，一般用queue是为了语义明确，逻辑清晰：
| 特性 | std::deque | std::queue |  |
| --- | --- | --- | --- |
| 分类 | 序列容器（真正的底层数据结构） | 容器适配器（外壳） |  |
| 访问能力 | 支持随机访问（如 d[i]） | 仅能访问队首/队尾（front/back） |  |
| 操作端 | 双端均可插入、删除 | 一端插入（尾），一端删除（头） |  |
| 比较能力 | 支持 operator<（可直接存入 set） | 不支持直接比较（无内置接口） |  |
| 遍历能力 | 可以使用迭代器遍历 | 无法遍历（除非手动弹出） |  |
deque支持下标访问：O(1)
```cpp
deque<int>p;//p[0]是头部元素，p[p.size()-1]是尾部元素，一般把p[0]视为堆底，把p[p.size()-1](即p.back())视为堆顶,类比stack和vector，新加入的元素一般放在尾部，即下标大的地方。
if (p.size() >= 3) {
    // 此时访问 p[0], p[1], p[p.size()-1] 才是安全的
}
```
std::deque::erase(调用方式：d.erase(it)) 的时间复杂度是 O(n)，具体来说是O(n=该元素到头部的距离和到尾部的距离的最小值)。
内部逻辑：deque 为了保持随机访问能力，删除中间元素时必须进行元素的“挪动”。
优化策略：为了尽可能高效，deque 会聪明地判断：如果被删元素靠近头部，就挪动头部的元素；如果靠近尾部，就挪动尾部的元素。
特例：如果你删的是 d.begin()（头部）或 d.end() - 1（尾部）,它的复杂度会退化为 O(1)（实际上这等同于 pop_front() 或 pop_back()）。
146.定义vector数组：vector<int>v[5];
147.有vector的结构体不能用memset清空（赋值0）可以把一个空结构体赋值给需要用的结构体，如果是结构体数组，则利用循环挨个把空结构体赋值给数组元素。
148.可以在一个结构体中用另一个结构体（结构体嵌套）。
149.用tie构建tuple时传入的必须是变量，因为tie的形参是&引用，不能传入值（如a+1），传值可以用make_tuple(……)；
150.定义局部变量一定记得初始化，否则是垃圾值，bool flag[4];这样在局部定义元素值是随机的，容易造成隐蔽错误。
151.如果bfs时结构体中有类似vector的东西，则队列再push这个结构体时会进行深度拷贝，运行时间会有小幅度延长。
152.vector<int>v[3][3];可以这样定义多维的对应数组。
153.lambda表达式中捕获列表的不同含义：
[]：不捕获。只能使用 Lambda 内部定义的变量（最快，适合纯逻辑判断）。
[=]：按值捕获。拷贝一份外部所有变量到 Lambda 内部。也是捕获局部的变量（可以是main函数（也是局部）中定义在自己之前的，捕获值，
[&]：按引用捕获。直接操作外部变量（竞赛中最常用，比如在 Lambda 里修改全局计数器）捕获所在作用域中定义在自己之前的所有局部变量的引用，即可以在函数中使用。
[x, &y]：指定捕获，x 按值，y 按引用。
全局变量无需捕获，可以直接用
常用示例：
```cpp
struct Node {
    int id, score;
};
vector<Node> v;
// 按分数降序，分数相同按 ID 升序
sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
});
string s = "1234a5";
// 判断是否包含非数字字符
bool has_alpha = any_of(s.begin(), s.end(), [](unsigned char c) {
    return isalpha(c);
});
#include <functional>
// 定义一个计算阶乘的局部 DFS
function<int(int)> dfs = [&](int n) {//std::function 是一个通用的函数包装器，<int(int,int)>外层是函数返回类型，括号内是函数参数类型列表
    if (n <= 1) return 1;
    return n * dfs(n - 1); // 必须捕获dfs这个局部变量才能递归，所以列表里用的&,不能用=，因为dfs还没定义完，要用引用，用=会报错。
};//别忘了这个分号
int add(int a, int b) { return a + b; }
// 声明一个接收两个 int 返回一个 int 的包装器
std::function<int(int, int)> func;
func = add; // 直接赋值函数名
auto dfs = [&](int n) {
    if (n <= 1) return 1;
    return n * dfs(n - 1); // 编译错误！
};
使用 auto 时，编译器在处理 dfs(n-1) 那一行时，dfs 还没有定义完成。它不知道 dfs 是个什么东西，所以无法推导类型,所以必须用function。
```
std::function 的本质是一个类模板，它的存在是为了给所有“长得一样”的函数提供一个统一的“变量类型”。
std::function：类模板名。
虚函数开销：std::function 内部有类型擦除机制（Type Erasure），它的调用比普通函数多几层间接寻址。
“卡常数”的意思就是：出题人故意把时间限制设得很紧（比如跑 5 * 10^7 的数据只给 0.5 秒）
你的算法时间复杂度（Big O）是对的，但因为实现细节导致实际运行时间略微超过了题目限制，结果拿了 TLE
在处理10^5 级别以内的递归时，随便用，代码更爽；如果遇到 10^7 级别这种极其卡常数的题目，老老实实写全局函数。
154.
```cpp
string s = "12345";
// 使用 Lambda 表达式
bool is_num = all_of(s.begin(), s.end(), [](unsigned char c) {
    return isdigit(c);
});
if (is_num) cout << "是一个纯数字字符串" << endl;
//dfs用lambda表达式的示例：
// 1. 先声明（给递归一个名字和签名）
std::function<void(int)> dfs;
// 2. 后定义（通过引用捕获 [&] 拿到 dfs 自己的引用）
dfs = [&](int u) {//需要用到外部的两个数组，所以用&
    // 递归终止条件
    if (u == 0) return;
    // 业务逻辑
    cout << "Visiting node: " << u << endl;
    // 递归调用
    dfs(left_child[u]);
    dfs(right_child[u]);
};
```
155.将数值型转为字符串，可以用sprintf(buf, "%03d", 5),结果为005，优点是可以控制格式，也可以用to_string,但不能控制格式。两者都可以处理变量。如to_string(a);
| 输入类型 | 代码示例 | 转换后的字符串 (string)内容 |  |
| --- | --- | --- | --- |
| int | to_string(123) | "123" |  |
| 负数 | to_string(-45) | "-45" |  |
| long long | to_string(1234567890123LL) | "1234567890123" |  |
| float/double | to_string(3.14) | "3.140000"（注意：默认保留 6 位小数） |  |
156.goto不能跨越函数跳跃，即不能跳到函数外面。
157.你绕过了 plus 和 i 的初始化。如果后续代码（即使在 jump: 之后）还处于这些变量的作用域内，编译器就无法保证这些变量的状态，因此直接报错。
158.用""表示的是字符串字面量，它的底层类型是const char*,不是string;
```cpp
auto dfs = [&](int r0, int c0, string s) -> string { // 明确指定返回 string，否则会报错：返回类型不一样
    if (/* 某种错误条件 */) return ""; // 这里的 "" 会自动转成 string
    // ... 逻辑 ...
    return to_string(sum);
};
方法二：
if (/* 某种条件 */) return string(""); // 或者 return string("\0");
return to_string(sum);
在竞赛中，如果你想表达“空”或“错误”，通常直接返回空字符串 "" 即可。"\0" 实际上是一个包含 null 字符的字符串，在处理时可能会产生意外的 Bug。
```
string("")：调用构造函数（Constructor）
本质：你是在请求 std::string 类创建一个新的对象，并使用 "" (类型为 const char*) 作为初始化参数。
编译器行为：编译器寻找 std::string 类中接受 const char* 的构造函数，创建一个临时对象。
合法性：完全合法。
(string)""：C 风格强制转换（C-style Cast）
本质：这是从 C 语言继承来的暴力转换逻辑。它尝试强行把内存里的一段 const char* 指针解释成一个 std::string 对象。
编译器行为：由于 std::string 是一个复杂的类（Class），而指针是一个原始类型，C 风格转换无法直接在它们之间建立桥梁。
后果：编译错误。你不能用括号强转的方式把字符指针转成类对象。
159.stoi可以处理带符号的数
| 代码 | 结果 |
| --- | --- |
| stoi("123") | 123 |
| stoi("-456") | -456 |
| stoi("+78") | 78 |
| stoi("-12abc") | -12 （遇到 'a' 停止） |
160.两个set之间可以用==判断是否相同,也可以用<,<=等比较，是从头挨个比较。可以用.size()得到set的元素个数。
161.花括号内可以放变量：
```cpp
int x = 10, y = 20;
vector<int> v = {x, y, x + y}; // 完全合法
set<int> s = {x, y};           // 完全合法
struct Node {
    int id, dist;
};
// 在 BFS 过程中
int d = current_dist + 1;
int v = neighbor;
q.push({v, d}); // 这里的 {v, d} 就是含变量的初始化列表
```
162.结构体可以直接相互赋值。
163.你的 BFS 状态定义为 sta {loc, visited_edges}。visited_edges 是一个集合set。如果有 E 条边，边的子集就有 2^E 种。E 最大可以是  500,000。2^500,000 是宇宙毁灭都算不完的数字。BFS 只能处理状态数在 10^6 /10^7 级别的问题。
164,计算机一秒处理10^8次运算，这里的运算指一条语句的执行，包括以下几类：
算术运算：加（+）、减（-）、乘（*）、位运算（&, |, ^, <<）。注意：除法（/）和取模（%）通常比加减法慢 10-40 倍。
逻辑比较：a < b, a == b, a != b。
内存访问：从数组中取值（a[i]）或给变量赋值。
跳转指令：这就是你问的 continue, break, if, 函数调用。
所以即使for循环中continue了好几次，这也是O(n),但这样的运行时间会明显缩短，
搜索的理论复杂度往往是指数级的（如 O(2^N) 或 O(N!)）。通过合理的 continue 提前跳过不可能的分支，可以将实际运行的状态数从 10^15 压减到 10^6。。
我们看重的是运行时间，而非复杂度，运行时间=时间复杂度*常数（由程序内部语句决定）/10^8;加continue可以减小常数，也可能将答案由TLE转为AC
165.用for循环的语法糖时在循环内部改变x的值不会影响它遍历到容器的下一个
166.set的erase的三种重载形式：
| 形式 | 用法示例 | 复杂度 | 说明 |  |
| --- | --- | --- | --- | --- |
| 传数值 | s.erase(10); | O(logN) | 删除值为 10 的元素，若不存在则什么都不做。 |  |
| 传迭代器 | s.erase(it); | O(1) 均摊 | 删除迭代器 it 指向的元素，需确保 it 有效。 |  |
| 传区间 | s.erase(it1, it2); | O(logN+k) | 删除从 it1 到 it2 之间的所有元素。 |  |
167.c++里面有叫作函数式转型的强制类型转换方法，但有几点需要注意：
函数式转型要求类型名必须是一个单词。
✅ 可行：int(3.14)，double(10)，char(65)
❌ 不可行：unsigned int(x)，long long(y)，long double(z)
原因：编译器看到 long long(y) 会产生歧义。
对策：这种情况下必须使用 C 风格强转 (long long)y 或者 C++ 标准强转 static_cast<long long>(y)。
string("zjm")这种的是调用了容器内部的构造函数，构造了一个临时对象。其它容器也有，如：vector<int>(3, 10)，构造一个内容为 {10, 10, 10} 的临时变量
用%5d输出6位数会原样输出这个6位数。
168.string类型也可以sort(只要是提供了随机访问迭代器的容器都可以sort)
```cpp
    string s = "cba21";
    // 对整个字符串进行升序排序
    sort(s.begin(), s.end());
    cout << s << endl; // 输出: 12abc
```
169.next_permutation(p,p+n);将当前序列原地修改为比它“字典序大”的最小排列并返回true。如果已经是最大的排列（降序），则将其重置为最小排列（升序）并返回 false
170.判断能否用n!复杂度进行dfs：
| n | n! 近似值 | 1 秒内是否可跑过 (暴力) |
| --- | --- | --- |
| 10 | 3.6×10^6 | 稳过（大部分 DFS 的极限起点） |
| 11 | 4×10^7 | 能过（如果剪枝得当或常数小） |
| 12 | 4.7×10^8 | 悬（已经是 10^8 量级，除非极简单的逻辑） |
| 13 | 6.2×10^9 | 必挂（除非有强力剪枝或状压优化） |
| 20 | 2.4×10^18 | 溢出边缘（long long 的上限） |
171.剪枝就是在搜索树中，提前发现某条分支不可能产生合法解或最优解，从而直接跳过该分支的探索。
剪枝通常分为两大类：
最优性剪枝 (Optimality Pruning)
逻辑：当前路径虽然合法，但已经可以确定它不可能比目前找到的最佳答案更好。
例子：在求最短路时，如果你当前走过的步数 step 已经大于或等于目前已记录的最短步数 min_step，那就没必要继续搜了。
可行性剪枝 (Feasibility Pruning)
逻辑：当前路径已经不合法了，再走下去也绝不可能合法。
```cpp
void dfs(int state, int cost) {
    // 1. 最优性剪枝
    if (cost >= min_cost) return; 
    // 2. 可行性剪枝
    if (!is_valid(state)) return; 
    // 3. 递归边界
    if (state == target) {
        min_cost = min(min_cost, cost);
        return;
    }
    for (auto next : choices) {
        dfs(next, cost + weight);
    }
}
```
172.rbegin(): 指向最后一个元素。
rend(): 指向第一个元素的前一个位置。
```cpp
vector<int> v = {1, 2, 3, 4, 5};
// 像正常遍历一样，但底层是从后往前
sort(v.rbegin(), v.rend()); // 直接实现降序排列
```
173.将字符数组某区间转为字符串：
```cpp
char a[] = {'H', 'e', 'l', 'l', 'o'};
int n = 5;
string s(a, a + n);
```
不能string(a+k,a)这样转换为倒序，因为string的构造函数会从a+k开始通过指针自增找a,会产生未定义行为。
174.直接跳出整个dfs递归回到main函数的方法：
dfs函数得到正确结果后直接throw 1;就可以回到main执行catch中的，之后再进行下一轮数据;
情况 A：找到了解（触发了 throw）
进入 try 块。
执行 dfs()。
在递归深处执行 throw 1;。
立即中断 dfs 和 try 块中剩余的所有代码。
跳转到 catch (int e) 块执行。
执行完 catch 后，继续执行 catch 块之后的代码。
情况 B：没有找到解（未触发 throw）
进入 try 块。
执行 dfs()。
dfs 递归完所有分支，正常结束（Return）。
执行 dfs() 后面的代码（比如 cout << "No solution";）。
跳过整个 catch 块。
继续执行 catch 块之后的代码。
```cpp
while (cin >> n >> target) {
    try {
        dfs(0, 0); 
        // --- 重点在这里 ---
        // 如果能运行到这一行，说明上面的 dfs() 已经全部跑完了
        // 且内部从未执行过 throw。这意味着：没有找到解！
        cout << "No solution." << endl;
    } catch (int e) {
        // 如果进入了这里，说明 dfs 内部执行了 throw
        // 这里的代码块只负责处理“找到解”之后的逻辑
        if (e == 1) {
            cout << "Found and handled!" << endl;//这里也可以为空，只用于接收强行跳出。
        }
    }
    // 无论有没有解，最后都会走到这里，准备处理下一组数据
}
```
175.数组元素可以是任意对象，如
```cpp
set<int> adj[1005]; // 定义了一个长度为 1005 的数组，每个元素都是一个 set<int>
```
176.使用unique之前必须先sort,数组也可以用unique。数组指针就是最天然的迭代器，所以能用于容器的std函数（非容器成员函数）也能用于数组。
177.“统计每个元素的相邻位置且去重”可以定义一个set数组，但这不是最好的方法，可以用vector数组，统计完后再进行去重操作：
```cpp
for (int i = 1; i <= n; ++i) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
}
```
虽然有排序，但由于 CPU 的缓存命中率（Cache Locality）极高，实际运行效率远超 set。
178.max函数可以放入多个参数进行比较，但不能max(a,b,c)这样传，应该写max({a,b,c});这里的元素可以是定义了<的任意对象。
179.用Node{}代替Node():auto n = Node{}; // 无论你有没有写构造函数，它都会尝试执行最安全的清零操作
180.用swap实现数组或vector元素位置的互换：
```cpp
vector<int> v = {1, 2, 3, 4, 5};
// 交换下标为 1 和 3 的元素 (即 2 和 4)
swap(v[1], v[3]);
int a[3][3];
// 交换坐标 (0,1) 和 (2,2) 的元素
swap(a[0][1], a[2][2]);
int a[5][5];
swap(a[1], a[3]); // 将第 2 行和第 4 行的所有元素对调
//array也可以
std::array<int, 9> board = {1, 2, 3, 0, 4, 5, 6, 7, 8};
std::swap(board[3], board[4]);
```
181.用已有数组定义vector：
```cpp
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(int);
// 核心写法：传入数组的首地址和尾地址
vector<int> v(arr, arr + n);
```
182.在结构体中一般不用数组，因为不能在构造结构体时传数组（数组名会退化为指针），一般用std::array
```cpp
struct state {
    int cnt;
    // 使用 std::array 嵌套定义 3x3 数组
    array<array<int, 3>, 3> a;
};

int main() {
    array<array<int, 3>, 3> a;
    // 输入时
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> a[i][j];
    state s{0,a};
}
//这里也能用数组实现相同目的：
struct state{int cnt;int a[3][3];};
int main(){state s;for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>s.a[i][j];}
```
183.array:定义方式：array<类型, 长度> 变量名;
特性：
可以直接赋值：
arr1 = arr2; 会自动拷贝所有元素。原生数组不能这么干。
支持比较运算符：
if (arr1 == arr2) 会逐个比较元素。原生数组 a == b 比较的是地址，永远是错的。
内置了 operator<：
这极其重要！这意味着你可以直接把它作为 std::set 的元素或 std::map 的 Key。
184.简单来说，typedef 是给现有的数据类型起一个“外号”（别名）。它并不会创建新类型，只是让编译器把你的“外号”理解成原名。
基本语法：
typedef 原类型名 新别名;特殊情形：
```cpp
typedef int State[9];//State会被编译器看作含有9个int的数组
State st[1000];
State& s = st[0];//实现了9个int的数组的引用
//注意：引用后就不能用s表示首元素地址了，因为s成为了数组的引用,被视为一个对象，必须用&s的方式取首地址,但这个地址一般不能用，还是要用数组名让其自动退化为指针。
//但取出来的地址是指向含有 9 个整数的数组的指针，不是int*,而是int(*)[9],所以不能传入形参为int*型的函数中，这时直接传入数组名s使其退化为int*。
```
//也可以值传递，但不推荐：
| 写法 | 代码 | 复杂度 | 内存表现 |
| --- | --- | --- | --- |
| 引用 (Reference) | State& s = st[0]; | O(1) | s 只是 st[0] 的一个别名，不占用额外内存。 |
| 值传递 (Value) | State s = st[0]; | O(N) | 在栈上开辟 9 个位置，并把 st[0] 的数据一个一个搬过去。 |
```cpp
//不用别名也可以：
int a[maxn][9];
int(&s)[9]=a[1];
//现在用using替代typedef:
using State = int[9]; // 语义是：State 等于 int[9]
//但这些都只能在定义时完成数组的引用，不能在定义完后再赋值或引用数组。所以可以用array：
嵌套(多维)array也可以起别名，那样会少很多代码，下面这个其实不用起别名。
using State = array<int, 9>; 
State st[1000];
State& s = st[0]; // 这里的 & 依然是引用，s 依然是 st[0] 的别名
```
185.memcmp、memcpy 等函数中的 mem 代表 Memory（内存）。它们的操作对象是字节（Byte）,因此适用于任意类型,注意memcmp在使用时要传
```cpp
struct State {
    int board[9]; // 八数码棋盘
    int dist;     // 步数
}; 
// 这种结构体成员全是 int，内存是紧凑连续的，可以用 memcmp。若每个变量值都相等返回0.
struct Node {
    char c;    // 占用 1 字节
               // 编译器可能在这里填充 3 字节！
    int i;     // 占用 4 字节
};
struct Node {
    char c;    // 占用 1 字节
               // 编译器可能在这里填充 3 字节！
    int i;     // 占用 4 字节
};
//即使两个 Node 对象的 c 和 i 完全相同，那填充的 3 个字节里的内容是随机垃圾值。memcmp 会比对这些垃圾值，导致逻辑上相等的两个结构体被判定为“不等”。
186.浮点型也可以自增，但不推荐，容易有误差。
187.数组下标的类型是size_t(unsigned long long)，该类型的定义是足以保存目标平台最大可能对象大小的无符号整数类型。所以你不用担心定义数组时长度超过限制，因为你超不了限制。
但是由于大数组需要的内存大，如果你定义 int a[10^9];则需要的内存为3.7GB，如果定义时使用很大的长度，会报错：error: size of array 'a' is too large
题目一般都有内存限制。
| 数组定义 | 内存占用 | 128MB 限制下安全吗？ |
| --- | --- | --- |
| int a[10^6] | ≈4 MB | 非常安全 |
| int a[10^7] | ≈40 MB | 安全 |
| int a[5 \times 10^7] | ≈190 MB | 危险 (MLE) |
| long long a[10^7] | ≈80 MB | 安全 |
| char a[10^8] | ≈95 MB | 勉强安全 |
188.结构体中有数组时构建临时对象的方法：
```cpp
//法一：列表初始化
struct state {
	int a[3],  sum;
};
state{{0, 0, 1}, 0};
//法二：构造函数
struct state {
    int a[3], sum;
    state(int a0, int a1, int a2, int s) {
        a[0] = a0; a[1] = a1; a[2] = a2;
        sum = s;
    }
};
//列表的构造函数：
struct state {
    int a[3], sum;

    // 使用初始化列表
    state(int a0, int a1, int a2, int s) 
        : a{a0, a1, a2}, sum(s) {} 
};
// 调用方式：
state(0, 0, 1, 0)
```
189.不能tie(1,1,1)这样构建一个tuple，因为tie要求传入变量，它需要引用它们。解决方法：
```
s.insert({0, 0, a[2]});//最推荐
s.insert(make_tuple(0, 0, a[2]));
190.fgets的第二个参数是字节数，由于ASCII字符占一个字节，所以存储字符时也可以看作是字符数,代表本次读取最多允许占用的内存字节数（包括最后的空字符 \0）。
```cpp
char s[1005];
fgets(s, sizeof(s), stdin);
```
191.0xff 是一个极其常用的“工具”，它的核心作用是 “掩码（Mask）”，用来截取或保留数据的低 8 位，而将其余位清零。
在 C++ 中，0x 前缀表示十六进制。
十六进制的 f 等于十进制的 15。
十进制的 15 写成 4 位二进制是 1111。
因此，0xff 写成二进制就是：1111 1111
当然也有0xfff(12位)
192.如果在局部定义了很大的数组会导致一运行就段错误，不要在局部定义10^5长度以上的数组。
193.当用完scanf接着需要用fgets时会有遗留换行符，解决方法：
while(scanf("%d\n",&a)==1){fgets(s,sizeof(s),stdin);}//在 scanf 的格式字符串中，任何空白字符（空格      、回车 \n、制表符 \t）的意思都是：“持续读取并丢弃输入流中的所有空白字符，直到遇到第一个非空白字符为止。”
194.现代宏定义：using LL=long long;
195.deque的front所在处是下标0
196.不是void的函数一定要显式写出return，否则返回的是随机值，如bool型可能返回false或true，不确定。
197.char s[1005] = {0}; // 将所有元素初始化为 '\0' (ASCII 0)
198.取出集合中的最大元素：
```cpp
set<int> s = {1, 5, 10, 2};
int max_val = *s.rbegin(); // 结果是 10,也可以是*(--s.end());
```
199.set<int, greater<int>> s;这样就是从大到小排列了，for(auto x:s)就可以从大到小遍历了，也可以for (auto it = s.rbegin(); it != s.rend(); ++it)这样遍历
200.greater<>后面是否加括号的规则：在尖括号 < > 里不加括号，在圆括号 ( ) 里通常要加括号。set<int, greater<int>>这里的 greater<int> 充当的是模板参数你是在告诉 set 容器：“请使用这个类（Class/Struct）作为你的比较规则。
sort(..., greater<int>())sort 函数需要接收一个具体的实例（Instance），即一个活生生的“比较器对象”，这里的 greater<int>() 是在调用构造函数来创建一个临时对象。
201.求所有元素的最大值：用max_element,它返回的是一个迭代器（指针），所以需要用 * 解引用来获取值。求最小值用min_element.
```cpp
int a[] = {3, 1, 9, 7, 5};
    int n = 5;
    // 1. 对于普通数组
    int max_val = *max_element(a, a + n);//一定要注意a+n是最后一个元素地址的下一处地址
    // 2. 对于 vector
     vector<int> v = {3, 1, 9};
     int max_v = *max_element(v.begin(), v.end());
```
202.tuple也可以放二元。
