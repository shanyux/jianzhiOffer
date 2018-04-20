void combination(string str) {
	if(str == NULL)
		return;
	size_t len = str.size();
	vector<char> v;
	for(int i = 1; i<= len; i++) {
		combinaton(str,0, i, v);
	}
}
void combination(string str,int index, int k, vector<char> & v) {
	if(k ==0) {
		for (auto i = v.begin(); i!=v.end(); i++)
			cout << v[i];
		cout << endl;

	}
	if(str == NULL)
		return;
	v.push_back(str[index]);
	combination(str,index+1,k-1,v);
	v.pop_back();
	combination(str,index+1,k,v);
}