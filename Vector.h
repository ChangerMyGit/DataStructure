#define MAX_SIZE 100
typedef struct _vec{
	int size;
	int * elem;
	int capacity;
} Vector;

// ��ʼ��
void initVector(Vector * vec , int capacity);
// ����
void expand(Vector * vec);
// ����
void insert(Vector * vec , int e);
// ����
void insert2(Vector * vec , int e,unsigned int i);
// ɾ�� ��Χɾ��
void deleteRange(Vector * vec,unsigned int lo,unsigned int high);
// ����ɾ��
void deleteSingle(Vector * vec,unsigned int i);
// ����
int find(Vector * vec,unsigned int i);
// ȥ��
void reduplicate(Vector * vec);
// �鿴�Ƿ�����
int disortered(Vector * vec);
// ����������ȥ�� ��ʱ�临�Ӷ�ΪO(n)
int uniquify(Vector * vec);
// ����
void sort(Vector * vec);
// ���ֲ��� lo = 0 hi = length
int binSearch(Vector * vec,int lo,int hi,int x);
// ���ֲ��� lo = 0 hi = length-1
int binSearch2(Vector * vec,int lo,int hi,int x);
// 쳲���������
int fibonacciSearch(Vector * vec,int x);
//����쳲���������  
void fibonacci(int *f);   
// �滻
void vec_swap(int * x , int * y);
void printVector(Vector * vec );