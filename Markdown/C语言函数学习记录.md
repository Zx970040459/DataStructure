# C语言字符串操作->常用函数说明

> 资料说明：
>
> 日期：2022年7月30日
>
> 作者：zx
>
> ------
>
> 

**定义字符串的两种方式：**

1. 数组定义法，如：char str1[] = "hello world!";

2. 指针定义法，如：char *str2 = "hello world!";  

	> 注：两者的不同在于，只有指针法可以进行递增操作！
	>
	> ```c
	> while(*(str2) != '\0')//在字符串末尾处停止
	>   	putchar(*(str2++));//打印字符，指针指向下一个位置
	> ```
	>
	> 上述函数的运行结果为：hello world!

### 1. 字符串操作（引自库：**#include** **<string.h>**）

#### ***strlen()：***

> **函数名：strlen()**
>
> **函数功能**：获取字符串s中实际字符个数，不包括结尾的'\0'；
>
> ```c
> size_t strlen(const char *s);
> ```
>
> **入口参数：**
>
> |  s   | 目标字符串 |
> | :--: | ---------- |
>
> **返回值：**
>
> | 字符串s中实际字符个数，不包括结尾的'\0'； |
> | ----------------------------------------- |
>
> **应用举例：**
>
> ```c
> strlen("hello");
> //结果为5
> ```
>
> **注意：**暂无

#### ***strnlen()：***

> **函数名：strnlen()**
>
> **函数功能**：获取字符串s中实际字符个数，不包括结尾的'\0'；如果实际个数 <= maxlen，则返回n，否则返回第二个参数；
>
> ```c
> size_t strnlen(const char *s, size_t maxlen);
> ```
>
> **入口参数：**
>
> |   s    | 目标字符串               |
> | :----: | ------------------------ |
> | maxlen | 人为设定的字符串长度上限 |
>
> **返回值：**
>
> | 字符串s中实际字符个数，不包括结尾的'\0'；如果实际个数 <= maxlen，则返回n，否则返回第二个参数； |
> | ------------------------------------------------------------ |
>
> **应用举例：**
>
> ```c
> strnlen("hello",4);
> //结果为4
> ```
>
> **注意：**暂无

#### ***strcat()：***

> **函数名：strcat()**
>
> **函数功能：**拼接字符串
>
> ```c
> char	*strcat(char *__s1, const char *__s2);
> ```
>
> **入口参数：**
>
> |  s1  | 目标字符串       |
> | :--: | ---------------- |
> |  s2  | 用于拼接的字符串 |
>
> **返回值：**
>
> | 返回拼接后的s1的首字母地址； |
> | ---------------------------- |
>
> **应用举例：**
>
> ```c
> char str1[11] = "hello";
> char *str2 = "world";
> strcat(str1,str2);
> puts(str1);
> //输出结果为：helloworld
> ```
>
> **注意：**
>
> 1. 函数无法自动判断s1的空间是否可以完全容纳s2，可能造成缓冲区溢出；
>
> 2. 上述例程中的str1不能用指针定义；使用指针定义后，编译报错：trace trap ；
>
> 引入下一个函数strncat()；

#### ***strncat()：***

> **函数名：**strncat();
>
> **函数功能：**拼接字符串
>
> ```c
> char	*strncat(char *__s1, const char *__s2, size_t __n);
> ```
>
> **入口参数：**
>
> |  s1  | 目标字符串           |
> | :--: | -------------------- |
> |  s2  | 用于拼接的字符串     |
> |  n   | 最大添加字符串的长度 |
>
> **返回值：**
>
> | 返回字符串s1的地址 |
> | ------------------ |
>
> **应用举例：**
>
> ```c
> char str1[11] = "hello";
> char *str2 = "world";
> strncat(str1,str2,3);
> printf("结果为：%s\n",str1);
> //输出结果为：hellowor
> ```
>
> **注意：**上述例程中的str1不能用指针定义；使用指针定义后，编译报错：trace trap ；
>
> 

#### ***strcmp()：***

> **函数名：**字符串比较
>
> **函数功能：**比较两个字符串大小；
>
> ```c
> int  strcmp(const char *__s1, const char *__s2);
> ```
>
> **入口参数：**
>
> | s1   | 字符串1 |
> | ---- | ------- |
> | s2   | 字符串2 |
>
> **返回值：**
>
> | 如果s1>s2，返回大于0的整型数 |
> | ---------------------------- |
> | 如果s1<s2，返回一个负数      |
> | 如果s1=s2，返回0             |
>
> **应用举例：**
>
> ```c
> char *str1 = "aabbcc";
> char *str2 = "bbccdd";
> int res = strcmp(str1,str2);
> printf("比较结果是：%d\n",res);
> //比较结果是：-1，即str1<str2;
> ```
>
> **注意：**

