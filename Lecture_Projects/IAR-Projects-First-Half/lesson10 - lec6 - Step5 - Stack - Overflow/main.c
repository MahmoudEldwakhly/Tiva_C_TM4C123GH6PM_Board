

unsigned fact(unsigned n);

int main() {
    unsigned volatile x;
    
    x = fact(0U);
    x = 2U + 3U*fact(1U);
    (void)fact(7U);

    return 0;
}

unsigned fact(unsigned n) {
// 0! = 1
// n! = n*(n-1)!  for n > 0
    unsigned foo[100];
    foo[n] = n;
  
    if (n == 0U) {
        return 1U;
    }
    else {
        return foo[n] * fact(n - 1U);
    }
}
