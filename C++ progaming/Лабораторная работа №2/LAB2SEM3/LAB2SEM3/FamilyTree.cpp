#include "FamilyTree.h"
void FamilyTree::myhasband(int lvl)
{
	int elem=0;
	for(int j=0; &(operator()(lvl,j))!=NULL;j++)
		elem++;
	cout<<"�� "<<lvl<<" ������ � ��c "<< elem<<" �������"<<endl;
}