#ifndef FRACTION_H
#define FRACTION_H

namespace utility
{
	/// <summary>
	/// Return 'Greatest Common Division' of the given two integers
	/// </summary>
	/// <param name="x">An integer</param>
	/// <param name="y">An integer</param>
	/// <returns>Greatest Common Division of the given two integers</returns>
	int Gcd(int x, int y);

	/// <summary>
	/// Return 'Least Common Multiple' of the given two integers
	/// </summary>
	/// <param name="x">An integer</param>
	/// <param name="y">An integer</param>
	/// <returns>Least Common Multiple of the given two integers</returns>
	int Lcm(int x, int y);
}

struct Fraction
{
private:
	/// <summary>
	/// Numerator of the Fraction
	/// </summary>
	int m_numerator = 0;

	/// <summary>
	/// Denominator of the Fraction
	/// </summary>
	int m_denominator = 1;

public:
	/// <summary>
	/// Constructor of Fraction Class which takes two integers and a boolean as parameter
	/// </summary>
	/// <param name="doSimplify">Simplify the fraction when true</param>
	Fraction(int numerator, int denominator, bool doSimplify = true);

	/// <summary>
	/// Constructor of Fraction Class which takes a float and a boolean as parameter
	/// </summary>
	/// <param name="value">Value of float type</param>
	/// <param name="doSimplify">Simplify the fraction when true</param>
	Fraction(float value, bool doSimplify = true);

	/// <summary>
	/// Get Numerator of the fraction
	/// </summary>
	/// <returns>Numerator of the fraction</returns>
	int GetNumerator();

	/// <summary>
	/// Get Denominator of the fraction
	/// </summary>
	/// <returns>Denominator of the fraction</returns>
	int GetDenominator();

	/// <summary>
	/// Set Numerator of the fraction
	/// </summary>
	/// <param name="numerator">An integer value to set as numerator</param>
	void SetNumerator(const int numerator);

	/// <summary>
	/// Set Denominator of the fraction
	/// </summary>
	/// <param name="denominator">An integer value to set as denominator</param>
	void SetDenominator(const int denominator);

	/// <summary>
	/// Reduce the fraction
	/// </summary>
	void Simplify();

	/// <summary>
	/// Reduce the fractions to a common denominator
	/// </summary>
	void Common(Fraction& fraction);

	/// <summary>
	/// Reduce the fractions to a common denominator
	/// </summary>
	static void Common(Fraction& fraction0, Fraction& fraction1);

	Fraction operator + () const;
	Fraction operator - () const;

	Fraction operator + (Fraction& fraction);
	Fraction operator - (Fraction& fraction);
	Fraction operator * (Fraction& fraction);
	Fraction operator / (Fraction& fraction);
};

#endif
