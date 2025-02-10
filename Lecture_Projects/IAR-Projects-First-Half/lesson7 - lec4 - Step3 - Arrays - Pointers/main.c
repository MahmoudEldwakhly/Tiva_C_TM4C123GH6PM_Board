int counter[2] = {0,0};
int main() {
  ++counter[0];
  ++counter[1];
  *(counter) = 3;
  *(counter + 1) = 5;
}
