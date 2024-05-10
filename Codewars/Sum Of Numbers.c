int get_sum(int a , int b) {
  int total=0;
  if(a<=b){
    for(int i=a;i<=b;i++){
      total+=i;
    }
  }else if(a>=b){
    for(int i=b;i<=a;i++){
      total+=i;
    }
  }
  return total;  
}
