
#pragma once
#include <stdio.h>
#include <conio.h>
#include "Storage.h"
#include <queue>
#include <math.h>
#include "Storage.h"

class Edge;

class Vertex{
public:
	int x,y;
	bool moving;
	bool selected;
	bool connecting;

	virtual void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr, int RAD, int FRAME, int num=0){
		System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(Colr);
		System::Drawing::SolidBrush^ b_magenta = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Magenta);
		System::Drawing::SolidBrush^ b_coral = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Coral);
		System::Drawing::SolidBrush^ wBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);

		if(selected)
			e->Graphics->FillEllipse(b_coral, x-RAD/2, y-RAD/2, RAD, RAD);
		else if(connecting)
			e->Graphics->FillEllipse(b_magenta, x-RAD/2, y-RAD/2, RAD, RAD);
		else
			e->Graphics->FillEllipse(myBrush, x-RAD/2, y-RAD/2, RAD, RAD);
		e->Graphics->FillEllipse(wBrush, x-RAD/2+FRAME/2, y-RAD/2+FRAME/2, RAD-FRAME, RAD-FRAME);

		if(num>0){
			System::Drawing::StringFormat^ numSF = gcnew System::Drawing::StringFormat();
			System::Drawing::Font^ numDF = gcnew System::Drawing::Font("Arial", 8);
			System::Drawing::SolidBrush^ BlackBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
			e->Graphics->DrawString(System::Convert::ToString(num), numDF, BlackBrush, x-8, y-8, numSF);
			delete numSF;
			delete numDF;
			delete BlackBrush;
		}
		
		delete b_magenta;
		delete b_coral;
		delete myBrush;
		delete wBrush;
	}	

	virtual void Move(int X, int Y){
		x+=X; y+=Y;
	}

	virtual void Save(ofstream* of){
		*of<<"V "<<x<<" "<<y;
	}

	Vertex(int _x, int _y){
		x=_x; y=_y;
		connecting=selected=moving=false;
	}

	virtual ~Vertex(){};
};

class MiddleVert:public Vertex{
public:
	Edge* edge;
	void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr, int RAD, int FRAME, int num=0){
		System::Drawing::SolidBrush^ myBrush = gcnew System::Drawing::SolidBrush(Colr);
		System::Drawing::SolidBrush^ wBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);


		e->Graphics->FillEllipse(myBrush, x-RAD/2, y-RAD/2, RAD, RAD);
		e->Graphics->FillEllipse(wBrush, x-RAD/2+FRAME/2, y-RAD/2+FRAME/2, RAD-FRAME, RAD-FRAME);

		if(num>0){
			System::Drawing::StringFormat^ numSF = gcnew System::Drawing::StringFormat();
			System::Drawing::Font^ numDF = gcnew System::Drawing::Font("Arial", 8);
			System::Drawing::SolidBrush^ BlackBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
			e->Graphics->DrawString(System::Convert::ToString(num), numDF, BlackBrush, x-8, y-8, numSF);
			delete numSF;
			delete numDF;
			delete BlackBrush;
		}
		
		delete myBrush;
		delete wBrush;
	}	

	MiddleVert(int X, int Y, Edge* ed):Vertex(X,Y){edge=ed;}
	~MiddleVert(){};
};

class Edge{
public:
	int cost;
	Vertex *V1, *V2;
	MiddleVert *Mid;

	virtual void Action(){}

	virtual bool Del(Edge* de){
		return false;
	}
	virtual bool Add(Edge* ae){
		return false;
	}
	virtual MiddleVert* getMid(Edge* ed){return this==ed?Mid:0;}
	virtual bool isA(Edge* ed){return this==ed;}
	virtual bool isFull(){return false;}
	virtual int getCount(){return 1;}
	virtual Edge* getITS(){return this;}
	virtual char whos(){return 'E';}

