int counter = 0;
unsigned int counter1=0;
int main() {
  int *p_int;
  p_int = &counter;
  while (*p_int < 21) {
    ++(*p_int);
  }
  ++counter; 
  ++counter1;
  p_int = (int *)0x20000002;
  *p_int = 0xDEADBEEF;
  
  return 0;
}
