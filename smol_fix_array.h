
/*
 * MIT No Attribution
 * Full text: https://opensource.org/licenses/MIT-0
 *
 * Copyright 2025 Antônio Ivo da Silva Gomes
 */

#ifndef INCLUDE_SMOL_FIX_ARRAY_H
#define INCLUDE_SMOL_FIX_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;
  size_t capacity;
  size_t size;
} smol_fix_array;

smol_fix_array *smol_fix_array_create(size_t size, size_t capacity);

void *smol_fix_array_get(smol_fix_array *array, size_t index);

void smol_fix_array_set(smol_fix_array *array, void *value, size_t index);

void smol_fix_array_free(smol_fix_array *array);

#ifdef SMOL_FIX_ARRAY_IMPLEMENTATION

smol_fix_array *smol_fix_array_create(size_t size, size_t capacity) {
  smol_fix_array *array = (smol_fix_array *)malloc(sizeof(smol_fix_array));

  if (array != NULL) {
    array->data = malloc(size * capacity);
    array->size = size;
  }

  if (array->data == NULL) {
    free(array);
  }

  return array;
}

void *smol_fix_array_get(smol_fix_array *array, size_t index) {
  if (array->capacity > index) {
    return (void *)((char *)(array->data) + (array->size * index));
  } else {
    return NULL;
  }
}

void smol_fix_array_set(smol_fix_array *array, void *value, size_t index) {
  if (array->capacity > index) {
    void *array_ptr = smol_fix_array_get(array, index);
    memcpy(array_ptr, value, array->size);
  }
}

void smol_fix_array_free(smol_fix_array *array) {
  free(array->data);
  free(array);
}

#endif // SMOL_FIX_ARRAY_IMPLEMENTATION

#endif // INCLUDE_SMOL_FIX_ARRAY_H
