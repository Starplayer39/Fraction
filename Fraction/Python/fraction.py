class Utility:
    @staticmethod
    def gcd(x : int, y : int) -> int:
        tmp = 0
        n = 0

        if x < y:
            tmp = x
            x = y
            y = tmp

        while y != 0:
            n = x % y
            x = y
            y = n

        return abs(x)

    @staticmethod
    def lcm(x : int, y : int) -> int:
        return abs((x * y) / Utility.gcd(x, y))

class Fraction:

    @property
    def numerator(self):
        return self.__m_numerator

    @numerator.setter
    def numerator(self, numerator : int):
        self.__m_numertator = numerator

    @property
    def denominator(self):
        return self.__m_denominator

    @denominator.setter
    def denominator(self, denominator : int):
        assert denominator != 0

        self.__m_denominator = denominator

    def __init__(self, numerator : int, denominator : int, doSimplify=True):
        assert denominator != 0

        self.__m_numerator = numerator
        self.__m_denominator = denominator

        if doSimplify:
            self.simplify()

    @classmethod
    def from_float(cls, value : float, doSimplify=True):
        n = 1

        while not (abs(value - int(value)) < 1e-12):
            value *= 10
            n *= 10

        numerator = int(value)
        denominator = n

        assert denominator != 0

        return cls(numerator, denominator)

    def common(self, fraction):
        lcm = Utility.lcm(self.__m_denominator, fraction.__m_denominator)
        multiplier0 = lcm / self.__m_denominator
        multiplier1 = lcm / fraction.__m_denominator

        newNumerator0 = self.__m_numerator * multiplier0
        newNumerator1 = fraction.__m_numerator * multiplier1

        self.__m_denominator = lcm
        fraction.__m_denominator = lcm

        self.__m_numerator = newNumerator0
        fraction.__m_numerator = newNumerator1

    @staticmethod
    def common_all(fraction0, fraction1):
        lcm = Utility.lcm(fraction0.__m_denominator, fraction1.__m_denominator)
        multiplier0 = lcm / fraction0.__m_denominator
        multiplier1 = lcm / fraction1.__m_denominator

        newNumerator0 = fraction0.__m_numerator * multiplier0
        newNumerator1 = fraction1.__m_numerator * multiplier1

        fraction0.__m_denominator = lcm
        fraction1.__m_denominator = lcm

        fraction0.__m_numerator = newNumerator0
        fraction1.__m_numerator = newNumerator1

    def simplify(self):
        gcd = Utility.gcd(self.__m_numerator, self.__m_denominator)

        new_numerator = int(self.__m_numerator / gcd)
        new_denominator = int(self.__m_denominator / gcd)

        self.__m_numerator = new_numerator
        self.__m_denominator = new_denominator

    def __add__(self, fraction):
        self.common(fraction)

        new_numerator = self.__m_numerator + fraction.__m_numerator

        return Fraction(new_numerator, self.__m_denominator)

    def __pos__(self):
        return Fraction(self.numerator * -1, self.denominator)

    def __sub__(self, fraction):
        self.common(fraction)

        new_numerator = self.__m_numerator - fraction.__m_numerator

        return Fraction(new_numerator, self.__m_denominator)

    def __neg__(self):
        return Fraction(self.numerator * -1, self.denominator)

    def __mul__(self, fraction):
        new_numerator = self.__m_numerator * fraction.__m_numerator
        new_denominator = self.__m_denominator * fraction.__m_denominator

        return Fraction(new_numerator, new_denominator)

    def __truediv__(self, fraction):
        new_numerator = self.__m_numerator * fraction.__m_denominator
        new_denominator = self.__m_denominator * fraction.__m_numerator

        return Fraction(new_numerator, new_denominator)
