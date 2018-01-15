#include "Tree.h"
Tree::Tree()
{
	Tree::son=NULL;
	Tree::brother=NULL;
	Tree::fath=NULL;
	Tree::lvl=0;
	Tree::root=NULL;
}


istream& operator>>(istream& cin, Tree& d)
{
	cin>>d.info;
	return cin;
}

Tree &Tree::operator()(int lvl, int elem)
{
	Tree* Pointer=root;
	Tree* temp=NULL;
	Tree* temp2=NULL;
	bool found=0;
	int l=lvl;
	int e=elem;
	if(lvl==0) return *Pointer;
	if(lvl==1)
	{
		Pointer=Pointer->son;
		if(Pointer==NULL) return *Pointer;
		for(int i=0; i<elem; i++)
		{
			Pointer=Pointer->brother;
			if(Pointer==NULL) return *Pointer;
		}
		return *Pointer;
	}
	temp2=Pointer->son;
	l--;
	gettorightlvl(temp,temp2,l,e,found);
	Pointer=temp;
	return *Pointer;
}
void Tree::gettorightlvl (Tree* &temp, Tree* temp2,int curlvl, int &curelem,bool &found)
{	
	if(found) return;
	if(curlvl==0)
	{
		if(found) return;
		if(curelem==0){found=1; temp=temp2;}
		if(found) return;
		curelem--;
		if(temp2->brother!=NULL){gettorightlvl(temp,temp2->brother,curlvl,curelem,found);}
		return;
	}
	if(temp2->son!=NULL)gettorightlvl(temp,temp2->son,curlvl-1,curelem,found);
	if(found) return;
	if(temp2->brother!=NULL)gettorightlvl(temp,temp2->brother,curlvl,curelem,found);
}


Tree* Tree::set(Tree* nodefath)
{
	if (nodefath->lvl==0)
	{
		nodefath->lvl=1;
		nodefath->root=this;
		return this;
	}
	if(nodefath->son!=NULL)
	{
		Tree *b= new Tree;
		Tree *temp=nodefath->son;
		while(temp->brother!=NULL)
			temp=temp->brother;
		temp->brother=b;
		b->fath=nodefath;
		b->lvl=(nodefath->lvl)+1;
		b->root=nodefath->root;
		return b;
	}
	if(nodefath->son==NULL)
	{
		Tree *s= new Tree;
		nodefath->son=s;
		s->lvl=(nodefath->lvl)+1;
		s->root=nodefath->root;
		s->fath=nodefath;
		return s;
	}	
}

ostream& operator<<(ostream& cout, const Tree d)
{
	cout<<d.info;
	return cout;
}
void Tree::visual(Tree* node)
{
	for(int i=0;i<node->lvl-1;i++)
		cout<<"  ";
	cout<<*node<<endl;
	if (node->son!=NULL)
		visual(node->son);
	if (node->brother!=NULL)
		visual(node->brother);
	return;
}
void Tree::remove(Tree* node)
{
	if((node->lvl==0)||(node==NULL)){cout<<"невозможно удалить то что еще не создано"<<endl;}
	if(node->brother!=NULL)
	{
		Tree* temp=node->fath->son;
		while(temp->brother!=node)
			temp=temp->brother;
		temp->brother=node->brother;
		destroy(node);
		return;
	}
	if(node==root)
	{
		strcpy(info,"\n");
		Tree::fath=NULL;
		Tree::lvl=0;
		Tree::root=NULL;
		if(node->son!=NULL) destroy(node->son);
		Tree::son=NULL;
		return;
	}
	if(node->fath!=NULL)
	{
		if(node->fath->son==node)
		{
			if (node->brother!=NULL) node->fath->son=node->brother;
			destroy (node);
			return;
		}
	}
	destroy (node);
}
void Tree::destroy(Tree *node)
{
	if(node->son!=NULL)
		destroy(node->son);
	if(node->brother!=NULL)
		destroy(node->brother);
	delete node;
}
void Tree::operator=(Tree &Tree2)
{
	strcpy(info,Tree2.info);
	if(Tree2.son!=NULL)
	{
		destroy(this->son);
		Tree *s= new Tree(*(Tree2.son));
		this->son=s;
		s->lvl=(this->lvl)+1;
		s->root=this->root;
		s->fath=this;
		if((((Tree2.son)->son)!=NULL)||(((Tree2.son)->brother)!=NULL))
		copyleftover(s,Tree2.son);
	}
}
void Tree::copyleftover(Tree* copynode,Tree* wherenode)
{
	if(wherenode->son!=NULL)
	{
		Tree *s= new Tree(*(wherenode->son));
		copynode->son=s;
		s->lvl=(copynode->lvl)+1;
		s->root=copynode->root;
		s->fath=copynode;
		copyleftover(s,wherenode->son);
	}
	if(wherenode->brother!=NULL)
	{
		Tree *b= new Tree(*(wherenode->brother));
		copynode->brother=b;
		b->fath=copynode->fath;
		b->lvl=copynode->lvl;
		b->root=copynode->root;
		copyleftover(b,wherenode->brother);
	}
}
Tree::Tree(const Tree &A)
{
	strcpy(info,A.info);
	Tree::son=NULL;
	Tree::brother=NULL;
	Tree::fath=NULL;
	Tree::lvl=0;
	Tree::root=NULL;
}

void Tree::filein(char name[256])
{ 
    ifstream fin(name);
    if (!fin.is_open())
        cout << "Файл не может быть открыт!"<<endl;
    else
    {
		fin >>*(set(this));
		while(fin)
		{
		int i=0;
		int j=0;
		fin >> i; 
		fin >> j;
		if(&(operator()(i,j))==NULL){cout<<"Нарушена последовательность"<<endl;continue;}
		fin>>*(set(&(operator()(i,j))));
		}
    }
	fin.close();
}

void Tree::fileout(char name[256])
{ 
    ofstream fout(name);
    if (!fout.is_open())
        cout << "Файл не может быть открыт!"<<endl;
    else
    {
		visualfile(fout,this);
    }
	fout.close();
}
void Tree::visualfile(ofstream& fout,Tree* node)
{
	for(int i=0;i<node->lvl-1;i++)
		fout<<"  ";
	fout<<*node<<endl;
	if (node->son!=NULL)
		visualfile(fout,node->son);
	if (node->brother!=NULL)
		visualfile(fout,node->brother);
	return;
}

void Tree::operator [](int lvl)
{
	cout << "Вы запустили функцию перегрузки operator[] c параметром "<<lvl<<endl;
}
Tree::~Tree()
{

}
