#ifndef LINKLIST
#define LINKLIST
namespace MyLinkList{

	template<class T>
	class LinkList{

		/* Stores length of the LinkList */
		int len;

		/* Node of the link list that stores the information*/
		struct Node{
			T *data;
			Node *next;
			Node(T *dat, Node *nxt):data(dat),next(nxt){}
			~Node(){}
			}*head;
		public:

		/* Defining our own iterator*/
			class iterator;
			friend class iterator;
		
		/* Definition of iterator class */
			class iterator{
				LinkList &l;
				Node *index;
				public:
					iterator(LinkList& L):l(L),index(L.head){}
					iterator(LinkList &L, Node* ind):l(L),index(ind){}
					iterator(const iterator& I):l(I.l),index(I.index){}
					~iterator(){}

					const iterator operator + (int i){
						Node *temp = l.head;
						for(int ii =0 ; ii < i; ii++){

						/* checks if adding i excees the the lenght of the link list */ 
							if(!temp){
								std::cout<<"Addition of the "<< i<<" is not desired"<<std::endl;
								exit(0);
							}else{
								temp = temp->next;
							}
						}
						return iterator(l, temp);
					} 

					/* checks if two iterators are equal */							 
					bool operator == (const iterator &I) const{
						return index == I.index;
					}

					/* checks if two iterators are not equal */
					bool operator != (const iterator &I) const{
						return index != I.index;
					}
					
					/* Assignment operarot for iterator*/
					iterator & operator = (const iterator &I){
						l = I.l;
						index = I.index;
						return *this;
					}
						
					/* Pre increment operator for iterator */
					iterator& operator ++(){

						/* Checks if increment is valid or not */
						if(!index){
							std::cout<<"Invalid movement"<<std::endl;
						}
						index = index->next;
						return *this;
					}

					/* Post increment operator for iterator */
					iterator operator ++(int){
						iterator temp = *this;
						operator ++();
						return temp;
					}

					/* Dereference operator for the node of the link list using iterator */
					T& operator * (){
						static T* dummy = NULL;
						if(!index) return *dummy;
						return *(index->data);
					}
					
					/* Over loading Sub script operator.
					   it prints if the node exists else print error messege*/
					T& operator [] (int i){
						static T *dummy = NULL;
						Node *temp = l.head;
						for(int ii = 0; ii < i && temp ; ii++){
							temp = temp->next;
						}

						if(temp)
						return *(temp->data);
						else{
							std::cout<<"Out of bound"<<std::endl;
							exit(0);
						}
					}

					
};
			/* LinkList Constructor*/
			LinkList():head(0),len(0){}

			/* Copy Constructor for Link List */
			LinkList(LinkList &l):head(l.head){}

			/* Overloading Assignment Operator for the LinkList */
			LinkList& operator = (const LinkList &l){
				head = l.head;
				return *this;
			}

			/* LinkList Destructor */
			~LinkList();

			/* Method that insert node into LinkList */
			void Insert_Data(T *dat);

			/* Print the Entire LinkList */
			void Print_List();

			/* Removed the Node with Matched Key from the LinkList*/
			void Remove_Key(T *dat);

			/* Returns the iterator pointing the beginning of the LinkList */
			const iterator isbegin(){
				return iterator(*this);
			}

			/* Returns the iterator pointing to the end of the LinkList node */		
			const iterator isend(){
				return iterator(*this,0);
			}

			/* Returns the length of the LinkList */
			int length(){
				return len;
			}
	};


	/*LinkList Destructor Defintion*/
	/* Cleans up all the allocated memory*/
	template <class T> LinkList <T>::~LinkList(){
		Node *temp;
		while(head){
			temp=head;
			head=head->next;
			delete temp->data;
			delete temp;
		}
	}

/*Inserting into head of the LinkList*/
template <class T> void LinkList <T>::Insert_Data(T *dat){
	head = new Node(dat, head);
	len++;
}

/* Printing the data in LinkList*/
template <class T> void LinkList<T>::Print_List(){
	Node *temp = head;
	using namespace std;
	while(temp){
		std::cout << temp->data <<std::endl;
		temp = temp->next;
	}
}

/*Removing the node with the matched key from the LinkList; Also removes all the key with matched key*/
template <class T> void LinkList <T>::Remove_Key(T *data){
	bool flag;
	if(*(T*)head->data == *(T*)data){
		Node *temp = head;
		head = head->next;
		delete temp->data;
		delete temp;
		len--;
		flag = true;
	}
		Node *temp1;
		Node *temp2=head;
		while(temp2){
			if(*(T*)temp2->data == *(T*)data){
				flag=true;
				temp1->next = temp2->next;
				delete temp2->data;
				delete temp2;
				temp2=temp1->next;
				len--;
			}
			else{
			temp1=temp2;
			temp2=temp2->next;
			}
		}

	if(!flag){
		std::cout<<"Key not found"<<std::endl;
	}
delete data;
}
}
#endif	
