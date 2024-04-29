bool isPrime(int num) {
  if(num==1 || num<=0){
    return false;
  }else if(num==2){
    return true;
  }
  for(int i=2;i<=sqrt(num);i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}
