#include <cmath>
#include <string>
#include <iostream>
#include "racional.h"

int mdc(int num1, int num2) {
  int rest, a, b;

  a = num1;
  b = num2;

  do {
    rest = a % b;
    a = b;
    b = rest;
  } while (rest != 0);

  return a;
}

int mmc(int num1, int num2) { return (num1 * num2) / mdc(num1, num2); }

void Racional::Simplificar() {
  int max_div = mdc(numerador_, denominador_);

  numerador_ /= max_div;
  denominador_ /= max_div;
}

Racional::Racional() {
  numerador_ = 0;
  denominador_ = 1;
}

Racional::Racional(int n) {
  numerador_ = n;
  denominador_ = 1;
}

Racional::Racional(int n, int d) {
  numerador_ = n;
  denominador_ = d;
}

int Racional::numerador() const { return numerador_; }

int Racional::denominador() const { return denominador_; }

Racional Racional::operator-() const {
  int num = -1 * numerador_;
  Racional result = Racional(num, denominador_);

  result.Simplificar();

  return result;
}


Racional Racional::operator+(Racional k) const {
  int mmc_denominator = mmc(denominador_, k.denominador_);
  int pri_numerador = (mmc_denominator / denominador_) * numerador_;
  int sec_numerador = (mmc_denominator / k.denominador_) * k.numerador_;

  Racional result = Racional(pri_numerador + sec_numerador, mmc_denominator);

  result.Simplificar();

  return result;
}

Racional Racional::operator-(Racional k) const {
  int mmc_denominator = mmc(denominador_, k.denominador_);
  int pri_numerador = (mmc_denominator / denominador_) * numerador_;
  int sec_numerador = (mmc_denominator / k.denominador_) * k.numerador_;

  Racional result = Racional(pri_numerador - sec_numerador, mmc_denominator);

  result.Simplificar();

  return result;
}

Racional Racional::operator*(Racional k) const {
  Racional result =
      Racional(numerador_ * k.numerador_, denominador_ * k.denominador_);
  result.Simplificar();

  return result;
}

Racional Racional::operator/(Racional k) const {
  Racional result =
      Racional(numerador_ * k.denominador_, denominador_ * k.numerador_);
  result.Simplificar();

  return result;
}

Racional::operator string() const {
  Racional result = Racional(numerador_, denominador_);
  result.Simplificar();
  return std::to_string(result.numerador_) + "/" + std::to_string(result.denominador_);
}

Racional::operator float() const {
  Racional result = Racional(numerador_, denominador_);
  result.Simplificar();
  return static_cast<float>(result.numerador_) / result.denominador_;
}

ostream& operator<<(ostream& out, Racional r) {
  out << r.numerador_ << '/' << r.denominador_;

  return out;
}

istream& operator>>(istream& in, Racional& r) {
  in >> r.numerador_ >> r.denominador_;

  return in;
}
