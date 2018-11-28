#include "memory_management.h"

void free_all(int *memory_ptrs, int size_memory_ptr){
	for (int i = 0; i < size_memory_ptr; i++){
		free(memory_ptrs[i]);
	}
}
