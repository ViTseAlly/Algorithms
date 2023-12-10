#include <iostream>




struct Node														                               	//--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+//
{																	                                    //						             STRUCTURE NODES						               	//
	char current;												                              	//			Structure creates new data type, where saved nodes			      //
	Node* next;													                              	//			values and pointers.										                      //
	Node() {};													                              	//																		                                //
	Node(char curV, Node* nextV) : current(curV), next(nextV){};       	//                                																		//
};																	                                  //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+//


class LinkedList													                            //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+//
{																	                                    //																	                                 	//
public:																                                //							            LINKED LIST CLASS					            		//
	LinkedList() : node(nullptr) {};								                    //			Constructors, destructors, fields and linked list			        //
	~LinkedList();													                            //			methods are declared here.							                  		//
	void addNode(char value);										                        //																	                                	//
	void getNodes();												                            //																                                 		//
private:														                                 	//																	                                	//
	Node* node;												                              		//																		                                //
};																                                  	//--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+//


LinkedList::~LinkedList()											                        //--+--+--+--+--+--+--+--+--+--+--+--+--+--+- -+--+--+--+--+--+--+--+--+//
{																	                                    //								            DESTRUCTOR							                 //
	Node* current = node;									                          		//			             FREEING MEMORY (DELETING ALL LIST NODES)          //
	while (current != nullptr)							                      			//			      Finding all Nodes and deleting him. Freeing memory.		   //
	{																                                    //																	                                   //
		Node* next = current->next;						                      			//			    [1] -> [2] -> [3] -> [4] -> [n]... -> [nullptr]			       //
		delete current;											                            	//			    ^	^	^	^	^										                               //
		current = next;											                            	//		  delete node -> move -> delete node -> move ....				         //
	}															                                    	//	   Big O notation:	 O(n)										                       //
}																                                    	//--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-//


																	                                    //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-//
void LinkedList::addNode(char value)								                  //																		                                 //
{																	                                    //	                ADDED ELEMENT AT LINKED LIST AD END					       //
	Node* cur = new Node(value, nullptr);							                  //			Code checked head Node element, if element not find			       //
	if (node == nullptr) node = cur;							                    	//			code replace head at new Node. Else -> find end list		       //
	else                                                                //			and added element in end.									                     //
	{																                                    //																		                                 //
		Node* current = node;										                          //			  [1] -> [2] -> [3] -> [4] -> [n]... -> [nullptr]			         //
		while (current->next != nullptr)						                    	//														^				                                 //
		{															                                    //														|				                                 //
			current = current->next;								                        //											Here add new Node element	                     //
		}															                                    //																		                                 //
		current->next = cur;										                          //		Big O notation:    O(n)											                     //
	}																                                    //																		                                 //
}																	                                    //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-//


void LinkedList::getNodes()											                      //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-//
{																	                                    //																		                                 //
	Node* value = node;												                          //					DISPLAYS ALL ITEMS OF A LINKED LIST					               //
	while (value != nullptr)										                        // 			Finding Node by pointer and print Node value				           //
	{																                                    //																		                                 //
		std::cout << value->current;							                      	//			[1] -> [2] -> [3] -> [4] -> [n]... -> [nullptr]				         //
		value = value->next;										                          //			print -> find -> print -> find -> ....						             //
	}																                                    //		Big O notation:    O(n)											                     //
}																	                                    //--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-//


int main()
{
	LinkedList linkedList;
	linkedList.addNode('H');
	linkedList.addNode('e');
	linkedList.addNode('l');
	linkedList.addNode('l');
	linkedList.addNode('o');
	linkedList.addNode(' ');
	linkedList.addNode('w');
	linkedList.addNode('o');
	linkedList.addNode('r');
	linkedList.addNode('l');
	linkedList.addNode('d');
	linkedList.addNode('!');

	linkedList.getNodes();
	return 0;
}

