#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

using value_type = long double;

int d = 10000, times = 5, tot;

int main() {
	vector<vector<value_type>> m(d, vector<value_type>(d, 1)); 
	vector<value_type> v(d, 1), res(d, 0);
	vector<int> iteration(times, 0);
#ifdef MP
	cout << "Matrix " << d << "x" << d;
	cout << " * vector of size " << d << " with OpenMP" << endl;
#else
	cout << "Matrix " << d << "x" << d;
	cout << " * vector of size " << d << " w/o OpenMP" << endl;
#endif
	for (int i = 0; i < iteration.size(); ++i) {
		auto start = chrono::high_resolution_clock::now();
#ifdef MP
#pragma omp parallel for
#endif
		for (int r = 0; r < m.size(); ++r)
			for (int c = 0; c < v.size(); ++c)
				res[c] += m[r][c] * v[c];
		auto end = chrono::high_resolution_clock::now();
		iteration[i] = (int) chrono::duration_cast<chrono::milliseconds>(end - start).count();
		tot += iteration[i];
		cout << "Iteration "<< i + 1 << ": " << iteration[i] << " ms" << endl;
	}
	cout << "Average time: " << tot / times << " ms" << endl;
}
