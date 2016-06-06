#include <stdlib.h>
#include <stdio.h>
#include <time.h>



#define WIDTH 80
#define HEIGHT 22
int columnCheck(int i){
    if(i >= 0 && i < WIDTH){
        //printf("got a good col %i\n", i);
        return 1;
    }
    return 0;
}

int rowCheck(int i){
    if(i >= 0 && i < HEIGHT){
        //printf("got a good row %i\n", i);
        return 1;
    }
    return 0;
}

int checkNeighbor(char * holder[], int col, int row, int coldelta, int rowdelta){
    if(columnCheck(col + coldelta)){
        if(rowCheck(row + rowdelta)){
            if(holder[col+coldelta][row+rowdelta] == '@'){
                return 1;
            }
        }
    }
    return 0;
}

int numberOfNeighbors(char * holder[], int col, int row){
    int result = 0;
    result += checkNeighbor(holder, col, row, 0, 1);
    result += checkNeighbor(holder, col, row, 1, 1);
    result += checkNeighbor(holder, col, row, 1, 0);
    result += checkNeighbor(holder, col, row, 1, -1);
    result += checkNeighbor(holder, col, row, 0, -1);
    result += checkNeighbor(holder, col, row, -1, -1);
    result += checkNeighbor(holder, col, row, -1, 0);
    result += checkNeighbor(holder, col, row, -1, 1);
    return result;
}


void fillArray(char ** holder){
    srand(time(NULL));

    int i = 0;
    for(; i < HEIGHT; i++){
        int j = 0;
        for(; j < WIDTH; j++){
            printf("%i\n", rand());
            if(rand()%2){
                holder[j][i] = '@';
                //printf("%i ", i);
                //fflush(stdout);
            }
            else{
                holder[j][i] = ' ';
            }
        }
    }
}


void printArray(char ** holder){
    int i = 0;
    for(; i < HEIGHT; i++){
        int j = 0;
        for(; j < WIDTH; j++){
            printf("%c", holder[j][i]);
        }
        printf("\n");
    }
}


void copyConstructor(char ** holder, char ** tempArray){
    int i, j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            holder[j][i] = tempArray[j][i];
        }
    }
}
void handleLife(char ** holder, char ** tempArray){
    while(1){
        int j, k;
        getchar();
        for(j = 0; j < HEIGHT; j++){
            for(k = 0; k < WIDTH; k++){
                int temp = numberOfNeighbors(holder, k, j);
                if(holder[k][j] == '@'){
                    if(temp < 2 || temp > 3 ){
                        tempArray[k][j] = ' ';
                    }
                    else{
                        tempArray[k][j] = '@';
                    } 
                }
                else{
                    if(temp == 3){
                        tempArray[k][j] = '@';
                    }
                    else{
                        tempArray[k][j] = ' ';
                    }
                }
            }
        }
        copyConstructor(holder, tempArray);
        printf("\n\n------------------------------------------------\n\n");
        printArray(holder);

    }


}
int main(){
    char * holder[WIDTH];
    char * tempArray[WIDTH];
    int i = 0;
    for(; i < WIDTH; i++){
        holder[i] = malloc(HEIGHT);
        tempArray[i] = malloc(HEIGHT);  
    }
    
    fillArray(holder);
    printArray(holder);
    handleLife(holder, tempArray);
    //printf("\n\n%i\n\n", numberOfNeighbors(holder, 1, 1));
}


