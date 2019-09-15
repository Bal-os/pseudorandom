#pragma once
#include"generator.h"

class QCG : public lgenerator {
private:
	int a;
	int c;
	int d;
public:
	QCG(int a, int c, int d);
	void generate() override;
};

class LCG : public QCG {
public:
	LCG(int a, int c);
};

class FG : public lgenerator {
private:
	int f1 ;
	int f2 ;
	int n;
public:
	FG(int f1, int f2, int n);
	void generate() override;
};

class ICG : public lgenerator {
private:
	int a;
	int c;
	const int p = 1 << 8;
public:
	ICG(int a, int c);
	int phi(int n);
	int modPow(int a, int pow, int m);
	void generate() override;
};

class UnionGen : public lgenerator {
protected:
	lgenerator* g1, * g2;
	const int a = 3192;
	const int b = 9282;
private:
	const int c = b - 1;
public:
	virtual ~UnionGen();
	UnionGen();
	void generate() override;
};

class OneGen : public generator {
protected:
	generator* g = new UnionGen;
public:
	OneGen() = default;
};

class SumGen : public OneGen {
public:
	SumGen() = default;
	void generate() override;
};

class dUnion : public UnionGen {
protected:
	double ans;
public:
	dUnion() = default;
	double getAns() override;
};

class PolarGen : public dUnion {
private:
	double v1;
	double v2;
	double s;
	void sum();
public:
	PolarGen() = default;
	void generate() override;
};

class CorrGen : public dUnion {
private:
	const double e = exp(1);
	double v = 0;
	double u;
	double findX();
public:
	CorrGen();
	void generate() override;
};

class LogGen :public OneGen {
public:
	LogGen() = default;
	void generate() override;
};

class ArensGen :public OneGen {
private:
	double x;
	double y;
	double u;
	double v;
	void FindXnY();
	const int a = 10;
	const double pi = acos(-1);
public:
	ArensGen() = default;
	void generate() override;
};