#include <cstddef>

template<class T>
struct BiList
{
  T val;
  BiList* next;
  BiList* prev;
};

template<class T>
BiList<T>* fake()
{
  BiList<T>* f = static_cast<BiList<T>*>(::operator new(sizeof(BiList<T>)));
  f->next = f;
  f->prev = f;
  return f;
}

template<class T>
void rmfake(BiList<T>* f) noexcept
{
  ::operator delete(f);
}

template<class T>
BiList<T>* after(BiList<T>* p, const T& v)
{
  BiList<T>* n = new BiList<T>{v};
  n->next = p->next;
  n->prev = p;
  p->next->prev = n;
  p->next = n;
  return n;
}

template<class T>
BiList<T>* before(BiList<T>* p, const T& v)
{
  return insert_after(p->prev, v);
}

template<class T>
BiList<T>* erase(BiList<T>* p) noexcept
{
  BiList<T>* r = p->next;
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
  return r;
}

template<class T>
void clear(BiList<T>* f) noexcept
{
  BiList<T>* t = f->next;
  while (t != f)
  {
    t = erase(t);
  }
}

template<class T, class F>
F forward(F func, BiList<T>* f)
{
  for (BiList<T>* t = f->next; t != f; t = t->next)
  {
    func(t->val);
  }
  return func;
}

template<class T, class F>
F backward(F func, BiList<T>* f)
{
  for (BiList<T>* t = f->prev; t != f; t = t->prev)
  {
    func(t->val);
  }
  return func;
}

template<class T>
BiList<T>* convert(const T* a, size_t k)
{
  BiList<T>* f = fake<T>();
  BiList<T>* tail = f;
  for (size_t i = 0; i < k; ++i)
  {
    tail = insert_after(tail, a[i]);
  }
  return f;
}

template<class T>
T* convert(size_t& k, const BiList<T>* f)
{
  k = 0;
  const BiList<T>* t = f->next;
  while (t != f)
  {
    ++k;
    t = t->next;
  }
  T* arr = new T[k];
  size_t i = 0;
  t = f->next;
  while (t != f)
  {
    arr[i++] = t->val;
    t = t->next;
  }
  return arr;
}

int main()
{
}
