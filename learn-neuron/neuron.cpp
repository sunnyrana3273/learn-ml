#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// method signatures so main knows what to reference when calling methods
float loss(float actual, float predicted);
float predict(float w1, float w2, float x1, float x2, float bias);
float averageLoss(vector<vector <int>> examples, float w1, float w2, float bias);


int main() {
  float w1 = 0.2;
  float w2 = 0.8;
  float bias = 0;
  
  // x1, x2, expected result
  vector<vector <int>> examples = {{2, 3, 5}, {4, 7, 11}, {1, 9, 10}, {8, 2, 10}};

  cout << averageLoss(examples, w1, w2, bias) << endl;
}

float loss(float actual, float predicted) {
  return pow((actual - predicted), 2);
}

float predict(float w1, float w2, float x1, float x2, float bias) {
  return (x1 * w1) + (x2 * w2) + bias;
}

float averageLoss(vector<vector <int>> examples, float w1, float w2, float bias) {
  float lossSum = 0;

  for (int i = 0; i < examples.size(); i++) {
    int x1 = examples[i][0];
    int x2 = examples[i][1];

    float pred = predict(w1, w2, x1, x2, bias);

    lossSum += loss(examples[i][2], pred);
  }

  return lossSum / examples.size();
}
