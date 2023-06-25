#include "google_password.h"

#include <iostream>

void GooglePassword::insert(const std::string &url, const std::string &login,
                            const std::string &password) {
  auto node = passwords_.find(url);

  if (node != passwords_.end())
    return;

  if (validPassword(password)) {
    Usuario newUser = {login, password};
    passwords_[url] = newUser;
  }

}

void GooglePassword::remove(const std::string &url) { passwords_.erase(url); }

void GooglePassword::update(const std::string &url, const std::string &login,
                            const std::string &old_password,
                            const std::string &new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  auto node = passwords_.find(url);

  if (node == passwords_.end())
    return;
  if (node->second.password != old_password)
    return;

  if (validPassword(new_password)) {
    passwords_[url].login = login;
    passwords_[url].password = new_password;
  }
}

void GooglePassword::printPasswords() {
  std::cout << passwords_.size() << std::endl;
  for (auto i = passwords_.begin(); i != passwords_.end(); i++) {
    std::cout << i->first << ": " << i->second.login << " and "
              << i->second.password << std::endl;
  }
}

bool GooglePassword::validPassword(const std::string &password) const {
  int passwordLength = password.length();
  if (6 > passwordLength || passwordLength > 50) {
    return false;
  }

  std::string::size_type position;
  position = password.find(" ");

  if (std::string::npos != position) {
    return false;
  }

  position = password.find("123456");
  if (std::string::npos != position) {
    return false;
  }

  return true;
}
