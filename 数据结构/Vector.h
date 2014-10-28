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
void printVector(Vector * vec );