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
  try{
  mtx = make(rows, cols);
  }
  catch(const std::bad_alloc){
  return 2;
  }
  output(mtx);
  rm(mtx);
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

int **make (int rows, int cors){
  int **mtx = new int*[rows];
  for (size_t i=0; i<rows; ++i)
  { try{
      mtx[i]=new int[cors];
    }
    catch(...){
      rm(mtx,i);
    }
  }
  return mtx;
}
