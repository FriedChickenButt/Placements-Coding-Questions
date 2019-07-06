/*
Input:
	n : number of the elements in the list.

Output:
	Yes/No. 
		No - If any element is a prefix of any other element.
		Yes - If no element is a prefix of any other element.
Example:
	Input:
		4
		10 100 20 30
	Output:
		No
	Explanation:
		10 is a prefix for 100
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> list;
	for(int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		list.push_back(temp);
	}
	for(int i = 0; i < list.size(); i++)
	{
		int len = list[i].size();
		for(int j = i + 1; j < list.size(); j++)
		{
			if(list[j].size() < list[i].size())
				continue;
			string temp = list[j].substr(0,len);
			if(temp == list[i])
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
