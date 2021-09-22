#include <iostream>
#include <cassert>

#include "fraction.h"

int utility::Gcd(int x, int y)
{
	int tmp, n;

	if (x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	while (y != 0)
	{
		n = x % y;
		x = y;
		y = n;
	}

	return std::abs(x);
}

int utility::Lcm(int x, int y)
{
	return std::abs((x * y) / Gcd(x, y));
}

Fraction::Fraction(int numerator, int denominator, bool doSimplify)
{
	assert(denominator != 0);

	m_numerator = numerator;
	m_denominator = denominator;

	if (doSimplify) Simplify();
}

Fraction::Fraction(float value, bool doSimplify)
{
	int n = 1;

	while (!(abs(value - (int)value) < 1e-12))
	{
		value *= 10;
		n *= 10;
	}

	m_numerator = static_cast<int>(value);
	m_denominator = n;

	assert(m_denominator != 0);

	if (doSimplify) Simplify();
}

int Fraction::GetNumerator() { return m_numerator; }
int Fraction::GetDenominator() { return m_denominator; }

void Fraction::SetNumerator(int numerator) { m_numerator = numerator; }
void Fraction::SetDenominator(int denominator)
{
	assert(denominator != 0);
	m_denominator = denominator;
}

void Fraction::Common(Fraction& fraction)
{
	int lcm = utility::Lcm(m_denominator, fraction.m_denominator);
	int multiplier0 = lcm / m_denominator;
	int multiplier1 = lcm / fraction.m_denominator;

	int newNumerator0 = m_numerator * multiplier0;
	int newNumerator1 = fraction.m_numerator * multiplier1;

	m_denominator = lcm;
	fraction.m_denominator = lcm;

	m_numerator = newNumerator0;
	fraction.m_numerator = newNumerator1;
}

void Fraction::Common(Fraction& fraction0, Fraction& fraction1)
{
	int lcm = utility::Lcm(fraction0.m_denominator, fraction1.m_denominator);
	int multiplier0 = lcm / fraction0.m_denominator;
	int multiplier1 = lcm / fraction1.m_denominator;

	int newNumerator0 = fraction0.m_numerator * multiplier0;
	int newNumerator1 = fraction1.m_numerator * multiplier1;

	fraction0.m_denominator = lcm;
	fraction1.m_denominator = lcm;

	fraction0.m_numerator = newNumerator0;
	fraction1.m_numerator = newNumerator1;
}

void Fraction::Simplify()
{
	int gcd = utility::Gcd(m_numerator, m_denominator);

	int newNumerator = m_numerator / gcd;
	int newDenominator = m_denominator / gcd;

	m_numerator = newNumerator;
	m_denominator = newDenominator;
}

Fraction Fraction::operator + (Fraction& fraction)
{
	this->Common(fraction);

	int newNumerator = this->m_numerator + fraction.m_numerator;

	return Fraction(newNumerator, this->m_denominator);
}

Fraction Fraction::operator - (Fraction& fraction)
{
	this->Common(fraction);

	int newNumerator = this->m_numerator - fraction.m_numerator;

	return Fraction(newNumerator, this->m_denominator);
}

Fraction Fraction::operator * (Fraction& fraction)
{
	int newNumerator = m_numerator * fraction.m_numerator;
	int newDenominator = m_denominator * fraction.m_denominator;

	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator / (Fraction& fraction)
{
	int newNumerator = m_numerator * fraction.m_denominator;
	int newDenominator = m_denominator * fraction.m_numerator;

	return Fraction(newNumerator, newDenominator);
}
