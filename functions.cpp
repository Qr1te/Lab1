#include "functions.h"

void setNumber(int* number){
    int isInvalid = 0;
    do {
        isInvalid = 0;
        int i = 0;
        *number = 0;
        char digits[10];
        cin>>digits;
        int negative = 1;
        if(digits[0] == '-'){negative = -1;i++;}
        do {
            if (digits[i] < '0' || digits[i] > '9') {
                cout<<"Enter a valid number\n";
                isInvalid = 1;
                while(getchar()!='\n');
                break;
            }
            else {*number = *number * 10 + digits[i] - '0'; }
        } while(digits[++i] != 0);
        *number *= negative;
    }while(isInvalid == 1);
    rewind(stdin);
}

void menu(){

    char reset = 'y';
    do {
        int row1, col1, row2, col2; 
        int choice;
        cout<<"Enter size of the first matrix"<<endl;
        setNumber(&row1);
        setNumber(&col1);
        cout<<"Enter size of the second matrix"<<endl;
        setNumber(&row2);
        setNumber(&col2);
        Matrix matrix1(row1,col1); 
        Matrix matrix2(row2,col2);
        matrix1.fill();
        matrix2.fill();

        cout<<"What u want to do with your matrices: 1.add 2.multiply "<<endl;
        setNumber(&choice);
        while(choice!=1 && choice !=2 && choice!=3){
            cout<<"Incorrect input";
            setNumber(&choice);
        }
        if(choice == 1){
            Matrix result = matrix1.add(matrix2);
            result.print();
            cout<<"Want to try again?(y/n)"<<endl;
            cin>>reset;
            system("cls");
        }
        else if(choice == 2){
            Matrix result = matrix1.multiply(matrix2);
            result.print();
            cout<<"Want to try again?(y/n)"<<endl;
            cin>>reset;
            system("cls");
        }

    }while(reset!='n');
}
