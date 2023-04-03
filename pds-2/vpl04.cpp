#include <iostream>

#include <map>
#include <string>

using namespace std;

string most_common_word(string sentence) {
  map<string, int>word_mapper;
  string word = "";

  for (const auto& c : sentence) {
    if (c == ' ') {
      if (!word.empty()) {
        auto result = word_mapper.emplace(word, 1);
        if (!result.second) {
          result.first->second++;
        }
        word = "";
      } 
    } else {
      word += c;
    }
  }

  if (!word.empty()) {
    auto result = word_mapper.emplace(word, 1);

    if (!result.second) {
      result.first->second++;
    }
  }

  int times = 0;
  string most_common = "";
  for (auto it = word_mapper.begin(); it != word_mapper.end(); it++) {
    if (it->second >= times) {
      most_common = it->first;
      times = it->second;
    }
  }

  return most_common;
}


int main() {
  string sentence, str = "";
  while(cin >> sentence) {
    if(sentence.empty()) {
        break;
    }

    str += " " + sentence;
  }

  cout << most_common_word(str) << endl;
  
  return 0;
}