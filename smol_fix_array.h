
/*
 * MIT No Attribution
 * Full text: https://opensource.org/licenses/MIT-0
 *
 * Copyright 2025 Antônio Ivo da Silva Gomes
 */

#ifndef INCLUDE_SMOL_FIX_ARRAY_HEADER
#define INCLUDE_SMOL_FIX_ARRAY_HEADER

#include <stdlib.h>
#include <string.h>

typedef struct smol_fix_array {
  void *data;
  size_t size;
  size_t capacity;
} smol_fix_array;

smol_fix_array *smol_fix_array_init(size_t size, size_t capacity);

void *smol_fix_array_get(smol_fix_array *array, size_t index);

void smol_fix_array_set(smol_fix_array *array, void *value, size_t index);

void smol_fix_array_free(smol_fix_array *array);

#ifdef SMOL_FIX_ARRAY_IMPLEMENTATION

smol_fix_array *smol_fix_array_init(size_t size, size_t capacity) {
  smol_fix_array *array = (smol_fix_array *)malloc(sizeof(smol_fix_array));

  if (array != NULL) {
    array->data = malloc(size * capacity);
    array->size = size;
    array->capacity = capacity;
  }

  if (array->data == NULL) {
    free(array);
    array = NULL;
  }

  return array;
}

void *smol_fix_array_get(smol_fix_array *array, size_t index) {
  if (index < array->capacity || index >= 0) {
    return (void *)((char *)(array->data) + (array->size * index));
  } else {
    return NULL;
  }
}

void smol_fix_array_set(smol_fix_array *array, void *value, size_t index) {
  void *array_value = smol_fix_array_get(array, index);
  if (array_value != NULL) {
    memcpy(array_value, value, array->size);
  }
}

void smol_fix_array_free(smol_fix_array *array) {
  free(array->data);
  free(array);
}

#endif /* SMOL_FIX_ARRAY_IMPLEMENTATION */

#endif /* INCLUDE_SMOL_FIX_ARRAY_HEADER */
