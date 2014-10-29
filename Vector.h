typedef struct _vec{
	int size;
	int * elem;
	int capacity;
} Vector;

// 初始化
void initVector(Vector * vec , int capacity);
// 扩容
void expand(Vector * vec);
// 插入
void insert(Vector * vec , int e);
// 插入
void insert2(Vector * vec , int e,unsigned int i);
// 删除 范围删除
void deleteRange(Vector * vec,unsigned int lo,unsigned int high);
// 单个删除
void deleteSingle(Vector * vec,unsigned int i);
// 查找
int find(Vector * vec,unsigned int i);
// 去重
void reduplicate(Vector * vec);
// 查看是否有序
int disortered(Vector * vec);
// 对有序向量去重 ，时间复杂度为O(n)
int uniquify(Vector * vec);
// 排序
void sort(Vector * vec);
// 二分查找 lo = 0 hi = length
int binSearch(Vector * vec,int lo,int hi,int x);
void vec_swap(int * x , int * y);
void printVector(Vector * vec );