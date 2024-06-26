/* tree.h */

#include <string.h>
#include <getopt.h>

typedef enum {
  Type, Void, If, Else, While, Return, Or, And,
  Character, Addsub, Divstar,
  Order, Eq,
  Ident,
  Num,
  Corps,
  instructions,
  Prog,
  None,
  Function,
  Parameters,
  Equals,
  Array,
  Global_vars,
  Functions,
  Not
} label_t;

typedef struct Node {
  label_t label;
  struct Node *firstChild, *nextSibling;
  int lineno;
  int num;
  char * ident;
} Node;

Node *makeNode(label_t label);
void addSibling(Node *node, Node *sibling);
void addChild(Node *parent, Node *child);
void deleteTree(Node*node);
void printTree(Node *node);
void parse_args(int argc, char *argv[], Node * node);
void help();

#define FIRSTCHILD(node) node->firstChild
#define SECONDCHILD(node) node->firstChild->nextSibling
#define THIRDCHILD(node) node->firstChild->nextSibling->nextSibling
