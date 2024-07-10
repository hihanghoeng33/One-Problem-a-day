int numberOfChild(int n, int k) {
     int head = 0, check = 1;
    while(k>0){
        if(check==1 && head!=n-1){
            head++;
        }else if(head<=n-1 || check == 0){
            if(head==0){
                check=1;
                head++;
            }else{
                check=0;
                head--;
            }
        }
        printf("%d ", head);
        printf("%d ", check);
        k--;
    }
    return head;
}