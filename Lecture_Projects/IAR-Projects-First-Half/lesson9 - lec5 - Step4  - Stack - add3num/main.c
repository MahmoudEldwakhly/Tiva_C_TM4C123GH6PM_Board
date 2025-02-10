

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
        return n+1;
}        
unsigned add2num(unsigned n,unsigned m) {
        return (addnum(n)+m);
}
unsigned add3num(unsigned n,unsigned m, unsigned l) {
        return (add2num(n,m)+l);
}