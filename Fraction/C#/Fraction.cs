using System;
using System.Diagnostics;

namespace FractionUtility
{
    public class Utility
    {
        public static int Gcd(int x, int y)
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

            return Math.Abs(x);
        }

        public static int Lcm(int x, int y)
        {
            return Math.Abs((x * y) / Gcd(x, y));
        }
    }
}

public struct Fraction
{
    public int Numerator
    {
        get => m_numerator;
        set => m_numerator = value;
    }

    public int Denominator
    {
        get => m_denominator;
        set
        {
            Debug.Assert(value != 0 && m_denominator != 0);
            m_denominator = value;
        }
    }

    private int m_numerator;
    private int m_denominator;

    public Fraction(int numerator, int denominator, bool doSimplify = true)
    {
        Debug.Assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;

        if (doSimplify) Simplify();
    }

    public Fraction(float value, bool doSimplify = true)
    {
        int n = 1;

        while (!(Math.Abs(value - (int)value) < 1e-12))
        {
            value *= 10;
            n *= 10;
        }

        m_numerator = (int)value;
        m_denominator = n;

        Debug.Assert(m_denominator != 0);

        if (doSimplify) Simplify();
    }

    /// <summary>
    /// Reducing to common denominator
    /// </summary>
    public void Common(ref Fraction fraction)
    {
        int lcm = FractionUtility.Utility.Lcm(m_denominator, fraction.m_denominator);
        int multiplier0 = lcm / m_denominator;
        int multiplier1 = lcm / fraction.m_denominator;

        int newNumerator0 = m_numerator * multiplier0;
        int newNumerator1 = fraction.m_numerator * multiplier1;

        m_denominator = lcm;
        fraction.m_denominator = lcm;

        m_numerator = newNumerator0;
        fraction.m_numerator = newNumerator1;
    }

    /// <summary>
    /// Reducing to common denominator
    /// </summary>
    public static void Common(ref Fraction fraction0, ref Fraction fraction1)
    {
        int lcm = FractionUtility.Utility.Lcm(fraction0.m_denominator, fraction1.m_denominator);
        int multiplier0 = lcm / fraction0.m_denominator;
        int multiplier1 = lcm / fraction1.m_denominator;

        int newNumerator0 = fraction0.m_numerator * multiplier0;
        int newNumerator1 = fraction1.m_numerator * multiplier1;

        fraction0.m_denominator = lcm;
        fraction1.m_denominator = lcm;

        fraction0.m_numerator = newNumerator0;
        fraction1.m_numerator = newNumerator1;
    }

    public void Simplify()
    {
        int gcd = FractionUtility.Utility.Gcd(m_numerator, m_denominator);

        int newNumerator = m_numerator / gcd;
        int newDenominator = m_denominator / gcd;

        m_numerator = newNumerator;
        m_denominator = newDenominator;
    }

    public static Fraction operator +(Fraction fraction0, Fraction fraction1)
    {
        fraction0.Common(ref fraction1);

        int newNumerator = fraction0.m_numerator + fraction1.m_numerator;

        return new Fraction(newNumerator, fraction0.m_denominator);
    }

    public static Fraction operator +(Fraction fraction) => fraction;

    public static Fraction operator -(Fraction fraction0, Fraction fraction1)
    {
        fraction0.Common(ref fraction1);

        int newNumerator = fraction0.m_numerator - fraction1.m_numerator;

        return new Fraction(newNumerator, fraction0.m_denominator);
    }

    public static Fraction operator -(Fraction fraction)
    {
        fraction.Numerator *= -1;
        return fraction;
    }

    public static Fraction operator *(Fraction fraction0, Fraction fraction1)
    {
        int newNumerator = fraction0.m_numerator * fraction1.m_numerator;
        int newDenominator = fraction0.m_denominator * fraction1.m_denominator;

        return new Fraction(newNumerator, newDenominator);
    }

    public static Fraction operator /(Fraction fraction0, Fraction fraction1)
    {
        int newNumerator = fraction0.m_numerator * fraction1.m_denominator;
        int newDenominator = fraction0.m_denominator * fraction1.m_numerator;

        return new Fraction(newNumerator, newDenominator);
    }
}