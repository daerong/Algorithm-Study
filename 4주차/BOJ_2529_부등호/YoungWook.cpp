#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
// �ε�ȣ ���� 
char str[9];
vector<int> v1;
vector<int> v2;

// �ε�ȣ �������� 
bool possible(vector<int> v)
{
	for(int i=0;i<n;i++)
	{
		char temp = str[i];
		if(temp == '<')
		{
			if(v[i] > v[i+1])
				return false;
		}
		else
		{
			if(v[i] < v[i+1])
				return false;
		}
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> str[i];
	
	// �ε�ȣ n���� ���� n+1 �� �ʿ�	
	for(int i=0;i<n+1;i++)
	{
		v1.push_back(i);
		v2.push_back(9-i);
	}
	
	//�ε�ȣ �����ϴ� ���� ū �� 
	do{
		if(possible(v2))
		{
			for(int i=0;i<v2.size();i++)
				cout << v2[i];
			
			
			cout <<"\n";
			break;
		}
			
	}while(prev_permutation(v2.begin(), v2.end()));
	
	// �ε�ȣ �����ϴ� ���� ���� �� 
	do{
		if(possible(v1))
		{
			for(int i=0;i<v1.size();i++)
				cout << v1[i];
			
			break;
		}
		
	}while(next_permutation(v1.begin(), v1.end()));
	
	return 0;
}