	virtual void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr2, System::Drawing::Color Colr1, bool oriented){
		System::Drawing::Pen^ Pen1 = gcnew System::Drawing::Pen(Colr1);
		System::Drawing::Pen^ Pen2 = gcnew System::Drawing::Pen(Colr2);
		
		Mid->x= (V1->x + V2->x)/2;
		Mid->y= (V1->y + V2->y)/2;
		if(oriented){
			e->Graphics->DrawLine(Pen2, V1->x, V1->y, Mid->x, Mid->y);
			e->Graphics->DrawLine(Pen1, Mid->x, Mid->y, V2->x, V2->y);
		}
		else{
			e->Graphics->DrawLine(Pen2, V1->x, V1->y, V2->x, V2->y);
		}
		Mid->Paint(e,Colr2, 16,2,cost);
		delete Pen1;
		delete Pen2;
	}

	void PaintWMid(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr2, System::Drawing::Color Colr1, bool oriented){
		System::Drawing::Pen^ Pen1 = gcnew System::Drawing::Pen(Colr1);
		System::Drawing::Pen^ Pen2 = gcnew System::Drawing::Pen(Colr2);
			
		if(oriented){
			e->Graphics->DrawLine(Pen2, V1->x, V1->y, Mid->x, Mid->y);
			e->Graphics->DrawLine(Pen1, Mid->x, Mid->y, V2->x, V2->y);
		}
		else{
			e->Graphics->DrawLine(Pen1, V1->x, V1->y, Mid->x, Mid->y);
			e->Graphics->DrawLine(Pen1, Mid->x, Mid->y, V2->x, V2->y);
		}
		Mid->Paint(e, Colr2, 16,2,cost);

		delete Pen1;
		delete Pen2;
	}

	virtual void Save(ofstream* of){
		*of<<"E "<<cost<<" "<<V1->x<<" "<<V1->y<<" "<<V2->x<<" "<<V2->y<<" "<<Mid->x<<" "<<Mid->y;
	}
	virtual void Load(ifstream* ifs, Storage<Vertex>* V){
		int c; *ifs>>c; cost=c;
		int x1,y1,x2,y2, xm, ym;
		*ifs>>x1; *ifs>>y1; *ifs>>x2; *ifs>>y2; *ifs>>xm; *ifs>>ym;
		for(V->first(); !V->eol(); V->next()){
			Vertex* tmp=V->getObject();
			if(tmp->x==x1 && tmp->y==y1)
				V1=tmp;
			else if(tmp->x==x2 && tmp->y==y2)
				V2=tmp;
		}
		Mid=new MiddleVert(xm,ym, this);
	}

	Edge(){		
	}
	Edge(Vertex* v1, Vertex* v2){
		V1=v1;
		V2=v2;
		cost=1;
		Mid=new MiddleVert((V1->x+V2->x)/2, (V1->y+V2->y)/2, this);
	}
	Edge(Vertex* v1, Vertex* v2, int c){
		V1=v1;
		V2=v2;
		cost=c;
		Mid=new MiddleVert((V1->x+V2->x)/2, (V1->y+V2->y)/2, this);
	}
	virtual ~Edge(){
		delete Mid;
	}
};

class Loop: public Edge{
	static int pos[4][2];
	int cp;
	int dist;
public:
	char whos(){return 'L';}
	void set_cp(int p){
		cp=p;
		if(cp>3) cp=4;
		if(cp<0) cp=0;
	}

	void Change_pos(){
		cp++;
		if(cp>3) cp=0;
	}

	void Action(){
		Change_pos();
	}

	bool Del(Edge* de){
		return false;
	}
	bool Add(Edge* ae){
		return false;
	}

