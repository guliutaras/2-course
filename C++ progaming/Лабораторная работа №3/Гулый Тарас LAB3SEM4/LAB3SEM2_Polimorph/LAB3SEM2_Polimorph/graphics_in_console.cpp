#pragma once
#include "graphics_in_console.h"

void moving_trace(Shape* s)
{
	system("cls");
	Sleep(100);
	cout<<"Двигайтесь стрелочками по завершению нажмите нажмите esc"<<endl;
	s->draw(s->color);
	char c;
	while (c = getch(), c!=27)
	{
		
		if (c == '\xe0')
		{
		   c = getch();

		   switch (c)
		   {
		      case LARROW:
		      			s->move_trace(-STEP,0);
		      			break;
		      case RARROW:
		      			s->move_trace(+STEP,0);
		      			break;
		      case UARROW:
		      			s->move_trace(0,-STEP);
		      			break;
		      case DARROW:
		      			s->move_trace(0,+STEP);
		      			break;
		   }
		}
	}
}
void moving_trac(Shape *s)
{
	int n=0;
	char* a;
	system("cls");
	Sleep(100);
	cout<<"Введите длину траекторию"<<endl;
	cin>>n;
	a=new char[n];
	cout<<"Введите последовательность из "<<n<<" елементов."<<endl;
	cout<<"В последовательности w-вверх d-влево a-вправо s-вниз"<<endl;
	cout<<"Поставте последним елементом с если хотите зациклить траекторию"<<endl;
	for(int i=0; i<n;i++)
	cin>>a[i];
	s->draw(s->color);
	if(a[n-1]!='c')
	{
		for(int i=0;i<n;i++) 
		{
			Sleep(200);
			switch (a[i])
			{
			case 'a':
				s->move(-STEP,0);
				break;
			case 'd':
				s->move(+STEP,0);
				break;
			case 'w':
				s->move(0,-STEP);
				break;
			case 's':
				s->move(0,+STEP);
				break;
			}
		}
	}
	else
	{
		cout<<"Сколько итераций цикла траектории вы хотите проделать?"<<endl;
		int j;
		cin>>j;
		for(int k=0;k<j;k++) 
		{
			for(int i=0;i<n;i++) 
			{
				Sleep(200);
				switch (a[i])
				{
				case 'a':
					s->move(-STEP,0);
					break;
				case 'd':
					s->move(+STEP,0);
					break;
				case 'w':
					s->move(0,-STEP);
					break;
				case 's':
					s->move(0,+STEP);
					break;
				}
			}
		}
	}
	cout<<"Фигура заврешила движение."<<endl;
	getch();
}
void moving(Shape* s)
{
	system("cls");
	Sleep(100);
	cout<<"Двигайтесь стрелочками по завершению нажмите нажмите esc"<<endl;
	s->draw(s->color);
	char c;
	while (c = getch(), c!=27)
	{
		if (c == '\xe0')
		{
		   c = getch();

		   switch (c)
		   {
		      case LARROW:
		      			s->move(-STEP,0);
		      			break;
		      case RARROW:
		      			s->move(+STEP,0);
		      			break;
		      case UARROW:
		      			s->move(0,-STEP);
		      			break;
		      case DARROW:
		      			s->move(0,+STEP);
		      			break;
		   }
		}
	}
}
void ShapeOption(Shape* s)
{
	Shape *sold=NULL;
	sold=s->copy();
	while(true)
	{
		system("cls");
		cout<<"Меню работы с фигурой"<<endl;
		cout<<"1-Поменять цвет"<<endl;
		cout<<"2-Двигать фигуру"<<endl;
		cout<<"3-Двигать по траектории"<<endl;
		cout<<"4-Деформировать фигуру"<<endl;
		cout<<"5-Двигать со следом"<<endl;
		cout<<"0-Выйти в меню работы со списком"<<endl;
		switch(getch())
		{
		case'1':
			{
				cout<<"Введите идентификатор цвета"<<endl;
				int i;
				cin>>i;
				s->colorch(i);
				s->draw(s->color);
				getch();
				system("cls");
				continue;
			}
		case'2':
			{
				moving(s);
				system("cls");
				continue;
			}
		case'3':
			{
				moving_trac(s);
				system("cls");
				continue;
			}
		case'4':
			{
				system("cls");
				Sleep(100);
				cout<<"Объект был уменьшен на 20%"<<endl;
				s->deform();
				s->draw(s->color);
				getch();
				system("cls");
				continue;
			}
		case'5':
			{
				moving_trace(s);
				system("cls");
				continue;
			}
		case'0':{return;}
		}
		system("cls");
		cin.clear();
		_flushall();
	}
}
void Nstar::draw(int c) 
	{
		float a=0;
		int *xi= new int[2*n+1];
		int *yi= new int[2*n+1];
		console_graphics.setcolor(c); 
		for (int i=0; i<2*n+1; i++)
		{
			if(!(i%2))
			{
				*(xi+i)=x+r/2*cos(a*M_PI/180);
				*(yi+i)=y+r/2*sin(a*M_PI/180);
			}
			else
			{
				*(xi+i)=x+r*cos(a*M_PI/180);
				*(yi+i)=y+r*sin(a*M_PI/180);
			}
			a=a+180/n;
		}
		*(xi+2*n)=*(xi);
		*(yi+2*n)=*(yi);
		int xlast=*(xi);
		int ylast=*(yi);
		for(int i=1; i<2*n+1; i++)
		{
			console_graphics.line(xlast,ylast,*(xi+i),*(yi+i));
			xlast=*(xi+i);
			ylast=*(yi+i);
		}
		delete[] xi;
		delete[] yi;
	}
