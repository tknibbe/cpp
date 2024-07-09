#pragma once


#define func void (*func) (T a)

template <typename T> void iter(T& arr, int len, func){
	for (size_t i=0;i<len;i++){
		func(arr[i]);
	}
}