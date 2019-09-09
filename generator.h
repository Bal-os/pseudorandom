#pragma once
#include<iostream>

class generator{
public:
	class lgenerator {
	private:
		int m = (1 << 31) - 1;;
		int x;
	public:
		double getDouble();
	};
	class rgenerator {
	
	};
};

class LCG : public generator::lgenerator {
private:
	int a = 101427;
	int c = 321;
public:
	void generate();
};

class QCG : public generator::lgenerator {
private:
	int a = 101427;
	int c = 321;
public:
	void generate();
};

class FG : public generator::lgenerator {
private:
	int a = 101427;
	int c = 321;
public:
	void generate();
};

class ICG : public generator::lgenerator {
private:
	int a = 101427;
	int c = 321;
public:
	void generate();
};