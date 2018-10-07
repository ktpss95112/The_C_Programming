void place(int bucket[1024], int N, int ball[16384],\
           int M, int method, int result[16384]){
    int rst_ins=0;
    if(method==0){
        //first fit
        for(int i=0; i<M; i++){
            int fit=0;
            for(int j=0; j<N; j++){
                if(bucket[j] >= ball[i]){
                    result[rst_ins++] = j;
                    bucket[j] -= ball[i];
                    fit = 1;
                    break;
                }
            }
            if(!fit) result[rst_ins++] = -1;
        }
    }
    if(method==1){
        //best fit
        for(int i=0; i<M; i++){
            int least_remain=100000000, least_index;
            for(int j=0; j<N; j++){
                if(bucket[j]>=ball[i] && bucket[j]<least_remain){
                    least_remain=bucket[j];
                    least_index=j;
                }
            }
            if(least_remain==100000000) result[rst_ins++] = -1;
            else{
                result[rst_ins++] = least_index;
                bucket[least_index] -= ball[i];
            }
        }
    }
    if(method==2){
        //worst fit
        for(int i=0; i<M; i++){
            int max_remain=-1, max_index;
            for(int j=0; j<N; j++){
                if(bucket[j]>=ball[i] && bucket[j]>=max_remain){
                    max_remain=bucket[j];
                    max_index=j;
                }
            }
            if(max_remain==-1) result[rst_ins++] = -1;
            else{
                result[rst_ins++] = max_index;
                bucket[max_index] -= ball[i];
            }
        }
    }
}
