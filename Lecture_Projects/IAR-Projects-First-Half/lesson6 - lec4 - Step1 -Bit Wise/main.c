
unsigned int g = 0xABABABAF;
int main() {
  
  unsigned int a = 0xa0000001;
  unsigned int b = 0xDEADBEEF;
  unsigned int c;
  signed int d=0xa0000001;
  signed int e=0x0;
  c = a | b;   // OR
  c = a & b;   // AND
  c = a ^ b;   // XOR
  c = ~b;      // NOT
  c = a << 2;  // Left-shift
  c = d << 2;  // Left-shift
  e = d << 2;  // Left-shift
  e = a << 2;  // Left-shift
  c = a >> 2;  // Right-shift
  c = d >> 2;  // Right-shift
  e = d >> 2;  // Right-shift
  e = a >> 2;
  c=a&0xFFFFFFFE;
  c|=0x00000004;
  g|=0x00000004;
  c=a^0x00000004;    
  e=0x7fffffff;
  e++;
  
  //return 0;
}
