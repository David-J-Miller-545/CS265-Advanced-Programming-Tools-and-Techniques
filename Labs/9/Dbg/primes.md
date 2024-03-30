---
title: Info on `primes.c`
author: Dmitra Vista
geometry: margin=3cm
secnumdepth: 2
#toc: yes
#toccolor: BrickRed
#toc-depth: 2
urlcolor: Blue
lang: en
---

# How to compile

> ~~~
> gcc -g primes.c -lm
> ~~~

# Output

List of prime numbers from 1 to 10:

> ~~~
> 2 3 5 7 
> sum=17
> ~~~

# The Program Bugs

- 1 is not a prime
- 2 is a prime
- The arguments to `sum` should be `x` not `n`
- The addition in `sum` is wrong
- We do not initialize `total` in `sum`
