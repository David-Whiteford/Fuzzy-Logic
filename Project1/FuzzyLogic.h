#pragma once
#include <math.h>
class FuzzyLogic
{
public:
	FuzzyLogic();
	~FuzzyLogic();
	double FuzzyGrade(double t_value, double t_x0, double t_x1);
	double FuzzyTriangle(double t_value, double t_x0, double t_x1, double t_x2);
	double FuzzyTrapezoid(double t_value, double t_x0, double t_x1, double t_x2, double t_x3);
	double FuzzyAnd(double t_A, double t_B)
	{
		return fmin(t_A, t_B);
	}
	double FuzzyOr(double t_A, double t_B)
	{
		return fmax(t_A, t_B);
	}
	double FuzzyNot(double t_A)
	{
		return 1.0 - t_A;
	}


private:

};



