#pragma once
#include<iostream>
#include<cmath>

class generator{
protected: 
	double ans = 0;
public:
	virtual void generate() = 0;
	virtual double getAns();
};

class lgenerator : public generator {
private:
	const int x1 = 12334545;
	const int m1 = 1000000007;
public:
	int m;
	int x;
	double getAns() override;
	lgenerator();
};
