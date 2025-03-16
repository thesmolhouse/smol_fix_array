# Smol Fix Array
A smol lib about fixed arrays.
It's only for study, but if you can use it, use it.

## How to use?
``` c
#include <stdio.h>
#define SMOL_FIX_ARRAY_IMPLEMENTATION
#include "smol_fix_array.h"

typedef struct {
  char value;
} Content;

Content buffer;

int main() {
  size_t size = 26;
  size_t size_of_value = sizeof(Content);

  // Create
  smol_fix_array *array = smol_fix_array_create(sizeof(Content), size);

  for (int i = 0; i < size; i++) {
    buffer.value = 65 + i;
    // Set
    smol_fix_array_set(array, &buffer, i);
  }

  for (int i = 0; i < size; i++) {
    // Get
    buffer = *(Content *)smol_fix_array_get(array, i);
    printf("array[%2d] = {%c}\n", i, buffer.value);
  }

  // Free
  smol_fix_array_free(array);
  return 0;
}
```
