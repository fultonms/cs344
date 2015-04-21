using namespace std;

template <class T>
BST<T>* BST<T>::insert(const T &value){
	if(this->getValue() < value){
		if(this->getRight() == NULL){
			this->setRight(new BST<T>(value, NULL, NULL, this));
		}
		else{
			BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
			this->setRight(right->insert(value));	
		}
	}
	else if(this->getValue() > value){
		if(this->getLeft() == NULL){
			this->setLeft( new BST<T>(value, NULL, NULL, this));
		}
		else{
			BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());
			this->setLeft(left->insert(value));
		}
	}

	return this;
}

template <class T>
BST<T>* BST<T>::search(const T &value){

	if(this->getValue() == value)
		return this;
	else if(this->getValue() > value && this->getLeft() != NULL){
		BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());
		return left->search(value);
	}
	else if(this->getValue() < value && this->getRight() != NULL){	
		BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
		return right->search(value);
	}
	else 
		return NULL;
}

template <class T>
BST<T>* BST<T>::remove(const T &value){
	if(this->getValue() == value){
		if(this->getRight() == NULL && this->getLeft() == NULL){
			BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
			if(parent != NULL){
				if( parent->getLeft() == this)
					parent->setLeft(NULL);

				else if(parent->getRight() == this)
					parent->setRight(NULL);

				return parent;
			}
			else
				return NULL;
			
			
		}
		else if( this->getRight() != NULL){
			BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
			BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());
			
			right->setParent(parent);
			return right;
		}
		else if( this->getLeft() != NULL){
			BST<T>* parent = dynamic_cast<BST<T>*>(this->getParent());
			BST<T>* left = dynamic_cast<BST<T>*>(this->getLeft());

			left->setParent(parent);
			return left;
		}
		else{
			BST<T>* next = dynamic_cast<BST<T>*>(this->successor());
			BST<T>* right = dynamic_cast<BST<T>*>(this->getRight());

			T val = next->getValue();
			right = right->remove(next->getValue());
			return this;
		}
	}
	else if(this->getValue() > value && this->getLeft() != NULL){
		BST<T>* next = dynamic_cast<BST<T>*>(this->getLeft());
		return next->remove(value);
	}
	else if(this->getValue() < value && this->getRight() != NULL){
		BST<T>* next = dynamic_cast<BST<T>*>(this->getRight());
		return next->remove(value);
	}
	else
		return NULL;
	
}
