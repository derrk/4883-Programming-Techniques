#include <iostream>
#include <vector>

using namespace std;

int main() {
  int caseCount;
  int maxx;
  int min;
  int sum = 0;
  vector<int> range;

  cin >> caseCount;


  for (int i = 1; i <= caseCount; i++) {
    cin >> min;
    
    cin >> maxx;
   
    for (int j = min; j <= maxx; ++j) {
      range.push_back(j);
    }
    for (int k = 0; k <= range.size(); k += 2) {

      if (range[k] % 2 == 1) {
        sum += range[k];
      }
    }
    printf("Case %d: %d\n", i, sum);
    range.clear();
    sum = 0;
    min = 0;
    maxx = 0;
  }

  return 0;
}