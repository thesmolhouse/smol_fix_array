# Smol Fix Array
A smol lib about (generic) fixed arrays.
It's only for study, but if you can use it, use it.

## How to use?
``` c
#include <stdio.h>
#define SMOL_FIX_ARRAY_IMPLEMENTATION
#include "smol_fix_array.h"

typedef struct {
  char value;
} Character;

Character buffer;

int main() {
  size_t size = 26;
  size_t size_of_value = sizeof(Character);

  smol_fix_array *array = smol_fix_array_init(size_of_value, size); // create

  for (int i = 0; i < size; i++) {
    buffer.value = 65 + i;
    smol_fix_array_set(array, &buffer, i); // set
  }

  for (int i = 0; i < size; i++) {
    buffer = *(Character *)smol_fix_array_get(array, i); // get
    printf("array[%02d] = {%c}\n", i, buffer.value);
  }

  smol_fix_array_free(array); // free
  return 0;
}
```
