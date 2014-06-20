
/* Name @Sangeet Dahal
   Demonstration of generic LinkedList in C++ and walking through the LinkedList
   using iterator design pattern. In this example I have taken data class as a 
   node of LinkedList. Each instance of Data class is instantiated from the heap
   using simple factory design pattern
*/


#include <iostream>
#include<cstdio>
#include<cstdlib>
#include "linklist.h"
#include "data.h"

using namespace MyLinkList;


int main(){

	LinkList <Data> L;

	L.Insert_Data(Data::create(2,3));
	L.Insert_Data(Data::create(4,5));
	L.Insert_Data(Data::create(5,6));
	L.Insert_Data(Data::create(6,7));
	L.Insert_Data(Data::create(7,8));
	

	LinkList <Data>::iterator p = L;

	std::cout<<"Printing Array subscripting to print using iterator"<<std::endl;
	std::cout<<"___________________________________________________________"<<std::endl;
	for(int i=0;i<L.length();i++)
		std::cout<<p[i];

	/*Iterator does not work when the first node is removed from the LinkedList as there
	  is no way to fix the head pointer later. However it can be fixed using some dummy
	  node with null data. This approach will always create dummy node as a first node.*/

	L.Remove_Key(Data::create(2,3));

	std::cout<<std::endl<<"Using Dereference (pointer like way) for printing LinkedList using iterator"<<std::endl;
	std::cout<<"___________________________________________________________________________"<<std::endl;
	while(p != L.isend())
		std::cout<<*p++;
		

return 0;
}
				
