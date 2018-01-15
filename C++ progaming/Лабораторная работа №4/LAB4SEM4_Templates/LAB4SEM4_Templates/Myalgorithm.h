#pragma once

template<class t1, class itor>
itor find(itor b, itor e, t1 what)// ������� ���������� �������� � ����������
{
	for(;b!=e; b++) if((*b)==what) return b;//������� ���� ��������� ���� �� ������� ������� ������� � ��������� ��� ��������
	return e;
}

template<class itor>
itor min_element(itor b, itor e)//������� ���������� ������������ �������� � ����������
{
	itor temp=b;
	for(;b!=e; b++) if((*b)<(*temp)) temp=b;// ������� ��������� ��������� ����������� ������� � ���������� ����������
	return temp;//���������� �����������
}

template<class iter, class Predicate>
void for_each(iter b, iter e, Predicate pred)// ������� "��� ������� ��������"
{
	iter i=b;
	for(i; i!=e; i++)//��� ������� �������� ���������� ��������� ���������
		pred(*i);
}