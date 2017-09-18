#include <ucc.h>
#include <assert.h>
#include <stdlib.h>

static PURE CONST __inline__ int
foo(int a, int b) {
  return a + b;
}

NORETURN void
die(int code) {
  exit(code);
}

int main(void) {
  assert(10203UL == VERNO(1, 2, 3));
  assert(5 == foo(2, 3));
  die(0);
}
