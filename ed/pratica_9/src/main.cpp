#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT 3
#define ALGQSORT3 4
#define ALGQSORTINS 5
#define ALGQSORT3INS 6
#define ALGHEAPSORT 7
#define ALGRECSEL 8

typedef struct alg {
  int num;
  char *name;
} alg_t;

alg_t algvet[] = {
    {ALGINSERTION, "i"}, {ALGSELECTION, "s"}, {ALGQSORT, "q"},
    {ALGQSORT3, "q3"},   {ALGQSORTINS, "qi"}, {ALGQSORT3INS, "q3i"},
    {ALGHEAPSORT, "h"},  {ALGRECSEL, "rs"},   {0, 0}};

int name2num(char *name) {
  int i = 0;
  while (algvet[i].num) {
    if (!strcmp(algvet[i].name, name))
      return algvet[i].num;
    i++;
  }
  return 0;
}

char *num2name(int num) {
  int i = 0;
  while (algvet[i].num) {
    if (algvet[i].num == num)
      return algvet[i].name;
    i++;
  }
  return 0;
}

typedef struct opt {
  int size;
  int seed;
  int alg;
} opt_t;

typedef struct sortperf {
  unsigned long int cmp;
  unsigned long int move;
  unsigned long int calls;
} sortperf_t;

void resetcounter(sortperf_t *s) {
  s->cmp = 0;
  s->move = 0;
  s->calls = 0;
}

void inccmp(sortperf_t *s, int num) { s->cmp += num; }

void incmove(sortperf_t *s, int num) { s->move += num; }

void inccalls(sortperf_t *s, int num) { s->calls += num; }

char *printsortperf(sortperf_t *s, char *str, char *pref) {
  sprintf(str, "%s cmp %ld move %ld calls %ld", pref, s->cmp, s->move,
          s->calls);
  return str;
}

void initVector(int *vet, int size) {
  int i;
  for (i = 0; i < size; i++) {
    vet[i] = (int)(drand48() * size);
  }
}

void printVector(int *vet, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}

void swap(int *xp, int *yp, sortperf_t *s) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
  incmove(s, 3);
}

// heapsort
void heapify(int *A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);

  int i, j;
  i = l;
  j = i * 2;

  int x = A[i];
  while (j <= r) {
    if (j < r) {
      inccmp(s, 1);
      if (A[j] < A[j + 1])
        j++;
    }
    inccmp(s, 1);
    if (x >= A[j])
      break;
    incmove(s, 1);
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  A[i] = x;
  incmove(s, 2);
}

void buildheap(int *A, int n, sortperf_t *s) {
  inccalls(s, 1);
  int l;
  l = n / 2 + 1;

  while (l > 1) {
    l--;
    heapify(A, l, n, s);
  }
}

void heapSort(int *A, int n, sortperf_t *s) {
  inccalls(s, 1);
  int l, r;
  buildheap(A, n, s);
  l = 1;
  r = n;

  while (r > 1) {
    swap(&A[l], &A[r], s);
    r--;
    heapify(A, l, r, s);
  }
}

void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s) {
  int min = l;
  inccalls(s, 1);
  for (int j = l + 1; j <= r; j++) {
    inccmp(s, 1);
    if (arr[j] < arr[min]) {
      min = j;
    }
  }

  if (min != l)
    swap(&arr[min], &arr[l], s);

  if (l + 1 < r) {
    recursiveSelectionSort(arr, l + 1, r, s);
  }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  for (int i = l; i < r - 1; i++) {
    int min = i;
    for (int j = i + 1; j < r; j++) {
      inccmp(s, 1);
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&arr[min], &arr[i], s);
    }
  }
  return;
}

// insertion sort
void insertionSort(int v[], int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  for (int i = l + 1; i < r; i++) {
    int aux = v[i];
    int j = i - 1;

    inccmp(s, 1);

    while (j >= 0 && aux < v[j]) {
      inccmp(s, 1);
      incmove(s, 1);
      v[j + 1] = v[j];
      j--;
    }
    incmove(s, 2);
    v[j + 1] = aux;
  }
}

// median of 3 integers
int median(int a, int b, int c) {
  if ((a <= b) && (b <= c))
    return b; // a b c
  if ((a <= c) && (c <= b))
    return c; // a c b
  if ((b <= a) && (a <= c))
    return a; // b a c
  if ((b <= c) && (c <= a))
    return c; // b c a
  if ((c <= a) && (a <= b))
    return a; // c a b
  return b;   // c b a
}

