 
int fun(void);
int fun() 
{ 
  static int count = 0;
  int countx =0;
  count++;
  countx++;
  return count;
} 
   
int main() 
{ 
  int x;
  x=fun(); 
  x = fun();
  x = fun();
  return 0; 
}
