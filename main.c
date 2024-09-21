//Totalistic Cellular Automaton
//Jai Batra


#include <stdio.h>
#include <stdbool.h>

const int WORLD_SIZE = 65;

typedef struct cell_struct{
    int localSum; // total sum of local cells, [left] + [me] + [right]: possible values are 0-6
    int status;   // this cell's current status: 0, 1, or 2
    int count;    // running accumulated count of this cell's active status for all generations
} cell;

// convert an integer rule (0-2186) to its base-3 representation, 
// stored in reverse order, as an array of 7 status values, i.e. valArray[7] 
//   ex: rule = 777  -> [0121001], since 777  = 1*3^1 + 2*3^2 + 1*3^3 + 1*3^6   
//   ex: rule = 177  -> [0210200], since 177  = 2*3^1 + 1*3^2 + 2*3^4
//   ex: rule = 2040 -> [0210122], since 2040 = 2*3^1 + 1*3^2 + 1*3^4 + 2*3^5 + 2*3^6
//return true if input rule is valid (0-2186)
//return false if input rule is invalid
bool setValArray(int valArray[7], int rule) {

        //TODO: Task 1 - write the setValArray() function
        //validates the rule
        if(rule < 0 || rule > 2186){ 
            return false;
        }
        //base 3 
        for(int i = 0; i < 7; i++){
            valArray[i] = rule % 3;
            rule /= 3;
        }

        return true;
}

// update the localSum subitem for each cell in the world array based on the
// current statuses for the nearby [left, me, right] cells
// note: world is periodic/cyclic, with front-to-back and back-to-front wrapping 
//calculates the localSum for each cell based on right left or me
void setSums(cell world[WORLD_SIZE]) {

    //TODO: Task 4 - write the setSums() function
    for(int i = 0; i < WORLD_SIZE; i++){
        int left = world[(i-1 + WORLD_SIZE) % WORLD_SIZE].status;
        int me = world[i].status;
        int right = world[(i+1) % WORLD_SIZE].status;
        world[i].localSum = left + me + right;  //updates the localSum
    }
}

// Evolve the world to the next generation by updating each cell's status value 
// using its localSum subitem (assumed to be updated outside of this function), where
// ruleValArray[7] stores the status values for the 7 possible local sums, in reverse order, 
// e.g. if local sum = 4, the new status value can be found at index 4 of the ruleValArray[].
// This function must also update the count subitems for all cells in world[] 
// with the new generation status values.
// This function returns the total sum of all status values in world[] after the evolution step.
int evolveWorld(cell world[WORLD_SIZE], int ruleValArray[7]) {

    //TODO: Task 6 - write the evolveWorld() function
    int totalSum = 0;

    for(int i = 0;  i < WORLD_SIZE; i++){
        int newStatus = ruleValArray[world[i].localSum];
        world[i].count += newStatus;      //updates count for the cell
        world[i].status = newStatus;       // new status
        totalSum += newStatus;
    }
    //returns totalSum after evolution
    return totalSum;        
}


//task 3
//prints the evolution states then is called in main.
void printEvolutionStates(){
   printf("Local Sum:   6       5       4       3       2       1       0      \n");
   printf("States:    |+++|   |++-|   |++ |   |+- |   |-- |   |-  |   |   |    \n"); 
   printf("                   |+-+|   |+ +|   |+ -|   |- -|   | - |            \n");
   printf("                   |-++|   | ++|   |-+ |   | --|   |  -|            \n");
   printf("                           |+--|   | +-|   |+  |                    \n");
   printf("                           |-+-|   |- +|   | + |                    \n");
   printf("                           |--+|   | -+|   |  +|                    \n");
   printf("                                   |---|                            \n");
}
//prints user specified state
void printNewStatus(int valArray[7]){
    printf("New Status: ");
    for(int i = 6; i >= 0; i--){
        char state;
        if(valArray[i] == 0){
            state = ' ';
        } else if(valArray[i] == 1){
            state = '-';
        } else if(valArray[i] == 2){
            state = '+';
        }
        printf("|%c|     ", state);
    }
    printf("\n");
}
//Initializes the world with all cells being set to 0 except middle cell.
void initializeWorld(cell world[WORLD_SIZE], int initialStatus){
    for (int i = 0; i < WORLD_SIZE; i++){
        world[i].status = 0;
        world[i].count = 0;
    }

    world[WORLD_SIZE / 2].status = initialStatus; //set middle cell to initialStatus

    setSums(world);
}


