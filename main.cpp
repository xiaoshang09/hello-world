#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<string, int> ErrorRecord;

bool descend(ErrorRecord comp1, ErrorRecord comp2)
{
	return comp1.second > comp2.second;
}

int main_1()
{
	unordered_map<int, int> map;

	vector<ErrorRecord> errors;
	string input_line;
	while (getline(cin,input_line))
	{
		if(input_line.empty())
			break;

		int idx = input_line.rfind('\\');
		string suffix = input_line.substr(idx + 1);
		int size = errors.size();
		bool repeat = false;
		for (int i = 0; i < size; i++)
		{
			if (errors[i].first == suffix)
			{
				errors[i].second++;
				repeat = true;
				break;
			}
		}
		if(!repeat)
			errors.push_back(make_pair(suffix, 1));
	}
	stable_sort(errors.begin(), errors.end(), descend);

	int output_num = errors.size() < 8 ? errors.size() : 8;
	for (int i = 0; i < output_num; i++)
	{
		string suffix = errors[i].first;
		int idx = suffix.find(' ');
		if (idx > 16)
			suffix.erase(0, idx - 16);
		cout << suffix << " " << errors[i].second << endl;
	}
    return 0;
}


int _main(int argc,char* argv[])
{
	int* a = (int*)malloc(sizeof(int) * 2);
	a[0] = 8;
	a[1] = 7;
	a[2] = 6;
	a[3] = 5;


	string str = "abc66adefgadhiaj";
	int size = str.size();
	int idx1 = str.find("ad");
	int idx2 = str.find('a', 2);
	int idx3 = str.find('a', 3);
	int idx4 = str.rfind("ad");
	string str1 = str.substr(2, 5);
	string str2 = str.substr(4);
	string str3 = str;
	str3.erase(3);
	string str4 = str;
	str4.erase(2, 5);

	return 0;
}

int main_2() 
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER")!=-1)
			cout << "joker JOKER" << endl;
		else
		{
			int idx = line.find('-');
			string card1 = line.substr(0, idx);
			string card2 = line.substr(idx + 1);
			int cnt1 = count(card1.begin(), card1.end(), ' ') + 1;
			int cnt2 = count(card2.begin(), card2.end(), ' ') + 1;
			if (cnt1 == cnt2)
			{
				string first1 = card1.substr(0, card1.find(' '));
				string first2 = card2.substr(0, card2.find(' '));
				const string str = "345678910JQK12jokerJOKER";
				if (str.find(first1) > str.find(first2))
					cout << card1 << endl;
				else
					cout << card2 << endl;
			}
			else
			{
				if (cnt1 == 4)
					cout << card1 << endl;
				else if (cnt2 == 4)
					cout << card2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}

int main_4()
{
	int input = 0;
	while (cin >> input)
	{
		if (input > 1000)
			input = 1000;

		vector<int> vec;
		for (int i = 0; i < input; i++)
			vec.push_back(i);
		
		int erase_idx = 0;
		while (vec.size() != 1)
		{
			erase_idx = (erase_idx + 2) % (int)vec.size();
			vec.erase(vec.begin() + erase_idx, vec.begin() + erase_idx + 1);
		}
		cout << vec[0] << endl;
	}
	return 0;
}

int main_5()
{
	string str;
	while (cin >> str)
	{
		char c[100];
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			char single = str.at(i);
			bool repeat = false;
			for (int j = 0; j < count; j++)
			{
				if (single == c[j])
				{
					repeat = true;
					break;
				}
			}
			if (!repeat)
			{
				c[count] = single;
				count++;
			}
		}

		for (int i = 0; i < count; i++)
			cout << c[i];
		cout << endl;
	}
	return 0;
}

bool stillSoduku(int* soduku, int row, int col)
{
	int num = soduku[row * 9 + col];
	bool row_echo = false;
	bool col_echo = false;
	bool palace_echo = false;

	for (int i = 0; i < 9; i++)
	{
		if (i != row && num == soduku[row * 9 + i])
		{
			row_echo = true;
			break;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (j != col && num == soduku[j * 9 + col])
		{
			col_echo = true;
			break;
		}
	}

	int row_start = row / 3;
	int col_start = col / 3;
	for (int i = row_start * 3; i < row_start * 3 + 3; i++)
	{
		for (int j = col_start * 3; j < col_start * 3 + 3; j++)
		{
			if ((i != row || j != col) && num != soduku[i * 9 + j])
			{
				palace_echo = true;
				break;
			}
		}
	}

	return !(row_echo || col_echo || palace_echo);
}

bool fillSoduku(int* soduku, int idx, int num)
{
	if (idx < 81)
	{
		if (soduku[idx] == 0)
		{
			soduku[idx] = num;
			bool flag_still = stillSoduku(soduku, idx / 9, idx % 9);
			if (flag_still)
			{
				

			}










			if (flag_still)
			{
				bool flag_fill = fillSoduku(soduku, idx, num);
				if (flag_fill)
				{
					idx++;
					num = 1;
				}
				else
				{
					num++;
					if (num > 9)
						return false;
				}
			}
			else
			{
				num++;
				if (num > 9)
					return false;
			}
		}
		else
		{
			idx++;
			num = 1;
		}
		fillSoduku(soduku, idx, num);
	}
}



int main()
{
	int soduku[81];
	for (int i = 0; i < 81; i++)
		cin >> soduku[i];

	fillSoduku(soduku, 0, 1);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << soduku[i * 9 + j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}