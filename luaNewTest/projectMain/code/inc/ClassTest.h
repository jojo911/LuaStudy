#pragma once
class CClassTest
{
public:
	CClassTest(void);
	CClassTest(int a, int b);
	~CClassTest(void);

public:
	int sum(int a, int b);
	int sum();

private:
	int m_a;
	int m_b;
};