#include"generators.h"

QCG::QCG(int a, int c, int d) : lgenerator(),a(a),c(c),d(d){
}

void QCG::generate() {
	this->x = (d * x * x + a * x + c) % m;
}

LCG::LCG(int a, int c) : QCG(a, c, 0) {
}

FG::FG(int f1, int f2, int n) : lgenerator(),f1(f1),f2(f2),n(n){
}

void FG::generate() {
	for (int i = 0; i < n; i++) {
		f2 += f1;
		f1 = f2 - f1;
		f2 %= m;
	}
	this->x = f2;
}

ICG::ICG(int a, int c) : lgenerator(), a(a), c(c){
}

int ICG::phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}
	if (n > 1)
		res -= res / n;
	return res;
}

int ICG::modPow(int a, int pow, int m) {
	int res = 1;
	while (pow) {
		if (pow & 1)res = res * 1ll * a % m;
		a = a * 1ll * a % m;
		pow /= 2;
	}
	return res;
}


void ICG::generate(){
	int pow = phi(m) - 1;
	this->x = (modPow(x, pow, m) * 1ll * a + c) % m;
}

UnionGen::~UnionGen(){
	delete g1;
	delete g2;
}

UnionGen::UnionGen() : lgenerator(){
	g1 = new ICG(a, c);
	g2 = new LCG(a - 7, b);
}

void UnionGen::generate(){
	g1->generate();
	g2->generate();
	int z = g1->x;
	int y = g2->x;

	this->x = (z - y) % m;
}

void SumGen::generate() {
	ans = 0;
	for (int i = 0; i < 12; i++){
		g->generate();
		ans += g->getAns();
	}

	ans -= 6;
}

double dUnion::getAns(){
	return ans;
}

void PolarGen::sum() {
	g1->generate();
	g2->generate();
	v1 = 2 * g1->getAns() - 1;
	v2 = 2 * g2->getAns() - 1;
	s = v1 * v1 + v2 * v2;
}

void PolarGen::generate(){
	do
		sum();
	while (s >= 1);
	double x1 = v1 * sqrt(-2 * log(s) / s);
	double x2 = v2 * sqrt(-2 * log(s) / s);
	ans = (v1 >= 0.5) ? x2 : x1;
}

CorrGen::CorrGen() {
	g1 = new ICG(a, b);
	g2 = new FG(1, 1, 1);
}

double CorrGen::findX(){
	do {
		g2->generate();
		u = g2->getAns();
	} while (u == 0);
	g1->generate();
	v = g1->getAns();
	ans = sqrt(8 / e) * (v - 0.5) / u;
	return ans;
}

void CorrGen::generate(){
	double x = findX();
	if (x * x <= pow(5 - 4 * e, 0.25) * u)
		ans = x;
	else
	{
		while (x * x >= (pow(4 * e, -1.35) / u + 1.4))
			x = findX();
		while (x * x > -4 * log(u))
			x = findX();
		ans = x;
	}
}	

void LogGen::generate(){
	g->generate();
	ans = -log(g->getAns());
}

void ArensGen::FindXnY()
{
	g->generate();
	u = g->getAns();
	g->generate();
	v = g->getAns();
	y = tan(pi * u);
	x = sqrt(2 * a - 1) * y + a - 1;
}

void ArensGen::generate(){
	bool a = 0;
	bool b = 0;
	do {
		FindXnY();
		a = (x <= 0);
		b = (v > (1 + y * y) * exp((a - 1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y));
	} while (a && b);
		ans = fabs(x);
}
