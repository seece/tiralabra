#ifndef TRIE_H_
#define TRIE_H_

#include <stdint.h>
#include <stdbool.h>

// Used in Node.value field to mark a non-leaf node
#define NODE_VALUE_NONE -1

struct Node {
	struct Node* left;
	struct Node* right;
	int32_t weight;
	int32_t value;
};

struct SymbolCode {
	uint32_t code;
	int32_t length;
};

struct Node* node_new(void);
void node_del(struct Node* node);
struct Node* node_join(struct Node* left, struct Node* right);
bool node_is_leaf(struct Node* node);
struct SymbolCode node_get_code(struct Node* root, int32_t value);
int32_t node_count_leaf_nodes(struct Node* node);
#endif
