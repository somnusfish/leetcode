int reverse(char *a){
    int i = 0;
    int j = 0;
    char temp;
    int size;
    while((a[i]=='0')||a[i]=='1'){
        i++;
    }
    a[i] = '\0';
    size = i;
    
    j = 0;
    i = i-1;
    while(j<i){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j++;
        i--;
    }
    
    return size;
}

char addChar(char a, char b, char *tag){
    int _a,_b,_tag;
    int addUp;
    _a = a-'0';
    _b = b-'0';
    _tag = *tag - '0';
    addUp = _a+_b+_tag;
    if(addUp==0){
        *tag = '0';
        return '0';
    }
    if(addUp==1){
        *tag = '0';
        return '1';
    }
    if(addUp==2){
        *tag = '1';
        return '0';
    }
    if(addUp==3){
        *tag = '1';
        return '1';
    }
}

char* addBinary(char* a, char* b) {
    char *c;
    int aSize = reverse(a);
    int bSize = reverse(b);
    int cSize;
    int i=0,j=0;
    char tag = '0';
    
    cSize = aSize>bSize? aSize+2 : bSize+2;
    c = (char *)malloc(sizeof(char)*cSize);
    while((i<aSize)&&(i<bSize)){
        c[i] = addChar(a[i],b[i],&tag);
        i++;
    }
    while(i<aSize){
        c[i] = addChar(a[i],'0',&tag);
        i++;
    }
    while(i<bSize){
        c[i] = addChar('0',b[i],&tag);
        i++;
    }
    if(tag=='1'){
        c[i++] = tag;
        c[i] = '\0';
    }
    else{
        c[i] = '\0';
    }
    reverse(c);
    
    return c;
    
}
