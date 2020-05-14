#include "bits/stdc++.h"
using namespace std;

struct data
{
  int val;
  data* L;
  data* R;
};
data* newNode(int v)
{
  data* node = (data*) malloc(sizeof(data));
  node->val = v;
  node->L = node->R = NULL;
  return node;
}
data* insert(data* head, int v)
{
  if (head == NULL) head = newNode(v);
  else if (head->val <= v) head->L = insert(head->L, v);
  else head->R = insert(head->R, v);
  return head;
}
void getHashCode(data* head, stringstream& ss)
{
  if (head->L)
  {
	ss << 'L';
	getHashCode(head->L, ss);
  }
  else
  {
	ss << 'T';
  }
  if (head->R)
  {
	ss << 'R';
	getHashCode(head->R, ss);
  }
  else
  {
	ss << 'P';
  }
}
int main()
{
  int n, k, x, cnt;
  while (cin >> n >> k)
  {
	cnt = 0;
	unordered_set<string> hashes;
	for (int i = 0; i < n; i++)
	{
	  data* head = NULL;
	  for (int j = 0; j < k; j++)
	  {
		cin >> x;
		head = insert(head, x);
	  }
	  stringstream ss;
	  getHashCode(head, ss);
	  string str = ss.str();
	  if (hashes.find(str) == hashes.end())
	  {
		cnt++;
		hashes.insert(str);
	  }
	}
	cout << cnt << endl;
  }
}
