#ifndef FRACTION_H
#define FRACTION_H

namespace utility
{
	int Gcd(int x, int y);
	int Lcm(int x, int y);
}

struct Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator);
	Fraction(float value);

	float GetNumerator();
	float GetDenominator();

	void SetNumerator(const int numerator);
	void SetDenominator(const int denominator);

	void Simplify();

	/// <summary>
	/// Reducing to common denominator
	/// </summary>
	void Common(Fraction& fraction);

	Fraction operator + (Fraction& fraction);
	Fraction operator - (Fraction& fraction);
	Fraction operator * (Fraction& fraction);
	Fraction operator / (Fraction& fraction);
};

#endif
