bool checkRow(char board[9][9]){
    int tag[10];
    int i;
    int j;
    int value;
    for(i=0; i<9; i++){
        for(j=1; j<=9; j++){
            tag[j] = 0;
        }
        for(j=0; j<9; j++){
            if(board[i][j]!='.'){
                value = board[i][j] - '0';
                if(tag[value]){
                    return false;
                }
                else{
                    tag[value] = 1;
                }
            }
        }
    }
    return true;
}

bool checkColum(char board[9][9]){
    int tag[10];
    int i;
    int j;
    int value;
    for(i=0; i<9; i++){
        for(j=1; j<=9; j++){
            tag[j] = 0;
        }
        for(j=0; j<9; j++){
            if(board[j][i]!='.'){
                value = board[j][i]-'0';
                if(tag[value]){
                    return false;
                }
                else{
                    tag[value] = 1;
                }
            }
        }
    }
    return true;
}

bool checkBlock(char board[9][9], int row, int colum){
    int tag[10];
    int i;
    int j;
    int value;
    for(i=1; i<=9; i++){
        tag[i] = 0;
    }
    for(i=row; i<row+3; i++){
        for(j=colum; j<colum+3; j++){
            if(board[i][j]!='.'){
                value = board[i][j]-'0';
                if(tag[value]){
                    return false;
                }
                else{
                    tag[value] = 1;
                }
            }
        }
    }
    return true;
}
bool isValidSudoku(char board[9][9]) {
    bool check=true;
    int i;
    int j;
    check = check&&checkRow(board)&&checkColum(board);
    for(i=0; i<9; i=i+3){
        for(j=0; j<9; j=j+3){
            check &= checkBlock(board, i, j);
            if(!check){
                return check;
            }
        }
    }
    return check;
}
