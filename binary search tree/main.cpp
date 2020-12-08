//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

class TNode {

public:
	int Key;
	TNode* Left = nullptr;
	TNode* Right = nullptr;
	int height = 0; // h(v)
	int semipathLength = 0;
	int semipathsNumber = 0; // b(v)
	int semipathsFromParentNumber = 0; // a(v)
	int otherNodeSemipathLength = 0; // h'(v)
	int otherNodeSemipathNumber = 1; // l'(v)
	int leaves = 1; // l_h(v)
	TNode(int key) : Key(key) {}

};

class Tree {

	TNode* Root;

	static void DestroyNode(TNode* node) {
		if (node) {
			DestroyNode(node->Left);
			DestroyNode(node->Right);
			delete node;
		}
	}

public:
	Tree() : Root(0) {}

	~Tree() {
		DestroyNode(Root);
	}

	void Insert(int x) {
		TNode** cur = &Root;
		while (*cur) {
			TNode& node = **cur;
			if (x < node.Key) {
				cur = &node.Left;
			}
			else if (x > node.Key) {
				cur = &node.Right;
			}
			else {
				return;
			}
		}
		*cur = new TNode(x);
	}

	TNode* getRoot() {
		return Root;
	}

	int getKey() {
		return Root->Key;
	}

	void replace_child(TNode* parent, TNode* oldNode, TNode* newNode) {
		if (!parent)
			Root = newNode;
		else if ((*parent).Left == oldNode)
			(*parent).Left = newNode;
		else if ((*parent).Right == oldNode)
			(*parent).Right = newNode;
	}

	void right_deletion(int x) {
		TNode* parent = nullptr;
		TNode* cur = Root;
		TNode* result = nullptr;
		TNode* minNodeParent = nullptr;
		TNode* minNode = nullptr;
		while (true) {
			if (!cur) {
				return;
			}
			if (x < (*cur).Key) {
				parent = cur;
				cur = (*cur).Left;
			}
			else if (x > (*cur).Key) {
				parent = cur;
				cur = (*cur).Right;
			}
			else {
				break;
			}
		}
		if (!cur->Left)
			result = cur->Right;
		else if (!cur->Right)
			result = cur->Left;
		else {
			minNodeParent = cur;
			minNode = cur->Right;
			while (minNode->Left) {
				minNodeParent = minNode;
				minNode = minNode->Left;
			}
			result = cur;
			cur->Key = minNode->Key;
			replace_child(minNodeParent, minNode, minNode->Right);
		}
		replace_child(parent, cur, result);
	}

    int setHeightsAndLeavesAndMax(TNode* cur, TNode* leftChild, TNode* rightChild) {
	    int max = 0;
        if(cur) {
            int left;
            int right;
            if(leftChild) {
                left = setHeightsAndLeavesAndMax(leftChild, leftChild->Left, leftChild->Right);
                if(left > max)
                    max = left;
            }
            if(rightChild) {
                right = setHeightsAndLeavesAndMax(rightChild, rightChild->Left, rightChild->Right);
                if(right > max)
                    max = right;
            }
            if (!leftChild && !rightChild) {
                return max;
            } else if (!leftChild) {
                cur->height = rightChild->height + 1;
                cur->leaves = rightChild->leaves;
                cur->semipathLength = rightChild->height + 1;
                max = cur->semipathLength;
            } else if (!rightChild) {
                cur->height = leftChild->height + 1;
                cur->leaves = leftChild->leaves;
                cur->semipathLength = leftChild->height + 1;
                max = cur->semipathLength;
            } else { // left and right children are not null
                if (rightChild->height > leftChild->height) {
                    cur->height = rightChild->height + 1;
                    cur->leaves = rightChild->leaves;
                } else if (leftChild->height > rightChild->height) {
                    cur->height = leftChild->height + 1;
                    cur->leaves = leftChild->leaves;
                } else {
                    cur->height = leftChild->height + 1;
                    cur->leaves = rightChild->leaves + leftChild->leaves;
                }
                cur->semipathLength = leftChild->height + rightChild->height + 2;
                max = cur->semipathLength;
            }
        }
        return max;
    }

