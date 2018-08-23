void removeFollowingEvens(ListType &list) {

	/*ListType first = list;
	while(list->next != NULL){
		//if(list->next == NULL){
			cout<<list->next<<endl;
		//}
		list = list->next;
	}*/

	ListType first = list;
	ListType temp = list;
	while(temp->next != NULL){
		//cout<<"data: "<<list->data<<endl;
		if(temp->data % 2 == 0){
			
			ListType p = temp;
			ListType q = temp;
			q = temp->next;
			
			if(q->data%2 == 0){
				cout<<"q data:"<<q->data<<endl;
				if(q->next == NULL){
					
					cout<<"I am in Null"<<endl;
					list = temp;
					list = list->next;
					cout<<list->data<<endl;
					if(list->next == NULL){
						cout<<"NULL it is"<<endl;
					}
					delete list;
					cout<<list->data<<endl;
					break;
				}
				else{
					
					list = temp;
					p->next = temp->next->next;
					delete list->next;
				}	
				temp = p;
			}
			else{
				temp = temp->next;
			}
		}
		else{
			temp = temp->next;
		}
	}
	
	list = first;
	
}