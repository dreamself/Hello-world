void calNext(char* pstr, int* next, int length){
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < length; ++i){
        while(k > -1 && pstr[k+1] != pstr[i]){
            k = next[k];
        }
        if (pstr[k+1] == pstr[i]){
            ++k
        }
        next[i] = k;
    }
}

int kMP(char* pSource, int srceLen, char* pDest, int desLen){
    int* next = new int[desLen];
    calNext(pDest, next, desLen);
    int k = -1;
    for (int i = 0; i < srceLen; ++i){
       while( k>-1 &&  pSource[i] != pDest[k+1]){
            k = next[k];
       }
       if (pSource[i] == pDest[k+1]){
            ++k;
       }
       if (k == desLen-1){
            return i - desLen + 1;
       }
    }
    return -1;
}
