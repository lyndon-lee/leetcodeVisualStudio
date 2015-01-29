#include<iostream>
#include<vector>
using namespace std;
	class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
		int n = numbers.size();
		vector<int> res;
		unordered_multimap<int, int> umap;
			for (int i = 0; i < n; i++)
				umap.insert(make_pair(numbers[i], i));
			for (int i = 0; i < n; i++)
			{
				auto range = umap.equal_range(target - numbers[i]);
				if (range.first != umap.end())//found
				{
					if (numbers[i] != target - numbers[i])
					{
						auto range2 = umap.equal_range(numbers[i]);
						res.push_back(min(range.first->second, range2.first->second) + 1);
						res.push_back(max(range.first->second, range2.first->second) + 1);
					}
					else
					{
						auto ite = ++(range.first);
						if (ite != range.second)
						{
							auto range2 = umap.equal_range(numbers[i]);
							res.push_back(min(ite->second, range2.first->second) + 1);
							res.push_back(max(ite->second, range2.first->second) + 1);
						}
					}
				}
			}
			return res;
		}
	};