	void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr2, System::Drawing::Color Colr1, bool oriented){
		System::Drawing::Pen^ Pen1 = gcnew System::Drawing::Pen(Colr2);
		System::Drawing::Pen^ Pen2 = gcnew System::Drawing::Pen(Colr1);

		Mid->x = V1->x + pos[cp][0]*dist;
		Mid->y = V1->y + pos[cp][1]*dist;

		e->Graphics->DrawLine(Pen1, V1->x, V1->y, Mid->x-(dist*pos[cp][0])/2, Mid->y);
		e->Graphics->DrawLine(Pen1, Mid->x-(dist*pos[cp][0])/2, Mid->y, Mid->x, Mid->y);
		e->Graphics->DrawLine(Pen1, Mid->x, Mid->y, Mid->x, Mid->y-(dist*pos[cp][1])/2);
		e->Graphics->DrawLine(Pen1, Mid->x, Mid->y-(dist*pos[cp][1])/2, V1->x, V1->y);

		Mid->Paint(e, Colr2, 16,2,cost);

		delete Pen1;
		delete Pen2;
	}

	virtual void Save(ofstream* of){														///ERRRRRRRRRRRRRRRRRRRRRRRRRRRoR?
		*of<<"L "<<cost<<" "<<cp<<" "<<V1->x<<" "<<V1->y<<" "<<V2->x<<" "<<V2->y<<" "<<Mid->x<<" "<<Mid->y;
	}
	virtual void Load(ifstream* ifs, Storage<Vertex>* V){
		/*char* ch; *ifs>>ch;
		if(ch!='L')
			return;*/
		int c; *ifs>>c; cost=c;
		*ifs>>cp;
		int x1,y1,x2,y2, xm, ym;
		*ifs>>x1; *ifs>>y1; *ifs>>x2; *ifs>>y2; *ifs>>xm; *ifs>>ym;
		for(V->first(); !V->eol(); V->next()){
			Vertex* tmp=V->getObject();
			if(tmp->x==x1 && tmp->y==y1)
				V1=tmp;
			else if(tmp->x==x2 && tmp->y==y2)
				V2=tmp;
		}
		Mid=new MiddleVert(xm,ym, this);
	}

	Loop(){cp=0;dist=20;}
	Loop(Vertex* v1, Vertex* v2):Edge(v1,v2){
		cp=0;dist=20;
		Mid->x = V1->x + pos[cp][0]*dist;
		Mid->y = V1->y + pos[cp][1]*dist;
	}																		//////DISTANCE
	Loop(Vertex* v1, Vertex* v2, int c):Edge(v1,v2,c){
		cp=0;dist=20;
		Mid->x = V1->x + pos[cp][0]*dist;
		Mid->y = V1->x + pos[cp][1]*dist;
	}
	~Loop(){delete Mid;
	}
};
int  Loop::pos[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};

class Multiedge:public Edge{
	Edge* Edges[5];
	int count;
	int get;
public:
	void Action(){
	}

	char whos(){return 'M';}
	bool Add(Edge* ed){
		if(count>=5)
			return false;
		Edges[count++]=ed;
		return true;
	}
	bool Del(Edge* ed){
		if(count<=0)
			return false;
		for(int i=0; i<count; ++i)
			if(Edges[i]==ed){
				delete Edges[i];
				for(int j=i; j<count-1; ++j)
					Edges[j]=Edges[j+1];
				count--;
				return true;
			}
		return false;
	}

	MiddleVert* getMid(Edge* ed){
		for(int i=0; i<count; ++i){
			if(Edges[i]->getMid(ed))
				return Edges[i]->getMid(ed);
		}
		return 0;
	}

	bool isA(Edge* ed){
		for(int i=0; i<count; ++i){
			if(Edges[i]->isA(ed))
				return true;
		}
		return false;
	}

	bool isFull(){
		if(count>=5)
			return true;
		return false;
	}
	int getCount(){
		return count;
	}

	Edge* getITS(){
		Edge* ed = Edges[get++];
		if(get>=count) get=0;
		return ed;
	}

