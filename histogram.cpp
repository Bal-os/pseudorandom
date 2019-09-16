#include"histogram.h"
std::string buildGistagram(double *arr,int size,int type) {
	std::ostringstream gist;

	gist << std::fixed;
	gist.precision(3);

	gist << "\nInterval\tChastota\n";

	double ch[10];
	for (int i = 0; i < 10; ++i)ch[i] = 0;

	if (type <= 5)
	{
		for (int i = 0; i < size; ++i) {
			double x = double(*(arr + i));
			ch[int(x * 10)]++;
		}
		for (int i = 0; i < 10; ++i) {
			gist << "[0";
			if (i)
				gist << "." << i;
			gist << "; ";

			if (i < 9)
				gist << "0." << i + 1 << "]";
			else 
				gist << "1.0]";
			gist << "\t" << double(ch[i]) / size << "\n";
		}
	}
	else if (type <= 8)
		{
			for (int i = 0; i < size; ++i) {
				double x = double(*(arr + i));
				ch[int((x + 3) / 0.6)]++;
			}
			for (int i = 0; i < 10; ++i) {
				gist << "[";
				gist.precision(1);
				if (i)
					gist << double(i) * 0.6 - 3;
				else
					gist << "-3";
				gist << "; ";

				if (i < 9)
					gist << double(i + 1) * 0.6 - 3 << "]";
				else
					gist << "3.0]";
				gist.precision(3);
				gist << "\t" << double(ch[i]) / size << "\n";
			}
		}
	else if (type <= 10)
	{

		for (int i = 0; i < size; ++i) {
			double x = double(*(arr + i));
			ch[int(x/10)]++;
		}
		for (int i = 0; i < 10; ++i) {
			gist << "[" << i * 10 << "; " ;

			gist << (i + 1) * 10 << "]";
			gist << "\t" << double(ch[i]) / size << "\n";
		}
	}
	return gist.str();
}