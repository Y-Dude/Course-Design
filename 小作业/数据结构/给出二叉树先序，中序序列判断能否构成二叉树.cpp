#include <stdio.h>

const int kMaxN = 1000;

int pre[kMaxN] = {0};
int in[kMaxN] = {0};
int post[kMaxN] = {0};

int n = 0;

bool Construct(int ps, int pe, int is, int ie, int s, int e) {
  if (pe - ps != ie - is) return false;
  char root = pre[ps];
  post[e] = root;

  int i;
  for (i = is; i <= ie; i++) {
    if (in[i] == root) break;
  }

  if (i > ie) {
    return false;
  }

  int len1 = i - is;
  int len2 = ie - i;

  bool l = false;
  bool r = false;
  if (len1 == 0) {
    l = true;
  } else {
    l = Construct(ps + 1, ps + len1, is, is + len1 - 1, s, s + len1 - 1);
  }
  if (len2 == 0) {
    r = true;
  } else {
    r = Construct(ps + len1 + 1, pe, is + len1 + 1, ie, s + len1, e - 1);
  }
  return l && r;
}



int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &in[i]);
    }
    if (Construct(0, n - 1, 0, n - 1, 0, n - 1)) {
      for (int i = 0; i < n; i++) {
        printf("%d ", post[i]);
      }
      printf("\n");
    } else {
      printf("No\n");
    }
  }
}
