#ifndef ADDVALUE_H
#define ADDVALUE_H

template <auto Val, typename T = decltype(Val)> T addValue(T x) {
  return x + Val;
}

#endif
