# Unknown and unforgivable specifications of the C language

# Unknown specifications

## digraph

(sample code)
```digraph.c
#include <stdio.h>

int main()
{
    int arr<::> = <%1, 10%>;
    printf("arr[0]=%d, arr[1]=%d\n", arr<:0:>, arr<:1:>);
    return 0;
}
```

(result)
```
$ gcc ./digraph.c -o digraph
$ ./digraph
arr[0]=1, arr[1]=10
```

```no_digraph.c
#include <stdio.h>

int main()
{
    int arr[] = {1, 10};
    printf("arr[0]=%d, arr[1]=%d\n", arr[0], arr[1]);
    return 0;
}
```

|digraph |equivalent character |
|---|---|
|<: |[ |
|:> |] |
|<% |{ |
|%> |} |
|%: |# |


## trigraph

|trigraph |equivalent character |
|---|---|
|??( |[ |
|??) |[ |
|??< |{ |
|??> |} |
|??= |# |
|??/ |\ |
|??! |&#124; |
|??' |^ |
|??- |~ |


```unable_digraph.c
#include <stdio.h>

int main()
{
    int a = 10;
    printf("<: %d :>\n", a);
    return 0;
}
```

```trigraph.c
#include <stdio.h>

int main()
{
    int a = 10;
    printf("??( %d ??)\n", a);
    return 0;
}
```

```
$ gcc ./trigraph.c -o trigraph -trigraphs
$ ./trigraph
[ 10 ]
```

## comma

```comma.c
#include <stdio.h>

int main()
{
    int x = 0;
    int y = (x = 1, x + 1, x * 2);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

```
$ gcc ./comma.c -o comma
$ ./comma
x = 1, y = 2
```

## auto

```auto.c
#include <stdio.h>

int main()
{
    auto int x = 0;
    auto int y = (x = 1, x + 1, x * 2);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

## register

```register.c
#include <stdio.h>

int main()
{
    register int x = 0;
    register int y = (x = 1, x + 1, x * 2);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```


## restrict

```restrict.c
#include <stdio.h>

void hoge(int d[], int* s)
{
    d[0] += *s;
    d[1] += *s;
}

void piyo(int d[], int* restrict s)
{
    d[0] += *s;
    d[1] += *s;
}

int main(void)
{
    int a[] = {1, 1};
    hoge(a, &a[0]);
    printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);

    int b[] = {1, 1};
    piyo(b, &b[0]);
    printf("b[0] = %d, b[1] = %d\n", b[0], b[1]);
}
```

```
$ gcc ./restrict.c -o restrict
$ ./restrict
a[0] = 2, a[1] = 3
b[0] = 2, b[1] = 3
```

```
$ gcc ./restrict.c -o restrict -O
$ ./restrict
a[0] = 2, a[1] = 3
b[0] = 2, b[1] = 2
```
```
gcc -S restrict.c -O
```

```restrict.s
    :
hoge:
    :
	movl	(%rdx), %eax
	addl	%eax, (%rcx)
	movl	(%rdx), %eax
	addl	%eax, 4(%rcx)
	ret
    :
piyo:
    :
	movl	(%rdx), %eax
	addl	%eax, (%rcx)
	addl	%eax, 4(%rcx)
	ret
    :
```

# Unforgivable specifications

## Control statement without braces

```no_brace.c
#include <stdio.h>

int main()
{
    int x = 5;
    if (x == 0)
        printf("Here, x is 0.\n");
        printf("Here, x is also 0. (It should be)\n");
    return 0;
}
```

```
$ gcc no_brace.c -o no_brace
$ no_brace
Here, x is also 0. (It should be)
```

```brace.c
#include <stdio.h>

int main()
{
    int x = 5;
    if (x == 0)
    {
        printf("Here, x is 0.\n");
        printf("Here, x is also 0. (Definitely)\n");
    }
    return 0;
}
```


## Increment prefix and postfix

```inc.c
#include <stdio.h>

int main()
{
    char a[] = "Zaru";
    int i = 0;
    printf("%c\n", a[i++]);
    printf("%c\n", a[++i]);
    return 0;
}
```

```
$ gcc ./inc.c -o inc
$ ./inc
Z
r
```


```inc2.c
#include <stdio.h>

int main()
{
    char a[] = "Zaru";
    int i = 0;
    printf("%c\n", a[i]);
    i++;
    i++;
    printf("%c\n", a[i]);
    return 0;
}
```


## Assignments in control expressions

```equal.c
#include <stdio.h>

int main()
{
  int a = 5;
  if (a = 10)
  {
      printf("a is 10\n");
  }
  else
  {
      printf("a is not 10\n");
  }
  return 0;
}
```

```
a is 10
```

```equal2.c
#include <stdio.h>

int main()
{
    int a = 5;
    if ((a = 10))
    {
        printf("a is 10\n");
    }
    else
    {
        printf("a is not 10\n");
    }
    return 0;
}
```

```
$ gcc ./equal.c -o equal -Wall
equal.c: In function 'main':
equal.c:6:9: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
     if (a = 10)
```

## goto statement

```ave.c
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float average;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (n != 0)
    {
        average = (float)sum / n;
        printf("Average: %f\n", average);
    }
    else
    {
        printf("Error: Division by zero\n");
    }
    return 0;
}
```

```goto.c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float average;
    int i = 0;

start:
    if (i >= n)
    {
        goto end;
    }
    sum += arr[i];
    i++;
    goto start;

end:
    if (n != 0)
    {
        average = (float)sum / n;
    }
    else
    {
        goto error;
    }
    printf("Average: %f\n", average);
    return 0;

error:
    printf("Error: Division by zero\n");
    return 1;
}
```

```c
start:
    if (i >= n)
    {
        goto end;
    }
    sum += arr[i];
    i++;
    goto start;
```


## In Japanese
[C言語の知られザル・許されザル仕様](https://qiita.com/y-tetsu/items/d839baff7b9f7f54704a)
