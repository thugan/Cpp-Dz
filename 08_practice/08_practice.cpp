#include <iostream>
using namespace std;
void sqere(int arr[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int factorial(int fact) 
{
    int sum = 1;
    for (int i = 1; i <= fact; i++)
    {
        sum *= i;
    }
    return sum;
}
void simple(int num)
{
    int cicle = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            cicle +=1;
            break;
        }
    }
    if (cicle == 1) {
        cout << "SIMPLE" << endl;
    }
    else {
        cout << "NO SIMPLE" << endl;
    }
}
int max1, index,min;
void maxNum(int arr[],int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > ::max1)
        {
            ::max1 = arr[i];
            index = i;
        }
    }
    cout << "MAx element in the array " << ::max1 <<" on "<<::index<<" index!"<< endl;
}
void minNum(int arr[],int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < ::min)
        {
            ::min = arr[i];
            index = i;
        }
    }
    cout << "Min element in the array " << ::min <<" on "<<::index<<" index!"<< endl;
}
int cube(int num)
{
    int sum = num;
    for (int i = 1; i < 3; i++)
    {
        sum *= num;
    }
    return sum;
}
int isPlOrMn(int num) 
{
    if (num < 0) {
        return false;
    }
    else {
        return true;
    }
}
int main()
{
    const int column = 10;
    const int row = 10;
    int arr[row][column] = {};
    sqere(arr, row, column);

    int fact = 5;
    cout << "Factorial : " << factorial(fact)<<endl;

    int smpl = 5;
    simple(smpl);

    const int len1 = 6;
    int arr1[len1] = {1,7,3,4,-8,6};
    maxNum(arr1,len1);
    minNum(arr1,len1);

    int num1 = 5;
    cout << cube(num1) << endl;

    int num2 = 1;
    int num3 = -1;
    cout << isPlOrMn(num2) <<" "<<isPlOrMn(num3) << endl;
}