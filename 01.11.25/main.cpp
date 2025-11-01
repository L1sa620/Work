#include <iostream>
int**make(int rows, int cors);
void output(const int *const *mtx);
void rm(int **mtx);


int main()
{
int rows=0,cols=0;
std::cin >> rows >> cols;
if(std::cin.fail())
{
  return 1;
}

int **mtx=nullptr;
output(mtx);
rm(mtx);
return 0;
}