	void differentMaxSemipathsCurIsRootFor(TNode* cur, int max) {
	    if(cur) {
	        if(cur->semipathLength == max) {
	            if(cur->Left && cur->Right)
	                cur->semipathsNumber = cur->Left->leaves * cur->Right->leaves;
	            else if(cur->Left)
	                cur->semipathsNumber = cur->Left->leaves;
	            else if(cur->Right)
	                cur->semipathsNumber = cur->Right->leaves;
	        }
	        differentMaxSemipathsCurIsRootFor(cur->Left, max);
	        differentMaxSemipathsCurIsRootFor(cur->Right, max);
	    }
	}

    void semipathsCurIsNotRoot(TNode* cur) {
        if(cur) {
            if(cur->Left || cur->Right) {
                if(!cur->Left) {
                    cur->Right->otherNodeSemipathNumber = cur->otherNodeSemipathNumber;
                    cur->Right->otherNodeSemipathLength = cur->otherNodeSemipathLength + 1;
                }
                if(!cur->Right) {
                    cur->Left->otherNodeSemipathNumber = cur->otherNodeSemipathNumber;
                    cur->Left->otherNodeSemipathLength = cur->otherNodeSemipathLength + 1;
                }
                if(cur->Left && cur->Right) {
                    if(cur->otherNodeSemipathLength == cur->Right->height + 1) {
                        cur->Left->otherNodeSemipathLength = cur->Right->height + 2;
                        cur->Left->otherNodeSemipathNumber = cur->otherNodeSemipathNumber + cur->Right->leaves;
                    }
                    else if(cur->otherNodeSemipathLength < cur->Right->height + 1) {
                        cur->Left->otherNodeSemipathLength = cur->Right->height + 2;
                        cur->Left->otherNodeSemipathNumber = cur->Right->leaves;
                    }
                    else if(cur->otherNodeSemipathLength > cur->Right->height + 1) {
                        cur->Left->otherNodeSemipathLength = cur->otherNodeSemipathLength + 1;
                        cur->Left->otherNodeSemipathNumber = cur->otherNodeSemipathNumber;
                    }
                    if(cur->otherNodeSemipathLength == cur->Left->height + 1) {
                        cur->Right->otherNodeSemipathLength = cur->Left->height + 2;
                        cur->Right->otherNodeSemipathNumber = cur->otherNodeSemipathNumber + cur->Left->leaves;
                    }
                    else if(cur->otherNodeSemipathLength < cur->Left->height + 1) {
                        cur->Right->otherNodeSemipathLength = cur->Left->height + 2;
                        cur->Right->otherNodeSemipathNumber = cur->Left->leaves;
                    }
                    else if(cur->otherNodeSemipathLength > cur->Left->height + 1) {
                        cur->Right->otherNodeSemipathLength = cur->otherNodeSemipathLength + 1;
                        cur->Right->otherNodeSemipathNumber = cur->otherNodeSemipathNumber;
                    }
                }
            }
            semipathsCurIsNotRoot(cur->Left);
            semipathsCurIsNotRoot(cur->Right);
        }
    }

	void setParentSemipaths(TNode* cur, TNode* parent, int max) {
/* maximum semipath parent has
		 how much of them parent has
		 does cur have a brother
		 if no then cur->parentSemipaths = parent->semipaths
		 if yes then cur->parentSemipaths = parent->semipaths - 1*/
		if(cur) {
            if (parent) {
               if(cur->otherNodeSemipathLength + cur->height == max) {
                   cur->semipathsFromParentNumber = cur->otherNodeSemipathNumber * cur->leaves;
               }
            }
            setParentSemipaths(cur->Left, cur, max);
            setParentSemipaths(cur->Right, cur, max);
        }
		if(!Root->Left && !Root->Right) {
		    Root->semipathsNumber = 1;
		}
	}

	void output(TNode* cur) {
        if(cur) {
            cout << cur->Key << " " << cur->semipathsFromParentNumber + cur->semipathsNumber << endl;
            output(cur->Left);
            output(cur->Right);
        }
    }
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x; // will also become max
	Tree tree;
	while (cin >> x) {
		tree.Insert(x);
	}
	tree.right_deletion(tree.getKey());
    x = tree.setHeightsAndLeavesAndMax(tree.getRoot(), tree.getRoot()->Left, tree.getRoot()->Right);
	tree.differentMaxSemipathsCurIsRootFor(tree.getRoot(), x);
	tree.semipathsCurIsNotRoot(tree.getRoot());
	tree.setParentSemipaths(tree.getRoot(), nullptr, x);
	tree.output(tree.getRoot());
	return 0;
}