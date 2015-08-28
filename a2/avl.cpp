/*
CS344 A2 Michael Fulton and David Josephs

AVL Trees
*/
using namespace std;

template <class T>
AVL<T>* AVL<T>::search(const T &v){

        //Here is the value;
        if(this->getValue() == v)
                return this;

        //It's to the left.
        else if(this->getValue() > v && this->getLeft() != NULL){
                AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());
                return left->search(v);
        }

        //It's to the right;
        else if(this->getValue() < v && this->getRight() != NULL){
                AVL<T>* right = dynamic_cast<AVL<T>*>(this->getRight());
                return right->search(v);
        }

        //That value isn't in the tree.
        else
                return NULL;
}

template <class T>
AVL<T> * AVL<T>::insert( const T &v ){
        //The value should be inserted to the right.

	if(this->getValue() == v)
		return this->balance();
        else if(this->getValue() < v){
                if(this->getRight() == NULL){
                        this->setRight(new AVL<T>(v, NULL, NULL, this));
			return this->balance();
                }
                else{
                        AVL<T>* right = dynamic_cast<AVL<T>*>(this->getRight());
                        return right->insert(v);
                }
        }

        //The value should be inserted to the left.
        else if(this->getValue() > v){
                if(this->getLeft() == NULL){
                       
			this->setLeft( new AVL<T>(v, NULL, NULL, this));
			return this->balance();
                }
                else{
                        AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());
                        return left->insert(v);
			
                }
        }
}

template <class T>
AVL<T> * AVL<T>::remove( const T &v ){
	
	//This node is the one that we want to delete.
	if(this->getValue() == v){
		//The node is a leaf node.
		if(this->getRight() == NULL && this->getLeft() == NULL){
			//This node is root.
			if(this->getParent() == NULL)
				return NULL;
			else{
				AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
				
				///This node is a right child.
				if(parent->getRight() == this){
					parent->setRight(NULL);
					delete this;
					return parent->balance();
				}

				//This node is a left child.
				else if(parent->getLeft() == this){
					parent->setLeft(NULL);
					delete this;
					return parent->balance();
				}

				///Something's gone horribly wrong.
				else
					exit(1);
			}
		}
	
		//Node has only a left child.
		else if(this->getLeft() != NULL && this->getRight() == NULL){
			AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
			AVL<T>* child = dynamic_cast<AVL<T>*>(this->getLeft());

			//This node is the root.
			if(parent == NULL){
				child->setParent(NULL);
				delete this;
				return child->balance();
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
				return parent->balance();
			}
		}

		//Node has only a right child.
		else if(this->getRight() != NULL && this->getLeft() ==NULL){
			AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
			AVL<T>* child = dynamic_cast<AVL<T>*>(this->getRight());
			
			//This node is the root.
			if(parent == NULL){
				child->setParent(NULL);
				delete this;
				return child->balance();
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
				return parent->balance();
			}
		}

		//Node has two children.
		else if(this->getRight() != NULL && this->getLeft() != NULL){
			AVL<T>* successor = dynamic_cast<AVL<T>*>(this->successor());
			
			T val = successor->getValue();
			this->remove(val);
			this->setValue(val);
			
			return this->balance();
		}
	}

	//The node we want to delete is to the left.
	else if(this->getValue() > v && this->getLeft() != NULL){
		AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());
		return left->remove(v);
	}

	//The node we want to delete is to the right.
	else if(this->getValue() < v && this->getRight() != NULL){
		AVL<T>* right = dynamic_cast<AVL<T>*>(this->getRight());
		return right->remove(v);
	}

	//The node we want to delete doesn't exist.
	else
		return this->balance();

}

template <class T>
AVL<T> * AVL<T>::balance(){
	AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
	AVL<T>* current = this;

	do{
		current->updateHeight();
		
		//Left Side too heavy.
		if(current->heightDifference() < -1){
			AVL<T>* left = dynamic_cast<AVL<T>*>(current->getLeft());
			
			//Needs Double right rotation
			if(left->heightDifference() > 1){
				left->rotateL();
			}
		
			current->rotateR();
		
		}

		//Right Side too heavy.
		else if(current->heightDifference() > 1){
			AVL<T>* right = dynamic_cast<AVL<T>*>(current->getRight());
				
			//needs Double left rotation
			if(right->heightDifference() < -1){
				right->rotateR();				
			}

			current->rotateL();

		}

		if(parent != NULL){
			current = parent;
			parent = dynamic_cast<AVL<T>*>(current->getParent());
		}

	}while(parent != NULL);
	cerr<<"BALANCE RETURNING "<<current<<" VALUE=" ;
	if(current != NULL)
		cerr<<current->getValue();
	else
		cerr<<"NULL";
	cerr<<endl;	

	return current;
}


template <class T>
void AVL<T>::rotateR(){
	AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());
	AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
	AVL<T>* leftRight = dynamic_cast<AVL<T>*>(left->getRight());

	left->setParent(parent);
	left->setRight(this);
	this->setParent(left);
	this->setLeft(leftRight);
	
	if(parent != NULL){
		if(parent->getLeft() == this)
			parent->setLeft(left);
		else
			parent->setRight(left);
	}
}

template <class T>
void AVL<T>::rotateL(){
	AVL<T>* right = dynamic_cast<AVL<T>*>(this->getRight());
	AVL<T>* parent = dynamic_cast<AVL<T>*>(this->getParent());
	AVL<T>* rightLeft = dynamic_cast<AVL<T>*>(right->getLeft());


	right->setParent(parent);
	right->setLeft(this);
	this->setParent(right);
	this->setRight(rightLeft);

	if(parent != NULL){
		if(parent->getLeft() == this)
			parent->setLeft(right);
		else
			parent->setRight(right);
	}
}

template <class T>
void AVL<T>::updateHeight(){
	AVL<T> * right = dynamic_cast<AVL<T>*>(this->getRight());
	AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());

        if (left == NULL && right == NULL){
                this->setHeight(0);
        }
        else if (left == NULL){
                right->updateHeight();
                this->setHeight( 1 + right->getHeight());
        }

        else if (right == NULL){
                left->updateHeight();
                this->setHeight(1 + left->getHeight());
        }

        else{
                left->updateHeight();
                right->updateHeight();
                this->setHeight(1 + max(left->getHeight(),right->getHeight()));
        }
}

template <class T>
int AVL<T>::heightDifference(){
	AVL<T>* right = dynamic_cast<AVL<T>*>(this->getRight());
	AVL<T>* left = dynamic_cast<AVL<T>*>(this->getLeft());

	int rHeight, lHeight;	

	if(left == NULL)
		lHeight = 0;
	else
		lHeight = left->getHeight();

	if(right == NULL)
		rHeight = 0;

	else
		rHeight = right->getHeight();
			
	return rHeight - lHeight;		
}
