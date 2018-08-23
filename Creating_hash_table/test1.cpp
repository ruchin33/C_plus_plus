bool remove(ListType &list, const string &key) {

  	if (list == NULL) {
    	return false;
  	}
  
  	if (list->next == NULL) {   // only one element in list
    	if(list->key == key) {
			delete list;
			list = NULL;
			return true;
		}
  	}
  
  	int count = 0;
  
  	ListType p = list;
  	ListType prev = NULL;
  
  	while (p != NULL) {
	  
		count++;
		  
    	if(p->key == key) {
		
			if (count == 1) {			// one element in list
				ListType nextGuy = p->next;
				delete p;
				list = nextGuy;
			}
			else if (p->next == NULL && count != 1) {	// last element in list
				delete p;
				prev->next = NULL;
			}
			else {
				ListType nextGuy = p->next;
				delete p;
				prev->next = nextGuy;
			}
			return true;
		}
	
		prev = p;
    	p = p->next;
	}
	
  	return false;
  
}



//mine first

bool remove(ListType &list, const string &target) {

  	if (list == NULL) {
    	return false;
  	}
  
  	if (list->next == NULL) {   // only one element in list
    	if(list->key == key) {
			delete list;
			list = NULL;
			return true;
		}
		else{
			return false;
		}
  	}
  
  	int count = 0;
  
  	ListType p = list;
  	ListType prev = NULL;
  
  	while(p != NULL){
  		count++;
  		if(count == 1){ 
  			if(p->key == target){
  				Node *q = p->next;
  				delete p;
  				list =  q;
  				return true;
  			}
  		}
  		else if(count != 1){
  			if(p->next == NULL){  //last element
  				if(p->key == target){
  					delete p;
  					prev->next = NULL;
  					return true;
  				}
  			}
  			else{                //any other element
  				if(p->key == target){
  					Node *q = p->next;
  					delete p;
  					prev->next = q;
  					return true;
  				}
  			}
  		}
  		else{
  			return false;
  		}
  		
  		prev = p;
    	p = p->next;
  		
  	}
  	
}

  
// mine 2

bool listRemove(ListType &list, const string &target) {

  	if (list == NULL) {
    	return false;
  	}
  
  	if (list->next == NULL) {   // only one element in list
    	if(list->key == target) {
			delete list;
			list = NULL;
			return true;
		}
		else{
			return false;
		}
  	}
  
  	int count = 0;
  
  	ListType p = list;
  	ListType prev = NULL;
  
  	while(p != NULL){
  		count++;
  		if(count == 1){ 
  			if(p->key == target){
  				Node *q = p->next;
  				delete p;
  				list =  q;
  				return true;
  			}
  		}
  		else if(count != 1){
  			if(p->next == NULL){  //last element
  				if(p->key == target){
  					delete p;
  					prev->next = NULL;
  					return true;
  				}
  			}
  			else{                //any other element
  				if(p->key == target){
  					Node *q = p->next;
  					delete p;
  					prev->next = q;
  					return true;
  				}
  			}
  		}
  		else{
  			return false;
  		}
  		
  		prev = p;
    	p = p->next;
  		
  	}
  	return false;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
}