#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "postcard.h"

using namespace std;

static int N;
static int M;
static int Q = 0;
static long long a[100005];
static long long pref[100005];

void wa(string MSG) {
  cout << "Wrong answer: " << MSG << endl;
  exit(0);
}

int ask(int x) {
  ++Q;
  if (x < 1 || x > N) {
    wa("k out of range.");
  }

  return pref[x];
}

int main() {
  if (!(cin >> N >> M)) {
    wa("Could not read N and M");
  }
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  int answer = postcard(N, M);

  int correct_answer = 0;
  while (correct_answer + 1 <= N && pref[correct_answer + 1] <= M)
    correct_answer++;

  if (answer != correct_answer) {
    wa("Your guess " + to_string(answer) + " was incorrect");
  } else {
    cout << "Correct: Q=" << Q;
  }

  return 0;
}
