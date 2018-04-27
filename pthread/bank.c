#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>

#define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000000UL + (end.tv_usec - start.tv_usec))

#define THREADS 1
#define MAXEMP 10000
#define MAXOP 10

pthread_mutex_t locks[12000];


typedef struct  {
    int number;
    float  balance;
} Account;

typedef struct {
    int transaction_seq;
    int type;
    float amount;
    int number1;
    int number2;
} Operation;


struct thread_param{
        pthread_t tid;
        Account* arr1;
        Operation* arr2;
        int skip;
        int size;
        int thread_ctr;
};

int scan_account(Account* e, const char *line){
    if(sscanf(line, "%d %f ",&e->number, &e->balance) != 2)
        return -1;

    return 0;
}

int scan_operation(Operation* e, const char *line){
    if(sscanf(line, "%d %d %f %d %d ",&e->transaction_seq, &e->type, &e->amount,
                &e->number1, &e->number2) != 5)
        return -1;

    return 0;
}


void* operate(void* arg)
{
    struct thread_param *param = (struct thread_param *) arg;
    int ctr = param->thread_ctr;

    Account* arr1 = param->arr1;
    Operation* arr2 = param->arr2;

    while(ctr < param->size){

        int type = arr2[ctr].type;
        int amt  = arr2[ctr].amount;
        int ac1 = arr2[ctr].number1;
        int ac2 = arr2[ctr].number2;
        
        pthread_mutex_lock(&locks[ac1]);
        pthread_mutex_lock(&locks[ac2]);

        if(type == 1){
            arr1[ac1-1001].balance += 99*(amt/100.0); 
        }

        else if(type == 2){
            arr1[ac1-1001].balance -= 101*(amt/100.0);
        }

        else if( type == 3 ){

            arr1[ac1-1001].balance += (71*(arr1[ac1-1001].balance))/1000;
        }

        else{
            arr1[ac1 - 1001].balance -= 101*(amt/100.0);
            arr1[ac2 - 1001].balance += 99*(amt/100.0);
        }
        /*printf("here %d",arr2[ctr].type);*/
        pthread_mutex_unlock(&locks[ac1]);
        pthread_mutex_unlock(&locks[ac2]);
        ctr += param->skip;
    }

    return NULL;
}

/*void dumpoperation(FILE *fp, const char *tag, const Operation *e)*/
/*{*/
    /*fprintf(fp, "%s %d %d %.2f %d %d\n", tag, e->transaction_seq, e->type, e->amount,*/
            /*e->number1,e->number2);*/
/*}*/
void dumpacount(FILE *fp,  const Account *e)
{
    fprintf(fp, "%d %.2f\n", e->number, e->balance);
}

int main(int argc, char** argv){

    struct timeval start, end;

    char* accountFile = argv[1]; 
    char* logFile = argv[2]; 

    int transactions = atoi(argv[3]);
    int num_threads = atoi(argv[4]);

    for(int i=0; i<12000;i++){
        pthread_mutex_init(&locks[i], NULL);
    }

    FILE* stream1 = fopen(accountFile, "r");

    Account arr1[MAXEMP];

    char line1[1024];
    
    for(int i = 0; i < MAXEMP && fgets(line1, sizeof(line1), stream1) != 0 ; i++) {

        if(scan_account(&arr1[i], line1) == 0);
            /*dump(stdout, "Employee: ",&arr[i]);*/
    }


    fclose(stream1);

    FILE* stream2 = fopen(logFile, "r");

    Operation arr2[MAXOP];
    char line2[1024];
    
    for(int i = 0; i < MAXOP && fgets(line2, sizeof(line2), stream2) != 0 ; i++) {

        if(scan_operation(&arr2[i], line2) == 0);
            /*dumpoperation(stdout, "Operation: ",&arr2[i]);*/
    }

    fclose(stream2);

    int  num_elements=transactions;
    /*Allocate thread specific parameters*/
    struct thread_param *params;
    params = malloc(num_threads * sizeof(struct thread_param));
    bzero(params, num_threads * sizeof(struct thread_param));

    gettimeofday(&start, NULL);

    /*Partion data and create threads*/
    for(int ctr=0; ctr < num_threads; ++ctr){
        struct thread_param *param = params + ctr;
        param->size = num_elements;
        param->skip = num_threads;
        param->arr1 = arr1;
        param->arr2 = arr2;
        param->thread_ctr = ctr;

        pthread_create(&param->tid, NULL, operate, param) ;
        
    }

    for(int ctr=0; ctr < num_threads; ++ctr){
        struct thread_param *param = params + ctr;
        pthread_join(param->tid, NULL);
    }

    FILE* fp = fopen("final_acc1.txt","a");

    for(int i = 0; i < MAXEMP  ; i++) {

            dumpacount(fp, &arr1[i]);
    }
    
    fclose(fp);

    gettimeofday(&end, NULL);
    printf("Time taken = %ld microsecs\n", TDIFF(start, end));

    return 0;

}
