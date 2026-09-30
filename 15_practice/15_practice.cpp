#include <iostream>
using namespace std;
char AOrO(char arr[],int mxchar){
	int a = 0;
	int o = 0;
	for (int i = 0; i < mxchar; i++)
	{
		if (i == 'a') {
			a += 1;
		}
		else if (i == 'o') {
			o += 1;
		}
	}
	if (o<a){
		return'a';
		}
	else{
		return 'o';
	}
}
int isSomething(char arr[],int choise) {
	int cnt = 0;
	if (choise == 0) {
		for (int i = 0; i < strlen(arr); i++)
		{
			if (isalpha(arr[i])) {
				cnt += 1;
			}
		}
		return cnt;
	}
	else if (choise == 1) {
		
		for (int i = 0; i < strlen(arr); i++)
		{
			if (isdigit(arr[i])) {
				cnt += 1;
			}
		}
		return cnt;
	}
	else if (choise == 2) {
		
		for (int i = 0; i < strlen(arr); i++)
		{
			if (isspace(arr[i])) {
				cnt += 1;
			}
		}
		return cnt;
	}
	
}
void ReCase(char arr[]) {
	for (int i = 0; i < strlen(arr); i++)
	{
		if(isupper(arr[i])){
			arr[i] = (char)tolower(arr[i]);
		}
		else if(islower(arr[i])){
			arr[i] = (char)toupper(arr[i]);
		}
	}
	
}
int LenAnalog(char arr[]) {
	int len = 0;
	for (int i = 0; i < 255; i++)
	{
		if (isspace(arr[i])|| isdigit(arr[i]) || isalpha(arr[i])) {
			len++;
		}
		else {
			break;
		}
	}
	return len;
}
void DelSumblos(char arr[], char sumbol) {
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == sumbol) {
			for (int j = i; j < strlen(arr); j++)
			{
				arr[j] = arr[j + 1];
			}
			i--;
		}
	}
}
int main()
{
	const int mxchar = 255;
    char arr[mxchar];
	
   /* cout << "Enter text : "; cin.getline(arr, mxchar);
	cout << "Line has more " << AOrO(arr, mxchar) << " letters!" << endl;
	*/
	/*cout << "Enter text : "; cin.getline(arr, mxchar);
	cout << isSomething(arr,0) << " --- letters"<<endl;
	cout << isSomething(arr,1) << " --- numbers" << endl;
	cout << isSomething(arr,2) << " --- spaces" << endl;*/
	cout << "Enter text : "; cin.getline(arr, mxchar);
	ReCase(arr);
	cout << arr<<endl;
	cout << LenAnalog(arr)<<endl;
	DelSumblos(arr, 'A');
	cout << arr << endl;
}