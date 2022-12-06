#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// struct for creating blocks given the dimensions
struct block{
	int x, y, z;
	block(int x, int y, int z);
};

// block minecraft(int x, int y, int z){
// 	int _x = x;
// 	int _y = y;
// 	int _z = z;

// 	return block(_x,_y,_z);
// }
// compare the bases of the blocks because we 
// cannot stack blocks that have >= base dimensions
bool comp(const block& a , const block& b){
	return a.x * a.z > b.x * b.z;
}

int main() {
	// the number of different sized blocks available 
	int cases;
	int caseCount = 1;
	// dimensions possible for the n block
	int x, y, z;
	// to store all 6 possible blocks for each type
	vector<block> chest;
	// vector for all blocks in case
	vector<int> L;
	

	cin >> cases;
	
	while (cases !=0 ){
		for (int i = 0; i < cases; i++){
			cin >> x >> y >> z;
			// store all possible block combos in chest
			chest.push_back(block(x,y,z));
			chest.push_back(block(x,z,y));
			chest.push_back(block(y,z,x));
			chest.push_back(block(y,x,z));
			chest.push_back(block(z,y,x));
			chest.push_back(block(z,x,y));
			
			
		}
		// order the chest vector 
		sort(chest.begin(), chest.end(), comp);
		// store the height of each block in L vector
		for (int i = 0; i < cases; i++) L[i] = chest[i].y;

		for (int i = 1; i < cases; i++){
			for(int j = 0; j < i; j++){
				// compare base dimensions of the blocks stored in chest
				if(chest[j].z > chest[i].z && chest[j].x > chest[i].x){
					L[i] = max(L[i], L[j] + chest[i].y);
				}
			}
		}
		int pos = 0;
		for(int i = 1; i < cases; i++){
			if(L[pos] < L[i]){
				pos = i;
			}
		}
		printf("Case %d: maximum height = %d\n", caseCount++, L[pos]);
		chest.clear();
		cin >> cases;
		}
	return 0;
}