#### ***strncmp()：***

> **函数名**：strncmp()
>
> **函数功能：**比较两个字符串指定长度的大小；
>
> ```c
> int  strncmp(const char *__s1, const char *__s2, size_t __n);
> ```
>
> **入口参数：**
>
> | s1   | 字符串1          |
> | ---- | ---------------- |
> | s2   | 字符串2          |
> | n    | 要比较的字符长度 |
>
> **返回值：**
>
> | 如果s1>s2，返回大于0的整型数 |
> | ---------------------------- |
> | 如果s1<s2，返回一个负数      |
> | 如果s1=s2，返回0             |
>
> **应用举例：**
>
> ```c
> char *str1 = "aabbcc";
> char *str2 = "aabcdd";
> int res = strncmp(str1,str2,3);
> printf("比较结果是：%d\n",res);
> //比较结果是：0,前三位相等
> 
> /**典型应用--查找一个堆字符串中，以某一特定字段开头的字符串数量***/
> int test()
> {
>     int count = 0;//定义计数器
>     const char *list[4] = 
>     {
>         "aotraddfdfadfd","aotraldjsdf",
>         "aotrawewes","aorapoods"
>     };
>     for(int i =0;i<4;i++)
>     {
>         if(strncmp(list[i],"aotra",5) == 0)
>         {
>             count++;
>         }
>     }
>     printf("结果是：%d\n",count);
>     return 1;
> }
> //测试结果为：3
> ```
>
> **注意：**

#### ***strcpy()：***

> **函数名**：strcpy()
>
> **函数功能**：字符串赋值
>
> ```c
> char	*strcpy(char *__dst, const char *__src);
> ```
>
> **入口参数：**
>
> | dst  | 目标字符串 |
> | ---- | ---------- |
> | src  | 源字符串   |
>
> **返回值：**
>
> | 返回dst字符串的地址； |
> | --------------------- |
>
> **应用举例：**
>
> ```c
> char str1[20] = "zhangzhang";
> char *str2 = "xuxiao";
> printf("拷贝结果是：%s\n",strcpy(str1,str2));
> //拷贝结果是：xuxiao
> ```
>
> **注意：**该函数不能检测目标字符串是否可以容纳源字符串，引入函数：strncpy；

#### ***strncpy()：***

> **函数名：**字符串拷贝
>
> **函数功能：字符串赋值
>
> ```c
> char	*strncpy(char *__dst, const char *__src, size_t __n);
> ```
>
> **入口参数：**
>
> | dst  | 目标字符串         |
> | ---- | ------------------ |
> | src  | 源字符串           |
> | n    | 要拷贝的字符串长度 |
>
> **返回值：**
>
> | 返回dst字符串的地址； |
> | --------------------- |
>
> **应用举例：**
>
> ```c
> char str1[20] = "zhangzhang";
> char *str2 = "xuxiao";
> printf("拷贝结果是：%s\n",strncpy(str1,str2+3,2));
> //拷贝结果是：iaangzhang
> ```
>
> **注意：**
>
> strcpy函数自定义：
>
> ```c
> char *mystrcpy(char *str1,char *str2)
> {
>   	int i = 0;
>   	if(!(str1 && str2))
>       return;
>   	while(str1[i++] = *str2++);
>   	return str1;
> }
> ```
>
> 

#### ***sprintf()：***

> **函数名：sprintf()
>
> **函数功能：把多个元素组合成一个字符串;
>
> ```c
> int	 sprintf(char * __restrict, const char * __restrict, ...) __printflike(2, 3) __swift_unavailable("Use snprintf instead.");
> ```
>
> **入口参数：**
>
> | __restrict              | 目标字符串                   |
> | ----------------------- | ---------------------------- |
> | const char * __restrict | 后面的参数为需要拼接的字符串 |
>
> **返回值：**
>
> | 返回dst字符串的地址； |
> | --------------------- |
>
> **应用举例：**
>
> ```c
> char str1[100] = "拼接的内容：";
> char *str2 = "测试1的内容";
> sprintf(str1,"测试1：%s",str2);
> puts(str1);
> //输出的结果为：测试1测试1的内容
> ```
>
> **注意：**char    *strchr(const char *__s, int __c);

