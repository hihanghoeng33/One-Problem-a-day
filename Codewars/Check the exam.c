#include <stddef.h>

int check_exam(size_t n, const char answers[n], const char student[n]) {
    int res = 0;
    for(size_t i=0;i<n;i++){
      if(answers[i] == student[i] && student[i]!=' '){
        res+=4;
      }else if(student[i]==' '){
        res+=0;
      }else{
        res-=1;
      }
    }
  if(res<0){
    return 0;
  }
    return res;
}
