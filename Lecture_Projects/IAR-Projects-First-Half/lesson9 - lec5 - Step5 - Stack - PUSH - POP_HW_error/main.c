

unsigned add2num(unsigned n,unsigned m);
unsigned add3num(unsigned n,unsigned m,unsigned l);
unsigned addnum(unsigned n);

int main() {
    unsigned x1=1;
    unsigned x2=2;
    unsigned x3=3;
    unsigned x=0; 
    x = x + add3num(x1,x2,x3);
}

unsigned addnum(unsigned n) { 
  *(unsigned int *)0x1ffffffc = 2;
        return n+1;
}        
unsigned add2num(unsigned n,unsigned m) {
        return (addnum(n)+m);
}
unsigned add3num(unsigned n,unsigned m, unsigned l) {
    double a[100];
    a[1]=5;
        return (add2num(n,m)+(int)a[1]);
}