/*----------------------------------------------------------------------------------------------
Project: CSC1007 - Operating Systems Assignment
Program name: OS File System
Authors: Xie Yuan Shan, Kwang Qi Rong, Hui Jie, Sharon, June, Hui Ting
Group: ???
Date Created: 16 January 2020
Description: 
-----------------------------------------------------------------------------------------------*/

#include "main.h"
#include "contiguous.c"

int main(void)
{
    register int i = 0;
    register int j = 0;
    unsigned char input[20];
    unsigned int choice = 0;
    unsigned int format = 0;
    int counter = 0, blockIndex = 0;

    do
    {
        printf("Type Y to format File System or N to exit\n");
        scanf("%s", &input);
        if (strlen(input) == 1)
        {
            if (input[0] == 89 || input[0] == 121) //If user key in Y(89) / y(121)
            {
                //space for format
                format = 1;
            }
            else if (input[0] == 78 || input[0] == 110) ////If user key in N(78) / n(110)
            {
                exit(0);
            }
            else
            {
                printf("Invalid input, please enter between Y or N\n");
            }
        }
        else
        {
            printf("Invalid input, please enter between Y or N\n");
        }

    } while (format != 1);

    do
    {
        printf("\nEnter required block size: ");
        scanf("%s", &input);
        //Convert the input to become a int
        blockSize = atoi(input);
    } while (blockSize < 0 || blockSize > 130);

    noOfBlocks = MAX_BLOCK / blockSize;
    //If the max block is not divisible by the blocksize, the no of block will be -1
    noOfBlocks = (MAX_BLOCK % blockSize) ? noOfBlocks - 1 : noOfBlocks;

    initialize(noOfBlocks, blockSize);
    extraSpace = MAX_BLOCK % blockSize;


    
    //printf("%i", blocks[10][9].blockNo);
    //printf("%i", blocks[12][15].blockNo);
    //blocks[9] = realloc(blocks[9],(blockSize + 10 * sizeof(struct node)));
    //printf("%i", blocks[10][10].blockNo);
    //printf("Block\t\tIndex\tFile Data\n");
    //while (counter < MAX_BLOCK)
    //{
    //    for (j = 0; j < blockSize; j++)
    //    {
            //If the no of block size is more than the block index
            //Block index will become -1, else it will be the current counter value
            //node[counter].blockNo = (noOfBlocks < blockIndex) ? -1 : blockIndex;
            //node[counter].index = counter;
            //node[counter].filename = 0;

            //(counter == MAX_BLOCK)
            //If the condition is true, j = block size
            //Else noOfB locks < blockIndex
    //        (counter == MAX_BLOCK) ? j = blockSize : printf("%d\t\t%d\t%s\n", node[counter].blockNo, node[counter].index, node[counter].data);
    //        counter++;
    //    }
    //    blockIndex++;
    //}

    //File system choice
    do
    {
        printf("\nEnter choice for file system: \n1: Contiguous Allocation\n2: Linked Allocation\n3: Indexed Allocation\n4: Custom Allocation\n");
        scanf("%s", &input);
        choice = atoi(input);
        if (choice == 1)
        {
            //Space for Contiguous
            contiguous();
        }
        else if (choice == 2)
        {

            //Space for Linked
        }
        else if (choice == 3)
        {
            //  indexed();

        }
        else if (choice == 4)
        {
            //Space for custom
        }
        else
            printf("Invalid choice, please enter between 1 - 4");
    } while (choice <= 0 || choice > 4);

    return EXIT_SUCCESS;
}

void initialize(int noBlocks, int size){
    blocks = (struct node**)malloc(noBlocks * sizeof(struct node*));
     for(int i = 0; i<noBlocks ; i++){
        blocks[i] = (struct node*)malloc(size * sizeof(struct node));
    }

}

void assign(int noBlocks, int size){
    for(int i = 0; i < noBlocks ; i ++){
        for(int j = 0; j < size; j ++){
            blocks[i][j].blockNo = i;
        }
    }
}