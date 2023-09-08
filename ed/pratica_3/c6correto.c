#include <stdint.h>
#include <stdlib.h>

struct _List {
  int32_t *data;
  int32_t length;
};
typedef struct _List List;

List *resizeArray(List *array) {
  array->data =
      realloc(array->data, 15 * sizeof(int32_t)); // doesn't update array->data
  return array;
}

int main() {
  List *array = calloc(1, sizeof(List));
  array->data = calloc(10, sizeof(int32_t));
  array = resizeArray(array);

  free(array->data);
  free(array);
  return 0;
}
