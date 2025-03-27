#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}

void CountingSort(vector<int>& A) {
	if (A.empty()) return;

	int max = *max_element(A.begin(), A.end());
	int min = *min_element(A.begin(), A.end());
	int range = max - min + 1;

	// Converts the numbers so that there are no negatives
	for (int& num : A) {
		num -= min;
	}

	vector<int> C(range, 0);

	for (int num : A) {
		C[num]++;
	}

	for (int i = 1; i < C.size(); i++) {
		C[i] += C[i - 1];
	}

	vector<int> B(A.size());

	for (int i = A.size() - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}

	// Converts the numbers back to their original form
	for (int i = 0; i < A.size(); i++) {
		A[i] = B[i];
	}

	for (int& num : A) {
		num += min;
	}

	Izpis_Stevil(&A[0], A.size());

	cout << "Counting sort done." << endl;
}

void RomanSort(vector<int>& A) {
	if (A.empty()) return;

	int max = *max_element(A.begin(), A.end());
	int min = *min_element(A.begin(), A.end());
	int range = max - min + 1;

	// Converts the numbers so that there are no negatives
	for (int& num : A) {
		num -= min;
	}

	vector<int> C(range, 0);

	for (int num : A) {
		C[num]++;
	}

	vector<int> B(A.size());
	int index = 0;

	for (int i = 0; i < C.size(); i++) {
		while (C[i] > 0) {
			B[index++] = i;
			C[i]--;
		}
	}

	// Converts the numbers back to their original form
	for (int i = 0; i < A.size(); i++) {
		A[i] = B[i];
	}

	for (int& num : A) {
		num += min;
	}

	Izpis_Stevil(&B[0], B.size());

	cout << "Roman sort done." << endl;
}

int main(int argc, const char* argv[]) {
	vector<int> A;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

	if (argv[1][0] == '0') {
		CountingSort(A);
	}
	else {
		RomanSort(A);
	}
	Izpis_Stevil(&A[0],A.size());

	return 0;
}
