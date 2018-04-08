#include <iostream>

using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
bool isEven(int n) {
	return (n&1)==0;
}
void transfer(int a[], int len, bool (*fun)(int)) {
	int left = 0;
	int right = len-1;
	while(left < right) {
		while(left < right && !fun(a[left]))
			left++;

		while(left < right && fun(a[right]))
			right--;
		if(left < right)
			swap(a[left], a[right]);
	}
}

void print(int a[], int length) {
	for(int i = 0; i< length; i++)
		cout << a[i] << " ";
	cout << endl;
}
void reorder(int a[], int length) {
	transfer(a,length,isEven);
	print(a,length);
}
int main() {
	int numbers1[] = {1, 2, 3, 4, 5, 6, 7};
	print(numbers1,7);
	reorder(numbers1,7);

	int numbers2[] = {2, 4, 6, 1, 3, 5, 7};
	print(numbers2,7);
	reorder(numbers2,7);

	int numbers3[] = {1, 3, 5, 7, 2, 4, 6};
	print(numbers3,7);
	reorder(numbers3,7);

	int numbers4[] = {1};
	print(numbers4,1);
	reorder(numbers4,1);


	return 0;
}