int main() {
    cell world[WORLD_SIZE];
    int rule;
    int generations;
    int initialStatus;
    int valArray[7];

    printf("Welcome to the Totalistic Cellular Automaton!\n");

    //TODO: Task 2 - read in a valid rule#, allowing repeated attempts if necessary,
    //      generate the rule's 7-trit (i.e. 7 base-3 digits) status value array,  
    //      print the status value array in correct ternary (i.e. base-3) number order
    //makes sure the rule is valid
    while(true){
    printf("Enter the rule # (0-2186): \n");
    scanf("%d", &rule);
    
    if(setValArray(valArray, rule)){
       printf("\nThe value array for rule #%d is ", rule);
    for(int i = 6; i >= 0; i--){
        printf("%d", valArray[i]);
       }
        break; //breaks so that the loop doesnt continue
    }
}
    printf("\n");
    printf("\nThe evolution of all possible states are as follows:\n");
    printEvolutionStates(); //calls the evolution states
    printNewStatus(valArray); //calls the new status

    //TODO: Task 3 - use the rule status value array to report the evolution 
    //      step for all possible cell neighbor states [left, me, right].
    //      Follow the format, including whitespaces, of the sample output EXACTLY. 
    
    while(true){
    printf("\nEnter the number of generations (1-49): ");
    scanf("%d", &generations);     
    //TODO: Task 5a - read in the total number of generation evolution steps
    //      from the user, allowing repeated attempts for invalid values.
    //      Follow the format, including whitespaces, of the sample output EXACTLY.
    if(generations >= 1 && generations <= 49){
        break;
    }
}

    printf("\nEnter the value (1 or 2) for the initial active cell: ");
    //TODO: Task 5b - read in the initial status value for the middle cell, 
    //      allowing repeated attempts for invalid values. 
    //      Follow the format, including whitespaces, of the sample output EXACTLY.
    initialStatus = -1;
    while(!(initialStatus == 1 || initialStatus == 2)){ //sets the bounds
        printf("\n");
        scanf("%d", &initialStatus); 
        if(initialStatus != 1 && initialStatus != 2){ //this makes it so that if the user has entered a out of range cell, it can ask again without taking up a newline.
            printf("Enter the value (1 or 2) for the initial active cell: "); 
        }
    }

    printf("\nInitializing world & evolving...\n");
    initializeWorld(world, initialStatus);
    //TODO: Task 5c - initialize the world with the ONLY non-zero cell in the 
    //      exact middle of the world, whose status value is set using the 
    //      scanned-in value from the user above. Make sure to also set the 
    //      localSum subitem for each cell of the initial world.
    //      Follow the format, including whitespaces, of the sample output EXACTLY.
    int totalSum = 0;
    for(int i = 0; i < WORLD_SIZE; i++){
        if(world[i].status == 2){
            printf("+");
        } else if(world[i].status == 1){
            printf("-");
        } else {
            printf(" ");
        }
        totalSum += world[i].status; //total sum of status
    }
    printf(" %d \n", totalSum);


    //TODO: Task 7 - evolve the world the user-specified number of generations,
    //      printing the world after each evolution step, where each cell prints as
    //      '+', '-', or ' ' (whitespace) for status value of 2, 1, or 0, respectively.
    //      After the world display, also print out the total sum of all status values.
    //      Follow the format, including whitespaces, of the sample output EXACTLY.
    //
    //      Ex: world = [00000000000000000020101212111001210011121210102000000000000000000]
    //          display->                  + - -+-+---  -+-  ---+-+- - +                   28 <-display
    //
    //      At the end of ALL evolution steps, print a line under the last generation. 
    //      Ex: world = [02211210000121122111001121121001210012112110011122112100001211220]
    //          display-> ++--+-    -+--++---  --+--+-  -+-  -+--+--  ---++--+-    -+--++  64 <-display
    //          display->_________________________________________________________________<-display
    for (int j = 0; j < generations - 1; j++){
        totalSum = evolveWorld(world, valArray);

        //print the world after each step
        for(int i = 0; i < WORLD_SIZE; i++){
            int status = world[i].status;
            
            if(status == 0){
                printf(" ");
            } else if (status == 1){
                printf("-");
            } else if(status == 2) {
                printf("+");
            }
        }

        printf(" %d \n", totalSum);
        setSums(world); //updates the sum
    }
    
    printf("_________________________________________________________________\n");

    //TODO: Task 8 - after the line under the last generation, 
    //      print the total sum for each cell throughout all evolution steps vertically.
    //      The cell total sums should be printed as two digit numbers across two lines.
    //      Single-digit total sums should be represented as a whitespace on the top line, 
    //      and the single-digit on the lower line. 
    //      For total sums of zero, print both digits as whitespaces.
    //      Follow the format, including whitespaces, of the sample output EXACTLY.
    //
    //      Ex: consider a world after many evolution steps with the following final generation:
    //          display-> ++--+-    -+--++---  --+--+-  -+-  -+--+--  ---++--+-    -+--++  64 <-display
    //          display->_________________________________________________________________<-display   
    //          display->            11111111122121222233233222212122111111111            <-display 
    //          display-> 243666698963456647182091851471191174158190281746654369896666342 <-display 
    //                   ^ ^                             ^
    //      note: the first cell was ALWAYS 0, so its total sum is zero, and prints as two whitespaces
    //            the third cell has a total sum of 4, so it prints as a whitespace above the digit 4
    //            the middle cell has a total sum of 29, so it prints the digit 2 above the digit 9

    for(int i = 0; i < WORLD_SIZE; i++){ //prints first line 10 digits
        if(world[i].count > 9){
            printf("%d", (world[i].count / 10));
        } else {
            printf(" ");
        }
    }
    printf("\n");

    world[WORLD_SIZE / 2].count += initialStatus;
    for(int i = 0; i < WORLD_SIZE; i++){ //prints the second line ones digits
        if(world[i].count == 0){
            printf(" ");
        } else {
            printf("%d", (world[i].count % 10));
        }
    }
    printf("\n"); // make sure to end your program with a newline
    return 0;
}
