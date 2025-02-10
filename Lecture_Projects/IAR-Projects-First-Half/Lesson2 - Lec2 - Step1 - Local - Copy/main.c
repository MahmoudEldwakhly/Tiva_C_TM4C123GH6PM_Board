
const   int y=1;
int main() {
  const   int x=1;
  int counter = 0;
  static  int counter1 = 0;
  
  while (counter < 21) {
    counter=counter+y;
  }
  while (counter1 < 21) {
    counter1=counter1+x;
  }    
  return 0;
}
