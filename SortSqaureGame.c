#include<stdio.h>
char a[3][3] = {{'4','7','3'},{'1','2','6'},{'8','5',' '}};
int blank_i=2, blank_j=2;
int complete = 0;

void printArray();
void move(char key);
int isCompleted();

int main()
{
    char key;
    do
    {
        system("cls");
        printArray();
        printf("\n L:left R:right U:up D:down Q:quit \n Enter a character: ");
        scanf("%c",&key);
        move(key);
        complete = isCompleted();
    }while(key!='Q' && !complete);


    system("cls");
    printArray();
    if(complete)
        printf("\n Square is completed, you have won!");
    else
        printf("\n You quit...");
}

void move(char key)
{
    int i,j;
    switch(key)
    {
        case 'U': i=blank_i-1; j=blank_j; break;
        case 'D': i=blank_i+1; j=blank_j; break;
        case 'L': j=blank_j-1; i=blank_i; break;
        case 'R': j=blank_j+1; i=blank_i;; break;
        default: return;
    }

    if( i<0 || i==3 || j<0 || i==3)
        return;

    char temp = a[blank_i][blank_j];
    a[blank_i][blank_j] = a[i][j];
    a[i][j] = temp;

    blank_i = i;
    blank_j = j;

}

int isCompleted()
{
    int i,j,flag=0;
    char k = '1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j] == k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
    }

    if(k == '9')
        flag = 1;
    return flag;
}


void printArray()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("| %c |",a[i][j]);
        }
        printf("\n");
    }
}
