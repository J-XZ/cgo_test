package main

/*
#cgo CFLAGS: -I ../C/c_header
#cgo LDFLAGS: -L ../C/build -lmy_qsort_cmp

#include "sort.h"
typedef int (*qsort_compare_fn)(const void *, const void *);
*/
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	fmt.Println("this is cgo test")

	fmt.Println("go running. Calling C function")
	C.hello()

	var arr = []int32{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	fmt.Print("before sort: ")
	C.print_array((*C.int)(unsafe.Pointer(&arr[0])), C.int(len(arr)))

	C.qsort(unsafe.Pointer(&arr[0]), C.size_t(len(arr)), C.size_t(C.sizeof_int), C.qsort_compare_fn(C.int_cmp))
	fmt.Println("after sort:", arr)
}
