#include <iostream>
#include"generator.h"
#include"generators.h"
#include"histogram.h"
using namespace std;

const int LEN = 1000;
const int A = 293;
const int C = 37436;
const int D = 32882;
const int F1 = 1;
const int F2 = 1;
const int N = 2;

generator* create_generator(int type) {
	switch (type) {
	case 1:
		return new LCG(A, C);
	case 2:
		return new QCG(A, C, D);
	case 3:
		return new FG(F1, F2, N);
	case 4:
		return new ICG(A, C);
	case 5:
		return new UnionGen();
	case 6:
		return new SumGen();
	case 7:
		return new PolarGen();
	case 8:
		return new CorrGen();
	case 9:
		return new LogGen();
	case 10:
		return new ArensGen();
	default:
		return new LCG(A, C);
	}
}

int main()
{
	cout << "Choose your generator..." << endl;
	int type;
	while (cin >> type) {
		if (type <= 0) break;
		generator *gen = create_generator(type);
		double a[LEN+1];
		for (int i = 0; i < LEN; ++i) {
			gen->generate();
			cout << (a[i] = gen->getAns()) << " ";
		}
		cout << buildGistagram(a, LEN, type);

		delete gen;
	}

	return 0;
}