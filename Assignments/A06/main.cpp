#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {

  map<string, double> treeCount;

  int T;
	int linesRead = 0;
  string tree;

  cin >> T;
	cin.ignore();

  while (T >= 0) {

    getline(cin, tree);

    if (tree.size()) {
      if (treeCount.find(tree) == treeCount.end()) {
        treeCount.insert(pair<string, int>(tree, 0));
      }

      treeCount[tree]++;

    } else {
      for (auto it = treeCount.cbegin(); it != treeCount.cend(); ++it) {
        //cout << it->first << " " << it->second << endl;
        // cout << "printing tree and num" << endl;
		 linesRead += it->second;
      }

		
		// loop to go through trees and list the tree type as well as calculating
		// the percentage of that species of tree
		for (auto it = treeCount.cbegin(); it != treeCount.cend(); ++it) {
			
			cout << fixed << setprecision(4) << it->first << " " <<  (it->second / linesRead) * 100 << endl;
		}
	
      //cout << endl;
      treeCount.clear();
      T--;
		
	linesRead = 0;
    }
  }
}