	void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr1, System::Drawing::Color Colr2, bool oriented){
		int midX=0;
		int midY=0;

		int deltaX = V2->x - V1->x;
		int deltaY = V2->y - V1->y;
		int m1,m2,m3,m4;
		m1=1; m2=1; m3=1; m4=1;
		if(deltaX<0 && deltaY<0 || deltaX>0 && deltaY>0){
			m1=1;m4=1; m2=-1;m3=-1; 
		}
		if(deltaX>0 && deltaY<0 || deltaX<0 && deltaY>0){
			m1=-1;m2=-1; m3=1;m4=1;
		}
		midX = V1->x + deltaX/2;
		midY = V1->y + deltaY/2;

		if(count==1){
			Edges[0]->Mid->x = midX;
			Edges[0]->Mid->y = midY;
		}
		else if(count==2){
			Edges[0]->Mid->x = midX+12*m1;
			Edges[0]->Mid->y = midY+12*m2;
			Edges[1]->Mid->x = midX+12*m3;
			Edges[1]->Mid->y = midY+12*m4;
		}
		if(count==3){
			Edges[0]->Mid->x = midX+12*m1;
			Edges[0]->Mid->y = midY+12*m2;
			Edges[1]->Mid->x = midX+12*m3;
			Edges[1]->Mid->y = midY+12*m4;
			Edges[2]->Mid->x = midX;
			Edges[2]->Mid->y = midY;
		}
		if(count==4){
			Edges[0]->Mid->x = midX+12*m1;
			Edges[0]->Mid->y = midY+12*m2;
			Edges[1]->Mid->x = midX+12*m3;
			Edges[1]->Mid->y = midY+12*m4;
			Edges[2]->Mid->x = midX+24*m1;
			Edges[2]->Mid->y = midY+24*m2;
			Edges[3]->Mid->x = midX+24*m3;
			Edges[3]->Mid->y = midY+24*m4;
		}
		if(count==5){
			Edges[0]->Mid->x = midX+12*m1;
			Edges[0]->Mid->y = midY+12*m2;
			Edges[1]->Mid->x = midX+12*m3;
			Edges[1]->Mid->y = midY+12*m4;
			Edges[2]->Mid->x = midX+24*m1;
			Edges[2]->Mid->y = midY+24*m2;
			Edges[3]->Mid->x = midX+24*m3;
			Edges[3]->Mid->y = midY+24*m4;
			Edges[4]->Mid->x = midX;
			Edges[4]->Mid->y = midY;
		}

		for(int i=0; i<count; ++i)
			if(oriented)
				Edges[i]->PaintWMid(e, Colr1, Colr2, oriented);
			else
				Edges[i]->PaintWMid(e, Colr1, Colr1, oriented);
	}

	virtual void Save(ofstream* of){
		*of<<"M "<<count<<" ";					
		for(int i=0; i<count; ++i){
			Edges[i]->Save(of); *of<<" ";
		}
	}
	virtual void Load(ifstream* ifs, Storage<Vertex>* V){
		int n; *ifs>>n;
		char ch;
		for(int i=0; i<n; ++i){
			*ifs>>ch; if(ch!='E') return;
			Edge* NE=new Edge(); NE->Load(ifs, V);
			Add(NE);
		}
	}

	Multiedge(){
		count=0;
		get=0;
		Mid=new MiddleVert(-20,-20,this);
	}

	Multiedge(Edge* ed):Edge(ed->V1, ed->V2){
		count=0;
		Add(ed);
		count=1;
		Mid->x=-20;
		Mid->y=-20;
		get=0;
	}
	Multiedge(Edge* ed, Edge* ed2):Edge(ed->V1, ed->V2){
		count=0;
		Add(ed);
		Add(ed2);
		count=2;
		Mid->x=-20;
		Mid->y=-20;
		get=0;
	}
	~Multiedge(){
		for(int i=0; i<count; ++i)
			delete Edges[i]->Mid;
	}
};
////////////////////////////////////////////////////////////////
class Graph{
	Storage<Vertex> *V;
	Storage<Edge> *E;
	Storage<MiddleVert> *EMV;

	Vertex* con;
	Vertex* mov;
public:
	int RAD;
	int FRAME;
	int M_RAD;
	int M_FRAME;
	bool weight;
	bool oriented;

	bool isWeight(){
		return weight;
	}
	bool isOriented(){
		return oriented;
	}

	int VertNUM(){
		return V->numOf();
	}
	int EdgeNUM(){
		int count=0;
		for(E->first(); !E->eol(); E->next())
			count+=E->getObject()->getCount();
		return count;
	}
	int EmvNUM(){
		return EMV->numOf();
	}

