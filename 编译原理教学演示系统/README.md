# 词法分析部分
## Reg->NFA->DFA->minDFA
+ 输入正规式  形如
```
01*|00(10)*|01 或者 abc*|ac*b
``` 
+ 自动渲染展示Reg->NFA->DFA->minDFA状态图


# 语法分析部分
## LL(1)
+ 输入上下文无关文法,点击运行后会展示FIRST集,FOLLOW集，预测分析表的构造
+ 上下文无关文法区域输入规则：
    + 开始符号为：S
    + 结束符号为：ε
    + 因为会按->分割左右两边 ，左边为非终结符 ，右边不为非终结符的为终结符，字符中间中间不要加空格
    + 以下是人为输入规范
    + 大写符号为  非终结符
    + 小写单个字符,数字和ε（空符号）为： 终结符
+ 验证区域输入规则:
    + 输入任意字符串
    + 当匹配所输入的上下文无关文法时输出 匹配过程
    + 否则输出匹配失败
+ 输入案例 形如
```
S->TR
R->+TR|ε
T->FY
Y->*FY|ε
F->(S)|i
```
+ LL1.js返回值参数：
```
/**
 * @param {any}	hasLCF 判断是否含有左公因子
 * @param {any}	hasLRecursion 判断是否有左递归
 * @param {any} Vn 非终结符集合
 * @param {any} Vt 终结符集合
 * @param {any} P 所有（分解后）规则集合，（扩展后文法）
 * @param {any}	Vn2null 每个非终结符能否推出空
 * @param {any}	FIRST 非终结符的FIRST集合
 * @param {any}	FOLLOW 非终结符的FOLLOW集合
 * @param {any}	SELECT 非终结符的SELECT集合
 * @param {any}	isLL1 判断是否是LL(1)文法
 * @param {any}	LL1AnalysisTable 构造预测分析表
 * @param {any} isSentence 输入串是否匹配
 * @param {any} inputAnalysisTable 输入串分析过程
 * @returns
 */
 ```
 
## LR(0)