// quicksort partition using median of 3
void partition3(int *A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);
  *i = l;
  *j = r;
  int pivot = median(A[l], A[(l + r) / 2], A[r]);
  int aux;

  do {
    inccmp(s, 1);
    while (A[*i] < pivot) {
      inccmp(s, 1);
      (*i)++;
    }

    inccmp(s, 1);
    while (A[*j] > pivot) {
      inccmp(s, 1);
      (*j)--;
    }

    if (*i <= *j) {
      incmove(s, 3);
      aux = A[*i];
      A[*i] = A[*j];
      A[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// standard quicksort partition
void partition(int *A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);
  *i = l;
  *j = r;
  int pivot = A[(*i + *j) / 2];

  do {
    inccmp(s, 1);
    while (A[*i] < pivot) {
      inccmp(s, 1);
      (*i)++;
    }

    inccmp(s, 1);
    while (A[*j] > pivot) {
      inccmp(s, 1);
      (*j)--;
    }

    if (*i <= *j) {
      int aux;
      incmove(s, 3);
      aux = A[*i];
      A[*i] = A[*j];
      A[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// standard quicksort
void quickSort(int *A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  int i, j;
  partition(A, l, r, &i, &j, s);

  if (l < j) {
    quickSort(A, l, j, s);
  }

  if (r > i) {
    quickSort(A, i, r, s);
  }
}

// quicksort with median of 3
void quickSort3(int *A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  int i, j;
  partition3(A, l, r, &i, &j, s);

  if (l < j) {
    quickSort3(A, l, j, s);
  }

  if (r > i) {
    quickSort3(A, i, r, s);
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int *A, int l, int r, sortperf_t *s) {
  int i, j;
  int size = r - l;

  if (size <= 50) {
    insertionSort(A, l, r + 1, s);
  } else {
    partition(A, l, r, &i, &j, s);
    inccalls(s, 1);

    if (l < j) {
      quickSortIns(A, l, j, s);
    }

    if (r > i) {
      quickSortIns(A, i, r, s);
    }
  }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int *A, int l, int r, sortperf_t *s) {
  int i, j;
  int size = r - l;

  if (size <= 50) {
    insertionSort(A, l, r + 1, s);
  } else {
    partition3(A, l, r, &i, &j, s);
    inccalls(s, 1);

    if (l < j) {
      quickSort3Ins(A, l, j, s);
    }

    if (r > i) {
      quickSort3Ins(A, i, r, s);
    }
  }
}

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr, "sortperf\n");
  fprintf(stderr, "\t-z <int>\t(vector size)\n");
  fprintf(stderr, "\t-s <int>\t(initialization seed)\n");
  fprintf(stderr, "\t-a <s|i|q|q3|qi|q3i|h|rs>\t(algorithm)\n");
  fprintf(stderr, "\t    s\tselection\n");
  fprintf(stderr, "\t    i\tinsertion\n");
  fprintf(stderr, "\t    q\tquicksort\n");
  fprintf(stderr, "\t    q3\tquicksort+median3\n");
  fprintf(stderr, "\t    qi\tquicksort+insertion\n");
  fprintf(stderr, "\t    q3i\tquicksort+median3+insertion\n");
  fprintf(stderr, "\t    h\theapsort\n");
  fprintf(stderr, "\t    rs\trecursive selection\n");
}

void parse_args(int argc, char **argv, opt_t *opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
  // variaveis externas do getopt
  extern char *optarg;
  extern int optind;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opt->seed = 1;
  opt->size = 10;
  opt->alg = 1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "z:s:a:h")) != EOF) {
    switch (c) {
    case 'z':
      opt->size = atoi(optarg);
      break;
    case 's':
      opt->seed = atoi(optarg);
      break;
    case 'a':
      opt->alg = name2num(optarg);
      break;
    case 'h':
    default:
      uso();
      exit(1);
    }
  }
  if (!opt->alg) {
    uso();
    exit(1);
  }
}

void clkDiff(struct timespec t1, struct timespec t2, struct timespec *res)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  if (t2.tv_nsec < t1.tv_nsec) {
    // ajuste necessario, utilizando um segundo de tv_sec
    res->tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
    res->tv_sec = t2.tv_sec - t1.tv_sec - 1;
  } else {
    // nao e necessario ajuste
    res->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    res->tv_sec = t2.tv_sec - t1.tv_sec;
  }
}

int main(int argc, char **argv) {
  sortperf_t s;
  int *vet;
  char buf[200];
  char pref[100];
  opt_t opt;
  struct timespec inittp, endtp, restp;
  int retp;

  // parse_args
  parse_args(argc, argv, &opt);

  // malloc with opt.size+1 for heapsort
  vet = (int *)malloc((opt.size + 1) * sizeof(int));

  // initialize
  resetcounter(&s);
  srand48(opt.seed);
  initVector(vet, opt.size);
  vet[opt.size] = vet[0]; // for heapsort

  retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

  // execute algorithm
  switch (opt.alg) {
  case ALGINSERTION:
    insertionSort(vet, 0, opt.size, &s);
    break;
  case ALGSELECTION:
    selectionSort(vet, 0, opt.size, &s);
    break;
  case ALGQSORT:
    quickSort(vet, 0, opt.size - 1, &s);
    break;
  case ALGQSORT3:
    quickSort3(vet, 0, opt.size - 1, &s);
    break;
  case ALGQSORTINS:
    quickSortIns(vet, 0, opt.size - 1, &s);
    break;
  case ALGQSORT3INS:
    quickSort3Ins(vet, 0, opt.size - 1, &s);
    break;
  case ALGHEAPSORT:
    heapSort(vet, opt.size, &s);
    break;
  case ALGRECSEL:
    recursiveSelectionSort(vet, 0, opt.size - 1, &s);
    break;
  }
  retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
  clkDiff(inittp, endtp, &restp);

  sprintf(pref, "alg %s seed %d size %d time %ld.%.9ld", num2name(opt.alg),
          opt.seed, opt.size, restp.tv_sec, restp.tv_nsec);

  printsortperf(&s, buf, pref);
  printf("%s\n", buf);

  exit(0);
}
