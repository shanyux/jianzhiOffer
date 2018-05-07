//递归
void printProbability(int number) {
	if(number < 1)
		return;
	int g_value = 6;
	int maxnum = number *6;
	int *arr = new int[maxnum-number+1]();
	Probability(number, number,0,arr);
	int total = pow((double)g_value,number);
	for(int i = 0; i < maxnum-number+1; i++)
		cout << double(arr[i] / total) << endl;
	delete []arr;

}
void Probability(int original, int current, int sum, int *arr) {
	if(current == 0)
		arr[sum-number]++;
	else {
		for(int i = 0; i< 6; i++) {
			Probability(original, current-1, i+sum, arr)
		}
	}
}
//动态规划
void printProbability(int number) {
	if(number < 1)
		return;
	int g_value = 6;
	int maxnum = number *g_value;
	int *arr[2];
	for(int i = 0; i <= maxnum; i++){
		arr[0][i] = 0;
		arr[1][i] = 1;
	}
	int flag = 0;
	for(int i = 1; i <= g_value; i++)
		arr[flag][i] = 1;
	for(int k = 2; k <= number; k++){
		for(int i = 0; i < k; i++)
			arr[1-flag][i] = 0;
		for(int i =k; i <= k*g_value; i++)
			for(int j =1; j <= g_value; j++)
				arr[1-flag][i] += arr[flag][i-j]
		flag = 1 -flag;
	}
	int total = pow((double)g_value,number);
	for(int i = 0; i < maxnum-number+1; i++)
		cout << double(arr[i] / total) << endl;
	delete []arr;
	
	
}	


