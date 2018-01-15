#pragma once

template<class t1, class itor>
itor find(itor b, itor e, t1 what)// функци€ нахождени€ елемента в контейнере
{
	for(;b!=e; b++) if((*b)==what) return b;//обходим весь контейнер пока не находим искомый елемент и возвращем его итератор
	return e;
}

template<class itor>
itor min_element(itor b, itor e)//функци€ нахождени€ минимального елемента в контейнере
{
	itor temp=b;
	for(;b!=e; b++) if((*b)<(*temp)) temp=b;// обхлжим контейнер сравнива€ минимальний елемент с елементами контейнера
	return temp;//возвращ€ем минимальний
}

template<class iter, class Predicate>
void for_each(iter b, iter e, Predicate pred)// функци€ "дл€ каждого елемента"
{
	iter i=b;
	for(i; i!=e; i++)//дл€ каждого елемента контейнера выполн€ем действией
		pred(*i);
}