	Vertex* hit(int x, int y){
		for(V->first(); !V->eol(); V->next()){
			Vertex* tmp=V->getObject();
			if((x-tmp->x)*(x-tmp->x)+(y-tmp->y)*(y-tmp->y) <= RAD/2 * RAD/2)
				return tmp;
		}
		return 0;
	}
	Edge* hit_m(int x, int y){
		for(EMV->first(); !EMV->eol(); EMV->next()){
			MiddleVert* tmp=EMV->getObject();
			if((x-tmp->x)*(x-tmp->x)+(y-tmp->y)*(y-tmp->y) <= RAD/2 * RAD/2){
				return tmp->edge;
			}
		}
		return 0;
	}

	void AddVert(Vertex* v){
		V->add(v);
	}
	void AddEdge(Vertex* v1, Vertex* v2, int cost=0){
		Edge* exist=0;
		bool loop=false;
		if(v1==v2) loop=true;
		for(E->first(); !E->eol(); E->next()){
			if(E->getObject()->V1==v1 && E->getObject()->V2==v2 || E->getObject()->V1==v2 && E->getObject()->V2==v1){
				exist=E->getObject(); break;
			}
		}

		Edge* ed;

		if(loop && exist)
			return;

		if(loop && !exist){
			ed=new Loop(v1, v2, cost);
			EMV->add(ed->Mid);
			E->add(ed);
		}
		else if(!exist && !loop){
			ed=new Edge(v1, v2, cost);
			EMV->add(ed->Mid);
			E->add(ed);
		}
		else if(exist && !loop){
			if(exist->isFull())
				return;
			ed=new Edge(v1, v2, cost);

			
			if(exist->Add(ed)){
				EMV->add(ed->Mid);
				return;
			}

			EMV->add(ed->Mid);
			Del(exist);
			EMV->add(exist->Mid);
			
			Multiedge *me = new Multiedge(exist, ed);
			E->add(me);
		}
		
	}

	void Del(Vertex* v){
		for(V->first(); !V->eol(); V->next())
			if(V->getObject()==v){
				V->delCurrent();
				break;
			}
		for(int i=0; i<E->numOf()/4+2; ++i)
		for(E->first(); !E->eol(); E->next()){
			if(E->getObject()->V1 == v || E->getObject()->V2 == v)
				Del(E->getObject());
		}
	}
	void Del(Edge* e){
		if(e->whos()=='M'){
			int c=e->getCount();
			for(int i=0; i<c; ++i)
				Del(e->getITS());
			for(E->first(); !E->eol(); E->next())
				if(E->getObject()==e)
					E->delCurrent();
		}

		else{
		for(EMV->first(); !EMV->eol(); EMV->next())
			if(EMV->getObject()==e->getMid(e)){
				EMV->delCurrent();
				break;
			}
		

		for(E->first(); !E->eol(); E->next())
			//if(E->getObject()==e){
			if(E->getObject()->isA(e)){
				if(E->getObject()->Del(e)){
					if(E->getObject()->getCount()<=0)
						Del(E->getObject());
					break;
				}
				else{
					//for(int 
					//E->getObject()->getITS();     ////////////////////////////////HERE
					E->delCurrent();
					break;
				}
			}
		}
		E->first();
	}

	bool inPB(int x, int y, System::Windows::Forms::PictureBox^ PB){
		if(x-RAD/2 > 0 && y-RAD/2 > 0 && x+RAD/2 < PB->Width && y+RAD/2 < PB->Height)
			return true;
		return false;
	}

	void Paint(System::Windows::Forms::PaintEventArgs^  e, System::Drawing::Color Colr1, System::Drawing::Color Colr2, System::Drawing::Color Colr3, System::Drawing::Color Colr4){
		
		for(E->first(); !E->eol(); E->next())					//Edges
			E->getObject()->Paint(e, Colr2, Colr3, oriented);
		int i=1;
		for(V->first(); !V->eol(); V->next())					//Vertexes
			V->getObject()->Paint(e, Colr1, RAD, FRAME, i++);
	}

	void Move(Vertex* v, int deltaX, int deltaY, System::Windows::Forms::PictureBox^ PB){	
		if(v->selected)
			for(V->first(); !V->eol(); V->next()){
				if(V->getObject()->selected){
					if(inPB(V->getObject()->x+deltaX, V->getObject()->y+deltaY, PB))
						V->getObject()->Move(deltaX,deltaY);;
				}
			}
		else if(inPB(v->x+deltaX, v->y+deltaY, PB))
			v->Move(deltaX, deltaY);
	}

