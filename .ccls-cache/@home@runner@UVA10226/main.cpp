#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {

  map<string, double> treeCount;

  int T;
  int treeTypes = 0;
	int linesRead = 0;
  string tree;

  cin >> T;

  cout << T << endl;

  while (T > 0) {

    getline(cin, tree);
	treeTypes++;

    if (tree.size()) {
      if (treeCount.find(tree) == treeCount.end()) {
        treeCount.insert(pair<string, int>(tree, 0));
      }

      treeCount[tree]++;

    } else {
      for (auto it = treeCount.cbegin(); it != treeCount.cend(); ++it) {
        cout << it->first << " " << it->second << endl;
        // cout << "printing tree and num" << endl;
		 linesRead += it->second;
      }
      cout << treeTypes << endl;
		cout << "num: " << linesRead << endl;
      cout << endl;
      treeCount.clear();
      T--;
		treeTypes = 0;
		linesRead = 0;
    }
  }
}