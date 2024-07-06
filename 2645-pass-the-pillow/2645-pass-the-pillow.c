int passThePillow(int n, int time) {
    int head = 1, check = 1;
    while(time>0){
        if(check==1 && head!=n){
            head++;
        }else if(head<=n || check == 0){
            if(head==1){
                check=1;
                head++;
            }else{
                check=0;
                head--;
            }
        }
        printf("%d ", head);
        printf("%d ", check);
        time--;
    }
    return head;
}