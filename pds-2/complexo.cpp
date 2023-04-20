// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
}

Complexo::Complexo(double a, double b) {
  real_ = a;
  imag_ = b;
}

double Complexo::real() {
  return real_;
}

double Complexo::imag() {
  return imag_;
}

bool Complexo::igual(Complexo x) {
  return (real_ == x.real_ and imag_ == x.imag_);
}

void Complexo::Atribuir(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
}

double Complexo::modulo() {
  double mod = sqrt((real_ * real_) + (imag_ * imag_));
  return 0;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.real_ = real_;
  c.imag_ = (-1) * imag_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.real_ = (-1) * real_;
  c.imag_ = (-1) * imag_;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.real_ = 1/real_;
  i.imag_ = imag_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real_ = real_ + y.real_;
  s.imag_ = imag_ + y.imag_;

  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real_ = real_ - y.real_;
  s.imag_ = imag_ - y.imag_;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = (real_ * y.real_) - (imag_ * y.imag_);
  p.imag_ = (real_ * y.imag_) + (imag_ * y.real_);

  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  Complexo conjugado_y = y.conjugado();
  Complexo numerador = multiplicar(conjugado_y);
  double denominador = y.real_ * y.real_ + y.imag_ * y.imag_;

  d.real_ = (numerador.real_ / denominador, numerador.imag_ / denominador);

  return d;
}

