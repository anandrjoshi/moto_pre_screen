#include <iostream>
#include <string>

using namespace std;

void initialize(int* charPresent, int length)
{
	for(int i = 0; i < length; i++)
		*(charPresent+i) = 0;
}

void parse_string_into_unique_char(int * charPresent, string str)
{
	char * strTochar = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), strTochar);
	strTochar[str.size()] = '\0'; 
	
	char * temp = strTochar;

	while(*temp != '\0')
	{
		*(charPresent+((int)*temp)) = 1;
		*temp++;
	}

	delete[] strTochar;
}

bool check_if_characters_same(int * charPresent, string str)
{
	char * strTochar = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), strTochar);
	strTochar[str.size()] = '\0'; 
	
	char * temp = strTochar;

	while(*temp != '\0')
	{
		if(*(charPresent+((int)*temp)) != 1)
			return false;
		*temp++;
	}

	delete[] strTochar;
	return true;
}

bool using_array(string string1, string string2)
{
	int charPresent[256];
	int length  = sizeof(charPresent)/sizeof(int);

	initialize(charPresent, length);

	parse_string_into_unique_char(charPresent, string1);

	return check_if_characters_same(charPresent, string2);
}

int get_sum_of_chars(string str)
{
	int sum = 0;
	char * strTochar = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), strTochar);
	strTochar[str.size()] = '\0'; 
	
	char * temp = strTochar;

	while(*temp != '\0')
	{
		sum+=(int)*temp;
		*temp++;
	}

	delete[] strTochar;
	return sum;
}

bool using_ascii_sum(string string1, string string2)
{
	int ascii_sum_of_string1 = get_sum_of_chars(string1);
	int ascii_sum_of_string2 = get_sum_of_chars(string2);

	if(ascii_sum_of_string1 == ascii_sum_of_string2)
		return true;
	else
		return false;
}

int main()
{
	cout << "Enter first string " << endl;
	string string1;
	getline(cin, string1);

	cout << "Enter second string " << endl;
	string string2;
	getline(cin, string2);

	bool isSameUsingArray = using_array(string1, string2);
	bool isSameUsingAsciiSum = using_ascii_sum(string1, string2);

	if (isSameUsingArray)
		cout << string1 << " and " << string2 << " have exactly same character set!!!" << endl;
	else
		cout << string1 << " and " << string2 << " do NOT have exactly same character set!!!" << endl;

	if (isSameUsingAsciiSum)
		cout << string1 << " and " << string2 << 
		" have exactly same character set and each character is repeated exactly same number of times!!!" << endl;
	else
		cout << string1 << " and " << string2 <<
		" do NOT have exactly same character set or each character is NOT repeated exactly same number of times!!!" << endl;

	system("pause");
	return 0;
}