void Segment::draw(int c) {console_graphics.setcolor(c); console_graphics.line(x,y,x+dx,y+dy);}
void Circle::draw(int c) {console_graphics.setcolor(c); console_graphics.circle(x,y,r); }
void Rectangl::draw(int c) {console_graphics.setcolor(c); console_graphics.rectangle(x,y,x+dx,y+dy); }
void Triangle::draw(int c) 
	{
		console_graphics.setcolor(c); 
		console_graphics.line(x,y,x+dx1,y+dy1);
		console_graphics.line(x,y,x+dx2,y+dy2);
		console_graphics.line(x+dx1,y+dy1,x+dx2,y+dy2);
	}
void cashin(ifstream &fin, ShapeList &L)
{
	ShapeElem* prew=L.head;
	if(L.head!=NULL)
	{
		while(prew->next!=NULL)
			prew=prew->next;
	}
	char type;
	while(fin>>type)
	{
		Shape* newshape;
		switch (type)
		{
		case 'c':{newshape=new Circle(0,0,0,0); break;}
		case 'r':{newshape=new Rectangl(0,0,0,0,0); break;}
		case 's':{newshape=new Segment(0,0,0,0,0); break;}
		case 'n':{newshape=new Nstar(0,0,200,200,0); break;}
		case 't':{newshape=new Triangle(0,0,0,0,0,0,0); break;}
		case 'a':{fin>>type; type='a';ShapeList L; newshape=new Agregat(0,0,L,0); break;}
		case '}':{return;}
		}
		newshape->ifile(fin);
		ShapeElem* newobj= new ShapeElem(newshape,type);
		if (prew!=NULL){prew->next=newobj;}
		else{L.head=newobj;}
		prew=newobj;
	}
	fin.close();
	cout<<"Загрузка конфигураций прошла успешно"<<endl;
	getch();
}
void AgregMode(ShapeList LM)
{
	cout<<"Вы вошли в режим создания фигуры агрегата"<<endl;
	cout<<"Обязательным дерективой являеться агрегирования первой фигуры"<<endl;
	cout<<"Далее фигуры будут агрегироваться пока вы этого не захотите"<<endl;
	cout<<"Вы можете добавлять"<<endl;
	cout<<"Для агрегирования первой фигуры аггрегата нажмите любую клавишу"<<endl;
	getch();
	Shape* S=NULL;
	ShapeElem*Choo=LM.Choosing();
	ShapeElem* Choocpy= new ShapeElem(Choo->shape->copy(),Choo->name);
	ShapeList L;
	L.push_back(Choocpy);
	while(1)
	{
		cout<<"Хотите добавить еще фигуру?"<<endl;
		cout<<"1-да, 2-нет"<<endl;
		if(getch()=='1')
		{
			ShapeElem*Temp=LM.Choosing();
			ShapeElem* Tempcpy= new ShapeElem(Temp->shape->copy(),Temp->name);
			L.push_back(Tempcpy);
			continue;
		}
		else break;
	}
	Agregat* temp= new Agregat(0,0,L,0);
	temp->redraw();
	cout<<"Включен режим перемещений объектов фигуры-агрегата"<<endl;
	cout<<"Для начала перемещений фигур нажмите любую клавишу"<<endl;
	cout<<"Когда закончите перемещать конкретнкю фигуру нажмите esc"<<endl;
	temp->move_each();
	S=temp;
	ShapeElem* AgregObj= new ShapeElem(S,'a');
	LM.push_back(AgregObj);
	system("cls");
	cout<<"Фигура агрегат успешно создана копированием"<<endl;
	getch();
}
void Nstar::deform()
{
	float dt=r*0.2;
	r=int(r-dt);
}
Shape* Nstar::copy()
{
	Shape* su;
	int xs=Shape::x;
	int ys=Shape::y;
	int cs=Shape::color;
	int rs=Nstar::r;
	int ns=Nstar::n;
	su=new Nstar(xs,ys,rs,ns,cs);
	return su;
}
ofstream& Nstar::ofile(ofstream &fout)
{
	fout<<'n'<<" "<<x<<" "<<y<<" "<<r<<" "<<n<<" "<<color<<endl;
	return fout;
}
ifstream& Nstar::ifile(ifstream &fin)
{
	fin>>x>>y>>r>>n>>color;
	return fin;
}
void Segment::deform()
{
	float dt=dx*0.2;
	dx=int(dx-dt);
	dt=dy*0.2;
	dy=int(dy-dt);
}
Shape* Segment::copy()
{
	Shape* su;
	int xs=Shape::x;
	int ys=Shape::y;
	int cs=Shape::color;
	int dxs=Segment::dx;
	int dys=Segment::dy;
	su=new Segment(xs,ys,dx,dy,cs); 
	return su;
}
ofstream& Segment::ofile(ofstream &fout)
{
	fout<<'s'<<" "<<x<<" "<<y<<" "<<dx<<" "<<dy<<" "<<color<<endl;
	return fout;
}
ifstream& Segment::ifile(ifstream &fin)
{
	fin>>x>>y>>dx>>dy>>color;
	return fin;
}
void Circle::deform()
	{
		float dt=r*0.2;
		r=int(r-dt);
	}
	Shape* Circle::copy()
	{
		Shape* su;
		int xs=Shape::x;
		int ys=Shape::y;
		int cs=Shape::color;
		int rs=Circle::r;
		su=new Circle(xs,ys,rs,cs);
		return su;
	}
	ofstream& Circle::ofile(ofstream &fout)
	{
		fout<<'c'<<" "<<x<<" "<<y<<" "<<r<<" "<<color<<endl;
		return fout;
	}
	ifstream& Circle::ifile(ifstream &fin)
	{
		fin>>x>>y>>r>>color;
		return fin;
	}
	void Rectangl::deform()
	{
		float dt=dx*0.2;
		dx=int(dx-dt);
		dt=dy*0.2;
		dy=int(dy-dt);
	}
	Shape* Rectangl::copy()
	{
		Shape* su;
		int xs=Shape::x;
		int ys=Shape::y;
		int cs=Shape::color;
		int dxs=Rectangl::dx;
		int dys=Rectangl::dy;
		su=new Rectangl(xs,ys,dx,dy,cs); 
		return su;
	}
	ofstream& Rectangl::ofile(ofstream &fout)
	{
		fout<<'r'<<" "<<x<<" "<<y<<" "<<dx<<" "<<dy<<" "<<color<<endl;
		return fout;
	}
	ifstream& Rectangl::ifile(ifstream &fin)
	{
		fin>>x>>y>>dx>>dy>>color;
		return fin;
	}
	void Triangle::deform()
	{
		float dt=dx1*0.2;
		dx1=int(dx1-dt);
		dt=dy1*0.2;
		dy1=int(dy1-dt);
		dt=dx2*0.2;
		dx2=int(dx2-dt);
		dt=dy2*0.2;
		dy2=int(dy2-dt);
	}
	Shape* Triangle::copy()
	{
		Shape* su;
		int xs=Shape::x;
		int ys=Shape::y;
		int cs=Shape::color;
		int dx1s=Triangle::dx1;
		int dy1s=Triangle::dy1;
		int dx2s=Triangle::dx2;
		int dy2s=Triangle::dy2;
		su=new Triangle(xs,ys,dx1s,dy1s,dx2s,dy2s,cs); 
		return su;
	}
	ofstream& Triangle::ofile(ofstream &fout)
	{
		fout<<'t'<<" "<<x<<" "<<y<<" "<<dx1<<" "<<dy1<<" "<<dx2<<" "<<dy2<<" "<<color<<endl;
		return fout;
	}
	ifstream& Triangle::ifile(ifstream &fin)
	{
		fin>>x>>y>>dx1>>dy1>>dx2>>dy2>>color;
		return fin;
	}
	void Agregat::draw (int c)
	   {
		   ShapeElem* temp= Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->draw(temp->shape->color);
			   temp=temp->next;
		   }
	   }
	   void Agregat::show ()
	   {
		   ShapeElem* temp= Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->show();
			   temp=temp->next;
		   }
	   }
	   void Agregat::hide()
	   {
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->hide();
			   temp=temp->next;
		   }
	   }
	   void Agregat::deform()
	   {
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->deform();
			   temp=temp->next;
		   }
	   }
	   void Agregat::colorch(int color1)
	   {
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->colorch(color1);
			   temp=temp->next;
		   }
	   }
	   void Agregat::move(int dx, int dy) 
	   { 
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->move(dx,dy);
			   temp=temp->next;
		   }
	   }
	   void Agregat::move_trace(int dx, int dy)   
	   { 
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->move_trace(dx,dy);
			   temp=temp->next;
		   }
	   }
	   void Agregat::move_each()
	   {
		   ShapeElem* temp2=Headake.head;
		   while(temp2!=NULL)
		   {
			   system("cls");
			   redraw();
			   Sleep(200);
			   int cl= temp2->shape->color;
			   temp2->shape->draw(6);
			   Sleep(200);
			   temp2->shape->draw(cl);
			   redraw();
			   cout<<"Двигайтесь стрелочками по завершению нажмите нажмите esc"<<endl;
			   char c;
			   while (c = getch(), c!=27)
			   {
				   if (c == '\xe0')
				   {
					   c = getch();
					   switch (c)
					   {
					   case LARROW:
						   temp2->shape->move(-STEP,0);
						   break;
					   case RARROW:
						   temp2->shape->move(+STEP,0);
						   break;
					   case UARROW:
						   temp2->shape->move(0,-STEP);
						   break;
					   case DARROW:
						   temp2->shape->move(0,+STEP);
						   break;
					   }
					   redraw();
				   }
			   }
			   temp2=temp2->next;
		   }

	   }
	   Shape* Agregat::copy()
	   {
		   ShapeList L;
		   ShapeElem *temp=Headake.head;
		   while(temp!=NULL){ShapeElem* s=new ShapeElem(temp->shape->copy(),temp->name);L.push_back(s); temp=temp->next;}
		   Shape* su=new Agregat(Shape::x,Shape::y,L,Shape::color);
		   return su;
	   }
	   void Agregat::redraw()
	   {
		   ShapeElem* t=Headake.head;
		   if(t==NULL) return;
		   while(t!=NULL)
		   {
			   Shape* r;
			   r=t->shape;
			   Sleep(100);
			   r->draw(r->color);
			   t=t->next;
		   }
	   }
	   ofstream& Agregat::ofile(ofstream &fout)
	   {
		   fout<<'a'<<endl;
		   fout<<'{'<<endl;
		   ShapeElem* temp=Headake.head;
		   while(temp!=NULL)
		   {
			   temp->shape->ofile(fout);
			   temp=temp->next;
		   }
		   fout<<'}'<<endl;
		   return fout;
	   }
	   ifstream& Agregat::ifile(ifstream &fin)
	   {
		   ShapeList L;
		   cashin(fin,L);
		   Headake.head=L.head;
		   return fin;
	   }