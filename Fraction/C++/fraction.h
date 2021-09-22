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
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator, int denominator, bool doSimplify = true);
	Fraction(float value, bool doSimplify = true);

	int GetNumerator();
	int GetDenominator();

	void SetNumerator(const int numerator);
	void SetDenominator(const int denominator);

	void Simplify();

	/// <summary>
	/// Reducing to common denominator
	/// </summary>
	void Common(Fraction& fraction);

	/// <summary>
	/// Reducing to common denominator
	/// </summary>
	static void Common(Fraction& fraction0, Fraction& fraction1);

	Fraction operator + (Fraction& fraction);
	Fraction operator - (Fraction& fraction);
	Fraction operator * (Fraction& fraction);
	Fraction operator / (Fraction& fraction);
};

#endif
