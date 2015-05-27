#include "ClassTest.h"


CClassTest::CClassTest(void)
{
}

CClassTest::CClassTest(int a, int b)
{
	m_a = a;
	m_b = b;
}


CClassTest::~CClassTest(void)
{
}

int CClassTest::sum(int a, int b)
{
	return a+b;
}