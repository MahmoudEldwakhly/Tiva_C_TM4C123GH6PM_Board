

unsigned add2num(unsigned n,unsigned m);
unsigned add3num(unsigned n,unsigned m,unsigned l);

int main() {
  unsigned volatile x=0;
  unsigned volatile x1=1;
  unsigned volatile x2=2;
  unsigned volatile x3=3;
  x = add3num(x1,x2,x3);
}

unsigned add2num(unsigned n,unsigned m) {
  return n+m;
}
unsigned add3num(unsigned n,unsigned m, unsigned l) {
  return (add2num(n,m)+l);
}