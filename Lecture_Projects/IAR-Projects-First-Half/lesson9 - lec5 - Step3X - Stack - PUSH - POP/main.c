

unsigned add2num(unsigned n,unsigned m);
unsigned add3num(unsigned n,unsigned m,unsigned l);
void addnum(unsigned n,unsigned m);

int main() {
  unsigned volatile x1=1;
  unsigned volatile x2=2;
  //   unsigned volatile x3=3;
  //   unsigned volatile x=4; 
  //        unsigned volatile y=5; 
  //   x = add3num(x1,x2,x3);
  addnum(x1,x2);
  
  //       y = add3num(x1,x2,x3);
}

void addnum(unsigned n,unsigned m) {
  unsigned volatile y1=1;
  unsigned volatile y2=2;  
  y2=y1+2;
  return;
}        
unsigned add2num(unsigned n,unsigned m) {
  unsigned volatile y1=1;
  unsigned volatile y2=2;  
  y2=y1+2;
  return n+m;
}
unsigned add3num(unsigned n,unsigned m, unsigned l) {
  return (add2num(n,m)+l);
}