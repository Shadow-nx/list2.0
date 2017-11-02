#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	int data;
	Node *next;
};
void show_list(Node *curr) {
	if(curr != nullptr) {
		do {
			cout<<curr->data;
			if(curr->next!=nullptr)
				cout<<" -> ";
			curr=curr->next;
		} while (curr!=nullptr);
		cout<<endl;
	} else
		cerr<<"list is empty"<<endl;
}
void check_numbers(char *argv,int *&numbers_array,int *numbers_count) {
	for(int i=0; i<strlen(argv); i++) {
		if(argv[i]>='0'&& argv[i]<='9')
			;
		else (*numbers_count)++;
	}
	(*numbers_count)++;

	numbers_array=new int[(*numbers_count)];

	for(int i=0; i<(*numbers_count); i++) {
		numbers_array[i]=0;
	}
	int y=0;
	for(int i=0; i<strlen(argv)+1; i++)
		if(argv[i]>='0'&&argv[i]<='9')
			numbers_array[y]=numbers_array[y]*10+argv[i]-'0';
		else y++;

}


void fill_array(int numbers_array[],int argc,char **argv) {
	for(int i=0; i<argc-1; i++)
		numbers_array[i]=atoi(argv[i+1]);
}

Node* fill_list(int numbers_array[],int numbers_count) {
	Node *first=nullptr;
	Node *current=nullptr;
	for(int i=0; i<numbers_count; i++) {
		Node *node=new Node {numbers_array[i],nullptr};
		if(current == nullptr) {
			current=node;
			first=current;
			continue;
		}
		current->next = node;
		current = node;
	}
	return first;
}


void print_menu() {
	cout<<"choise operation"<<endl;
	cout<<"1: show list"<<endl;
	cout<<"2: add element to list"<<endl;
	cout<<"3: delete element from list"<<endl;
	cout<<"4: find an element of list"<<endl;
	cout<<"5: Replace the item with another one"<<endl;
	cout<<"6: sort list"<<endl;
	cout<<"7: finish programm"<<endl;
	cout<<endl;
}

int main(int argc,char *argv[]) {
	int *numbers_array=nullptr;
	int numbers_count=0;
	if(argc == 2) {
		check_numbers(argv[1],numbers_array,&numbers_count);
	} else if(argc>2) {
		numbers_count=argc-1;
		numbers_array=new int[numbers_count];
		fill_array(numbers_array,argc,argv);
	}

	Node *first=fill_list(numbers_array,numbers_count);

	int choice=0;
	do {
		print_menu();
		cin>>choice;
		Node *curr=first;
		switch(choice) {
			case 1:
				show_list(curr);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
		cout<<endl;
	} while(choice!=7);
	return 0;
}
