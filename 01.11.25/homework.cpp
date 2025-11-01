#include <iostream>
int**make(int rows, int cors);
void output(const int *const *mtx, int rows, size_t *lns);
void rm(int **mtx, int rows);
void input(int ** mtx, int rows, int cors);
int** convert(const int *t, size_t n, const size_t *lns, size_t rows);
int main()
{
  int rows=0, n=0;
  std::cin >> n;
  if(std::cin.fail())
  {
    return 1;
  }
  int *t = new int[n];
  for(int i = 0; i < n; ++i) {
    std::cin >> t[i];
  }
  std::cin >> rows;
  if(std::cin.fail())
  {
    delete[] t;
    return 1;
  }
  size_t *lns = new size_t[rows];
  for(int i = 0; i < rows; ++i) {
    std::cin >> lns[i];
  }
  int **mtx = convert(t, n, lns, rows);
  output(mtx, rows, lns);
  rm(mtx, rows);
  delete[] t;
  delete[] lns;
  return 0;
}

void rm(int **mtx, int rows)
{
  for (size_t i = 0; i < rows; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int **make (int rows, int cols){
  int **mtx = new int*[rows];
  for (size_t i=0; i<rows; ++i)
  { try{
      mtx[i]=new int[cols];
    }
    catch(const std::bad_alloc &){
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void input(int **mtx, int rows, int cols){
  for(size_t i=0; i<rows; ++i){
    for(size_t j=0; j<cols; ++j){
      std::cin >> mtx[i][j];
    }
  }
}

void output(const int *const *mtx, int rows, size_t *lns){
  std::cout << "Out\n";
  for(size_t i=0; i<rows; ++i){
    for(size_t j=0; j<lns[i]; ++j){
      std::cout << mtx[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int** convert(const int *t, size_t n, const size_t *lns, size_t rows) {
  int **mtx = new int*[rows];
  size_t index=0;
  for (size_t i=0; i<rows; ++i) {
    mtx[i] = new int[lns[i]];
    for (size_t j=0; j<lns[i]; ++j) {
      mtx[i][j] = t[index++];
    }
  }
  return mtx;
}
