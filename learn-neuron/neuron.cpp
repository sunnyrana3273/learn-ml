#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// method signatures so main knows what to reference when calling methods
float loss(float actual, float predicted);
float predict(float w1, float w2, float x1, float x2, float bias);
float averageLoss(const vector<vector <int>>& examples, float w1, float w2, float bias);
float updateWeight1(const vector<vector <int>>& examples, float w1, float w2, float bias, float learnignRate);


int main() {
  float w1 = 0.2;
  float w2 = 0.8;
  float bias = 0;
  float learningRate = 0.1; 
  // x1, x2, expected result
  const vector<vector <int>>& examples = {{2, 3, 5}, {4, 7, 11}, {1, 9, 10}, {8, 2, 10}};

  cout << updateWeight1(examples, w1, w2, bias, learningRate) << endl;
}

float loss(float actual, float predicted) {
  return pow((actual - predicted), 2);
}

float predict(float w1, float w2, float x1, float x2, float bias) {
  return (x1 * w1) + (x2 * w2) + bias;
}

float averageLoss(const vector<vector <int>>& examples, float w1, float w2, float bias) {
  float lossSum = 0;

  for (int i = 0; i < examples.size(); i++) {
    int x1 = examples[i][0];
    int x2 = examples[i][1];

    float pred = predict(w1, w2, x1, x2, bias);

    lossSum += loss(examples[i][2], pred);
  }

  return lossSum / examples.size();
}

float updateWeight1(const vector<vector <int>>& examples, float w1, float w2, float bias, float learningRate) {
  float incWeight = w1 + learningRate;
  float decWeight = w1 - learningRate;

  float originalLoss = averageLoss(examples, w1, w2, bias);

  float incLoss = averageLoss(examples, incWeight, w2, bias);
  float decLoss = averageLoss(examples, decWeight, w2, bias);

  cout << originalLoss << endl << incLoss << endl << decLoss << endl;

  if (incLoss < decLoss && incLoss < originalLoss) {
    return incWeight;
  } else if (decLoss < incLoss && decLoss < originalLoss) {
    return decWeight;
  } else {
    return w1;
  }

}

