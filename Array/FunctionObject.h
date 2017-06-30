#pragma once

class FunctionObject
{
public:
	int operator() (int in_parameter) const;
	static int doSquare(int in_parameter);
};

inline int FunctionObject::operator()(int in_parameter) const
{
	return doSquare(in_parameter);
}

inline int FunctionObject::doSquare(int in_parameter)
{
	return in_parameter* in_parameter;
}
