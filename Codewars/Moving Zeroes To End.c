#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
  int notzero[100000], zero[100000];
  size_t notzeroCount=0, zeroCount=0;
    for(size_t i = 0; i < len; i++){
      if(arr[i]!=0){
        notzero[notzeroCount++] = arr[i];
      }else{
        zero[zeroCount++] = arr[i];
      }
    }
    for (size_t i = 0; i < notzeroCount; i++) {
        arr[i] = notzero[i];
    }
    for (size_t i = 0; i < zeroCount; i++) {
        arr[notzeroCount + i] = zero[i];
    }
}
