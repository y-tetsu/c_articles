# I'm so tired of undefined behaviors, I can't move...
![ub](../images/ub.png)

While I was learning the C language, I came across something called undefined behavior.

When I was researching undefined behaviors, I found that they are full of elements that cause “I'm so tired, I can't move...”

So, I would like to introduce the contents focusing on various **undefined behaviors**.


# What is undefined behavior?

[Wikipedia](https://en.wikipedia.org/wiki/Undefined_behavior#:~:text=In%20computer%20programming,%20undefined%20behavior%20(UB)) describes the undefined behavior as follows

> In computer programming, undefined behavior (UB) is the result of executing a program whose behavior is prescribed to be unpredictable, in the language specification of the programming language in which the source code is written.

I see. I guess it is as the saying goes.

In the C language, which is the main subject of this article, “within the rules of the program and outside the rules” is also defined.

If it is outside the rules, it will cause undefined behavior (UB), which is not guaranteed! (From now on, I would like to get used to this so that I will be able to recognize UB as soon as it is mentioned.)

...And I also found some more descriptions that smelled fishy.

> undefined behavior as allowing the compiler to do anything it chooses, even "to make demons fly out of your nose".

??? ...... What an original expression!

Actually, C code does not mean that you are allowed to write anything as long as the syntax is correct.

So what exactly do we have to offer to make demons fly out of your nose?

(note)
> The results of the operation checks in this article are based on GCC 14.1.0 on Windows 10.

(alert)
> The results of executing any of the codes presented in this article are not known what will happen, and there is no guarantee of operation.
>
> The author assumes no responsibility for any damage or malfunction caused by the use of the code in this article. Users should execute this code at their own risk.
>
> When using the code, please take care to ensure that it is executed safely in an appropriate environment.


# Undefined behavior that cause “I'm so tired I can't move..."

## division by zero
What was the first thing that came to your mind when you heard the word “undefined begavior”? In my case, it was “divide the value of a variable by `0`,” or division by zero. This is one of the most popular and familiar operations, isn't it?

An example code is shown below.

(for integer type)
```div0_int.c
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 0;

    printf("x , y = %d , %d\n", x, y);
    printf("x / y = %d\n", x / y);  // division by zero

    return 0;
}
```

I am trying to display the result of dividing `10` in `x` by `0` in `y`. Dividing by `0` is a bad idea even in arithmetic.

Let's try it just to see what it looks like. Will the devil come out of the nose?

```
$ gcc ./div0_int.c -o div0_int

$ ./div0_int
x , y = 10 , 0

$
```

The part with `$` at the beginning of the line is the execution part of the command, which compiles and executes the program from above, respectively. The part without `$` is the standard output of the program (the output of `printf`). (Incidentally, a line with only `$` indicates that the program is waiting for command input.)

It seems that the program has been forced to terminate immediately after the division by zero. The program is terminated without displaying the result of the division and is waiting for command input.

I guess you may have been disappointed and thought, “Oh, that's all there is to it...”. However, you would like to know more about the situation, wouldn't you?

In such a case, you may want to try using gdb.

(1. Compile with debugging information)
```
$ gcc ./div0_int.c -o div0_int_g -g
```

(2. gdb startup)
```
$ gdb ./div0_int_g
GNU gdb (GDB) 14.2
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from div0_int_g...
(gdb)
```

(3. Program execution)
```
(gdb) run
Starting program: C:\div0\div0_int_g.exe
x , y = 10[New Thread 2136.0x21b8]
 , 0

Thread 1 received signal SIGFPE, Arithmetic exception.
0x00007ff70ba814dd in main () at div0_int.c:9
9           printf("x / y = %d\n", x / y);  // division by zero
(gdb)
```

From the following message in the above output result, an **arithmetic exception** occurred at the timing of zero division.

```
Thread 1 received signal SIGFPE, Arithmetic exception.
```

In this case, it seems that when the program tried to do a division by zero, the CPU detected an anomaly, which caused the OS to stop the program. Thanks to the wise men and women (behind the scenes) around us, we may have been able to save the day.

By the way, the reason I used “in the case of integer type” in the previous example is that the behavior may be different in the case of floating-point type. Let's take a look at the example for floating-point types.

(for floating-point types)
```div0_double.c
#include <stdio.h>

int main()
{
    double x = 10.0;
    double y = 0.0;

    printf("x , y = %f , %f\n", x, y);
    printf("x / y = %f\n", x / y);  // division by zero

    return 0;
}
```

Unlike integer types, many implementations of floating-point types follow the IEEE754 standard. In this case, the result of division by zero is `INFINITY` - the predefined behavior - which represents “infinity”.

The result of the execution is as follows.

```
$ gcc ./div0_double.c -o div0_double

$ ./div0_double
x , y = 10.000000 , 0.000000
x / y = inf

$
```

It is true that in the case of GCC this time, it seems to be treated as `INFINITY` (`inf`) as in the standard. (Note that if the result is cast to an integer type, the problem of undefined behavior will occur again...)

By the way, one of the troublesome points of undefined behavior, not limited to this case, is that it may continue to work even if it occurs.

As far as we tested it, it “just happened to work like that,” but when we put it into operation, lightning strikes⚡ at the critical moment (e.g., a crash)! There are also situations like this....

I am sure that there are many of you who have had countless episodes of drama and taboo, of “I'm so tired, I can't move...”...

(note)
> The modulo (remainder to find the remainder) operation with `%` is undefined, as is the division by `/` with `0`.


## extra-regional access

```out_of_bounds_idx.c
#include <stdio.h>

int main()
{
    int arr[3] = {1, 2, 3};

    printf("%d\n", arr[3]);  // extra-regional access

    return 0;
}
```

```
$ gcc ./out_of_bounds_idx.c -o out_of_bounds_idx

$ ./out_of_bounds_idx
10490752

$ ./out_of_bounds_idx
1905536

$ ./out_of_bounds_idx
13374336

$
```

```out_of_bounds_ptr.c
#include <stdio.h>

int main()
{
    char arr[3] = {1, 2, 3};
    int i;
    int *ptr;

    ptr = (int*)arr;
    for (i=0; i<sizeof(arr); i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}
```

<br>
<br>
<br>
<br>
<br>

![clock_1200.png](./images/clock_1200.png)

```
$ gcc ./out_of_bounds_ptr.c -o out_of_bounds_ptr

$ ./out_of_bounds_ptr
218300929
25086
268435456

$
```

```
    int *ptr;

    ptr = (int*)arr;
```

```
    char *ptr;

    ptr = arr;
```

```
$ gcc ./out_of_bounds_ptr.c -o out_of_bounds_ptr_g -fsanitize=undefied  -fsanitize-undefined-trap-on-error -g

$ gdb ./out_of_boundes_ptr_g
```

```
(gdb) run
Starting program: C:\out_of_bounds\out_of_bounds_ptr_g.exe
[New Thread 1932.0x37a0]

Thread 1 received signal SIGILL, Illegal instruction.
0x00007ff66c2414e8 in main () at out_of_bounds_ptr.c:12
12              printf("%d\n", *ptr);
(gdb)
```

## Use of uninitialized variables

```uninitialized.c
#include <stdio.h>

int global_var;
static int static_var;

int main()
{
    int local_var1;
    int local_var2 = local_var1;

    printf("global : %d\n", global_var);
    printf("static : %d\n", static_var);
    printf("local1 : %d\n", local_var1);  // Access to uninitialized automatic variables
    printf("local2 : %d\n", local_var2);  // Access to uninitialized automatic variables

    return 0;
}
```

```
$ gcc ./uninitialized.c -o uninitialized

$ ./uninitialized
global : 0
static : 0
local1 : 0
local2 : 0

$
```

```
$ gcc ./uninitialized.c -o uninitialized -Wall
uninitialized.c: In function 'main':
uninitialized.c:9:9: warning: 'local_var1' is used uninitialized [-Wuninitialized]
    9 |     int local_var2 = local_var1;
      |         ^~~~~~~~~~
uninitialized.c:8:9: note: 'local_var1' was declared here
    8 |     int local_var1;
      |         ^~~~~~~~~~
```


## In Japanese
[【C言語】ハァ… 困ったなァ 「未定義動作」にもう疲れちゃって 全然動けなくてェ…](https://qiita.com/y-tetsu/items/204fb43c3b9ac91827a0)
