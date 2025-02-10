

unsigned add2num(unsigned n,unsigned m);
unsigned int addnum(void);

int main() {
  unsigned x1=1;
  unsigned x2=2;
  unsigned z1;
  unsigned z2;
  z1=addnum();
  z2=add2num(x1,x2);
}

unsigned int addnum() {
  unsigned y1=1;
  unsigned y2=2;  
  y2=y1+2;
  return y2;
}        
unsigned add2num(unsigned n,unsigned m) {
  return n+m;
}
