/*
CS344 A2 Michael Fulton and David Josephs

Binary Search Trees
*/

using namespace std;

template <class T>
BST<T>* BST<T>::insert(const T &v){
	//The value should be inserted to the right.
	if(this->getValue() < v){
		if(this->getRight() == NULL){
			this->setRight(new BST<T>(v, NULL, NULL, this));
		}
		else{
			BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
			this->setRight(right->insert(v));	
		}
	}

	//The value should be inserted to the left.
	else if(this->getValue() > v){
		if(this->getLeft() == NULL){
			this->setLeft( new BST<T>(v, NULL, NULL, this));
		}
		else{
			BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());
			this->setLeft(left->insert(v));
		}
	}

	return this;
}

template <class T>
BST<T>* BST<T>::search(const T &v){

	//Here is the value;
	if(this->getValue() == v)
		return this;

	//It's to the left.
	else if(this->getValue() > v && this->getLeft() != NULL){
		BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());
		return left->search(v);
	}

	//It's to the right;
	else if(this->getValue() < v && this->getRight() != NULL){	
		BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
		return right->search(v);
	}

	//That value isn't in the tree.
	else 
		return NULL;
}

template <class T>
BST<T>* BST<T>::remove(const T &v){
	
	//This node is the one that we want to delete.
	if(this->getValue() == v){
		//The node is a leaf node.
		if(this->getRight() == NULL && this->getLeft() == NULL){
			//This node is root.
			if(this->getParent() == NULL)
				return NULL;
			else{
				BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
				
				///This node is a right child.
				if(parent->getRight() == this){
					parent->setRight(NULL);
					delete this;
					return parent;
				}

				//This node is a left child.
				else if(parent->getLeft() == this){
					parent->setLeft(NULL);
					delete this;
					return parent;
				}

				///Something's gone horribly wrong.
				else
					exit(1);
			}
		}
	
		//Node has only a left child.
		else if(this->getLeft() != NULL && this->getRight() == NULL){
			BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
			BST<T>* child = dynamic_cast<BST<T>*>(this->getLeft());

			//This node is the root.
			if(parent == NULL){
				child->setParent(NULL);
				delete this;
				return child;
			}
	
			//This note is not root.
			else{
				//This node is the left child.
				if(parent->getLeft() == this)
					parent->setLeft(child);
				//This node is the right child.
				else
					parent->setRight(child);
	
				child->setParent(parent);
				delete this;
				return parent;
			}
		}

		//Node has only a right child.
		else if(this->getRight() != NULL && this->getLeft() ==NULL){
			BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
			BST<T>* child = dynamic_cast<BST<T>*>(this->getRight());
			
			//This node is the root.
			if(parent == NULL){
				child->setParent(NULL);
				delete this;
				return child;
			}
			
			//Thjs node is not root.
			else{
				//This node is the right child.
				if(parent->getRight() == this)
					parent->setRight(child);
				//This node is the left child.
				else
					parent->setLeft(child);
	
				child->setParent(parent);
				delete this;
				return parent;
			}
		}

		//Node has two children.
		else if(this->getRight() != NULL && this->getLeft() != NULL){
			BST<T>* successor = dynamic_cast<BST<T>*>(this->successor());
			
			T val = successor->getValue();
			this->remove(val);
			this->setValue(val);
			
			return this;
		}
	}

	//The node we want to delete is to the left.
	else if(this->getValue() > v && this->getLeft() != NULL){
		BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());
		BST<T>* next = dynamic_cast<BST<T>*>(left->remove(v));
		if(next->getParent() == NULL || next == NULL)
			return next;

		BST<T>* parent = dynamic_cast<BST<T>*>(next->getParent());
		return parent;
	}

	//The node we want to delete is to the right.
	else if(this->getValue() < v && this->getRight() != NULL){
		BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
		BST<T>* next = dynamic_cast<BST<T>*>(right->remove(v));
		if(next->getParent() == NULL || next == NULL)
			return next;
		
		BST<T>* parent = dynamic_cast<BST<T>*>(next->getParent());
		return parent;
	}

	//The node we want to delete doesn't exist.
	else
		return NULL;
}
