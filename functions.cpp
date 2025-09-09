#include "functions.h"

void setNumber(int* number) {
    bool isInvalid = false;

    do {
        isInvalid = false;
        *number = 0;
        std::string digits;
        std::getline(std::cin, digits);
        int negative = 1;
        int i = 0;
        if (!digits.empty() && digits[0] == '-') {
            negative = -1;
            i++;
        }

        int j = i;
        while (j < digits.size() && std::isdigit(digits[j])) {
            j++;
        }

        if (j != digits.size() || i == digits.size()) {
            std::cout << "Enter a valid number" << std::endl;
            isInvalid = true;
            continue;
        }

        while (i < digits.size()) {
            *number = *number * 10 + (digits[i] - '0');
            i++;
        }

        *number *= negative;

    } while (isInvalid);

    std::cin.clear();
}

void menu(){

    char reset = 'y';
    do {
        int row1, col1, row2, col2;
        int choice;
        std::cout<<"Enter size of the first matrix"<<std::endl;
        setNumber(&row1);
        setNumber(&col1);
        std::cout<<"Enter size of the second matrix"<<std::endl;
        setNumber(&row2);
        setNumber(&col2);
        Matrix matrix1(row1,col1);
        Matrix matrix2(row2,col2);
        matrix1.fill();
        matrix2.fill();

        std::cout<<"What u want to do with your matrices: 1.add 2.multiply "<<std::endl;
        setNumber(&choice);
        while(choice!=1 && choice !=2 && choice!=3){
            std::cout<<"Incorrect input";
            setNumber(&choice);
        }
        if(choice == 1){
            Matrix result = matrix1.add(matrix2);
            result.print();
            std::cout<<"Want to try again?(y/n)"<<std::endl;
            std::cin>>reset;
            system("cls");
        }
        else if(choice == 2){
            Matrix result = matrix1.multiply(matrix2);
            result.print();
            std::cout<<"Want to try again?(y/n)"<<std::endl;
            std::cin>>reset;
            system("cls");
        }
        else{
            std::cout<<"Incorrect choice"<<std::endl;
        }

    }while(reset!='n');
}