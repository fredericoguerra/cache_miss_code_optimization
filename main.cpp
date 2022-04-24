#include <iostream>
#include <math.h>
#include <ctime>
#include <fstream>
#include <chrono>
#include <list>
#include <stdio.h>
using namespace std;

int original(int N){

    double A[N][N], B[N][N], MULT[N][N];
    int i, j;
    
    for(j = 0; j < N; ++j){
        for(i=0;i<N;++i){
            MULT[i][j] = 0;
            A[i][j] = pow(i,2.1);
            B[i][j] = pow(A[i][j],2.3)/(j+1);
            MULT[i][j] = A[i][j] * B[i][j];
        }
    }
    return 1;   
}

int merge_array(int N){
    struct DataStruct{
        double A, B, MULT;};
    DataStruct data[N][N];
    int i, j;

    for(j = 0; j < N; ++j){
        for(i=0;i<N;++i){
            data[i][j].MULT = 0;
            data[i][j].A = pow(i,2.1);
            data[i][j].B = pow(data[i][j].A,2.3)/(j+1);
            data[i][j].MULT = data[i][j].A * data[i][j].B;
        }
    }
    return 1;
}

int change_order(int N){
    double A[N][N], B[N][N], MULT[N][N];
    int i, j, Nq;
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            MULT[i][j] = 0;
            A[i][j] = pow(i,2.1);
            B[i][j] = pow(A[i][j],2.3)/(j+1);
            MULT[i][j] = A[i][j] * B[i][j];
        }
    }
    return 1;
}

int change_order_merge_array(int N){
    struct DataStruct{
        double A, B, MULT;};
    DataStruct data[N][N];
    int i, j;
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            data[i][j].MULT = 0;
            data[i][j].A = pow(i,2.1);
            data[i][j].B = pow(data[i][j].A,2.3)/(j+1);
            data[i][j].MULT = data[i][j].A * data[i][j].B;
        }
    }
    return 1;
}

int unnested_loop(int N){
    
    int i, j;
    double A[N][N], B[N][N], MULT[N][N];
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            A[i][j] = pow(i,2.1);
        }
    }
    
    
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            B[i][j] = pow(A[i][j],2.3)/(j+1);
            }
        }
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            MULT[i][j] = 0;
        }
    }

    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            MULT[i][j] = A[i][j] * B[i][j];
        }
    }
    return 1;   
}

int change_order_unnested_loop_merge_array(int N){
    
    struct DataStruct{
        double A, B, MULT;};
    DataStruct data[N][N];
    int i, j;
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            data[i][j].A = pow(i,2.1);
        }
    }
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            data[i][j].B = pow(data[i][j].A,2.3)/(j+1);
            }
        }
    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            data[i][j].MULT = 0;
        }
    }

    
    for(i = 0; i < N; ++i){
        for(j=0;j<N;++j){
            data[i][j].MULT = data[i][j].A * data[i][j].B;
        }
    }
    return 1;   
}

int main(){
    ofstream myfile;
    std::list<int> N_list({100,250,500,1000,5000,10000});
    int i;

    myfile.open ("results.csv");
    myfile << "array_size,index,method,time,\n";
    for(int k : N_list){
        printf("starting size:%d\n",k);
        for(i = 0; i < 30; ++i){
            if(i==15)
                printf("50%%\n");
            if(i==8)
                printf("25%%\n");
            if(i==23)
                printf("75%%\n");
            auto t1 = std::chrono::high_resolution_clock::now();
            original(k);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
            float time = (float)duration/1000000;
            myfile << k << "," << i << ",original," << time << ",\n";

            auto t3 = std::chrono::high_resolution_clock::now();
            merge_array(k);
            auto t4 = std::chrono::high_resolution_clock::now();
            auto duration2 = (std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count());
            float time2 = (float)duration2/1000000;
            myfile << k << "," << i << ",merge_array," << time2 << ",\n";

            auto t5 = std::chrono::high_resolution_clock::now();
            change_order(k);
            auto t6 = std::chrono::high_resolution_clock::now();
            auto duration3 = (std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count());
            float time3 = (float)duration3/1000000;
            myfile << k << "," << i << ",change_order," << time3 << ",\n";

            

            auto t7 = std::chrono::high_resolution_clock::now();
            change_order_merge_array(k);
            auto t8 = std::chrono::high_resolution_clock::now();
            auto duration4 = (std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count());
            float time4 = (float)duration4/1000000;
            myfile << k << "," << i << ",change_order_merge_array," << time4 << ",\n";

            auto t9 = std::chrono::high_resolution_clock::now();
            unnested_loop(k);
            auto t10 = std::chrono::high_resolution_clock::now();

            auto duration5 = (std::chrono::duration_cast<std::chrono::microseconds>(t10 - t9).count());
            float time5 = (float)duration5/1000000;
            myfile << k << "," << i << ",unnested_loop," << time5 << ",\n";

            auto t11 = std::chrono::high_resolution_clock::now();
            change_order_unnested_loop_merge_array(k);
            auto t12 = std::chrono::high_resolution_clock::now();

            auto duration6 = (std::chrono::duration_cast<std::chrono::microseconds>(t12 - t11).count());
            float time6 = (float)duration6/1000000;
            myfile << k << "," << i << ",change_order_unnested_loop_merge_array," << time6 << ",\n";
        }
    }
    myfile.close();
}