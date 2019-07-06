/*
Input: 
	n = number of question
	t = time limit
	marks[n] = marks for nth question
	time[n] = time for nth question
Output:
	Display the maximum marks with total time within the time limit t
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	vector<int> marks, time;
	vector<float> ratio;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		marks.push_back(temp);
	}
	for(int i = 0; i < n; i++)
        {
                int temp;
		float r;
                cin >> temp;
                time.push_back(temp);
		r = float(marks[i])/float(time[i]);
		ratio.push_back(r);
	}
	
	int sum = 0, summ = 0;
	// Eliminating questions having time > t and finding total time
	for(int i = 0; i < n; i++)
	{
		if(time[i] > t)
		{
			marks.erase(marks.begin() + i);
			time.erase(time.begin() + i);
			ratio.erase(ratio.begin() + i);
		}
		else
		{
			sum+= time[i];
			summ += marks[i];
		}
	}
	if(sum <= t)
	{
		cout << summ << endl;
		return 0;
	}
	sum = 0;
	int min_mark = 9999;
	
	while(t > 0)
	{
		int max_i = 0;
		max_i = max_element(ratio.begin(), ratio.end()) - ratio.begin();
		sum += marks[max_i];
		t -= time[max_i];
		cout << marks[max_i] << ":" << max_i << endl;
		if(min_mark > marks[max_i])
			min_mark = marks[max_i];
		/*
		remove(marks.begin(), marks.end(), marks[max_i]);
		remove(time.begin(), time.end(), time[max_i]);
		remove(ratio.begin(), ratio.end(), ratio[max_i]);
		*/
		marks.erase(marks.begin() + max_i);
		time.erase(time.begin() + max_i);
		ratio.erase(ratio.begin() + max_i);
	}
	sum -= min_mark;
	cout << sum << endl;

	return 0;
}
