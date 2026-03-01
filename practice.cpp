#include <iostream>
template<class T>
T* merge(const T* a, size_t sa,
         const T* b, size_t sb,
         T* c)
{
  size_t ia = 0;
  size_t ib = 0;
  size_t ic = 0;
  while (ia < sa && ib < sb)
  {
    if (a[ia] <= b[ib])
      {
        c[ic++] = a[ia++];
      }
    else
    {
      c[ic++] = b[ib++];
    }
  }
  while (ia < sa)
  {
    c[ic++] = a[ia++];
  }
  while (ib < sb)
  {
    c[ic++] = b[ib++];
  }
  return c;
}

int main()
{

return 0;
}
