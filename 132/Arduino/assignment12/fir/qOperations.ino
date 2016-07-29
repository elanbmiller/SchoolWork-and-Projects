// Replace with your completed library code!

float qtof(int number, int fractionalBits) {
  float answer = (float)(unsigned (number) * pow(2, -(fractionalBits)));
  return answer;
}

int ftoq(float number, int fractionalBits) {
  int answer = (unsigned(number) * pow(2, fractionalBits));
  return answer;
}

int qMultiply(int a, int b, int fractionalBits) {
  int answerHelper = 0;
  long answer = (long int)a * (long int)b;
  answer += (1 << (fractionalBits - 1));

  answerHelper = answer >> fractionalBits;

  return answerHelper;
}

