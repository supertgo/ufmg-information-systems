#include <iostream>
#include "vpl03.hpp"
#include <vector>

using namespace std;

int number_of_columns(vector<vector<int>> A) {
  return A[0].size();
}

int number_of_rows(vector<vector<int>> A) {
  return A.size();
}

vector<vector<int>> matrix_multiplication(
  vector<vector<int>> A, 
  vector<vector<int>> B
) {
  int rowA = number_of_rows(A);
  int colB = number_of_columns(B);
  int p = number_of_columns(A);

  vector<vector<int>> P(rowA, vector<int>(colB));

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colB; j++) {
      for (int k = 0; k < p; k++) {
        P[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return P;
}



// int main() {
//   vector<vector<int>> P;
//   auto a = vector<vector<int>> {
//     {11, 12, 13, 14, 15},
//     {21, 22, 23, 24, 25},
//     {31, 32, 33, 34, 35}
//   };

//   auto b = vector<vector<int>> {
//       {11, 12, 13},
//       {21, 22, 23},
//       {31, 32, 33},
//       {41, 42, 43},
//       {51, 52, 53}
//   };

//   P = matrix_multiplication(a, b);
//   return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int number_of_columns(vector<vector<int>> A) {
  return A[0].size();
}

int number_of_rows(vector<vector<int>> A) {
  return A.size();
}

vector<vector<int>> matrix_multiplication(
  vector<vector<int>> A, 
  vector<vector<int>> B
) {
  int rowA = number_of_rows(A);
  int colB = number_of_columns(B);
  int p = number_of_columns(A);

  vector<vector<int>> P(rowA, vector<int>(p));

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colB; j++) {
      for (int k = 0; k < p; k++) {
        P[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return P;
}

int main(){
    int l1, l2, l3;
  
  cin >> l1 >> l2 >> l3;
  
  vector<vector<int>> a(l1, vector<int>(l2));
  vector<vector<int>> b(l2, vector<int>(l3));
 
  
  for (int i = 0; i < l1; i++) {
      for (int j = 0; j < l2; j++) {
          cin >> a[i][j];
      }
  }
 
  
  for (int k = 0; k < l2; k++) {
      for (int l = 0; l < l3; l++) {
          cin >> b[k][l];
      }
  }
  
  vector<vector<int>>C = matrix_multiplication(a, b);
  
  
  for (int i = 0; i < C.size(); i++) {
    for (int j = 0; j < C[0].size(); j++) {
            cout << C[i][j] << " ";
    }
    cout << endl;
  }
    return 0;
}