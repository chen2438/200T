```cpp
string int2str1(int num){
	stringstream str1;
	str1<<num;
	string str2;
	str2=str1.str();
	return str2;
} 

string int2str2(int num){
	string str2;
	str2=to_string(num);
	return str2;
}

int str2int1(string str1){
	istringstream str2(str1);
	int num;
	str2>>num;
	return num;
}

int str2int2(string str){
	int num;
	num=atoi(str.c_str());
	return num;
}
```