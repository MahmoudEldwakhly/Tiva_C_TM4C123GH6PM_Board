unsigned int counter = 0;
unsigned int counter1 = 0;
int main() {
  unsigned int *p_int;
  p_int = &counter;
  while (*p_int < 21) {
    ++(*p_int);
  }
  while (counter1 < 21) {
    ++counter1;
  }   
  p_int = (unsigned int *)0x20000008U;
  //       p_int = 0x20000002;
  
  *p_int = 0xDEADBEEF;
  
  return 0;
}