	void Unselect(){
		for(V->first(); !V->eol(); V->next()){
			V->getObject()->selected=false;
		}
	}

	void Save(ofstream* of){
		*of<<V->numOf()<<"\n";
		for(V->first(); !V->eol(); V->next()){
			V->getObject()->Save(of); *of<<" ";
		}
		*of<<"\n"<<E->numOf()<<"\n";
		for(E->first(); !E->eol(); E->next()){
			E->getObject()->Save(of); *of<<" ";
		}
	}

	void Load(ifstream* ifs){
		Storage<Vertex>* NewV = new Storage<Vertex>;
		Storage<Edge>* NewE = new Storage<Edge>;
		Storage<MiddleVert>* NewEMV = new Storage<MiddleVert>;
		char w; *ifs>>w; if(w=='t') weight=true; else weight=false;
		char o; *ifs>>o; if(o=='t') oriented=true; else oriented=false;
		int n; *ifs>>n; char inch=' ';
		for(int i=0; i<n; ++i){
			*ifs>>inch;
			if(inch=='V'){
				int x,y; *ifs>>x; *ifs>>y;
				NewV->add(new Vertex(x,y));
			}
		}
		*ifs>>n;
		for(int i=0; i<n; ++i){
			Edge* ed;
			*ifs>>inch;
			if(inch=='E'){
				ed=new Edge();
				ed->Load(ifs, V);
				NewEMV->add(ed->Mid);
			}
			else if(inch=='L'){
				ed=new Loop();
				ed->Load(ifs, V);
				NewEMV->add(ed->Mid);
			}
			else if(inch=='M'){
				ed=new Multiedge();
				ed->Load(ifs, V);
				int jn=ed->getCount();
				for(int j=0; j<jn; ++j){
					MiddleVert* MiV=ed->getMid(ed->getITS());
					NewEMV->add(MiV);
				}
			}
			NewE->add(ed);
		}
		delete V; delete E; delete EMV;
		V=NewV; EMV=NewEMV; E=NewE;
	}

	void AddLoad(ifstream* ifs){
		char w; *ifs>>w; if(w=='t') weight=true; else weight=false;
		char o; *ifs>>o; if(o=='t') oriented=true; else oriented=false;
		int n; *ifs>>n; char inch=' ';
		for(int i=0; i<n; ++i){
			*ifs>>inch;
			if(inch=='V'){
				int x,y; *ifs>>x; *ifs>>y;
				V->add(new Vertex(x,y));
			}
		}
		*ifs>>n;
		for(int i=0; i<n; ++i){
			Edge* ed;
			*ifs>>inch;
			if(inch=='E'){
				ed=new Edge();
				ed->Load(ifs, V);
				EMV->add(ed->Mid);
			}
			else if(inch=='L'){
				ed=new Loop();
				ed->Load(ifs, V);
				EMV->add(ed->Mid);
			}
			else if(inch=='M'){
				ed=new Multiedge();
				ed->Load(ifs, V);
				int jn=ed->getCount();
				for(int j=0; j<jn; ++j){
					MiddleVert* MiV=ed->getMid(ed->getITS());
					EMV->add(MiV);
				}
			}
			E->add(ed);
		}
	}

	Graph(){
		V=new Storage<Vertex>;
		E=new Storage<Edge>;
		EMV=new Storage<MiddleVert>;
		RAD=26;		M_RAD=16;
		FRAME=4;	M_FRAME=2;
		weight=false;
		oriented=false;
		con=0; mov=0;
	}
	Graph(bool weigh, bool orient){
		V=new Storage<Vertex>;
		E=new Storage<Edge>;
		EMV=new Storage<MiddleVert>;
		RAD=26;		M_RAD=16;
		FRAME=4;	M_FRAME=2;
		weight=weigh;
		oriented=orient;
		con=0; mov=0;
	}
	~Graph(){
		delete V;
		delete E;
		delete EMV;
	}
};