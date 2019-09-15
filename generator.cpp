#include"generator.h"

double generator::getAns()
{
	return ans;
}

lgenerator::lgenerator(): x(x1),m(m1){
}

double lgenerator::getAns(){
	return ans = fabs(double(x) / m);
}
