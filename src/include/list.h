#ifndef LOL_LIST_H
#define LOL_LIST_H

#include <stdlib.h>

typedef struct LIST_STRUCT {
  void** items;
  size_t item_size;
  size_t size;
} list_t;

list_t* init_list(size_t item_size);

void list_push(list_t*, void* item);
void* list_get(list_t*, size_t index);

#endif
