#include<iostream>
#include<string>
#include<cstring> 
#include<algorithm>
using namespace std;

int main()
{
	string s;
	string str;
	cout << "Enter first string:" << endl;
	getline(cin, s);
	cout << "Enter second string:" << endl;
	getline(cin, str);
	cout << s << endl;
	cout << str << endl;

	//append character
	s += '!';
	cout << "after append the character s: ";
	cout << s << endl;
	//reverse a string
	s.push_back('a');
	cout << "after push operation:" << s << endl;
	s.pop_back();
	cout << "after pop operation: " << s << endl;
	reverse(s.begin(), s.end());
	cout << "reverse of s : " << s << endl;
	//Empty check
	if (s.empty())
		cout << "s is empty" << endl;
	else
		cout << "s is not empty" << endl;
	//substring 
	string sub = str.substr(0, 3);
	cout << "substring of str: " << sub << endl;
	//compare
	int k = s.compare(str);

	if (k > 0)
		cout << "s has greater length as compare to str1" << endl;
	else if (k < 0)
		cout << "s has small length as compare to str1" << endl;
	else
		cout << "both s and str1 are equal" << endl;


	//concat the string
	string str1 = s + str;
	cout << str1 << endl;
	// Copy the content of s to str3
	// Direct assignment
	string str3 = s;
	cout << "str3=" << str3 << endl;
	// C-style array for strcpy_s
	char str2[100];  // Make sure this is large enough for the string size
	strcpy_s(str2, s.size() + 1, s.c_str()); // Using c_str() to get a C-style string
	cout << str2 << endl;

	char ch[] = { 'C','p','p','\0' };
	string str4 = string(ch);
	cout << "str4=" << str4 << endl;

	// character array
	char key[25], buffer[25];
	cout << "Enter the key string: ";
	cin.getline(key, 25);
	cout << "Enter the buffer string: ";
	cin.getline(buffer, 25);
	strcat_s(key, buffer);
	cout << "Key = " << key << endl;
	cout << "Buffer = " << buffer << endl;



	return 0;
}