#### ***strstr()：***

> **函数名：strstr()
>
> **函数功能：查找字符串
>
> ```c
> char	*strstr(const char *__big, const char *__little);
> ```
>
> **入口参数：**
>
> | __big    | 主串   |
> | -------- | ------ |
> | __little | 模式串 |
>
> **返回值：**
>
> | 如果在big中找到了little，则返回从little在big中的首字母的地址； |
> | ------------------------------------------------------------ |
> | 如果没找到，返回NULL；                                       |
>
> **应用举例：**
>
> ```c
> char *str1 = "dadfasdaabbccddrr：";
> char *str2 = "aabbccddrr";
> if(strstr(str1,str2) != NULL)
> {
>   printf("主串中找到子串！\n");
> }
> else
> {
> 	printf("未找到子串！\n");
> }
> //输出的结果为：主串中找到子串！
> ```

#### ***strchr()：***

> **函数名：strchr()
>
> **函数功能：主串中查找字符；
>
> ```c
> char	*strchr(const char *__s, int __c);
> ```
>
> **入口参数：**
>
> | __s  | 主串         |
> | ---- | ------------ |
> | __c  | 要查找的字符 |
>
> **返回值：**
>
> | 如果找到字符，返回s字符串首字符的地址；如果没找到返回NULL； |
> | ----------------------------------------------------------- |
>
> **应用举例：**
>
> ```c
> //查找换行符
> char *str1 = "ceshi\n";
> char *find = NULL;
> find = strchr(str1,'\0');
> if(find != NULL)
>   printf("找到换行符！\n");
> else
>   printf("未找到换行符！\n");
> //结果为：找到换行符
> ```
>
> **注意：**暂无

### 2. 字符串输出

​		引自库：**#include** **<stdio.h>**

#### 		2-1. printf();

```c
int	 printf(const char * __restrict, ...) __printflike(1, 2);
```

#### 		2-2. puts();

```c
int	 puts(const char *);
```

#### 		2-3. fputs();

```c
int	 fputs(const char * __restrict, FILE * __restrict) __DARWIN_ALIAS(fputs);
```

### 3. 字符串输入函数

#### 		3-1. scanf();

```c
int	 scanf(const char * __restrict, ...) __scanflike(1, 2);
```

#### 		3-2. gets();

```c
char* gets(char *str);
```

#### 		3-3. fgets();

```c
char *fgets(char * restrict str, int size, FILE * restrict stream);
```

#### 		3-4. gets_s();

```c
char *gets_s(char *str,int size);
```

### 4. 内存管理函数

####  ***4-1. memset()：***

> **函数名**：memset()
>
> **函数功能**：将指针变量 s 所指向的前 n 字节的[内存](https://so.csdn.net/so/search?q=内存&spm=1001.2101.3001.7020)单元用一个“整数” c 替换，注意 c 是 int 型。s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化
>
> ```c
> void *memset(void *b, int c, size_t len);
> ```
>
> **入口参数：**
>
> | *b   | 要填充的内存地址 |
> | ---- | ---------------- |
> | c    | 要填充的值       |
> | len  | 填充值的长度     |
>
> **返回值：**
>
> | 返回b的地址； |
> | ------------- |
>
> **应用举例：**
>
> ```c
> int a[10];
> memset(a,-1,sizeof(a));
> for(int i=0;i<10;i++)
> {
>     printf("i = %d\t",i);
> 		printf("a = %d\n",a[i]);
> }
> /**输出结果为：
> i = 0   a = -1
> i = 1   a = -1
> i = 2   a = -1
> i = 3   a = -1
> i = 4   a = -1
> i = 5   a = -1
> i = 6   a = -1
> i = 7   a = -1
> i = 8   a = -1
> i = 9   a = -1
> **/
> char a[10];
> memset(a,'1',sizeof(a));
> for(int i=0;i<10;i++)
> {
>   	printf("i = %d\t",i);
>   	printf("i = %c\n",a[i]);
> }/*输出结果为：
> i = 0   i = 1
> i = 1   i = 1
> i = 2   i = 1
> i = 3   i = 1
> i = 4   i = 1
> i = 5   i = 1
> i = 6   i = 1
> i = 7   i = 1
> i = 8   i = 1
> i = 9   i = 1
> */
> ```
>
> **注意：**该函数出自库：string.h
>
> memset函数是按照字节进行逐个赋值，如果是对int型数组进行赋值，需要注意，因为int型变量在32位系统中占4个字节；

