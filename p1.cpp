//Problem 1
#include <iostream>
#include "p1.h"

using namespace std;



bool XOR(bool p, bool q)
{
	bool np = NOT(p);
	bool nq = NOT(q);
	bool npq = AND(np,q);
	bool nqp = AND(nq,p);
	bool ans = OR(npq,nqp);
	

	return ans;
}
bool MUX(bool operation,bool ifTrue, bool ifFalse)
{
	bool ns = NOT(operation);
	bool nsa = AND(ns,ifTrue);
	bool sb = AND(operation,ifFalse);
	bool ans = OR(nsa,sb);

	return ans;
}
bool SUM(bool p, bool q)
{
	return XOR(p,q);
}
bool SUM3(bool a,bool c,bool b)
{
	bool apb = SUM(a,b);
	bool ans = SUM(apb,c);

	return ans;
}
bool CarryOut(bool a, bool b, bool c)
{
	bool ab = AND(a,b);
	bool bc = AND(b,c);
	bool ac = AND(a,c);
	bool abORbc = OR(ab,bc);
	bool ans = OR(abORbc,ac);

	return ans;
}
bool equal(bool a, bool b)
{
	bool xorab = XOR(a,b);
	bool ans = NOT(xorab);

	return ans;
}
