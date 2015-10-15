bool canWinNim(int n) {
    /*int i=0;
    bool check[3];
    
    check[0] = check[1] = check[2] = true;
    
    for(i=4; i<=n; i++){
        check[i%3] = !(check[0] && check[1] && check[2]);
    }
    
    return check[n%3];*/
    
    return n%4;
    
}
