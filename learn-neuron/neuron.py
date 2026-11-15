# 2 neurons that learn how to generate accurate sum
def predict(x1, x2, w1, w2, bias):
    return (x1 * w1) + (x2 * w2) + bias

def loss(prediction, actual):
    # squared error, penalizes more for larger difference
    # avoids negative values
    return (actual - prediction) ** 2

w1 = 0.5
w2 = 0.8
bias = 0



# x1, x2, actual in tuple form 
examples = [
    (2, 3, 5),
    (4, 7, 11),
    (1, 9, 10),
    (8, 2, 10)
]

for example in examples:
    print("Num 1: " + str(example[0]))
    print("Num 2: " + str(example[1]))
    print("Expected Sum: " + str(example[2]))
    print("")

    predictVal = predict(example[0], example[1], w1, w2, bias)
    print("Prediction: " + str(predictVal))

    lossVal = loss(predictVal, example[2]);
    print("Loss: " + str(lossVal))

    print("")


