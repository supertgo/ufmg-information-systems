#include <iostream>

using namespace std;

int main () {
  string word;
  int size = 4;
  int vowels[] = {0, 0, 0, 0, 0};

  cin >> word;

  for (int i  = 0; i < word.length(); i++) {
    if (word[i] == 'a') {
      vowels[0] += 1;
    } else if (word[i] == 'e') {
      vowels[1] += 1;  
    } else if (word[i] == 'i') {
      vowels[2] += 1;
    } else if (word[i] == 'o') {
      vowels[3] += 1;
    } else if (word[i] == 'u') {
      vowels[4] += 1; 
    }
  }

    if (vowels[0] > 0) {
      cout << 'a' << ' ' << vowels[0] << '\n';
    }

    if (vowels[1] > 0) {
      cout << 'e' << ' ' << vowels[1] << '\n';
    }
    if (vowels[2] > 0) {
      cout << 'i' << ' ' << vowels[2] << '\n';
    }
    if (vowels[3] > 0) {
      cout << 'o' <<  ' ' << vowels[3] << '\n';
    }

    if (vowels[4] > 0) {
      cout << 'u' << ' ' << vowels[4] << '\n';
    }

  return 0;
}
