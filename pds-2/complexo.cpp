// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
}

Complexo::Complexo(double a, double b) {
  real_ = std::sqrt(a * a + b * b);
  imag_ = atan2(b, a);
}

double Complexo::real() {
  return real_ * std::cos(imag_);
}

double Complexo::imag() {
  return real_ * std::sin(imag_);
}

bool Complexo::igual(Complexo x) {
  return (real_ == x.real_ and imag_ == x.imag_);
}

void Complexo::Atribuir(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
}

double Complexo::modulo() {
  return real_;
}

Complexo Complexo::conjugado() {
  return Complexo(real_, -imag_);
}

Complexo Complexo::simetrico() {
  return Complexo(-real_, -imag_);
}

Complexo Complexo::inverso() {
  double mod = real_ * real_ + imag_ * imag_;
  return Complexo(real_ / mod, -imag_ / mod);
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real_ = real_ * std::cos(imag_) + y.real_ * std::cos(y.imag_);
  s.imag_ = real_ * std::sin(imag_) + y.real_ * std::sin(y.imag_);

  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real_ = real_ * std::cos(imag_) - y.real_ * std::cos(y.imag_);
  s.imag_ = real_ * std::sin(imag_) - y.real_ * std::sin(y.imag_);
  
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = (real_ * y.real_) - (imag_ * y.imag_);
  p.imag_ = (real_ * y.imag_) + (imag_ * y.real_);

  return p;
}

Complexo Complexo::dividir(Complexo y) {
  double denominador = y.real_ * y.real_ + y.imag_ * y.imag_;
  double a = (real_ * y.real_ + imag_ * y.imag_) / denominador;
  double b = (imag_ * y.real_ - real_ * y.imag_) / denominador;

  return Complexo(a, b);
}

