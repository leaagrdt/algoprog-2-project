typedef struct node
{
	int info;
	struct node* next;
} node;

typedef struct head_node
{
	node* head;
} head_node;


node* new_node(int Info);
void free_node(head_node* head);
void print_node(head_node head);
void stack_node(head_node* Head, int Info);
void queue_node(head_node* Head, int Info);
bool supp_node(head_node* Head, int info);

//========================================
typedef struct G_al
{
	int n;
	head_node* adj_list;	
} G_al;

G_al* init_G_al(int N);
G_al* extract_G_al_from_file(char* filename);

//=========================================
typedef struct G_m
{
	int n;
	int** matrix;
} G_m;

G_m* init_G_m(int N);
G_m* extract_G_m_from_file(char* filename);