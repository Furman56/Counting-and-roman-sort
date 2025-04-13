#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void CountingSort(vector<int>&);
void RomanSort(vector<int>&);

int main() {
    vector<int> vec1 = {5, 3, 1, 4, 2};
    CountingSort(vec1);
    assert(is_sorted(vec1.begin(), vec1.end()));

    vector<int> vec2 = {9, 7, 8, 6};
    RomanSort(vec2);
    assert(is_sorted(vec2.begin(), vec2.end()));

    cout << "All tests passed!" << endl;
    return 0;
}
