#pragma once
#include <vector>
#include <iostream>
using namespace std;
typedef enum {BLACK, RED} typeColor;
#define NIL &leaf

namespace qwe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public struct RBT {
		int key;
		RBT *left;
		RBT *right;
		RBT *parent;
		typeColor color;
	};
	RBT leaf = { 0, 0, 0, 0, BLACK};
	RBT *tree=NIL;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		Graphics^ g;

		Form1(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(984, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 51);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Добавляем элемент";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(984, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 21);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(984, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 51);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Удаляем элемент";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(984, 206);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(110, 21);
			this->textBox2->TabIndex = 4;
						// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1106, 662);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Red-Black-Tree";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void Make_RBT(RBT** Node, vector<int> vec){
			for(int i=0; i<(int)vec.size(); i++){
				RB_Insert(Node, vec[i]);
			}
		}
		void RB_Insert(RBT **Node, int data){
			RBT *newNode, **current, *ptr;
			ptr = NIL;
			current = Node;
			while(*current != NIL){
				ptr = *current;
				if(data < (*current)->key)
					current = &((*current)->left);
				else current = &((*current)->right);
			}
			newNode = new RBT();
			newNode->key = data;
			newNode->parent = ptr;
			newNode->left=NIL;
			newNode->right=NIL;
			newNode->color=RED;
			if(ptr == NIL)
				(*current) = newNode;
			else { if(data < ptr->key)
				ptr->left = newNode;
			else ptr->right = newNode;
			}
			RB_Insert_Fixup(Node,newNode);
		}
		void RB_Insert_Fixup(RBT **Node,RBT *newNode){
			while(newNode->parent->color == RED){
				MessageBox::Show("Перекрашиваем","Сообщение");
				if(newNode->parent == newNode->parent->parent->left){		//родитель нового узла  является 
					RBT *y = newNode->parent->parent->right;				//правым или левым потомком
					if(y->color == RED){
						MessageBox::Show("Перекрашиваем","Сообщение");//цвет дяди нового узла 
						newNode->parent->color = BLACK;				//случай 1 когда дядя красный
						y->color = BLACK;						//рисунок на стр 349
						newNode->parent->parent->color = RED;
						newNode = newNode->parent->parent;			//------
					} else { if(newNode == newNode->parent->right){
						newNode = newNode->parent;	
						 MessageBox::Show("Левый поворот","Поворот");//случай 2 дядя красный и новый узел 
						Left_Rotate(Node,newNode);					//является правым потомком
					}		//стр 350
					newNode->parent->color = BLACK;					//случай 3 дядя красный и новый узел 
					newNode->parent->parent->color = RED;	
						 MessageBox::Show("Правый поворот","Поворот");//является левым потомком
					Right_Rotate(Node,newNode->parent->parent);		//
					}
				}
				else {
					RBT *y = newNode->parent->parent->left;
					if(y->color == RED){
						newNode->parent->color = BLACK;
						y->color = BLACK;
						newNode->parent->parent->color = RED;
						newNode = newNode->parent->parent;
					} else {
						if(newNode == newNode->parent->left){
							newNode = newNode->parent;
						 MessageBox::Show("Правый поворот","Поворот");
							Right_Rotate(Node,newNode);
						}
						newNode->parent->color = BLACK;
						newNode->parent->parent->color = RED;
						MessageBox::Show("Левый поворот","Поворот");
						Left_Rotate(Node,newNode->parent->parent);
					}
				}
			}
			(*Node)->color = BLACK;
		}
		void Left_Rotate(RBT **Node, RBT *current){	
			RBT *y=current->right;
			current->right=y->left;
			if(y->left != NIL)
				y->left->parent = current;
			y->parent = current->parent;
			if(current->parent == NIL)
				*Node = y;
			else { if(current == current->parent->left)
				current->parent->left = y;
			else current->parent->right = y;
			}
			y->left = current;
			current->parent = y;
		}
		void Right_Rotate(RBT **Node, RBT *current){
			RBT *y=current->left;
			current->left = y->right;
			if(y->right != NIL)
				y->right->parent = current;
			y->parent = current->parent;
			if(current->parent == NIL)
				*Node = y;
			else { if(current == current->parent->right)
				current->parent->right = y;
			else current->parent->left = y;
			}
			y->right = current;
			current->parent = y;
		}
		void RB_Delete(RBT **Node, RBT *delNode){
			RBT *y, *x;
			if((delNode->left == NIL) || (delNode->right == NIL))
				y = delNode;
			else y = Tree_Successor(delNode);
			if(y->left != NIL)
				x = y->left;
			else x = y->right;
			x->parent = y->parent;
			if(y->parent == NIL)
				*(Node) = x;
			else {
				if(y == y->parent->left)
					y->parent->left = x;
				else y->parent->right = x;
			}
			if(y != delNode)
				delNode->key = y->key;
			if(y->color == BLACK)
				RB_Delete_Fixup(Node,x);
			delete[] y;
		}
		void RB_Delete_Fixup(RBT **Node, RBT *x){
			while ((x != *(Node)) && (x->color == BLACK)){
				if(x == x->parent->left){
					RBT *w = x->parent->right;
					if(w->color == RED){
						w->color = BLACK;
						x->parent->color = RED;
						MessageBox::Show("Левый поворот","Поворот");
						Left_Rotate(Node,x->parent);
						w = x->parent->right;
					}
					if((w->left->color == BLACK) && (w->right->color == BLACK)){
						w->color = RED;
						x = x->parent;
					}
					else {
						if(w->right->color == BLACK){
							w->left->color = BLACK;
							w->color = RED;
							MessageBox::Show("Правый поворот","Поворот");
							Right_Rotate(Node, w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						MessageBox::Show("Левый поворот","Поворот");
						Left_Rotate(Node, x->parent);
						x = *(Node);
					}
				}
				else {
					RBT *w = x->parent->left;
					if(w->color == RED){
						w->color = BLACK;
						x->parent->color = RED;
						MessageBox::Show("Правый поворот","Поворот");
						Right_Rotate(Node,x->parent);
						w = x->parent->left;
					}
					if((w->right->color == BLACK) && (w->left->color == BLACK)){
						w->color = RED;
						x = x->parent;
					}
					else {
						if(w->left->color == BLACK){
							w->right->color = BLACK;
							w->color = RED;
							MessageBox::Show("Левый поворот","Поворот");
							Left_Rotate(Node, w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						MessageBox::Show("Правый поворот","Поворот");
						Right_Rotate(Node, x->parent);
						x = (*Node);
					}
				}
			}
			x->color = BLACK;
		}
		RBT *Tree_Successor(RBT *Node){
			if(Node->right != NIL)
				return Tree_Minimum(Node->right);
			RBT *y=Node->parent;
			while((y != NIL) && (Node == y->right)){
				Node = y;
				y = y->parent;
			}
			return y;
		}
		RBT *Tree_Minimum(RBT *Node){
			while (Node->left != NIL){
				Node = Node->left;
			}
			return Node;
		}
		RBT *RB_Search(RBT **Node, int data){
			RBT *current;
			current=(*Node);
			while(current != NIL){
				if(data == current->key)
					return current;
				else if(data < current->key)
					current = current->left;
				else current = current->right;
			}
			return 0;
		}
		void Print_RBT(RBT* Node,int k){
			if(Node != NIL){
				Print_RBT(Node->right,k+1);
				Print_RBT(Node->left,k+1);
			}
			else cout<<endl;
		}	
		void Delete_RBT(RBT* Node){
			if (Node != NIL) {
				Delete_RBT(Node->left);
				Delete_RBT(Node->right);
				delete(Node);
			}
		}

	private: void drawNode(int parx, int x,int y,int key, typeColor color){
				 Pen^ myPen =gcnew Pen(Color::Blue);
				 myPen->Width=5;
				 if(y>40)
				 g->DrawLine(myPen,parx,y-40,x-5,y-5);  
				 SolidBrush^ myBrush=gcnew SolidBrush(Color::Black);
				 if(color==RED) myBrush->Color=Color::Red;
				 Rectangle rect=Rectangle(x-20,y-20,45,45);
				 g->FillEllipse(myBrush,rect);
				 System::Drawing::Font^ myFont = gcnew System::Drawing::Font( "Mistral",21 );
				 myBrush->Color=Color::White;
				 g->DrawString(key.ToString(),myFont,myBrush,x-12,y-12);
				 delete myBrush;
				 delete myFont;
				 delete myPen;
			 }
	private: void draw_RBT(RBT* Node,int parx, int x, int y,int count){
				 if (Node != NIL) {
					 drawNode(parx,x,y,Node->key,Node->color);
					 draw_RBT(Node->left,parx=x+(1000/(Math::Pow(2,count)))-11, x-=(1000/(Math::Pow(2,count))) , y+60, count+1); 
					 draw_RBT(Node->right,parx=x-(1000/(Math::Pow(2,count)))+11, x+=(1000/(Math::Pow(2,count-1))) , y+60,count+1);
				 }
			 }
	private: vector<int> getInt(TextBox^ box){
				 array<String^>^ split = box->Text->Split(gcnew array<System::String^>{","," "},
					 System::StringSplitOptions::RemoveEmptyEntries);
				 vector<int> vec;
				 for(int i=0;i<split->Length;i++){
					 vec.push_back(Convert::ToInt32(split[i]));
				 }
				 return vec;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 vector<int> vec;
				 vec=getInt(textBox1);
				 for(int i=0; i<(int)vec.size(); i++){
					 RB_Insert(&tree, vec[i]);
				 }
				 textBox1->Text="";
				 draw_RBT(tree,500,500,40,2);
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 vector<int> vec;
				 vec=getInt(textBox2);
				 for(int i=0; i<(int)vec.size(); i++){
					 try{RB_Delete(&tree,RB_Search(&tree,vec[i]));
					 g->Clear(Color::WhiteSmoke);
					 draw_RBT(tree,500,500,40,2);
					 }
					 catch(Exception^ e){
						 MessageBox::Show("Данного элемента не существует!","Ошибка!");
					 }
				 }
				 textBox2->Text="";
			 }
	};
}

